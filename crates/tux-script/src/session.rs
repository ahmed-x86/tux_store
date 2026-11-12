//! One running script: a blocking state machine on its own thread.
//!
//! The session publishes a [`ScriptViewData`] for every screen and then waits
//! for the UI's [`Message::ScriptAction`] (matched by `seq`, so a stale click
//! on an old screen is ignored).

use crate::clock;
use crate::logfile::{self, LogFile};
use crate::output::Output;
use crate::runner::{run_check, run_visible};
use crossbeam_channel::Receiver;
use std::sync::atomic::{AtomicBool, AtomicU32, Ordering};
use std::sync::{Arc, Mutex};
use std::thread;
use std::time::{Duration, Instant};
use tux_abi::receipt::{self, Receipt};
use tux_abi::script::{
    eval, interpolate, option_icon_key, Button, ButtonStyle, CheckStep, ChoiceStep, CommandSpec, DialogStep, FinishStep,
    LoadedScript, Mark, Origin, ProgressMode, RecordStep, RunStep, Step, Tone, Vars,
};
use tux_abi::text::is_valid_package_name;
use tux_abi::{Bus, Message, ScriptButtonView, ScriptOptionView, ScriptViewData};

/// Protection against endless `goto` loops in a faulty script.
const MAX_HOPS: usize = 2_000;
const MAX_VAR_LEN: usize = 4_096;

pub struct Input {
    pub seq: u64,
    pub button: usize,
    /// The chosen option of a radio list.
    pub selected: Option<usize>,
    /// The ticked options of a check-box list.
    pub checked: Vec<usize>,
}

#[derive(Clone, Copy, PartialEq, Eq, Debug)]
pub enum Mode {
    Install,
    Uninstall,
}

pub struct Session {
    bus: Bus,
    /// Console + log file: everything the commands print goes through here.
    out: Arc<Output>,
    mode: Mode,
    loaded: LoadedScript,
    vars: Vars,
    rx: Receiver<Input>,
    seq: u64,
    /// Overall progress of the add-on, 0.0–1.0; never goes backwards.
    progress: f64,
}

fn clip(s: &str, max: usize) -> String {
    if s.len() <= max {
        return s.to_string();
    }
    let mut cut = max;
    while !s.is_char_boundary(cut) {
        cut -= 1;
    }
    s[..cut].to_string()
}

impl Session {
    pub fn new(bus: Bus, loaded: LoadedScript, rx: Receiver<Input>, mode: Mode) -> Self {
        let mut vars = loaded.script.vars.clone();
        if mode == Mode::Uninstall {
            // The uninstall flow sees what the install chose and recorded.
            if let Some(r) = receipt::load(&loaded.script.id) {
                vars.extend(r.vars.clone());
                vars.extend(r.values.clone());
                vars.insert("installed_version".into(), r.installed_version.clone());
                vars.insert("recorded_packages".into(), r.packages.join(" "));
                vars.insert("recorded_files".into(), r.files.join("\n"));
            }
        }
        vars.insert("script_id".into(), loaded.script.id.clone());

        // The log of this run: `tux-store-<time>-<date>-<add-on name>.log`.
        let stamp = clock::now();
        let s = &loaded.script;
        let header = format!(
            "Tux Store {} — add-on log\nAdd-on  : {} ({})\nAction  : {}\nOrigin  : {}\nStarted : {}\n{}\n",
            env!("CARGO_PKG_VERSION"),
            s.title,
            s.id,
            if mode == Mode::Install { "install" } else { "uninstall" },
            if loaded.origin == Origin::User { "user script" } else { "shipped with the store" },
            stamp.pretty(),
            "-".repeat(60),
        );
        let log = LogFile::new(tux_abi::paths::logs_dir(), &stamp, &logfile::safe_name(&s.title, &s.id), header);
        let out = Arc::new(Output::new(bus, log));
        Session { bus, out, mode, loaded, vars, rx, seq: 0, progress: 0.0 }
    }

    /// Runs to completion. `Some(success)`, or `None` when the host shut down.
    /// Whatever happens, a log file is left behind if anything was run or failed.
    pub fn run(mut self) -> Option<bool> {
        let result = self.run_flow();
        let footer = format!(
            "{}\nFinished: {}",
            match result {
                Some(true) => "Result  : success",
                Some(false) => "Result  : not completed (failed or cancelled)",
                None => "Result  : interrupted (Tux Store was closed)",
            },
            clock::now().pretty()
        );
        if let Some(path) = self.out.finish(&footer) {
            log::info!("add-on log saved: {}", path.display());
            self.out.console(&format!("\n[log saved: {}]\n", path.display()));
        }
        result
    }

    fn run_flow(&mut self) -> Option<bool> {
        if self.loaded.origin == Origin::User && !self.trust_gate()? {
            return Some(false);
        }
        let mut cur = match self.mode {
            Mode::Install => self.loaded.script.start.clone(),
            Mode::Uninstall => match self.loaded.script.uninstall.clone() {
                Some(u) => u,
                None => return self.fail_screen("Cannot uninstall", "This add-on package has no uninstall flow."),
            },
        };
        for _ in 0..MAX_HOPS {
            let Some(step) = self.loaded.script.steps.get(&cur).cloned() else {
                return self.fail_screen("Script error", &format!("Unknown step “{cur}”."));
            };
            log::debug!("script {}: step {cur}", self.loaded.script.id);
            let next = match step {
                Step::Dialog(d) => self.dialog(&d)?,
                Step::Choice(c) => self.choice(&c)?,
                Step::Check(c) => self.check(&c),
                Step::Run(r) => self.run_step(&r),
                Step::Branch(b) => {
                    let hit = b.cases.iter().find(|c| eval(&c.when, &self.vars));
                    Next::Goto(hit.map(|c| c.goto.clone()).unwrap_or(b.default))
                }
                Step::Set(s) => {
                    for (k, v) in &s.vars {
                        let v = interpolate(v, &self.vars);
                        self.vars.insert(k.clone(), clip(&v, MAX_VAR_LEN));
                    }
                    Next::Goto(s.next)
                }
                Step::Print(p) => {
                    // Goes to the terminal Tux Store was started from, at any log level.
                    eprintln!("[add-on {}] {}", self.loaded.script.id, self.txt(&p.text.joined()));
                    Next::Goto(p.next)
                }
                Step::Record(r) => match self.record(&r) {
                    Ok(()) => Next::Goto(r.next),
                    Err(e) => return self.fail_screen("Could not save the install record", &e),
                },
                Step::Finish(f) => return self.finish(&f),
            };
            match next {
                Next::Goto(s) => cur = s,
                Next::Exit => return Some(false),
                Next::Shutdown => return None,
            }
        }
        self.fail_screen("Script error", "The script looped too many times and was stopped.")
    }

    // ───────────────────────── screens ─────────────────────────

    fn txt(&self, s: &str) -> String {
        interpolate(s, &self.vars)
    }

    fn publish(&mut self, mut view: ScriptViewData) -> u64 {
        self.seq += 1;
        view.seq = self.seq;
        view.script_id = self.loaded.script.id.clone();
        view.script_title = self.loaded.script.title.clone();
        self.bus.publish(&Message::ScriptView { view });
        self.seq
    }

    fn base_view(&self, title: &str, message: &str, tone: Tone) -> ScriptViewData {
        ScriptViewData {
            script_id: String::new(),
            script_title: String::new(),
            seq: 0,
            title: self.txt(title),
            message: self.txt(message),
            tone,
            options: Vec::new(),
            preselected: None,
            multi: false,
            min_select: 0,
            buttons: Vec::new(),
            busy: false,
        }
    }

    /// `message` plus, when a log file exists, where it is.
    fn with_log_note(&self, message: &str) -> String {
        match self.out.log_path() {
            Some(p) => {
                let sep = if message.is_empty() { "" } else { "\n\n" };
                format!("{message}{sep}Log: {}", p.display())
            }
            None => message.to_string(),
        }
    }

    /// Wait for an action on screen `seq`; `None` = the host is shutting down.
    fn wait(&self, seq: u64) -> Option<Input> {
        loop {
            let input = self.rx.recv().ok()?;
            if input.seq == seq {
                return Some(input);
            }
        }
    }

    fn busy_screen(&mut self, title: &str, message: &str) {
        let mut v = self.base_view(title, message, Tone::Info);
        v.busy = true;
        self.publish(v);
        self.bus.publish(&Message::ScriptProgress { fraction: self.progress, label: self.txt(title) });
    }

    fn button_views(&self, buttons: &[Button]) -> Vec<ScriptButtonView> {
        buttons
            .iter()
            .map(|b| ScriptButtonView { label: self.txt(&b.label), style: b.style, needs_selection: false })
            .collect()
    }

    fn press(&mut self, b: &Button) -> Next {
        for (k, v) in &b.set {
            let v = interpolate(v, &self.vars);
            self.vars.insert(k.clone(), clip(&v, MAX_VAR_LEN));
        }
        match (&b.goto, b.exit) {
            (Some(g), _) => Next::Goto(g.clone()),
            _ => Next::Exit,
        }
    }

    fn dialog(&mut self, d: &DialogStep) -> Option<Next> {
        let mut v = self.base_view(&d.title, &d.message.joined(), d.tone);
        if d.tone == Tone::Error {
            // A failure screen: keep a log of it and say where it is.
            self.out.note(&format!("[error] {}: {}", v.title, v.message));
            self.out.ensure_log();
            v.message = self.with_log_note(&v.message);
        }
        v.buttons = self.button_views(&d.buttons);
        let title = v.title.clone();
        let seq = self.publish(v);
        loop {
            let input = self.wait(seq)?;
            if let Some(b) = d.buttons.get(input.button) {
                let b = b.clone();
                self.out.note(&format!("[button] {title} → {}", self.txt(&b.label)));
                return Some(self.press(&b));
            }
        }
    }

    fn choice(&mut self, c: &ChoiceStep) -> Option<Next> {
        // visible options, remembering their index in the definition
        let visible: Vec<usize> = c
            .options
            .iter()
            .enumerate()
            .filter(|(_, o)| o.visible_if.as_ref().map_or(true, |w| eval(w, &self.vars)))
            .map(|(i, _)| i)
            .collect();
        // a `multiple` choice may start with some boxes ticked: `default` lists their values
        let ticked: Vec<String> = match (&c.default, c.multiple) {
            (Some(d), true) => self.txt(d).split_whitespace().map(str::to_string).collect(),
            _ => Vec::new(),
        };
        let script_id = self.loaded.script.id.clone();
        let options: Vec<ScriptOptionView> = visible
            .iter()
            .map(|&i| {
                let o = &c.options[i];
                let mut hint = self.txt(&o.hint.joined());
                for n in o.notes.iter().filter(|n| n.when.as_ref().map_or(true, |w| eval(w, &self.vars))) {
                    if !hint.is_empty() {
                        hint.push('\n');
                    }
                    hint.push_str(&self.txt(&n.text));
                }
                ScriptOptionView {
                    label: self.txt(&o.label),
                    hint,
                    icon: o.icon.as_ref().map(|ic| option_icon_key(&script_id, ic)).unwrap_or_default(),
                    checked: ticked.iter().any(|t| *t == o.value),
                }
            })
            .collect();
        let preselected = match (&c.default, c.multiple) {
            (Some(d), false) => {
                let d = self.txt(d);
                visible.iter().position(|&i| c.options[i].value == d)
            }
            _ => None,
        };

        let mut v = self.base_view(&c.title, &c.message.joined(), c.tone);
        v.options = options;
        v.preselected = preselected;
        v.multi = c.multiple;
        v.min_select = c.min_select;
        v.buttons.push(ScriptButtonView {
            label: self.txt(c.continue_label.as_deref().unwrap_or("Continue")),
            style: ButtonStyle::Primary,
            needs_selection: true,
        });
        v.buttons.extend(self.button_views(&c.buttons));
        let title = v.title.clone();
        let seq = self.publish(v);
        loop {
            let input = self.wait(seq)?;
            if input.button == 0 {
                if c.multiple {
                    // the ticked boxes, in the order of the options, each once
                    let mut picked: Vec<usize> = input.checked.iter().copied().filter(|&n| n < visible.len()).collect();
                    picked.sort_unstable();
                    picked.dedup();
                    if (picked.len() as u32) < c.min_select {
                        continue; // not enough ticked: ignore
                    }
                    let opts: Vec<_> = picked.iter().map(|&n| c.options[visible[n]].clone()).collect();
                    let joined = opts.iter().map(|o| o.value.as_str()).collect::<Vec<_>>().join(" ");
                    self.vars.insert(c.store_as.clone(), clip(&joined, MAX_VAR_LEN));
                    for o in &opts {
                        for (k, val) in &o.set {
                            let val = interpolate(val, &self.vars);
                            self.vars.insert(k.clone(), clip(&val, MAX_VAR_LEN));
                        }
                    }
                    self.out.note(&format!("[choice] {title}: {} = {joined:?}", c.store_as));
                    return Some(Next::Goto(c.next.clone()));
                }
                let Some(opt) = input.selected.and_then(|s| visible.get(s)).map(|&i| c.options[i].clone()) else {
                    continue; // nothing selected: ignore
                };
                self.vars.insert(c.store_as.clone(), opt.value.clone());
                for (k, val) in &opt.set {
                    let val = interpolate(val, &self.vars);
                    self.vars.insert(k.clone(), clip(&val, MAX_VAR_LEN));
                }
                self.out.note(&format!("[choice] {title}: {} = {:?}", c.store_as, opt.value));
                return Some(Next::Goto(opt.goto.clone().unwrap_or_else(|| c.next.clone())));
            }
            if let Some(b) = c.buttons.get(input.button - 1) {
                let b = b.clone();
                self.out.note(&format!("[button] {title} → {}", self.txt(&b.label)));
                return Some(self.press(&b));
            }
        }
    }

    fn finish(&mut self, f: &FinishStep) -> Option<bool> {
        if f.success {
            if let Some(mark) = f.mark {
                if let Err(e) = self.apply_mark(mark) {
                    return self.fail_screen("Could not update the install record", &e);
                }
            }
        }
        let tone = if f.success { Tone::Success } else { Tone::Error };
        if f.success {
            self.progress = 1.0;
            self.bus.publish(&Message::ScriptProgress { fraction: 1.0, label: String::new() });
        }
        let mut v = self.base_view(&f.title, &f.message.joined(), tone);
        self.out.note(&format!("[finish] {} ({})", v.title, if f.success { "success" } else { "failure" }));
        if !f.success {
            self.out.ensure_log();
        }
        v.message = self.with_log_note(&v.message);
        v.buttons = vec![ScriptButtonView {
            label: self.txt(f.button.as_deref().unwrap_or("Close")),
            style: ButtonStyle::Primary,
            needs_selection: false,
        }];
        let seq = self.publish(v);
        self.wait(seq)?;
        Some(f.success)
    }

    // ───────────────────────── install record ─────────────────────────

    /// The record of this add-on, or a fresh one.
    fn receipt(&self) -> Receipt {
        let s = &self.loaded.script;
        receipt::load(&s.id).unwrap_or_else(|| Receipt { id: s.id.clone(), title: s.title.clone(), ..Default::default() })
    }

    /// Variables worth keeping: the user's choices, not engine bookkeeping.
    fn snapshot_vars(&self) -> Vars {
        self.vars
            .iter()
            .filter(|(k, _)| {
                !k.starts_with("last_") && !k.starts_with("recorded_") && k.as_str() != "script_id" && k.as_str() != "installed_version"
            })
            .map(|(k, v)| (k.clone(), v.clone()))
            .collect()
    }

    fn record(&mut self, r: &RecordStep) -> Result<(), String> {
        let mut rc = self.receipt();
        rc.title = self.loaded.script.title.clone();
        for (k, v) in &r.set {
            let v = clip(&interpolate(v, &self.vars), MAX_VAR_LEN);
            self.vars.insert(k.clone(), v.clone());
            rc.values.insert(k.clone(), v);
        }
        for p in &r.packages {
            for word in interpolate(p, &self.vars).split_whitespace() {
                if !is_valid_package_name(word) {
                    return Err(format!("“{word}” is not a valid package name."));
                }
                if !rc.packages.iter().any(|x| x == word) {
                    rc.packages.push(word.to_string());
                }
            }
        }
        let home = tux_abi::paths::home();
        for f in &r.files {
            let raw = interpolate(f, &self.vars);
            let clean = receipt::clean_recorded_path(&raw, &home).ok_or_else(|| format!("“{raw}” is not a usable absolute path."))?;
            if !rc.files.contains(&clean) {
                rc.files.push(clean);
            }
        }
        rc.vars = self.snapshot_vars();
        rc.script_version = self.loaded.script.version.fixed();
        receipt::save(&rc).map_err(|e| e.to_string())
    }

    fn apply_mark(&mut self, mark: Mark) -> Result<(), String> {
        match mark {
            Mark::Installed => {
                let mut rc = self.receipt();
                rc.title = self.loaded.script.title.clone();
                rc.complete = true;
                rc.installed_at = receipt::now();
                rc.script_version = self.loaded.script.version.fixed();
                rc.installed_version = self
                    .vars
                    .get("installed_version")
                    .cloned()
                    .filter(|v| !v.is_empty())
                    .unwrap_or_else(|| self.loaded.script.version.fixed());
                rc.vars = self.snapshot_vars();
                receipt::save(&rc).map_err(|e| e.to_string())
            }
            Mark::Uninstalled => receipt::remove(&self.loaded.script.id).map_err(|e| e.to_string()),
        }
    }

    /// A one-button error screen that ends the script.
    fn fail_screen(&mut self, title: &str, message: &str) -> Option<bool> {
        let mut v = self.base_view(title, message, Tone::Error);
        self.out.note(&format!("[error] {}: {}", v.title, v.message));
        self.out.ensure_log();
        v.message = self.with_log_note(&v.message);
        v.buttons = vec![ScriptButtonView { label: "Close".into(), style: ButtonStyle::Primary, needs_selection: false }];
        let seq = self.publish(v);
        self.wait(seq)?;
        Some(false)
    }

    /// Scripts from the user's own config directory are not vetted by the
    /// distribution: say what is about to happen and ask first.
    fn trust_gate(&mut self) -> Option<bool> {
        let s = &self.loaded.script;
        let root_cmds = s.root_command_summaries();
        let mut msg = format!(
            "This script is not part of Tux Store. It was loaded from:\n{}\n",
            self.loaded.path.display()
        );
        if !s.author.is_empty() {
            msg.push_str(&format!("Author: {}\n", s.author));
        }
        if root_cmds.is_empty() {
            msg.push_str("\nIt does not ask for administrator rights.");
        } else {
            msg.push_str(&format!(
                "\nIt will run {} command(s) with ADMINISTRATOR rights:\n",
                root_cmds.len()
            ));
            for c in root_cmds.iter().take(15) {
                msg.push_str(&format!("  • {c}\n"));
            }
            if root_cmds.len() > 15 {
                msg.push_str(&format!("  …and {} more\n", root_cmds.len() - 15));
            }
        }
        msg.push_str("\nOnly continue if you wrote it yourself or trust its author.");
        let title = format!("Run “{}”?", s.title);
        let mut v = self.base_view(&title, &msg, Tone::Warning);
        v.buttons = vec![
            ScriptButtonView { label: "Cancel".into(), style: ButtonStyle::Secondary, needs_selection: false },
            ScriptButtonView { label: "I trust this script — run it".into(), style: ButtonStyle::Danger, needs_selection: false },
        ];
        let seq = self.publish(v);
        let input = self.wait(seq)?;
        Some(input.button == 1)
    }

    // ───────────────────────── commands ─────────────────────────

    fn set_last(&mut self, code: i32, output: &str, failed: &str) {
        self.vars.insert("last_exit_code".into(), code.to_string());
        self.vars.insert("last_output".into(), clip(output, 2_000));
        self.vars.insert("last_failed".into(), failed.to_string());
    }

    /// A `script` command becomes a plain `argv` command (see `addonscript`).
    fn resolve(&self, c: &CommandSpec) -> Result<CommandSpec, String> {
        crate::addonscript::resolve(c, &self.loaded.path, &self.vars)
    }

    fn command_runs(&self, c: &CommandSpec) -> bool {
        c.when.as_ref().map_or(true, |w| eval(w, &self.vars))
    }

    fn check(&mut self, c: &CheckStep) -> Next {
        if !self.command_runs(&c.command) {
            return Next::Goto(c.on_success.clone());
        }
        let title = if c.command.label.is_empty() { "Checking…".to_string() } else { c.command.label.clone() };
        self.busy_screen(&title, "");
        let out = match self.resolve(&c.command) {
            Ok(spec) => run_check(&spec, &self.vars),
            Err(e) => crate::runner::Outcome { code: -1, stdout: e, timed_out: false },
        };
        let ok = out.code == 0 && !out.timed_out;
        if let Some(name) = &c.capture {
            self.vars.insert(name.clone(), clip(&out.stdout, MAX_VAR_LEN));
        }
        let label = c.command.describe();
        self.set_last(out.code, &out.stdout, &label);
        if ok || c.command.ignore_failure {
            Next::Goto(c.on_success.clone())
        } else {
            log::info!("script check failed ({}): code {}", label, out.code);
            let why = if out.timed_out { "timed out".to_string() } else { format!("exit code {}", out.code) };
            let first = out.stdout.lines().next().unwrap_or("");
            self.out.note(&format!("[check failed] {label} ({why}) {first}"));
            Next::Goto(c.on_failure.clone())
        }
    }

    fn run_step(&mut self, r: &RunStep) -> Next {
        let todo: Vec<&CommandSpec> = r.commands.iter().filter(|c| self.command_runs(c)).collect();
        self.busy_screen(&r.title, &r.message.joined());
        // Something is about to run: from here on there is a log to keep.
        self.out.ensure_log();

        // Where each command ends on the overall bar (absolute 0.0–1.0).
        // Commands with `percent` say it themselves; the others share the
        // distance up to the step's highest explicit percent (or 100 %) by weight.
        let start0 = self.progress;
        let step_end = todo
            .iter()
            .filter_map(|c| c.percent)
            .map(|p| f64::from(p) / 100.0)
            .fold(None, |m: Option<f64>, p| Some(m.map_or(p, |m| m.max(p))))
            .unwrap_or(1.0)
            .max(start0);
        let total_w: f64 = todo.iter().map(|c| f64::from(c.weight)).sum::<f64>().max(1.0);
        let mut cum = 0.0;
        let mut last = start0;
        let ends: Vec<f64> = todo
            .iter()
            .map(|c| {
                cum += f64::from(c.weight);
                let e = c.percent.map_or(start0 + (step_end - start0) * (cum / total_w), |p| f64::from(p) / 100.0);
                last = e.max(last).min(1.0);
                last
            })
            .collect();

        // The command's own progress (tenths of a percent + 1, 0 = none yet),
        // filled in by the threads that read its output.
        let real = Arc::new(AtomicU32::new(0));
        // While a command runs the bar moves between `from` and `to`:
        // with the command's real progress when it reports one, otherwise it
        // creeps toward `to` (and, for `"progress": "percent"` commands, waits
        // for the real numbers instead of pretending).
        let state = Arc::new(Mutex::new(Tick {
            from: start0,
            to: start0,
            started: Instant::now(),
            expected: 30.0,
            label: String::new(),
            waits_for_real: false,
        }));
        let stop = Arc::new(AtomicBool::new(false));
        let ticker = {
            let (state, stop, real, bus) = (state.clone(), stop.clone(), real.clone(), self.bus);
            thread::spawn(move || {
                let mut shown = start0; // the bar never goes backwards
                while !stop.load(Ordering::Relaxed) {
                    thread::sleep(Duration::from_millis(400));
                    let t = tux_abi::sync::lock(&state);
                    let reported = real.load(Ordering::Relaxed);
                    let fraction = if reported > 0 {
                        t.from + (t.to - t.from) * (f64::from(reported - 1) / 1000.0)
                    } else if t.waits_for_real {
                        t.from
                    } else {
                        t.from + (t.to - t.from) * 0.95 * (1.0 - (-t.started.elapsed().as_secs_f64() / t.expected).exp())
                    };
                    shown = fraction.clamp(0.0, 0.99).max(shown);
                    bus.publish(&Message::ScriptProgress { fraction: shown, label: t.label.clone() });
                }
            })
        };

        let mut failure: Option<(i32, String)> = None;
        for (c, end) in todo.into_iter().zip(ends) {
            let label = c.describe();
            {
                let mut t = tux_abi::sync::lock(&state);
                t.from = self.progress;
                t.to = end;
                t.started = Instant::now();
                t.expected = c.expected_secs.unwrap_or(30).max(1) as f64;
                t.label = label.clone();
                t.waits_for_real = c.progress == ProgressMode::Percent;
                real.store(0, Ordering::Relaxed); // under the lock: the ticker never mixes two commands
            }
            // the name of the operation is on screen at once, not at the next tick
            self.bus.publish(&Message::ScriptProgress { fraction: self.progress.min(0.99), label: label.clone() });
            self.out.text(&format!("\n==> {label}\n"));
            if r.echo {
                eprintln!("[add-on {}] ==> {label}", self.loaded.script.id);
            }
            let code = match self.resolve(c) {
                Ok(spec) => run_visible(&spec, &self.vars, &self.out, r.echo, &real),
                Err(e) => {
                    self.out.text(&format!("{e}\n"));
                    -1
                }
            };
            if code == 0 || c.ignore_failure {
                self.progress = self.progress.max(end);
                {
                    let mut t = tux_abi::sync::lock(&state);
                    t.from = self.progress;
                    t.to = self.progress;
                    t.waits_for_real = false;
                    real.store(0, Ordering::Relaxed);
                }
                // a finished command is reported at once, not at the next tick
                self.bus.publish(&Message::ScriptProgress { fraction: self.progress.min(0.99), label: label.clone() });
            }
            if code != 0 && !c.ignore_failure {
                self.out.text(&format!("\n[{label}: exit code {code}]\n"));
                failure = Some((code, label));
                break;
            }
        }
        stop.store(true, Ordering::Relaxed);
        let _ = ticker.join();

        match failure {
            None => {
                self.set_last(0, "", "");
                self.bus.publish(&Message::ScriptProgress { fraction: self.progress, label: String::new() });
                Next::Goto(r.on_success.clone())
            }
            Some((code, label)) => {
                self.set_last(code, "", &label);
                match &r.on_failure {
                    Some(f) => Next::Goto(f.clone()),
                    None => match self.fail_screen(
                        "Something went wrong",
                        &format!("“{label}” failed (exit code {code}). Use “Show details” to read the output."),
                    ) {
                        Some(_) => Next::Exit,
                        None => Next::Shutdown,
                    },
                }
            }
        }
    }
}

struct Tick {
    from: f64,
    to: f64,
    started: Instant,
    expected: f64,
    label: String,
    /// The running command reports its own percentage: do not creep ahead of it.
    waits_for_real: bool,
}

enum Next {
    Goto(String),
    Exit,
    Shutdown,
}

#[cfg(test)]
mod tests {
    use super::*;
    use crossbeam_channel::unbounded;
    use std::ffi::c_void;
    use std::path::PathBuf;
    use tux_abi::script::Script;
    use tux_abi::HostApi;

    type Log = Mutex<Vec<Message>>;

    unsafe extern "C" fn publish(ctx: *mut c_void, data: *const u8, len: usize) {
        let log = &*(ctx as *const Log);
        let bytes = std::slice::from_raw_parts(data, len);
        if let Ok(m) = Message::decode(bytes) {
            log.lock().unwrap().push(m);
        }
    }
    unsafe extern "C" fn nolog(_: *mut c_void, _: u32, _: *const u8, _: usize, _: *const u8, _: usize) {}

    /// Plays the UI: answers every screen with `answer(view) -> (button, selected)`.
    fn play(json: &str, origin: Origin, answer: impl Fn(&ScriptViewData) -> (usize, Option<usize>) + Send + 'static) -> (Option<bool>, Vec<Message>) {
        play_mode(json, origin, Mode::Install, answer)
    }

    fn play_mode(json: &str, origin: Origin, mode: Mode, answer: impl Fn(&ScriptViewData) -> (usize, Option<usize>) + Send + 'static) -> (Option<bool>, Vec<Message>) {
        play_full(json, origin, mode, move |v| {
            let (button, selected) = answer(v);
            (button, selected, Vec::new())
        })
    }

    /// Where the logs of the tests go (never the real `~/.local/state`).
    fn isolate_logs() -> PathBuf {
        static DIR: std::sync::OnceLock<PathBuf> = std::sync::OnceLock::new();
        DIR.get_or_init(|| {
            let d = std::env::temp_dir().join(format!("tux-engine-state-{}", std::process::id()));
            let _ = std::fs::remove_dir_all(&d);
            std::env::set_var("XDG_STATE_HOME", &d);
            d.join("tux-store").join("logs")
        })
        .clone()
    }

    /// Like `play_mode`, and the answer may also tick check boxes.
    fn play_full(
        json: &str,
        origin: Origin,
        mode: Mode,
        answer: impl Fn(&ScriptViewData) -> (usize, Option<usize>, Vec<usize>) + Send + 'static,
    ) -> (Option<bool>, Vec<Message>) {
        isolate_logs();
        let log: &'static Log = Box::leak(Box::new(Mutex::new(Vec::new())));
        let api = HostApi { abi_version: 1, log_level: 0, ctx: log as *const Log as *mut c_void, publish, log: nolog };
        let script: Script = serde_json::from_str(json).unwrap();
        script.validate().unwrap();
        let loaded = LoadedScript { script, origin, path: PathBuf::from("/tmp/test.json") };
        let (tx, rx) = unbounded();
        let done = Arc::new(AtomicBool::new(false));
        let ui = {
            let done = done.clone();
            thread::spawn(move || {
                let mut answered = 0u64;
                while !done.load(Ordering::SeqCst) {
                    let next = log.lock().unwrap().iter().rev().find_map(|m| match m {
                        Message::ScriptView { view } if view.seq > answered && !view.busy => Some(view.clone()),
                        _ => None,
                    });
                    if let Some(v) = next {
                        answered = v.seq;
                        let (button, selected, checked) = answer(&v);
                        let _ = tx.send(Input { seq: v.seq, button, selected, checked });
                    }
                    thread::sleep(Duration::from_millis(10));
                }
            })
        };
        let result = Session::new(Bus::new(api), loaded, rx, mode).run();
        done.store(true, Ordering::SeqCst);
        ui.join().unwrap();
        let msgs = log.lock().unwrap().clone();
        (result, msgs)
    }

    const FLOW: &str = r#"{
      "schema":1,"id":"flow-1","title":"Flow","start":"hello",
      "steps":{
        "hello":{"type":"dialog","title":"Hello","buttons":[{"label":"Go","goto":"detect"},{"label":"Later","exit":true}]},
        "detect":{"type":"check","command":{"shell":"echo open"},"capture":"gpu","on_success":"pick","on_failure":"bad"},
        "pick":{"type":"choice","title":"Pick","store_as":"driver","default":"${gpu}","next":"gate",
          "options":[
            {"value":"open","label":"Latest","hint":"new","notes":[{"when":{"var":"gpu","eq":"open"},"text":"Recommended"}],"set":{"label":"Latest driver"}},
            {"value":"old","label":"Old","visible_if":{"var":"gpu","eq":"never"}}]},
        "gate":{"type":"branch","cases":[{"when":{"var":"driver","ne":"${gpu}"},"goto":"bad"}],"default":"work"},
        "work":{"type":"run","title":"Working","message":"Do not turn off","commands":[
            {"label":"say hi","shell":"echo installing $TUX_VAR_DRIVER","weight":2},
            {"label":"ignored","shell":"exit 9","ignore_failure":true}],
          "on_success":"done","on_failure":"bad"},
        "done":{"type":"finish","title":"Done ${label}","message":"ok"},
        "bad":{"type":"finish","title":"Bad","success":false}
      }}"#;

    fn titles(msgs: &[Message]) -> Vec<String> {
        msgs.iter().filter_map(|m| match m { Message::ScriptView { view } if !view.busy => Some(view.title.clone()), _ => None }).collect()
    }

    #[test]
    fn full_flow_with_choice_check_and_run() {
        let (res, msgs) = play(FLOW, Origin::System, |v| match v.title.as_str() {
            "Pick" => {
                assert_eq!(v.options.len(), 1, "visible_if hides the second option");
                assert_eq!(v.preselected, Some(0), "default preselects the detected value");
                assert!(v.options[0].hint.contains("Recommended"));
                assert!(v.buttons[0].needs_selection);
                (0, Some(0))
            }
            _ => (0, None),
        });
        assert_eq!(res, Some(true));
        assert_eq!(titles(&msgs), ["Hello", "Pick", "Done Latest driver"]);
        let out: String = msgs.iter().filter_map(|m| match m { Message::ScriptOutput { text } => Some(text.as_str()), _ => None }).collect();
        assert!(out.contains("installing open"), "output was: {out:?}");
        assert!(msgs.iter().any(|m| matches!(m, Message::ScriptProgress { fraction, .. } if *fraction >= 1.0)));
    }

    #[test]
    fn percent_is_absolute_across_steps_and_never_goes_back() {
        let json = r#"{"schema":2,"id":"p-1","title":"P","start":"one","steps":{
          "one":{"type":"run","title":"1","commands":[{"label":"a","shell":"true","percent":30},{"label":"b","shell":"true","percent":60}],"on_success":"two"},
          "two":{"type":"run","title":"2","commands":[{"label":"c","shell":"true","percent":50},{"label":"d","shell":"true"}],"on_success":"end"},
          "end":{"type":"finish","title":"ok"}}}"#;
        let (res, msgs) = play(json, Origin::System, |_| (0, None));
        assert_eq!(res, Some(true));
        let fr: Vec<f64> = msgs.iter().filter_map(|m| match m { Message::ScriptProgress { fraction, .. } => Some(*fraction), _ => None }).collect();
        // the bar passes 0.30, 0.60 and never decreases (0.50 < 0.60 is clamped)
        assert!(fr.iter().any(|f| (*f - 0.30).abs() < 1e-9), "{fr:?}");
        assert!(fr.iter().any(|f| (*f - 0.60).abs() < 1e-9), "{fr:?}");
        assert!(fr.windows(2).all(|w| w[1] + 1e-9 >= w[0]), "progress went backwards: {fr:?}");
        assert_eq!(*fr.last().unwrap(), 1.0);
    }

    #[test]
    fn install_leaves_a_record_and_uninstall_uses_and_removes_it() {
        let dir = std::env::temp_dir().join(format!("tux-engine-data-{}", std::process::id()));
        let _ = std::fs::remove_dir_all(&dir);
        std::env::set_var("XDG_DATA_HOME", &dir);
        let json = r#"{"schema":2,"id":"rec-test-1","title":"Rec","version":"1.0","start":"go","uninstall":"bye",
          "vars":{"choice":"blue"},
          "steps":{
            "go":{"type":"record","set":{"launcher":"v7"},"packages":["pkg-a pkg-b","pkg-a"],"files":["~/games/rec"],"next":"fin"},
            "fin":{"type":"finish","title":"Installed","mark":"installed"},
            "bye":{"type":"check","command":{"shell":"printf '%s|%s|%s' \"$TUX_VAR_CHOICE\" \"$TUX_VAR_RECORDED_PACKAGES\" \"$TUX_VAR_LAUNCHER\""},"capture":"seen","on_success":"gone","on_failure":"gone"},
            "gone":{"type":"finish","title":"Removed ${seen}","mark":"uninstalled"}
          }}"#;
        let (res, _) = play(json, Origin::System, |_| (0, None));
        assert_eq!(res, Some(true));
        let rc = tux_abi::receipt::load("rec-test-1").expect("a record was written");
        assert!(rc.complete);
        assert_eq!(rc.installed_version, "1.0");
        assert_eq!(rc.packages, ["pkg-a", "pkg-b"], "deduplicated");
        assert!(rc.files[0].ends_with("/games/rec"));
        assert_eq!(rc.values.get("launcher").map(String::as_str), Some("v7"));
        assert_eq!(rc.vars.get("choice").map(String::as_str), Some("blue"));

        // the uninstall flow sees the choices and the recorded packages
        let (res, msgs) = play_mode(json, Origin::System, Mode::Uninstall, |_| (0, None));
        assert_eq!(res, Some(true));
        assert_eq!(titles(&msgs), ["Removed blue|pkg-a pkg-b|v7"]);
        assert!(tux_abi::receipt::load("rec-test-1").is_none(), "record removed after uninstall");
        let _ = std::fs::remove_dir_all(&dir);
    }

    #[test]
    fn a_bad_recorded_path_stops_the_script() {
        let json = r#"{"schema":2,"id":"rec-test-2","title":"R","start":"go","steps":{
          "go":{"type":"record","files":["relative/path"],"next":"fin"},
          "fin":{"type":"finish","title":"ok"}}}"#;
        let (res, msgs) = play(json, Origin::System, |_| (0, None));
        assert_eq!(res, Some(false));
        assert_eq!(titles(&msgs), ["Could not save the install record"]);
    }

    #[test]
    fn exit_button_ends_unsuccessfully() {
        let (res, _) = play(FLOW, Origin::System, |_| (1, None));
        assert_eq!(res, Some(false));
    }

    #[test]
    fn failing_run_without_handler_shows_error() {
        let json = r#"{"schema":1,"id":"f-1","title":"F","start":"r","steps":{
          "r":{"type":"run","title":"R","commands":[{"label":"boom","shell":"exit 4"}],"on_success":"ok"},
          "ok":{"type":"finish","title":"ok"}}}"#;
        let (res, msgs) = play(json, Origin::System, |_| (0, None));
        assert_eq!(res, Some(false));
        assert_eq!(titles(&msgs), ["Something went wrong"]);
    }

    #[test]
    fn user_scripts_need_the_trust_gate() {
        let json = r#"{"schema":1,"id":"u-1","title":"U","start":"a","steps":{
          "a":{"type":"run","title":"R","commands":[{"label":"Danger","shell":"true","root":true}],"on_success":"ok"},
          "ok":{"type":"finish","title":"ok"}}}"#;
        // Cancel at the gate: nothing runs.
        let (res, msgs) = play(json, Origin::User, |_| (0, None));
        assert_eq!(res, Some(false));
        assert_eq!(titles(&msgs), ["Run “U”?"]);
        let gate = msgs.iter().find_map(|m| match m { Message::ScriptView { view } => Some(view.clone()), _ => None }).unwrap();
        assert!(gate.message.contains("Danger"), "root commands must be listed: {}", gate.message);
    }

    #[test]
    fn endless_loop_is_stopped() {
        let json = r#"{"schema":1,"id":"l-1","title":"L","start":"a","steps":{
          "a":{"type":"set","vars":{"x":"1"},"next":"a"}}}"#;
        let (res, msgs) = play(json, Origin::System, |_| (0, None));
        assert_eq!(res, Some(false));
        assert_eq!(titles(&msgs), ["Script error"]);
    }

    // ───────────────────────── check boxes, real progress, logs ─────────────────────────

    const MULTI: &str = r#"{"schema":2,"id":"multi-test-1","title":"Multi","start":"pick","steps":{
      "pick":{"type":"choice","title":"Pick some","multiple":true,"min_select":1,"store_as":"chosen","default":"b c","next":"show",
        "options":[
          {"value":"a","label":"A","set":{"pa":"yes"}},
          {"value":"b","label":"B","icon":{"theme":"firefox"}},
          {"value":"c","label":"C"}]},
      "show":{"type":"check","command":{"shell":"printf '%s|%s' \"$TUX_VAR_CHOSEN\" \"$TUX_VAR_PA\""},"capture":"seen","on_success":"end","on_failure":"end"},
      "end":{"type":"finish","title":"Got ${seen}"}}}"#;

    #[test]
    fn multiple_choice_collects_every_ticked_option_in_order() {
        let (res, msgs) = play_full(MULTI, Origin::System, Mode::Install, |v| match v.title.as_str() {
            "Pick some" => {
                assert!(v.multi);
                assert_eq!(v.min_select, 1);
                assert_eq!(v.preselected, None, "check boxes use `checked`, not `preselected`");
                let checked: Vec<bool> = v.options.iter().map(|o| o.checked).collect();
                assert_eq!(checked, [false, true, true], "`default` lists the values ticked at the start");
                assert!(v.options[1].icon.starts_with("multi-test-1.opt-"), "{:?}", v.options[1].icon);
                assert!(v.options[0].icon.is_empty() && v.options[2].icon.is_empty());
                // ticked out of order, one twice, one that does not exist
                (0, None, vec![2, 0, 0, 9])
            }
            _ => (0, None, Vec::new()),
        });
        assert_eq!(res, Some(true));
        // option order, each once, and the `set` of every ticked option applied
        assert_eq!(titles(&msgs), ["Pick some", "Got a c|yes"]);
    }

    #[test]
    fn multiple_choice_may_end_empty_when_min_select_is_zero() {
        let json = MULTI.replace(r#""min_select":1,"#, "").replace(r#""default":"b c","#, "");
        let (res, msgs) = play_full(&json, Origin::System, Mode::Install, |_| (0, None, Vec::new()));
        assert_eq!(res, Some(true));
        assert_eq!(titles(&msgs), ["Pick some", "Got |"]);
    }

    const REAL: &str = r#"{"schema":2,"id":"real-test-1","title":"Real","start":"go","steps":{
      "go":{"type":"run","title":"Working","commands":[
         {"label":"download","shell":"echo TUX_PROGRESS=50; sleep 1","percent":80},
         {"label":"meter","shell":"printf '30%%\\n'; sleep 1","percent":100,"progress":"percent"}],
       "on_success":"end"},
      "end":{"type":"finish","title":"ok"}}}"#;

    #[test]
    fn the_bar_follows_the_commands_own_progress() {
        let (res, msgs) = play(REAL, Origin::System, |_| (0, None));
        assert_eq!(res, Some(true));
        let fr: Vec<(f64, String)> = msgs
            .iter()
            .filter_map(|m| match m {
                Message::ScriptProgress { fraction, label } => Some((*fraction, label.clone())),
                _ => None,
            })
            .collect();
        let near = |want: f64| fr.iter().any(|(f, _)| (f - want).abs() < 1e-9);
        // 50 % of the first command's 0 → 80 % share, then 30 % of the 80 → 100 % share
        assert!(near(0.4), "{fr:?}");
        assert!(near(0.8 + 0.2 * 0.3), "{fr:?}");
        assert!(fr.windows(2).all(|w| w[1].0 + 1e-9 >= w[0].0), "progress went backwards: {fr:?}");
        assert!(fr.iter().any(|(_, l)| l == "download") && fr.iter().any(|(_, l)| l == "meter"), "operation names are published");
        // the marker line is not shown (nor logged), the percentage line is
        let out: String = msgs.iter().filter_map(|m| match m { Message::ScriptOutput { text } => Some(text.as_str()), _ => None }).collect();
        assert!(!out.contains("TUX_PROGRESS"), "{out:?}");
        assert!(out.contains("30%"), "{out:?}");
    }

    fn find_log(dir: &std::path::Path, name: &str) -> Option<PathBuf> {
        let suffix = format!("-{name}.log");
        std::fs::read_dir(dir).ok()?.flatten().map(|e| e.path()).find(|p| p.file_name().is_some_and(|n| n.to_string_lossy().ends_with(&suffix)))
    }

    #[test]
    fn a_successful_install_leaves_a_clean_log() {
        let dir = isolate_logs();
        let json = r#"{"schema":2,"id":"log-ok-1","title":"Log OK Demo","start":"go","steps":{
          "go":{"type":"run","title":"R","commands":[{"label":"say","shell":"echo hello-from-the-command; printf 'p 10%%\\rp 100%%\\n'"}],"on_success":"end"},
          "end":{"type":"finish","title":"Done"}}}"#;
        let (res, msgs) = play(json, Origin::System, |_| (0, None));
        assert_eq!(res, Some(true));
        let path = find_log(&dir, "Log-OK-Demo").expect("a log file was written");
        // tux-store-<HH-MM-SS>-<YYYY-MM-DD>-<name>.log
        let name = path.file_name().unwrap().to_string_lossy().into_owned();
        let stamp = name.strip_prefix("tux-store-").unwrap().strip_suffix("-Log-OK-Demo.log").unwrap();
        let digits: Vec<bool> = stamp.chars().map(|c| c.is_ascii_digit()).collect();
        assert_eq!(stamp.len(), "09-05-07-2026-11-11".len(), "{name}");
        assert!(digits[0] && digits[1] && stamp.as_bytes()[2] == b'-' && stamp.as_bytes()[8] == b'-', "{name}");
        let text = std::fs::read_to_string(&path).unwrap();
        assert!(text.contains("Add-on  : Log OK Demo (log-ok-1)"), "{text}");
        assert!(text.contains("==> say"), "{text}");
        assert!(text.contains("hello-from-the-command"), "{text}");
        assert!(text.contains("p 100%") && !text.contains("p 10%"), "progress redraws collapse: {text}");
        assert!(text.contains("Result  : success"), "{text}");
        let out: String = msgs.iter().filter_map(|m| match m { Message::ScriptOutput { text } => Some(text.as_str()), _ => None }).collect();
        assert!(out.contains("[log saved:") && out.contains(&name), "the console says where the log is: {out:?}");
        let done = msgs.iter().rev().find_map(|m| match m { Message::ScriptView { view } if view.title == "Done" => Some(view.clone()), _ => None }).unwrap();
        assert!(done.message.contains(&name), "the last screen says where the log is: {:?}", done.message);
    }

    #[test]
    fn a_failed_install_leaves_a_log_too() {
        let dir = isolate_logs();
        let json = r#"{"schema":2,"id":"log-bad-1","title":"Log Bad Demo","start":"go","steps":{
          "go":{"type":"run","title":"R","commands":[{"label":"boom","shell":"echo about-to-fail; exit 3"}],"on_success":"end","on_failure":"bad"},
          "end":{"type":"finish","title":"Done"},
          "bad":{"type":"dialog","title":"It failed","tone":"error","message":"exit ${last_exit_code}","buttons":[{"label":"Close","exit":true}]}}}"#;
        let (res, msgs) = play(json, Origin::System, |_| (0, None));
        assert_eq!(res, Some(false));
        let path = find_log(&dir, "Log-Bad-Demo").expect("a log file was written");
        let text = std::fs::read_to_string(&path).unwrap();
        assert!(text.contains("about-to-fail"), "{text}");
        assert!(text.contains("[boom: exit code 3]"), "{text}");
        assert!(text.contains("[error] It failed: exit 3"), "{text}");
        assert!(text.contains("Result  : not completed"), "{text}");
        let shown = msgs.iter().find_map(|m| match m { Message::ScriptView { view } if view.title == "It failed" => Some(view.clone()), _ => None }).unwrap();
        assert!(shown.message.starts_with("exit 3") && shown.message.contains("Log: "), "{:?}", shown.message);
    }

    #[test]
    fn cancelling_before_anything_ran_leaves_no_log() {
        let dir = isolate_logs();
        let json = r#"{"schema":2,"id":"log-none-1","title":"Log None Demo","start":"hi","steps":{
          "hi":{"type":"dialog","title":"Hi","buttons":[{"label":"Cancel","exit":true}]}}}"#;
        let (res, _) = play(json, Origin::System, |_| (0, None));
        assert_eq!(res, Some(false));
        assert!(find_log(&dir, "Log-None-Demo").is_none());
    }
}
