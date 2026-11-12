//! A tiny, dependency-free reader for the parts of `pacman.conf` libalpm
//! needs when it is driven by an application instead of by pacman itself.
//!
//! Arch's `pacman` binary parses this file before calling libalpm; if we call
//! libalpm directly we have to do the same work: root/db paths, architecture,
//! cache/log/gpg/hook directories, ignored packages, and one sync database per
//! `[repo]` with its `Server`/`Include` mirror list.

use std::path::{Path, PathBuf};

#[derive(Debug, Clone)]
pub struct Repo {
    pub name: String,
    pub servers: Vec<String>,
    pub siglevel: Option<String>,
}

#[derive(Debug, Clone)]
pub struct Config {
    pub root: String,
    pub dbpath: String,
    pub arch: Option<String>,
    pub cachedirs: Vec<String>,
    pub logfile: Option<String>,
    pub gpgdir: Option<String>,
    pub hookdirs: Vec<String>,
    pub ignore: Vec<String>,
    pub sandbox_user: Option<String>,
    pub siglevel: Option<String>,
    pub local_siglevel: Option<String>,
    pub repos: Vec<Repo>,
}

impl Default for Config {
    fn default() -> Self {
        Config {
            root: "/".into(),
            dbpath: "/var/lib/pacman/".into(),
            arch: None,
            cachedirs: vec!["/var/cache/pacman/pkg/".into()],
            logfile: Some("/var/log/pacman.log".into()),
            gpgdir: Some("/etc/pacman.d/gnupg/".into()),
            hookdirs: vec!["/usr/share/libalpm/hooks/".into(), "/etc/pacman.d/hooks/".into()],
            ignore: Vec::new(),
            sandbox_user: None,
            siglevel: None,
            local_siglevel: None,
            repos: Vec::new(),
        }
    }
}

#[derive(Debug, Clone, Copy)]
enum Section {
    Options,
    Repo(usize),
}

/// Read `$TUX_PACMAN_CONF` or `/etc/pacman.conf`.
pub fn load() -> Config {
    let path = std::env::var("TUX_PACMAN_CONF").unwrap_or_else(|_| "/etc/pacman.conf".into());
    let mut cfg = Config::default();
    let mut section = Section::Options;
    let mut seen_cachedir = false;
    parse_file(Path::new(&path), &mut cfg, &mut section, &mut seen_cachedir, 0);
    cfg
}

fn parse_file(path: &Path, cfg: &mut Config, section: &mut Section, seen_cachedir: &mut bool, depth: usize) {
    if depth > 8 {
        log::warn!("pacman.conf: Include nesting too deep at {}", path.display());
        return;
    }
    let text = match std::fs::read_to_string(path) {
        Ok(t) => t,
        Err(e) => {
            log::warn!("pacman.conf: cannot read {}: {e}", path.display());
            return;
        }
    };

    for raw in text.lines() {
        let line = raw.split('#').next().unwrap_or("").trim();
        if line.is_empty() {
            continue;
        }
        if line.starts_with('[') {
            let name = line.trim_start_matches('[').trim_end_matches(']').trim();
            if name.eq_ignore_ascii_case("options") {
                *section = Section::Options;
            } else if !name.is_empty() {
                cfg.repos.push(Repo { name: name.to_string(), servers: Vec::new(), siglevel: None });
                *section = Section::Repo(cfg.repos.len() - 1);
            }
            continue;
        }

        let Some((key, value)) = line.split_once('=') else {
            // Boolean options (`Color`, `CheckSpace`, …): nothing libalpm needs.
            continue;
        };
        let (key, value) = (key.trim(), value.trim());
        if key.is_empty() {
            continue;
        }

        if key.eq_ignore_ascii_case("Include") {
            for inc in expand_include(value) {
                parse_file(&inc, cfg, section, seen_cachedir, depth + 1);
            }
            continue;
        }

        match *section {
            Section::Options => match key.to_ascii_lowercase().as_str() {
                "rootdir" => cfg.root = value.to_string(),
                "dbpath" => cfg.dbpath = value.to_string(),
                "architecture" => {
                    cfg.arch = (!value.eq_ignore_ascii_case("auto") && !value.is_empty())
                        .then(|| value.to_string());
                }
                "cachedir" => {
                    if !*seen_cachedir {
                        cfg.cachedirs.clear();
                        *seen_cachedir = true;
                    }
                    cfg.cachedirs.push(value.to_string());
                }
                "logfile" => cfg.logfile = Some(value.to_string()),
                "gpgdir" => cfg.gpgdir = Some(value.to_string()),
                "hookdir" => cfg.hookdirs.push(value.to_string()),
                "ignorepkg" => cfg.ignore.extend(value.split_whitespace().map(str::to_string)),
                "siglevel" => cfg.siglevel = Some(value.to_string()),
                "localfilesiglevel" => cfg.local_siglevel = Some(value.to_string()),
                "downloaduser" => cfg.sandbox_user = Some(value.to_string()),
                _ => {}
            },
            Section::Repo(i) => {
                let repo = &mut cfg.repos[i];
                match key.to_ascii_lowercase().as_str() {
                    "server" => repo.servers.push(value.to_string()),
                    "siglevel" => repo.siglevel = Some(value.to_string()),
                    _ => {}
                }
            }
        }
    }
}

/// `Include` values are absolute paths, sometimes with a glob.
fn expand_include(value: &str) -> Vec<PathBuf> {
    if !value.contains(['*', '?', '[']) {
        return vec![PathBuf::from(value)];
    }
    let path = Path::new(value);
    let (dir, pattern) = match (path.parent(), path.file_name().and_then(|n| n.to_str())) {
        (Some(dir), Some(pattern)) => (dir, pattern),
        _ => return vec![PathBuf::from(value)],
    };
    let mut out: Vec<PathBuf> = std::fs::read_dir(dir)
        .map(|rd| {
            rd.flatten()
                .map(|e| e.path())
                .filter(|p| {
                    p.file_name()
                        .and_then(|n| n.to_str())
                        .is_some_and(|n| glob_match(pattern, n))
                })
                .collect()
        })
        .unwrap_or_default();
    out.sort();
    out
}

/// Minimal `*`/`?` glob matcher (sufficient for `Include = …/*.conf`).
fn glob_match(pattern: &str, name: &str) -> bool {
    let p: Vec<char> = pattern.chars().collect();
    let n: Vec<char> = name.chars().collect();
    fn go(p: &[char], n: &[char]) -> bool {
        match p.split_first() {
            None => n.is_empty(),
            Some(('*', rest)) => go(rest, n) || (!n.is_empty() && go(p, &n[1..])),
            Some(('?', rest)) => !n.is_empty() && go(rest, &n[1..]),
            Some((c, rest)) => n.first() == Some(c) && go(rest, &n[1..]),
        }
    }
    go(&p, &n)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn glob() {
        assert!(glob_match("*.conf", "foo.conf"));
        assert!(glob_match("a?c", "abc"));
        assert!(!glob_match("*.conf", "foo.conf.bak"));
    }

    #[test]
    fn parses_repos_and_include() {
        let dir = std::env::temp_dir().join(format!("tux-libalpm-conf-{}", std::process::id()));
        let _ = std::fs::create_dir_all(&dir);
        let mirror = dir.join("mirrorlist");
        std::fs::write(
            &mirror,
            "Server = https://example.invalid/$repo/os/$arch\n",
        )
        .unwrap();
        let conf = dir.join("pacman.conf");
        std::fs::write(
            &conf,
            format!(
                "[options]\nArchitecture = x86_64\nIgnorePkg = foo bar\n\n[core]\nInclude = {}\nServer = https://second.invalid\n\n[extra]\nSigLevel = Optional TrustAll\nInclude = {}\n",
                mirror.display(),
                mirror.display()
            ),
        )
        .unwrap();

        let mut cfg = Config::default();
        let mut section = Section::Options;
        let mut seen = false;
        parse_file(&conf, &mut cfg, &mut section, &mut seen, 0);
        assert_eq!(cfg.arch.as_deref(), Some("x86_64"));
        assert_eq!(cfg.ignore, ["foo", "bar"]);
        assert_eq!(cfg.repos.len(), 2);
        assert_eq!(cfg.repos[0].name, "core");
        assert_eq!(cfg.repos[0].servers.len(), 2);
        assert_eq!(cfg.repos[1].siglevel.as_deref(), Some("Optional TrustAll"));
        let _ = std::fs::remove_dir_all(&dir);
    }
}
