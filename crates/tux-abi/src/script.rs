//! The **script** ("interactive add-on") definition format.
//!
//! A script is one JSON file describing a small state machine of *steps*:
//! dialogs, choice lists, silent checks, visible command runs, branches…
//! Both the search module (to list scripts in the store) and the script
//! engine (to execute them) load files through this module, so a file is
//! validated exactly once, in exactly one way.
//!
//! Safety rules enforced here (see `DOCS/SCRIPTS_SYSTEM.md`):
//! * unknown JSON keys are errors (a typo such as `on_succes` must never
//!   silently change what a script does);
//! * every `goto` must point to an existing step;
//! * a command is either an `argv` array (never passed through a shell) or an
//!   explicit `shell` text;
//! * `check` steps run silently and therefore can never use `root`.

use crate::text::is_valid_package_name;
use serde::{Deserialize, Serialize};
use std::collections::{BTreeMap, HashSet};
use std::fs;
use std::path::{Path, PathBuf};

/// Newest format version. Version 1 files (no `info`, no `percent`) still load.
pub const SCHEMA: u32 = 2;
pub const MIN_SCHEMA: u32 = 1;
pub const MAX_STEPS: usize = 200;
pub const MAX_COMMANDS: usize = 64;
pub const MAX_OPTIONS: usize = 40;
const MAX_FILE_BYTES: u64 = 512 * 1024;
const MAX_TEXT: usize = 40_000;

// ───────────────────────────── small value types ─────────────────────────────

/// A string, or an array of lines joined with `\n` (handy for long messages
/// and shell snippets, because JSON has no multi-line strings).
#[derive(Debug, Clone, PartialEq, Eq, Serialize, Deserialize)]
#[serde(untagged)]
pub enum Text {
    One(String),
    Lines(Vec<String>),
}

impl Default for Text {
    fn default() -> Self {
        Text::One(String::new())
    }
}

impl Text {
    pub fn joined(&self) -> String {
        match self {
            Text::One(s) => s.clone(),
            Text::Lines(l) => l.join("\n"),
        }
    }

    fn len(&self) -> usize {
        match self {
            Text::One(s) => s.len(),
            Text::Lines(l) => l.iter().map(|x| x.len() + 1).sum(),
        }
    }
}

#[derive(Debug, Clone, Copy, Default, PartialEq, Eq, Serialize, Deserialize)]
#[serde(rename_all = "lowercase")]
pub enum Tone {
    #[default]
    Info,
    Warning,
    Error,
    Success,
}

#[derive(Debug, Clone, Copy, Default, PartialEq, Eq, Serialize, Deserialize)]
#[serde(rename_all = "lowercase")]
pub enum ButtonStyle {
    Primary,
    #[default]
    Secondary,
    Danger,
}

/// A condition over variables. All present parts must hold (logical AND).
/// Unset variables compare as the empty string. Operands are interpolated, so
/// `{"var": "driver", "ne": "${gpu_branch}"}` compares two variables.
#[derive(Debug, Clone, Default, PartialEq, Eq, Serialize, Deserialize)]
#[serde(deny_unknown_fields)]
pub struct Cond {
    #[serde(default)]
    pub var: Option<String>,
    #[serde(default)]
    pub eq: Option<String>,
    #[serde(default)]
    pub ne: Option<String>,
    #[serde(default)]
    pub one_of: Option<Vec<String>>,
    #[serde(default)]
    pub all: Option<Vec<Cond>>,
    #[serde(default)]
    pub any: Option<Vec<Cond>>,
    #[serde(default)]
    pub not: Option<Box<Cond>>,
}

pub type Vars = BTreeMap<String, String>;

#[derive(Debug, Clone, PartialEq, Eq, Serialize, Deserialize)]
#[serde(deny_unknown_fields)]
pub struct Button {
    pub label: String,
    #[serde(default)]
    pub style: ButtonStyle,
    /// Go to this step…
    #[serde(default)]
    pub goto: Option<String>,
    /// …or end the script (exactly one of `goto` / `exit`).
    #[serde(default)]
    pub exit: bool,
    /// Variables to set when pressed.
    #[serde(default)]
    pub set: Vars,
}

#[derive(Debug, Clone, PartialEq, Eq, Serialize, Deserialize)]
#[serde(deny_unknown_fields)]
pub struct Note {
    pub text: String,
    #[serde(default)]
    pub when: Option<Cond>,
}

#[derive(Debug, Clone, PartialEq, Eq, Serialize, Deserialize)]
#[serde(deny_unknown_fields)]
pub struct Choice {
    pub value: String,
    pub label: String,
    #[serde(default)]
    pub hint: Text,
    /// Extra lines under the hint, each optionally conditional.
    #[serde(default)]
    pub notes: Vec<Note>,
    /// Only shown when this holds.
    #[serde(default)]
    pub visible_if: Option<Cond>,
    /// Variables set when this option is picked (besides `store_as`).
    #[serde(default)]
    pub set: Vars,
    /// Overrides the step's `next` for this option.
    #[serde(default)]
    pub goto: Option<String>,
}

fn one() -> u32 {
    1
}

#[derive(Debug, Clone, PartialEq, Eq, Serialize, Deserialize)]
#[serde(deny_unknown_fields)]
pub struct CommandSpec {
    /// Shown in the progress line and in the trust summary.
    #[serde(default)]
    pub label: String,
    /// Shell text run with `sh -c` (variables arrive as `$TUX_VAR_<NAME>`;
    /// `${var}` is **not** interpolated into shell text, on purpose).
    #[serde(default)]
    pub shell: Option<Text>,
    /// Program and arguments, executed directly (no shell). `${var}` is
    /// interpolated into each element.
    #[serde(default)]
    pub argv: Option<Vec<String>>,
    /// Run with administrator rights through polkit (`pkexec`).
    #[serde(default)]
    pub root: bool,
    #[serde(default)]
    pub env: BTreeMap<String, String>,
    #[serde(default)]
    pub when: Option<Cond>,
    /// A failing command does not fail the step.
    #[serde(default)]
    pub ignore_failure: bool,
    /// Kill the command after this many seconds (checks default to 20).
    #[serde(default)]
    pub timeout_secs: Option<u64>,
    /// Share of the progress bar (relative to the other commands).
    #[serde(default = "one")]
    pub weight: u32,
    /// How long the command usually takes; only shapes the progress bar.
    #[serde(default)]
    pub expected_secs: Option<u64>,
    /// Overall progress of the whole add-on (0–100) once this command has
    /// finished. Absolute, so it also works across several `run` steps.
    #[serde(default)]
    pub percent: Option<u8>,
}

impl CommandSpec {
    /// A short human description for logs and the trust summary.
    pub fn describe(&self) -> String {
        if !self.label.is_empty() {
            return self.label.clone();
        }
        let raw = match (&self.shell, &self.argv) {
            (Some(t), _) => t.joined(),
            (None, Some(a)) => a.join(" "),
            _ => String::new(),
        };
        let first = raw.lines().next().unwrap_or("").trim();
        let mut out: String = first.chars().take(90).collect();
        if first.chars().count() > 90 || raw.lines().count() > 1 {
            out.push('…');
        }
        out
    }
}

// ───────────────────────────── steps ─────────────────────────────

#[derive(Debug, Clone, PartialEq, Eq, Serialize, Deserialize)]
#[serde(deny_unknown_fields)]
pub struct DialogStep {
    pub title: String,
    #[serde(default)]
    pub message: Text,
    #[serde(default)]
    pub tone: Tone,
    pub buttons: Vec<Button>,
}

#[derive(Debug, Clone, PartialEq, Eq, Serialize, Deserialize)]
#[serde(deny_unknown_fields)]
pub struct ChoiceStep {
    pub title: String,
    #[serde(default)]
    pub message: Text,
    #[serde(default)]
    pub tone: Tone,
    /// Variable that receives the chosen `value`.
    pub store_as: String,
    pub options: Vec<Choice>,
    /// Option value to preselect (interpolated, e.g. `"${gpu_branch}"`).
    #[serde(default)]
    pub default: Option<String>,
    /// Step to go to after a choice (unless the option has its own `goto`).
    pub next: String,
    #[serde(default)]
    pub continue_label: Option<String>,
    /// Extra buttons beside "Continue".
    #[serde(default)]
    pub buttons: Vec<Button>,
}

#[derive(Debug, Clone, PartialEq, Eq, Serialize, Deserialize)]
#[serde(deny_unknown_fields)]
pub struct CheckStep {
    /// Silent command; exit code 0 = success. Never runs as root.
    pub command: CommandSpec,
    /// Store the command's trimmed standard output in this variable
    /// (also when it fails).
    #[serde(default)]
    pub capture: Option<String>,
    pub on_success: String,
    pub on_failure: String,
}

#[derive(Debug, Clone, PartialEq, Eq, Serialize, Deserialize)]
#[serde(deny_unknown_fields)]
pub struct RunStep {
    pub title: String,
    #[serde(default)]
    pub message: Text,
    pub commands: Vec<CommandSpec>,
    pub on_success: String,
    /// Where to go when a command fails. Without it a generic error screen
    /// is shown.
    #[serde(default)]
    pub on_failure: Option<String>,
    /// Also write the commands' output to the terminal Tux Store was started
    /// from (handy while developing a script).
    #[serde(default)]
    pub echo: bool,
}

/// Saves what the install did, for the uninstall flow, in the install record.
#[derive(Debug, Clone, PartialEq, Eq, Serialize, Deserialize)]
#[serde(deny_unknown_fields)]
pub struct RecordStep {
    /// Values to remember (also set as variables).
    #[serde(default)]
    pub set: Vars,
    /// pacman packages installed (`${var}` allowed; split at spaces).
    #[serde(default)]
    pub packages: Vec<String>,
    /// Files or folders created: absolute, or starting with `~/`.
    #[serde(default)]
    pub files: Vec<String>,
    pub next: String,
}

/// What a finished flow means for the install record.
#[derive(Debug, Clone, Copy, PartialEq, Eq, Serialize, Deserialize)]
#[serde(rename_all = "lowercase")]
pub enum Mark {
    /// The add-on is now installed (finish with success).
    Installed,
    /// The add-on is gone: delete the record (finish with success).
    Uninstalled,
}

/// Writes a line to the terminal Tux Store was started from.
#[derive(Debug, Clone, PartialEq, Eq, Serialize, Deserialize)]
#[serde(deny_unknown_fields)]
pub struct PrintStep {
    pub text: Text,
    pub next: String,
}

#[derive(Debug, Clone, PartialEq, Eq, Serialize, Deserialize)]
#[serde(deny_unknown_fields)]
pub struct Case {
    pub when: Cond,
    pub goto: String,
}

#[derive(Debug, Clone, PartialEq, Eq, Serialize, Deserialize)]
#[serde(deny_unknown_fields)]
pub struct BranchStep {
    pub cases: Vec<Case>,
    pub default: String,
}

#[derive(Debug, Clone, PartialEq, Eq, Serialize, Deserialize)]
#[serde(deny_unknown_fields)]
pub struct SetStep {
    pub vars: Vars,
    pub next: String,
}

#[derive(Debug, Clone, PartialEq, Eq, Serialize, Deserialize)]
#[serde(deny_unknown_fields)]
pub struct FinishStep {
    pub title: String,
    #[serde(default)]
    pub message: Text,
    #[serde(default = "yes")]
    pub success: bool,
    #[serde(default)]
    pub button: Option<String>,
    #[serde(default)]
    pub mark: Option<Mark>,
}

fn yes() -> bool {
    true
}

#[derive(Debug, Clone, PartialEq, Eq, Serialize, Deserialize)]
#[serde(tag = "type", rename_all = "snake_case")]
pub enum Step {
    Dialog(DialogStep),
    Choice(ChoiceStep),
    Check(CheckStep),
    Run(RunStep),
    Branch(BranchStep),
    Set(SetStep),
    Print(PrintStep),
    Record(RecordStep),
    Finish(FinishStep),
}

// ───────────────────────────── the script ─────────────────────────────

/// Where an add-on package's thumbnail comes from. Exactly one field is set.
#[derive(Debug, Clone, Default, PartialEq, Eq, Serialize, Deserialize)]
#[serde(deny_unknown_fields)]
pub struct IconSource {
    /// A `.png` / `.svg` / `.ico` file **in the same folder as the JSON**
    /// (a bare file name, no path).
    #[serde(default)]
    pub file: Option<String>,
    /// A name asked from the user's icon theme (e.g. `"nvidia"`).
    #[serde(default)]
    pub theme: Option<String>,
    /// An `https://` link to a `.png` / `.svg` picture, downloaded once and cached.
    #[serde(default)]
    pub url: Option<String>,
}

/// One source, or a list tried in order until one works.
#[derive(Debug, Clone, PartialEq, Eq, Serialize, Deserialize)]
#[serde(untagged)]
pub enum IconSpec {
    One(IconSource),
    Many(Vec<IconSource>),
}

impl IconSpec {
    pub fn sources(&self) -> Vec<&IconSource> {
        match self {
            IconSpec::One(s) => vec![s],
            IconSpec::Many(v) => v.iter().collect(),
        }
    }
}

pub const ICON_EXTENSIONS: [&str; 3] = ["svg", "png", "ico"];

/// A bare, harmless file name with an allowed picture extension.
pub fn is_valid_icon_file_name(f: &str) -> bool {
    !f.is_empty()
        && f.len() <= 128
        && !f.starts_with('.')
        && !f.contains(['/', '\\', '\0'])
        && f.rsplit_once('.').is_some_and(|(_, e)| ICON_EXTENSIONS.contains(&e.to_ascii_lowercase().as_str()))
}

pub fn is_valid_icon_url(u: &str) -> bool {
    u.len() <= 500 && u.starts_with("https://") && u.len() > 12 && !u.chars().any(|c| c.is_whitespace() || c.is_control())
}

fn is_valid_theme_icon_name(n: &str) -> bool {
    !n.is_empty() && n.len() <= 100 && n.bytes().all(|b| b.is_ascii_alphanumeric() || matches!(b, b'.' | b'_' | b'+' | b'-'))
}

/// A number (megabytes) that is either written in the JSON or printed by a
/// command. A command runs without root and must print the number.
#[derive(Debug, Clone, PartialEq, Eq, Serialize, Deserialize)]
#[serde(untagged)]
pub enum DynNum {
    Fixed(u64),
    Command(CommandSpec),
}

impl DynNum {
    pub fn fixed(&self) -> Option<u64> {
        match self {
            DynNum::Fixed(n) => Some(*n),
            DynNum::Command(_) => None,
        }
    }
    pub fn command(&self) -> Option<&CommandSpec> {
        match self {
            DynNum::Command(c) => Some(c),
            DynNum::Fixed(_) => None,
        }
    }
}

/// A text (the version) that is either written in the JSON or printed by a command.
#[derive(Debug, Clone, PartialEq, Eq, Serialize, Deserialize)]
#[serde(untagged)]
pub enum DynText {
    Fixed(String),
    Command(CommandSpec),
}

impl Default for DynText {
    fn default() -> Self {
        DynText::Fixed(String::new())
    }
}

impl DynText {
    /// The written text ("" when it comes from a command).
    pub fn fixed(&self) -> String {
        match self {
            DynText::Fixed(s) => s.clone(),
            DynText::Command(_) => String::new(),
        }
    }
    pub fn command(&self) -> Option<&CommandSpec> {
        match self {
            DynText::Command(c) => Some(c),
            DynText::Fixed(_) => None,
        }
    }
}

/// Sizes shown on the add-on package's page (estimates, in megabytes).
#[derive(Debug, Clone, Default, PartialEq, Eq, Serialize, Deserialize)]
#[serde(deny_unknown_fields)]
pub struct StorageInfo {
    /// What will be downloaded from the internet.
    #[serde(default)]
    pub download_mb: Option<DynNum>,
    /// Space needed while installing (unpacked / built files).
    #[serde(default)]
    pub extracted_mb: Option<DynNum>,
    /// Space used once installed.
    #[serde(default)]
    pub installed_mb: Option<DynNum>,
    #[serde(default)]
    pub note: String,
}

#[derive(Debug, Clone, PartialEq, Eq, Serialize, Deserialize)]
#[serde(deny_unknown_fields)]
pub struct Script {
    pub schema: u32,
    /// Unique, e.g. `nvidia-drivers-id-1`.
    pub id: String,
    pub title: String,
    #[serde(default)]
    pub description: String,
    /// The add-on's own version, or a command that prints the version of what
    /// it installs (e.g. the latest game version).
    #[serde(default)]
    pub version: DynText,
    #[serde(default)]
    pub author: String,
    #[serde(default)]
    pub keywords: Vec<String>,
    /// List it on the Home page ("Tools & Scripts" shelf).
    #[serde(default)]
    pub show_on_home: bool,
    /// Download / disk-space estimate for the page (format version 2).
    #[serde(default)]
    pub info: Option<StorageInfo>,
    /// How to get the thumbnail (format version 2).
    #[serde(default)]
    pub icon: Option<IconSpec>,
    /// Initial variables.
    #[serde(default)]
    pub vars: Vars,
    pub start: String,
    /// Entry step of the uninstall flow (needs an install record to be offered).
    #[serde(default)]
    pub uninstall: Option<String>,
    pub steps: BTreeMap<String, Step>,
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum Origin {
    /// Shipped with the store (installed by the package manager).
    System,
    /// Found in the user's config directory: not trusted by default.
    User,
}

#[derive(Debug, Clone)]
pub struct LoadedScript {
    pub script: Script,
    pub origin: Origin,
    pub path: PathBuf,
}

// ───────────────────────────── validation ─────────────────────────────

pub fn is_valid_var_name(n: &str) -> bool {
    let mut c = n.chars();
    matches!(c.next(), Some('a'..='z'))
        && n.len() <= 48
        && n.bytes().all(|b| b.is_ascii_lowercase() || b.is_ascii_digit() || b == b'_')
}

fn is_valid_env_name(n: &str) -> bool {
    !n.is_empty()
        && n.len() <= 64
        && !n.starts_with(|c: char| c.is_ascii_digit())
        && n.bytes().all(|b| b.is_ascii_uppercase() || b.is_ascii_digit() || b == b'_')
}

impl Script {
    pub fn validate(&self) -> Result<(), String> {
        if !(MIN_SCHEMA..=SCHEMA).contains(&self.schema) {
            return Err(format!("unsupported schema {} (supported: {MIN_SCHEMA}..={SCHEMA})", self.schema));
        }
        if !is_valid_package_name(&self.id) || self.id.bytes().any(|b| b.is_ascii_uppercase()) {
            return Err(format!("invalid id {:?} (lowercase letters, digits, - _ . + only)", self.id));
        }
        if self.title.trim().is_empty() {
            return Err("title is empty".into());
        }
        if self.steps.is_empty() || self.steps.len() > MAX_STEPS {
            return Err(format!("a script needs 1..={MAX_STEPS} steps"));
        }
        for k in self.vars.keys() {
            if !is_valid_var_name(k) {
                return Err(format!("invalid variable name {k:?}"));
            }
        }
        if let Some(icon) = &self.icon {
            let sources = icon.sources();
            if sources.is_empty() || sources.len() > 8 {
                return Err("icon needs 1..=8 sources".into());
            }
            for src in sources {
                let set = [src.file.is_some(), src.theme.is_some(), src.url.is_some()].iter().filter(|b| **b).count();
                if set != 1 {
                    return Err("each icon source needs exactly one of file / theme / url".into());
                }
                if src.file.as_deref().is_some_and(|f| !is_valid_icon_file_name(f)) {
                    return Err("icon file must be a bare .svg/.png/.ico file name in the JSON's folder".into());
                }
                if src.theme.as_deref().is_some_and(|t| !is_valid_theme_icon_name(t)) {
                    return Err("invalid icon theme name".into());
                }
                if src.url.as_deref().is_some_and(|u| !is_valid_icon_url(u)) {
                    return Err("icon url must be a plain https:// link".into());
                }
            }
        }
        if let Some(u) = &self.uninstall {
            self.require_step(u, "uninstall")?;
        }
        for c in self.dynamic_commands() {
            self.check_command(c, false).map_err(|e| format!("version/info command: {e}"))?;
        }
        self.require_step(&self.start, "start")?;
        for (name, step) in &self.steps {
            self.validate_step(step).map_err(|e| format!("step {name:?}: {e}"))?;
        }
        Ok(())
    }

    /// Commands that compute the version or the sizes.
    pub fn dynamic_commands(&self) -> Vec<&CommandSpec> {
        let mut v: Vec<&CommandSpec> = Vec::new();
        v.extend(self.version.command());
        if let Some(i) = &self.info {
            for n in [&i.download_mb, &i.extracted_mb, &i.installed_mb].into_iter().flatten() {
                v.extend(n.command());
            }
        }
        v
    }

    pub fn has_dynamic_values(&self) -> bool {
        !self.dynamic_commands().is_empty()
    }

    fn require_step(&self, name: &str, what: &str) -> Result<(), String> {
        if self.steps.contains_key(name) {
            Ok(())
        } else {
            Err(format!("{what} points to unknown step {name:?}"))
        }
    }

    fn check_vars(vars: &Vars) -> Result<(), String> {
        for k in vars.keys() {
            if !is_valid_var_name(k) {
                return Err(format!("invalid variable name {k:?}"));
            }
        }
        Ok(())
    }

    fn check_cond(c: &Cond) -> Result<(), String> {
        if let Some(v) = &c.var {
            if !is_valid_var_name(v) {
                return Err(format!("invalid variable name {v:?} in condition"));
            }
            if c.eq.is_none() && c.ne.is_none() && c.one_of.is_none() {
                return Err(format!("condition on {v:?} needs eq, ne or one_of"));
            }
        } else if c.eq.is_some() || c.ne.is_some() || c.one_of.is_some() {
            return Err("eq/ne/one_of need a \"var\"".into());
        }
        for sub in c.all.iter().flatten().chain(c.any.iter().flatten()) {
            Self::check_cond(sub)?;
        }
        if let Some(n) = &c.not {
            Self::check_cond(n)?;
        }
        Ok(())
    }

    fn check_buttons(&self, buttons: &[Button]) -> Result<(), String> {
        for b in buttons {
            if b.label.trim().is_empty() {
                return Err("button without label".into());
            }
            match (&b.goto, b.exit) {
                (Some(g), false) => self.require_step(g, "button goto")?,
                (None, true) => {}
                _ => return Err(format!("button {:?} needs exactly one of goto / exit", b.label)),
            }
            Self::check_vars(&b.set)?;
        }
        Ok(())
    }

    fn check_command(&self, c: &CommandSpec, allow_root: bool) -> Result<(), String> {
        match (&c.shell, &c.argv) {
            (Some(s), None) => {
                if s.joined().trim().is_empty() || s.len() > MAX_TEXT {
                    return Err("empty or oversized shell text".into());
                }
            }
            (None, Some(a)) => {
                if a.is_empty() || a[0].trim().is_empty() {
                    return Err("argv is empty".into());
                }
            }
            _ => return Err("a command needs exactly one of shell / argv".into()),
        }
        if c.root && !allow_root {
            return Err("silent checks cannot run as root".into());
        }
        if c.weight == 0 {
            return Err("weight must be at least 1".into());
        }
        if c.percent.is_some_and(|p| p > 100) {
            return Err("percent must be between 0 and 100".into());
        }
        for k in c.env.keys() {
            if !is_valid_env_name(k) {
                return Err(format!("invalid environment variable name {k:?}"));
            }
        }
        if let Some(w) = &c.when {
            Self::check_cond(w)?;
        }
        Ok(())
    }

    fn validate_step(&self, step: &Step) -> Result<(), String> {
        match step {
            Step::Dialog(d) => {
                if d.buttons.is_empty() {
                    return Err("a dialog needs at least one button".into());
                }
                self.check_buttons(&d.buttons)
            }
            Step::Choice(c) => {
                if !is_valid_var_name(&c.store_as) {
                    return Err(format!("invalid store_as {:?}", c.store_as));
                }
                if c.options.is_empty() || c.options.len() > MAX_OPTIONS {
                    return Err(format!("a choice needs 1..={MAX_OPTIONS} options"));
                }
                let mut seen = HashSet::new();
                for o in &c.options {
                    if o.value.is_empty() || !seen.insert(o.value.as_str()) {
                        return Err(format!("empty or duplicate option value {:?}", o.value));
                    }
                    Self::check_vars(&o.set)?;
                    if let Some(g) = &o.goto {
                        self.require_step(g, "option goto")?;
                    }
                    if let Some(v) = &o.visible_if {
                        Self::check_cond(v)?;
                    }
                    for n in &o.notes {
                        if let Some(w) = &n.when {
                            Self::check_cond(w)?;
                        }
                    }
                }
                self.require_step(&c.next, "next")?;
                self.check_buttons(&c.buttons)
            }
            Step::Check(c) => {
                self.check_command(&c.command, false)?;
                if let Some(v) = &c.capture {
                    if !is_valid_var_name(v) {
                        return Err(format!("invalid capture variable {v:?}"));
                    }
                }
                self.require_step(&c.on_success, "on_success")?;
                self.require_step(&c.on_failure, "on_failure")
            }
            Step::Run(r) => {
                if r.commands.is_empty() || r.commands.len() > MAX_COMMANDS {
                    return Err(format!("a run step needs 1..={MAX_COMMANDS} commands"));
                }
                for c in &r.commands {
                    self.check_command(c, true)?;
                }
                self.require_step(&r.on_success, "on_success")?;
                if let Some(f) = &r.on_failure {
                    self.require_step(f, "on_failure")?;
                }
                Ok(())
            }
            Step::Branch(b) => {
                for c in &b.cases {
                    Self::check_cond(&c.when)?;
                    self.require_step(&c.goto, "case goto")?;
                }
                self.require_step(&b.default, "default")
            }
            Step::Set(s) => {
                Self::check_vars(&s.vars)?;
                self.require_step(&s.next, "next")
            }
            Step::Print(p) => {
                if p.text.len() > MAX_TEXT {
                    return Err("print text is too long".into());
                }
                self.require_step(&p.next, "next")
            }
            Step::Record(r) => {
                Self::check_vars(&r.set)?;
                if r.packages.len() > 200 || r.files.len() > 200 {
                    return Err("a record step is limited to 200 packages and 200 files".into());
                }
                self.require_step(&r.next, "next")
            }
            Step::Finish(_) => Ok(()),
        }
    }

    /// Descriptions of every command that asks for administrator rights, in
    /// step-name order. Shown before running scripts that are not shipped
    /// with the store.
    pub fn root_command_summaries(&self) -> Vec<String> {
        let mut out = Vec::new();
        for step in self.steps.values() {
            if let Step::Run(r) = step {
                out.extend(r.commands.iter().filter(|c| c.root).map(CommandSpec::describe));
            }
        }
        out
    }

    /// Does a search `needle` (already normalised) match this script?
    pub fn matches(&self, needle: &str, normalize: impl Fn(&str) -> String) -> bool {
        normalize(&self.id).contains(needle)
            || normalize(&self.title).contains(needle)
            || self.keywords.iter().any(|k| normalize(k).contains(needle))
    }
}

// ───────────────────────────── variables ─────────────────────────────

/// Replace `${name}` with the variable's value (unknown → empty). `$$` is a
/// literal `$`. Text without `${` is returned unchanged.
pub fn interpolate(s: &str, vars: &Vars) -> String {
    if !s.contains('$') {
        return s.to_string();
    }
    let mut out = String::with_capacity(s.len());
    let mut rest = s;
    while let Some(i) = rest.find('$') {
        out.push_str(&rest[..i]);
        let tail = &rest[i..];
        if let Some(t) = tail.strip_prefix("$$") {
            out.push('$');
            rest = t;
        } else if let Some(t) = tail.strip_prefix("${") {
            match t.find('}') {
                Some(end) if t[..end].bytes().all(|b| b.is_ascii_alphanumeric() || b == b'_') => {
                    out.push_str(vars.get(&t[..end]).map(String::as_str).unwrap_or(""));
                    rest = &t[end + 1..];
                }
                _ => {
                    out.push_str("${");
                    rest = t;
                }
            }
        } else {
            out.push('$');
            rest = &tail[1..];
        }
    }
    out.push_str(rest);
    out
}

/// Evaluate a condition (see [`Cond`]).
pub fn eval(c: &Cond, vars: &Vars) -> bool {
    let value = c.var.as_ref().map(|v| vars.get(v).map(String::as_str).unwrap_or(""));
    if let Some(v) = value {
        if let Some(eq) = &c.eq {
            if v != interpolate(eq, vars) {
                return false;
            }
        }
        if let Some(ne) = &c.ne {
            if v == interpolate(ne, vars) {
                return false;
            }
        }
        if let Some(list) = &c.one_of {
            if !list.iter().any(|x| interpolate(x, vars) == v) {
                return false;
            }
        }
    }
    if let Some(all) = &c.all {
        if !all.iter().all(|x| eval(x, vars)) {
            return false;
        }
    }
    if let Some(any) = &c.any {
        if !any.iter().any(|x| eval(x, vars)) {
            return false;
        }
    }
    if let Some(n) = &c.not {
        if eval(n, vars) {
            return false;
        }
    }
    true
}

// ───────────────────────────── loading ─────────────────────────────

/// Parse and validate one file.
pub fn load_file(path: &Path) -> Result<Script, String> {
    let meta = fs::metadata(path).map_err(|e| e.to_string())?;
    if meta.len() > MAX_FILE_BYTES {
        return Err(format!("file is larger than {MAX_FILE_BYTES} bytes"));
    }
    let text = fs::read_to_string(path).map_err(|e| e.to_string())?;
    let script: Script = serde_json::from_str(&text).map_err(|e| e.to_string())?;
    script.validate()?;
    Ok(script)
}

/// Every valid script of `dir` (sorted by file name). Invalid files are
/// logged and skipped; a missing directory is not an error.
pub fn load_dir(dir: &Path, origin: Origin) -> Vec<LoadedScript> {
    let mut files: Vec<PathBuf> = fs::read_dir(dir)
        .map(|rd| rd.flatten().map(|e| e.path()).collect())
        .unwrap_or_default();
    files.sort();
    let mut out = Vec::new();
    for path in files.into_iter().filter(|p| p.extension().is_some_and(|e| e == "json")) {
        match load_file(&path) {
            Ok(script) => out.push(LoadedScript { script, origin, path }),
            Err(e) => log::warn!("script {}: {e}", path.display()),
        }
    }
    out
}

/// Shipped scripts first, then the user's. The first script with a given id
/// wins, so a user file can never replace a shipped script.
pub fn load_all() -> Vec<LoadedScript> {
    let mut all = load_dir(&crate::paths::system_scripts_dir(), Origin::System);
    all.extend(load_dir(&crate::paths::user_scripts_dir(), Origin::User));
    let mut seen = HashSet::new();
    all.retain(|s| {
        let fresh = seen.insert(s.script.id.clone());
        if !fresh {
            log::warn!("script {}: duplicate id {:?} ignored", s.path.display(), s.script.id);
        }
        fresh
    });
    all
}

#[cfg(test)]
mod tests {
    use super::*;

    fn vars(pairs: &[(&str, &str)]) -> Vars {
        pairs.iter().map(|(k, v)| (k.to_string(), v.to_string())).collect()
    }

    fn sample() -> Script {
        serde_json::from_str(
            r#"{
              "schema": 1, "id": "demo-1", "title": "Demo", "start": "a",
              "steps": {
                "a": {"type":"dialog","title":"Hi","message":["l1","l2"],
                      "buttons":[{"label":"Go","goto":"b"},{"label":"No","exit":true}]},
                "b": {"type":"finish","title":"Done"}
              }}"#,
        )
        .unwrap()
    }

    #[test]
    fn valid_script_loads() {
        let s = sample();
        s.validate().unwrap();
        match &s.steps["a"] {
            Step::Dialog(d) => assert_eq!(d.message.joined(), "l1\nl2"),
            _ => panic!(),
        }
    }

    #[test]
    fn unknown_keys_are_rejected() {
        let r = serde_json::from_str::<Script>(
            r#"{"schema":1,"id":"x","title":"t","start":"a","oops":1,"steps":{}}"#,
        );
        assert!(r.is_err());
        let r = serde_json::from_str::<Script>(
            r#"{"schema":1,"id":"x","title":"t","start":"a","steps":{"a":{"type":"finish","title":"t","mesage":"x"}}}"#,
        );
        assert!(r.is_err());
    }

    #[test]
    fn dangling_goto_is_rejected() {
        let mut s = sample();
        if let Some(Step::Dialog(d)) = s.steps.get_mut("a") {
            d.buttons[0].goto = Some("nowhere".into());
        }
        assert!(s.validate().unwrap_err().contains("nowhere"));
    }

    #[test]
    fn checks_cannot_be_root() {
        let r: Script = serde_json::from_str(
            r#"{"schema":1,"id":"x","title":"t","start":"a","steps":{
              "a":{"type":"check","command":{"argv":["true"],"root":true},"on_success":"b","on_failure":"b"},
              "b":{"type":"finish","title":"t"}}}"#,
        )
        .unwrap();
        assert!(r.validate().is_err());
    }

    #[test]
    fn command_needs_exactly_one_form() {
        let r: Script = serde_json::from_str(
            r#"{"schema":1,"id":"x","title":"t","start":"a","steps":{
              "a":{"type":"run","title":"t","commands":[{"argv":["true"],"shell":"true"}],"on_success":"b"},
              "b":{"type":"finish","title":"t"}}}"#,
        )
        .unwrap();
        assert!(r.validate().is_err());
    }

    #[test]
    fn interpolation() {
        let v = vars(&[("a", "1"), ("b_2", "two")]);
        assert_eq!(interpolate("x${a}y${b_2}z", &v), "x1ytwoz");
        assert_eq!(interpolate("${missing}!", &v), "!");
        assert_eq!(interpolate("cost $$5 ${a", &v), "cost $5 ${a");
        assert_eq!(interpolate("plain", &v), "plain");
    }

    #[test]
    fn conditions() {
        let v = vars(&[("gpu", "580xx"), ("pick", "open")]);
        let c: Cond = serde_json::from_str(r#"{"var":"pick","ne":"${gpu}"}"#).unwrap();
        assert!(eval(&c, &v));
        let c: Cond = serde_json::from_str(
            r#"{"all":[{"var":"gpu","one_of":["open","580xx"]},{"not":{"var":"pick","eq":"580xx"}}]}"#,
        )
        .unwrap();
        assert!(eval(&c, &v));
        let c: Cond = serde_json::from_str(r#"{"var":"nothing","eq":""}"#).unwrap();
        assert!(eval(&c, &v));
        let c: Cond = serde_json::from_str(r#"{"any":[{"var":"gpu","eq":"x"},{"var":"pick","eq":"y"}]}"#).unwrap();
        assert!(!eval(&c, &v));
    }

    #[test]
    fn schema_one_and_two_load_and_percent_is_checked() {
        let mk = |schema: u32, pct: u32| -> Result<(), String> {
            let s: Script = serde_json::from_str(&format!(
                r#"{{"schema":{schema},"id":"x","title":"t","start":"a","steps":{{
                  "a":{{"type":"run","title":"t","commands":[{{"argv":["true"],"percent":{pct}}}],"on_success":"b"}},
                  "b":{{"type":"finish","title":"t"}}}}}}"#
            ))
            .unwrap();
            s.validate()
        };
        assert!(mk(1, 50).is_ok());
        assert!(mk(2, 100).is_ok());
        assert!(mk(3, 50).is_err());
        let r: Result<Script, _> = serde_json::from_str(
            r#"{"schema":2,"id":"x","title":"t","start":"a","steps":{"a":{"type":"run","title":"t","commands":[{"argv":["true"],"percent":300}],"on_success":"a"}}}"#,
        );
        assert!(r.is_err(), "300 does not fit u8");
    }

    #[test]
    fn icon_sources_are_checked() {
        let mk = |icon: &str| -> Result<(), String> {
            let s: Script = serde_json::from_str(&format!(
                r#"{{"schema":2,"id":"x","title":"t","start":"a","icon":{icon},"steps":{{"a":{{"type":"finish","title":"t"}}}}}}"#
            ))
            .unwrap();
            s.validate()
        };
        assert!(mk(r#"{"file":"logo.svg"}"#).is_ok());
        assert!(mk(r#"[{"file":"logo.png"},{"theme":"nvidia"},{"url":"https://example.com/a.svg"}]"#).is_ok());
        assert!(mk(r#"{"file":"../logo.svg"}"#).is_err());
        assert!(mk(r#"{"file":"sub/logo.svg"}"#).is_err());
        assert!(mk(r#"{"file":"logo.exe"}"#).is_err());
        assert!(mk(r#"{"url":"http://example.com/a.svg"}"#).is_err());
        assert!(mk(r#"{"url":"https://a b"}"#).is_err());
        assert!(mk(r#"{"file":"a.svg","theme":"x"}"#).is_err());
        assert!(mk(r#"{}"#).is_err());
    }

    #[test]
    fn var_names() {
        assert!(is_valid_var_name("gpu_branch"));
        assert!(!is_valid_var_name("Gpu"));
        assert!(!is_valid_var_name("1a"));
        assert!(!is_valid_var_name("a-b"));
    }

    #[test]
    fn root_summary() {
        let r: Script = serde_json::from_str(
            r#"{"schema":1,"id":"x","title":"t","start":"a","steps":{
              "a":{"type":"run","title":"t","commands":[
                 {"label":"Install things","shell":"pacman -S x","root":true},
                 {"argv":["echo","hi"]}],"on_success":"b"},
              "b":{"type":"finish","title":"t"}}}"#,
        )
        .unwrap();
        r.validate().unwrap();
        assert_eq!(r.root_command_summaries(), vec!["Install things".to_string()]);
    }
}

#[cfg(test)]
mod shipped {
    use super::*;

    /// Every script shipped in `data/scripts` must load and validate.
    #[test]
    fn shipped_scripts_are_valid() {
        let dir = Path::new(env!("CARGO_MANIFEST_DIR")).join("../../data/scripts");
        let found = load_dir(&dir, Origin::System);
        let files = fs::read_dir(&dir).unwrap().flatten().filter(|e| e.path().extension().is_some_and(|x| x == "json")).count();
        assert_eq!(found.len(), files, "a shipped script failed to validate (see warnings)");
        for f in fs::read_dir(&dir).unwrap().flatten().filter(|e| e.path().extension().is_some_and(|x| x == "json")) {
            load_file(&f.path()).unwrap_or_else(|e| panic!("{}: {e}", f.path().display()));
        }
    }
}
