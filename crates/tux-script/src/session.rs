//! One running script: a blocking state machine on its own thread.
//!
//! The session publishes a [`ScriptViewData`] for every screen and then waits
//! for the UI's [`Message::ScriptAction`] (matched by `seq`, so a stale click
//! on an old screen is ignored).

use crate::runner::{run_check, run_visible};
use crossbeam_channel::Receiver;
use std::sync::atomic::{AtomicBool, Ordering};
use std::sync::{Arc, Mutex};
use std::thread;
use std::time::{Duration, Instant};
use tux_abi::script::{
    eval, interpolate, ButtonStyle, Button, CheckStep, ChoiceStep, CommandSpec, DialogStep, FinishStep, LoadedScript,
    Origin, RunStep, Step, Tone, Vars,
};
use tux_abi::{Bus, Message, ScriptButtonView, ScriptOptionView, ScriptViewData};

/// Protection against endless `goto` loops in a faulty script.
const MAX_HOPS: usize = 2_000;
const MAX_VAR_LEN: usize = 4_096;

pub struct Input {
    pub seq: u64,
    pub button: usize,
    pub selected: Option<usize>,
}

pub struct Session {
    bus: Bus,
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
    pub fn new(bus: Bus, loaded: LoadedScript, rx: Receiver<Input>) -> Self {
        let mut vars = loaded.script.vars.clone();
        vars.insert("script_id".into(), loaded.script.id.clone());
        Session { bus, loaded, vars, rx, seq: 0, progress: 0.0 }
    }

    /// Runs to completion. `Some(success)`, or `None` when the host shut down.
    pub fn run(mut self) -> Option<bool> {
        if self.loaded.origin == Origin::User && !self.trust_gate()? {
            return Some(false);
        }
        let mut cur = self.loaded.script.start.clone();
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
            buttons: Vec::new(),
            busy: false,
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
        self.bus.publish(&Message::ScriptProgress { fraction: self.progress, label: String::new() });
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
        v.buttons = self.button_views(&d.buttons);
        let seq = self.publish(v);
        loop {
            let input = self.wait(seq)?;
            if let Some(b) = d.buttons.get(input.button) {
                return Some(self.press(&b.clone()));
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
                ScriptOptionView { label: self.txt(&o.label), hint }
            })
            .collect();
        let preselected = c.default.as_ref().map(|d| self.txt(d)).and_then(|d| {
            visible.iter().position(|&i| c.options[i].value == d)
        });

        let mut v = self.base_view(&c.title, &c.message.joined(), c.tone);
        v.options = options;
        v.preselected = preselected;
        v.buttons.push(ScriptButtonView {
            label: self.txt(c.continue_label.as_deref().unwrap_or("Continue")),
            style: ButtonStyle::Primary,
            needs_selection: true,
        });
        v.buttons.extend(self.button_views(&c.buttons));
        let seq = self.publish(v);
        loop {
            let input = self.wait(seq)?;
            if input.button == 0 {
                let Some(opt) = input.selected.and_then(|s| visible.get(s)).map(|&i| c.options[i].clone()) else {
                    continue; // nothing selected: ignore
                };
                self.vars.insert(c.store_as.clone(), opt.value.clone());
                for (k, val) in &opt.set {
                    let val = interpolate(val, &self.vars);
                    self.vars.insert(k.clone(), clip(&val, MAX_VAR_LEN));
                }
                return Some(Next::Goto(opt.goto.clone().unwrap_or_else(|| c.next.clone())));
            }
            if let Some(b) = c.buttons.get(input.button - 1) {
                return Some(self.press(&b.clone()));
            }
        }
    }

    fn finish(&mut self, f: &FinishStep) -> Option<bool> {
        let tone = if f.success { Tone::Success } else { Tone::Error };
        if f.success {
            self.progress = 1.0;
            self.bus.publish(&Message::ScriptProgress { fraction: 1.0, label: String::new() });
        }
        let mut v = self.base_view(&f.title, &f.message.joined(), tone);
        v.buttons = vec![ScriptButtonView {
            label: self.txt(f.button.as_deref().unwrap_or("Close")),
            style: ButtonStyle::Primary,
            needs_selection: false,
        }];
        let seq = self.publish(v);
        self.wait(seq)?;
        Some(f.success)
    }

    /// A one-button error screen that ends the script.
    fn fail_screen(&mut self, title: &str, message: &str) -> Option<bool> {
        let mut v = self.base_view(title, message, Tone::Error);
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

    fn command_runs(&self, c: &CommandSpec) -> bool {
        c.when.as_ref().map_or(true, |w| eval(w, &self.vars))
    }

    fn check(&mut self, c: &CheckStep) -> Next {
        if !self.command_runs(&c.command) {
            return Next::Goto(c.on_success.clone());
        }
        let title = if c.command.label.is_empty() { "Checking…".to_string() } else { c.command.label.clone() };
        self.busy_screen(&title, "");
        let out = run_check(&c.command, &self.vars);
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
            Next::Goto(c.on_failure.clone())
        }
    }

    fn run_step(&mut self, r: &RunStep) -> Next {
        let todo: Vec<&CommandSpec> = r.commands.iter().filter(|c| self.command_runs(c)).collect();
        self.busy_screen(&r.title, &r.message.joined());

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

        // The bar creeps toward the end of the running command.
        let state = Arc::new(Mutex::new(Tick { from: start0, to: start0, started: Instant::now(), expected: 30.0, label: String::new() }));
        let stop = Arc::new(AtomicBool::new(false));
        let ticker = {
            let (state, stop, bus) = (state.clone(), stop.clone(), self.bus);
            thread::spawn(move || {
                while !stop.load(Ordering::Relaxed) {
                    thread::sleep(Duration::from_millis(400));
                    let t = tux_abi::sync::lock(&state);
                    let creep = (t.to - t.from) * 0.95 * (1.0 - (-t.started.elapsed().as_secs_f64() / t.expected).exp());
                    let fraction = (t.from + creep).clamp(0.0, 0.99);
                    bus.publish(&Message::ScriptProgress { fraction, label: t.label.clone() });
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
            }
            self.bus.publish(&Message::ScriptOutput { text: format!("\n==> {label}\n") });
            if r.echo {
                eprintln!("[add-on {}] ==> {label}", self.loaded.script.id);
            }
            let code = run_visible(c, &self.vars, &self.bus, r.echo);
            if code == 0 || c.ignore_failure {
                self.progress = self.progress.max(end);
                {
                    let mut t = tux_abi::sync::lock(&state);
                    t.from = self.progress;
                    t.to = self.progress;
                }
                // a finished command is reported at once, not at the next tick
                self.bus.publish(&Message::ScriptProgress { fraction: self.progress.min(0.99), label: label.clone() });
            }
            if code != 0 && !c.ignore_failure {
                self.bus.publish(&Message::ScriptOutput { text: format!("\n[{label}: exit code {code}]\n") });
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
                        let (button, selected) = answer(&v);
                        let _ = tx.send(Input { seq: v.seq, button, selected });
                    }
                    thread::sleep(Duration::from_millis(10));
                }
            })
        };
        let result = Session::new(Bus::new(api), loaded, rx).run();
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
}
