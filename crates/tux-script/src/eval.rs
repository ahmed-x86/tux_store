//! Computes the version and the sizes of an add-on package.
//!
//! Each value is either written in the JSON or printed by a command. Commands
//! run silently, never as root, with a time limit. A script that is not
//! shipped with the store only gets evaluated when the user asked for it.

use crate::runner::run_check;
use tux_abi::script::{load_all, CommandSpec, Origin, Vars};
use tux_abi::{Bus, Message, ScriptValues};

/// First number on the last non-empty line, rounded up (megabytes).
pub fn parse_mb(out: &str) -> Option<u64> {
    let line = out.lines().rev().find(|l| !l.trim().is_empty())?;
    let n: f64 = line.split_whitespace().next()?.parse().ok()?;
    (n.is_finite() && (0.0..1.0e9).contains(&n)).then(|| n.ceil() as u64)
}

/// Last non-empty line, short.
pub fn parse_text(out: &str) -> Option<String> {
    let line = out.lines().rev().map(str::trim).find(|l| !l.is_empty())?;
    Some(line.chars().take(80).collect())
}

fn output_of(spec: &CommandSpec, vars: &Vars) -> Option<String> {
    let o = run_check(spec, vars);
    (o.code == 0 && !o.timed_out).then_some(o.stdout)
}

pub fn run(bus: Bus, id: &str, confirmed: bool) {
    let Some(loaded) = load_all().into_iter().find(|l| l.script.id == id) else { return };
    if loaded.origin == Origin::User && !confirmed {
        log::warn!("add-on {id}: refusing to run value commands without the user's confirmation");
        return;
    }
    let s = &loaded.script;
    let vars = s.vars.clone();
    let mut values = ScriptValues::default();
    if let Some(c) = s.version.command() {
        values.version = output_of(c, &vars).and_then(|o| parse_text(&o));
    }
    if let Some(i) = &s.info {
        let num = |d: &Option<tux_abi::script::DynNum>| d.as_ref().and_then(|d| d.command()).and_then(|c| output_of(c, &vars)).and_then(|o| parse_mb(&o));
        values.download_mb = num(&i.download_mb);
        values.extracted_mb = num(&i.extracted_mb);
        values.installed_mb = num(&i.installed_mb);
    }
    bus.publish(&Message::ScriptValuesReady { id: id.to_string(), values });
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn numbers_and_text_are_parsed_from_output() {
        assert_eq!(parse_mb("350\n"), Some(350));
        assert_eq!(parse_mb("warming up\n12.2 MB\n"), Some(13));
        assert_eq!(parse_mb("abc"), None);
        assert_eq!(parse_mb("-5"), None);
        assert_eq!(parse_mb(""), None);
        assert_eq!(parse_text("x\n 1.21.4 \n\n"), Some("1.21.4".into()));
        assert_eq!(parse_text("   "), None);
    }
}
