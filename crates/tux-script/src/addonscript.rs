//! Script files that live in an add-on's own folder.
//!
//! `nvidia-drivers-id-1.json` may have a folder `nvidia-drivers-id-1/` beside
//! it holding `install.sh`, `check.py`… A command says `"script": "install.sh"`
//! and `"args": [...]`; this module turns that into a plain `argv` command
//! (interpreter from the file's `#!` line, the file, the arguments), which the
//! rest of the engine runs like any other. The file need not be executable.

use std::path::{Path, PathBuf};
use tux_abi::script::{interpolate, CommandSpec, Vars};

/// `#!/bin/bash` → `["/bin/bash"]`; `#!/usr/bin/env python3` → `["/usr/bin/env", "python3"]`.
pub fn parse_shebang(first_line: &str) -> Result<Vec<String>, String> {
    let rest = first_line.trim_end().strip_prefix("#!").ok_or("the file does not start with a #! line (for example #!/bin/bash)")?;
    let mut it = rest.trim().splitn(2, char::is_whitespace);
    let interp = it.next().filter(|s| !s.is_empty()).ok_or("the #! line names no interpreter")?;
    let mut v = vec![interp.to_string()];
    if let Some(arg) = it.next().map(str::trim).filter(|s| !s.is_empty()) {
        v.push(arg.to_string());
    }
    Ok(v)
}

/// `$` → `$$`, so text that is interpolated again later stays as it is.
fn escape(s: &str) -> String {
    s.replace('$', "$$")
}

/// `${var}` → value (one argument); an element that is exactly `@{var}` → one
/// argument per space-separated word of the value.
pub fn expand_args(args: &[String], vars: &Vars) -> Vec<String> {
    let mut out = Vec::new();
    for a in args {
        let split = a.strip_prefix("@{").and_then(|r| r.strip_suffix('}')).filter(|n| !n.is_empty() && n.bytes().all(|b| b.is_ascii_alphanumeric() || b == b'_'));
        match split {
            Some(name) => out.extend(vars.get(name).map(String::as_str).unwrap_or("").split_whitespace().map(escape)),
            None => out.push(escape(&interpolate(a, vars))),
        }
    }
    out
}

/// The folder of an add-on: its JSON path without `.json`.
pub fn addon_dir(json_path: &Path) -> PathBuf {
    json_path.with_extension("")
}

/// Turn a `script` command into an `argv` command; other commands are returned unchanged.
pub fn resolve(spec: &CommandSpec, json_path: &Path, vars: &Vars) -> Result<CommandSpec, String> {
    let Some(name) = spec.script.as_deref() else { return Ok(spec.clone()) };
    let dir = addon_dir(json_path);
    let dir_real = dir.canonicalize().map_err(|_| format!("the add-on folder {} does not exist", dir.display()))?;
    let file = dir_real
        .join(name)
        .canonicalize()
        .map_err(|_| format!("script “{name}” not found in {}", dir_real.display()))?;
    // a symlink must not lead out of the folder
    if !file.starts_with(&dir_real) || !file.is_file() {
        return Err(format!("script “{name}” is not a regular file inside {}", dir_real.display()));
    }
    let mut head = [0u8; 256];
    let n = {
        use std::io::Read;
        std::fs::File::open(&file).and_then(|mut f| f.read(&mut head)).map_err(|e| format!("cannot read “{name}”: {e}"))?
    };
    let first = String::from_utf8_lossy(&head[..n]);
    let first = first.lines().next().unwrap_or("");
    let mut argv: Vec<String> = parse_shebang(first).map_err(|e| format!("script “{name}”: {e}"))?.iter().map(|s| escape(s)).collect();
    argv.push(escape(&file.to_string_lossy()));
    argv.extend(expand_args(&spec.args, vars));

    let mut out = spec.clone();
    out.script = None;
    out.args = Vec::new();
    out.argv = Some(argv);
    out.env.entry("TUX_ADDON_DIR".into()).or_insert_with(|| escape(&dir_real.to_string_lossy()));
    Ok(out)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn shebangs() {
        assert_eq!(parse_shebang("#!/bin/bash\n").unwrap(), ["/bin/bash"]);
        assert_eq!(parse_shebang("#!/usr/bin/env python3").unwrap(), ["/usr/bin/env", "python3"]);
        assert_eq!(parse_shebang("#! /bin/sh -e").unwrap(), ["/bin/sh", "-e"]);
        assert!(parse_shebang("echo hi").is_err());
        assert!(parse_shebang("#!").is_err());
    }

    #[test]
    fn args_expand_once_and_split_on_request() {
        let mut v = Vars::new();
        v.insert("driver".into(), "open".into());
        v.insert("extras".into(), "a  b c".into());
        v.insert("evil".into(), "${driver} $(x)".into());
        let a: Vec<String> = ["--gpu", "${driver}", "@{extras}", "x=${evil}", "@{none}", "keep@{extras}"].iter().map(|s| s.to_string()).collect();
        // `$` is doubled: the runner interpolates argv once more
        assert_eq!(expand_args(&a, &v), ["--gpu", "open", "a", "b", "c", "x=$${driver} $$(x)", "keep@{extras}"]);
    }
}
