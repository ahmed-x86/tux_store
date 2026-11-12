//! Direct read-only access to pacman's *local* database
//! (`/var/lib/pacman/local/<name>-<ver>-<rel>/desc`).
//!
//! Reading the directory is far cheaper than spawning `pacman -Q`: listing the
//! installed set is a single `readdir` and costs well under a millisecond.

use std::collections::HashSet;
use std::fs;
use std::path::PathBuf;

#[derive(Debug, Clone, Default)]
pub struct LocalPackage {
    pub name: String,
    pub version: String,
    pub description: String,
    pub install_size: u64,
    /// Installed explicitly (not pulled in as a dependency).
    pub explicit: bool,
}

pub fn db_path() -> PathBuf {
    std::env::var_os("TUX_PACMAN_DBPATH")
        .map(PathBuf::from)
        .unwrap_or_else(|| PathBuf::from("/var/lib/pacman"))
        .join("local")
}

/// `"foo-bar-1.2-3"` → `("foo-bar", "1.2-3")`.
fn split_dirname(dir: &str) -> Option<(&str, &str)> {
    let mut it = dir.rsplitn(3, '-');
    let _rel = it.next()?;
    let _ver = it.next()?;
    let name = it.next()?;
    let ver_rel = &dir[name.len() + 1..];
    Some((name, ver_rel))
}

pub fn installed_names() -> HashSet<String> {
    let mut set = HashSet::new();
    if let Ok(rd) = fs::read_dir(db_path()) {
        for entry in rd.flatten() {
            let fname = entry.file_name();
            if let Some((name, _)) = fname.to_str().and_then(split_dirname) {
                set.insert(name.to_string());
            }
        }
    }
    set
}

fn parse_desc(text: &str, name: &str, ver_rel: &str) -> LocalPackage {
    let mut p = LocalPackage {
        name: name.to_string(),
        version: ver_rel.to_string(),
        explicit: true,
        ..LocalPackage::default()
    };
    let mut key = "";
    for line in text.lines() {
        if line.len() > 1 && line.starts_with('%') && line.ends_with('%') {
            key = line;
            continue;
        }
        if line.is_empty() {
            key = "";
            continue;
        }
        match key {
            "%VERSION%" => p.version = line.to_string(),
            "%DESC%" if p.description.is_empty() => p.description = line.to_string(),
            "%SIZE%" => p.install_size = line.trim().parse().unwrap_or(0),
            "%REASON%" => p.explicit = line.trim() == "0",
            _ => {}
        }
    }
    p
}

/// Every installed package (a few hundred small file reads, done off-thread).
pub fn read_all() -> Vec<LocalPackage> {
    let mut out = Vec::new();
    if let Ok(rd) = fs::read_dir(db_path()) {
        for entry in rd.flatten() {
            let fname = entry.file_name();
            let Some((name, ver_rel)) = fname.to_str().and_then(split_dirname) else {
                continue;
            };
            if let Ok(text) = fs::read_to_string(entry.path().join("desc")) {
                out.push(parse_desc(&text, name, ver_rel));
            }
        }
    }
    out
}

pub fn read_one(name: &str) -> Option<LocalPackage> {
    let rd = fs::read_dir(db_path()).ok()?;
    for entry in rd.flatten() {
        let fname = entry.file_name();
        let Some((n, ver_rel)) = fname.to_str().and_then(split_dirname) else {
            continue;
        };
        if n == name {
            let text = fs::read_to_string(entry.path().join("desc")).ok()?;
            return Some(parse_desc(&text, n, ver_rel));
        }
    }
    None
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn dirnames() {
        assert_eq!(split_dirname("firefox-130.0-1"), Some(("firefox", "130.0-1")));
        assert_eq!(split_dirname("lib32-mesa-24.2.1-2"), Some(("lib32-mesa", "24.2.1-2")));
        assert_eq!(split_dirname("ALPM_DB_VERSION"), None);
    }

    #[test]
    fn desc() {
        let t = "%NAME%\nfoo\n\n%VERSION%\n1.0-1\n\n%DESC%\nA thing\n\n%SIZE%\n2048\n\n%REASON%\n1\n";
        let p = parse_desc(t, "foo", "1.0-1");
        assert_eq!(p.description, "A thing");
        assert_eq!(p.install_size, 2048);
        assert!(!p.explicit);
    }
}
