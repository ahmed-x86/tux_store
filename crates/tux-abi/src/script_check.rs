//! `tux-store --check-script FILE`: validate an add-on script and explain
//! what is wrong (or suspicious) before it is shared.
//!
//! It uses exactly the loader the store uses ([`script::Script::validate`]),
//! then adds *lints*: things that load fine but are probably mistakes
//! (unreachable steps, an install that never records anything, …).

use crate::script::{Mark, Script, Step};
use std::collections::BTreeSet;
use std::path::Path;

/// Result of a check. `ok` is false when the store would refuse the file.
pub struct Report {
    pub ok: bool,
    /// Printable lines: `✔` facts, `✖` errors, `⚠` warnings.
    pub lines: Vec<String>,
}

/// Step names a step can continue to.
fn targets(step: &Step) -> Vec<&str> {
    match step {
        Step::Dialog(d) => d.buttons.iter().filter_map(|b| b.goto.as_deref()).collect(),
        Step::Choice(c) => {
            let mut v = vec![c.next.as_str()];
            v.extend(c.options.iter().filter_map(|o| o.goto.as_deref()));
            v.extend(c.buttons.iter().filter_map(|b| b.goto.as_deref()));
            v
        }
        Step::Check(c) => vec![c.on_success.as_str(), c.on_failure.as_str()],
        Step::Run(r) => {
            let mut v = vec![r.on_success.as_str()];
            v.extend(r.on_failure.as_deref());
            v
        }
        Step::Branch(b) => {
            let mut v: Vec<&str> = b.cases.iter().map(|c| c.goto.as_str()).collect();
            v.push(b.default.as_str());
            v
        }
        Step::Set(s) => vec![s.next.as_str()],
        Step::Print(p) => vec![p.next.as_str()],
        Step::Record(r) => vec![r.next.as_str()],
        Step::Finish(_) => Vec::new(),
    }
}

/// Every step reachable from `from` (including itself).
fn reachable<'a>(s: &'a Script, from: &'a str) -> BTreeSet<&'a str> {
    let mut seen: BTreeSet<&str> = BTreeSet::new();
    let mut todo = vec![from];
    while let Some(name) = todo.pop() {
        if !seen.insert(name) {
            continue;
        }
        if let Some(step) = s.steps.get(name) {
            todo.extend(targets(step));
        }
    }
    seen
}

fn has_finish(s: &Script, set: &BTreeSet<&str>, want: Mark) -> bool {
    set.iter().any(|n| matches!(s.steps.get(*n), Some(Step::Finish(f)) if f.mark == Some(want)))
}

fn has_record(s: &Script, set: &BTreeSet<&str>) -> bool {
    set.iter().any(|n| matches!(s.steps.get(*n), Some(Step::Record(_))))
}

/// Explain a JSON / validation error in plain words.
fn hint(err: &str) -> Option<&'static str> {
    if err.contains("unknown field") {
        Some("a key is misspelled or does not exist: unknown keys are errors on purpose, so a typo can never silently change behaviour")
    } else if err.contains("missing field") {
        Some("a required key is missing in that step (see DOCS/SCRIPTS_SYSTEM.md, section 5)")
    } else if err.contains("unknown variant") {
        Some("\"type\" must be one of: dialog, choice, check, run, branch, set, print, record, finish")
    } else if err.contains("EOF") || err.contains("expected") {
        Some("the file is not valid JSON (a missing comma, quote or bracket); a JSON linter will point at the exact spot")
    } else {
        None
    }
}

/// Check the script in `text`. `dir` is where its icon files must sit.
pub fn check_text(text: &str, dir: &Path) -> Report {
    let mut lines: Vec<String> = Vec::new();
    let fail = |mut lines: Vec<String>, msg: String| {
        lines.push(format!("✖ {msg}"));
        if let Some(h) = hint(&msg) {
            lines.push(format!("  hint: {h}"));
        }
        Report { ok: false, lines }
    };

    if text.len() > 512 * 1024 {
        return fail(lines, "file is larger than 512 KiB".into());
    }
    let script: Script = match serde_json::from_str(text) {
        Ok(s) => s,
        Err(e) => return fail(lines, format!("cannot read the JSON: {e}")),
    };
    if let Err(e) = script.validate() {
        return fail(lines, e);
    }

    lines.push(format!("✔ valid: id \"{}\", title \"{}\", {} steps", script.id, script.title, script.steps.len()));

    // ── lints ──
    let from_start = reachable(&script, &script.start);
    let from_uninstall = script.uninstall.as_deref().map(|u| reachable(&script, u));

    let mut all: BTreeSet<&str> = from_start.clone();
    if let Some(u) = &from_uninstall {
        all.extend(u.iter().copied());
    }
    let dead: Vec<&str> = script.steps.keys().map(String::as_str).filter(|k| !all.contains(k)).collect();
    if !dead.is_empty() {
        lines.push(format!("⚠ steps nothing leads to: {}", dead.join(", ")));
    }
    if !has_finish(&script, &from_start, Mark::Installed) {
        lines.push("⚠ the install flow never reaches a finish step with \"mark\": \"installed\" — the store will never show it as installed".into());
    }
    match &from_uninstall {
        None => lines.push("⚠ no \"uninstall\": users will not get an Uninstall button".into()),
        Some(u) => {
            if !has_finish(&script, u, Mark::Uninstalled) {
                lines.push("⚠ the uninstall flow never reaches a finish step with \"mark\": \"uninstalled\" — the install record would never be deleted".into());
            }
            if !has_record(&script, &from_start) {
                lines.push("⚠ the install flow has no \"record\" step: the uninstall flow will have no files or packages to remove".into());
            }
        }
    }
    if script.description.trim().is_empty() {
        lines.push("⚠ no description".into());
    }
    if script.keywords.is_empty() {
        lines.push("⚠ no keywords: the script is harder to find by search".into());
    }
    if let Some(icon) = &script.icon {
        for src in icon.sources() {
            if let Some(f) = &src.file {
                if !dir.join(f).is_file() {
                    lines.push(format!("⚠ icon file \"{f}\" is not next to the JSON file"));
                }
            }
        }
    }

    let root = script.root_command_summaries();
    if root.is_empty() {
        lines.push("✔ no command asks for administrator rights".into());
    } else {
        lines.push(format!("ℹ {} command(s) ask for administrator rights (users see this list before running):", root.len()));
        for r in root {
            lines.push(format!("    • {r}"));
        }
    }
    let runs_without_failure = script
        .steps
        .iter()
        .filter(|(_, s)| matches!(s, Step::Run(r) if r.on_failure.is_none()))
        .count();
    if runs_without_failure > 0 {
        lines.push(format!("ℹ {runs_without_failure} run step(s) have no on_failure: a generic error screen is shown if they fail"));
    }

    Report { ok: true, lines }
}

/// Read and check a file (what the command line calls).
pub fn check_file(path: &Path) -> Report {
    match std::fs::read_to_string(path) {
        Ok(text) => check_text(&text, path.parent().unwrap_or_else(|| Path::new("."))),
        Err(e) => Report { ok: false, lines: vec![format!("✖ cannot read {}: {e}", path.display())] },
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn shipped_scripts_pass() {
        let dir = Path::new(env!("CARGO_MANIFEST_DIR")).join("../../data/scripts");
        let mut n = 0;
        for e in std::fs::read_dir(&dir).unwrap().flatten() {
            let p = e.path();
            if p.extension().is_some_and(|x| x == "json") {
                let r = check_file(&p);
                assert!(r.ok, "{}: {}", p.display(), r.lines.join("\n"));
                n += 1;
            }
        }
        assert!(n >= 1);
    }

    #[test]
    fn typo_is_explained() {
        let bad = r#"{"schema":2,"id":"x-id-1","title":"X","start":"a","steps":{"a":{"type":"finish","title":"t","mrak":"installed"}}}"#;
        let r = check_text(bad, Path::new("."));
        assert!(!r.ok);
    }

    #[test]
    fn unreachable_step_is_reported() {
        let s = r#"{"schema":2,"id":"x-id-1","title":"X","description":"d","keywords":["k"],"start":"a",
          "steps":{"a":{"type":"finish","title":"t","mark":"installed"},"lonely":{"type":"finish","title":"t"}}}"#;
        let r = check_text(s, Path::new("."));
        assert!(r.ok);
        assert!(r.lines.iter().any(|l| l.contains("nothing leads to: lonely")));
    }
}
