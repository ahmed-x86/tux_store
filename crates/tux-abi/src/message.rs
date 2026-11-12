//! The one vocabulary every module speaks.
//!
//! Naming convention: `XxxRequested` flows *towards* a backend module,
//! `XxxReady` / `Operation*` flows back to whoever is listening (normally the
//! UI, but any module may listen — e.g. the installer overhears
//! [`Message::DetailsReady`] to learn package sizes for its progress bar).

use crate::engine::Engine;
use crate::script::{ButtonStyle, Tone};
use serde::{Deserialize, Serialize};

// ───────────────────────────── data types ─────────────────────────────

#[derive(Debug, Clone, Default, PartialEq, Eq, Serialize, Deserialize)]
pub struct Package {
    pub name: String,
    /// Human title. Empty for pacman packages (the UI derives one from the
    /// name); set for scripts, whose `name` is the script id.
    #[serde(default)]
    pub title: String,
    pub repo: String,
    pub version: String,
    pub description: String,
    pub installed: bool,
}

#[derive(Debug, Clone, Default, PartialEq, Eq, Serialize, Deserialize)]
pub struct Dependency {
    pub name: String,
    pub size_bytes: u64,
    pub installed: bool,
}

/// Real transaction plan from pacman's own resolver.
#[derive(Debug, Clone, Default, PartialEq, Eq, Serialize, Deserialize)]
pub struct PackageDetails {
    /// Installed size of the package itself.
    pub app_size: u64,
    /// Dependencies of the plan that are already on disk.
    pub installed_deps: u64,
    /// Dependencies that still have to be installed.
    pub new_deps: u64,
    pub total_download: u64,
    pub total_installed: u64,
    pub net_upgrade: u64,
    /// Installed first, then new ones.
    pub dependencies: Vec<Dependency>,
    /// `false` when pacman could not produce a plan (AUR / foreign package…).
    pub plan_ok: bool,
}

impl PackageDetails {
    pub fn total_footprint(&self) -> u64 {
        self.app_size + self.installed_deps + self.new_deps
    }
}

#[derive(Debug, Clone, Default, PartialEq, Eq, Serialize, Deserialize)]
pub struct Addon {
    pub label: String,
    pub package: String,
}

/// Addons / language packs attached to a package, and the reverse link.
#[derive(Debug, Clone, Default, PartialEq, Eq, Serialize, Deserialize)]
pub struct SpecialCase {
    /// `"Language Packs"` or `"Addons"` (empty when only `addon_for` is set).
    pub kind: String,
    pub items: Vec<Addon>,
    /// The parent package when the viewed package is itself an addon.
    pub addon_for: Option<String>,
}

#[derive(Debug, Clone, Default, PartialEq, Eq, Serialize, Deserialize)]
pub struct Section {
    pub id: String,
    pub title: String,
    pub packages: Vec<Package>,
}

#[derive(Debug, Clone, Default, PartialEq, Eq, Serialize, Deserialize)]
pub struct Cover {
    pub name: String,
    pub images: Vec<String>,
}

#[derive(Debug, Clone, Default, PartialEq, Eq, Serialize, Deserialize)]
pub struct UpdateEntry {
    pub name: String,
    pub old_version: String,
    pub new_version: String,
}

/// The five uninstall flavours offered by the UI.
#[derive(Debug, Clone, Copy, PartialEq, Eq, Serialize, Deserialize)]
pub enum RemoveMode {
    Basic,
    Reset,
    Clean,
    Force,
    Complete,
}

impl RemoveMode {
    pub fn flag(self) -> &'static str {
        match self {
            RemoveMode::Basic => "-R",
            RemoveMode::Reset => "-Rn",
            RemoveMode::Clean => "-Rs",
            RemoveMode::Force => "-Rdd",
            RemoveMode::Complete => "-Rns",
        }
    }

    pub fn from_flag(flag: &str) -> Option<Self> {
        Some(match flag {
            "-R" => RemoveMode::Basic,
            "-Rn" => RemoveMode::Reset,
            "-Rs" => RemoveMode::Clean,
            "-Rdd" => RemoveMode::Force,
            "-Rns" => RemoveMode::Complete,
            _ => return None,
        })
    }
}

/// A privileged pacman transaction.
#[derive(Debug, Clone, PartialEq, Eq, Serialize, Deserialize)]
pub enum Operation {
    Install { name: String },
    Remove { name: String, mode: RemoveMode },
    SystemUpgrade,
}

/// What the script's own page shows (besides title / description / version).
#[derive(Debug, Clone, Default, PartialEq, Eq, Serialize, Deserialize)]
pub struct ScriptInfo {
    pub author: String,
    /// Found in the user's own config directory (not shipped with the store).
    pub user_script: bool,
    /// Number of commands that ask for administrator rights.
    pub root_commands: usize,
    pub path: String,
    /// Written values; `None` when absent or computed by a command.
    pub download_mb: Option<u64>,
    pub extracted_mb: Option<u64>,
    pub installed_mb: Option<u64>,
    pub note: String,
    /// Written version ("" when absent or computed by a command).
    pub version: String,
    pub version_dynamic: bool,
    pub download_dynamic: bool,
    pub extracted_dynamic: bool,
    pub installed_dynamic: bool,
    /// The values come from commands of a script that is not shipped with
    /// the store: they only run after the user asks.
    pub needs_confirm: bool,
    /// Free bytes on `/` right now (0 = unknown).
    pub free_bytes: u64,
    // ── install record ──
    pub installed: bool,
    pub installed_version: String,
    pub installed_at: u64,
    pub can_uninstall: bool,
}

/// Values computed by the commands of a script.
#[derive(Debug, Clone, Default, PartialEq, Eq, Serialize, Deserialize)]
pub struct ScriptValues {
    pub version: Option<String>,
    pub download_mb: Option<u64>,
    pub extracted_mb: Option<u64>,
    pub installed_mb: Option<u64>,
}

/// One selectable row of a `choice` screen, already resolved (variables
/// interpolated, conditional notes applied).
#[derive(Debug, Clone, Default, PartialEq, Eq, Serialize, Deserialize)]
pub struct ScriptOptionView {
    pub label: String,
    pub hint: String,
    /// Key to ask the thumbnail module for this option's picture
    /// (`IconRequested { name: icon }`); empty = the option has no picture.
    #[serde(default)]
    pub icon: String,
    /// Ticked from the start (only used by `multiple` choices).
    #[serde(default)]
    pub checked: bool,
}

#[derive(Debug, Clone, PartialEq, Eq, Serialize, Deserialize)]
pub struct ScriptButtonView {
    pub label: String,
    pub style: ButtonStyle,
    /// Disabled until a choice option is selected.
    pub needs_selection: bool,
}

/// Everything the UI needs to draw the current screen of a running script.
/// The UI is deliberately dumb: it renders this and reports button clicks.
#[derive(Debug, Clone, PartialEq, Serialize, Deserialize)]
pub struct ScriptViewData {
    pub script_id: String,
    pub script_title: String,
    /// Increases with every screen; actions for an older screen are ignored.
    pub seq: u64,
    pub title: String,
    pub message: String,
    pub tone: Tone,
    pub options: Vec<ScriptOptionView>,
    pub preselected: Option<usize>,
    /// The options are check boxes (any number can be ticked) instead of
    /// radio buttons (exactly one).
    #[serde(default)]
    pub multi: bool,
    /// For `multi`: how many options must be ticked before "Continue" works.
    #[serde(default)]
    pub min_select: u32,
    pub buttons: Vec<ScriptButtonView>,
    /// A command is running: no buttons, progress bar instead.
    pub busy: bool,
}

// ───────────────────────────── the bus message ─────────────────────────────

#[derive(Debug, Clone, Serialize, Deserialize)]
#[serde(tag = "type")]
pub enum Message {
    // ── lifecycle ──
    /// UI window exists; backends may warm up.
    UiReady,
    /// The user picked another package-manager engine. Everything that talks
    /// to pacman must switch to it and drop its caches.
    EngineChanged { engine: Engine },

    // ── requests (UI → backends) ──
    HomeRequested,
    SearchRequested { query: String },
    DetailsRequested { name: String },
    ExactRequested { name: String },
    AddonsRequested { package: String },
    InstalledRequested,
    UpdatesRequested,
    CoversRequested,
    IconRequested { name: String, size: u32 },
    ClearIconCache,
    /// Ask for the screenshots of a package (`data/screenshots/<name>/`).
    ScreenshotsRequested { name: String },
    /// Idle-time hint: these packages will probably be opened soon, so their
    /// screenshots may be downloaded quietly now (nothing is answered).
    ScreenshotsPrefetch { names: Vec<String> },
    InstallRequested { name: String },
    RemoveRequested { name: String, mode: RemoveMode },
    SystemUpgradeRequested,
    /// Ask for the details of a script (its page).
    ScriptInfoRequested { id: String },
    /// Run the commands that compute the version and sizes of a script.
    /// `confirmed`: the user asked (required for scripts from the user's own folder).
    ScriptEvalRequested { id: String, confirmed: bool },
    /// Start the uninstall flow of an installed add-on package.
    ScriptUninstallRequested { id: String },
    /// Start the interactive script with this id.
    ScriptStartRequested { id: String },
    /// A button was pressed on screen `seq` (`selected` = the chosen option of
    /// a radio list, `checked` = the ticked options of a check-box list).
    ScriptAction {
        seq: u64,
        button: usize,
        selected: Option<usize>,
        #[serde(default)]
        checked: Vec<usize>,
    },

    // ── answers (backends → UI) ──
    HomeReady { sections: Vec<Section> },
    SearchResults { query: String, packages: Vec<Package> },
    DetailsReady { name: String, details: PackageDetails, special: Option<SpecialCase> },
    ExactReady { package: Package },
    AddonsReady { package: String, packages: Vec<Package> },
    InstalledReady { packages: Vec<Package> },
    UpdatesReady { updates: Vec<UpdateEntry>, error: Option<String> },
    CoversReady { covers: Vec<Cover> },
    IconReady { name: String, path: String },
    IconFailed { name: String },
    IconCacheCleared { removed: u32 },
    /// Image files (absolute paths, in display order). May be sent several
    /// times for one package while Flathub downloads are still running; each
    /// message holds the complete list so far.
    ScreenshotsReady { name: String, images: Vec<String> },

    // ── transaction progress (installer → everyone) ──
    OperationStarted { op: Operation },
    OperationOutput { text: String },
    OperationProgress { fraction: f64 },
    OperationFinished { op: Operation, success: bool, exit_code: i32 },

    ScriptInfoReady { id: String, info: Option<ScriptInfo> },
    ScriptValuesReady { id: String, values: ScriptValues },

    // ── interactive scripts (script engine → UI) ──
    ScriptView { view: ScriptViewData },
    ScriptOutput { text: String },
    ScriptProgress { fraction: f64, label: String },
    ScriptEnded { id: String, success: bool },
}

impl Message {
    pub fn encode(&self) -> Result<Vec<u8>, serde_json::Error> {
        serde_json::to_vec(self)
    }

    pub fn decode(bytes: &[u8]) -> Result<Self, serde_json::Error> {
        serde_json::from_slice(bytes)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn roundtrip() {
        let m = Message::RemoveRequested { name: "vlc".into(), mode: RemoveMode::Complete };
        let bytes = m.encode().unwrap();
        match Message::decode(&bytes).unwrap() {
            Message::RemoveRequested { name, mode } => {
                assert_eq!(name, "vlc");
                assert_eq!(mode, RemoveMode::Complete);
            }
            other => panic!("unexpected {other:?}"),
        }
    }

    #[test]
    fn unit_variant() {
        let bytes = Message::UiReady.encode().unwrap();
        assert!(matches!(Message::decode(&bytes).unwrap(), Message::UiReady));
    }

    #[test]
    fn flags() {
        for m in [RemoveMode::Basic, RemoveMode::Reset, RemoveMode::Clean, RemoveMode::Force, RemoveMode::Complete] {
            assert_eq!(RemoveMode::from_flag(m.flag()), Some(m));
        }
        assert_eq!(RemoveMode::from_flag("-Syu"), None);
    }
}
