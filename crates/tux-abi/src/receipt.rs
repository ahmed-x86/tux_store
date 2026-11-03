//! Install records ("receipts") of add-on packages.
//!
//! When an add-on package installs something it leaves a small JSON file
//! behind. It tells Tux Store that the add-on ran (so the page can say
//! "Installed"), and it keeps what the uninstall flow needs: the choices made
//! during the install and the packages / files the script recorded.
//!
//! Files live in [`crate::paths::addons_state_dir`] as `<id>.json`. Ids are
//! validated package-style names, so an id can never escape the directory.

use crate::script::Vars;
use crate::text::is_valid_package_name;
use serde::{Deserialize, Serialize};
use std::fs;
use std::io;
use std::path::{Path, PathBuf};
use std::time::{SystemTime, UNIX_EPOCH};

#[derive(Debug, Clone, Default, PartialEq, Eq, Serialize, Deserialize)]
pub struct Receipt {
    pub id: String,
    pub title: String,
    /// Version of the JSON that did the install.
    #[serde(default)]
    pub script_version: String,
    /// Version of what was installed (e.g. the game), when known.
    #[serde(default)]
    pub installed_version: String,
    /// Unix seconds.
    #[serde(default)]
    pub installed_at: u64,
    /// `false` while an install is only partly done.
    #[serde(default)]
    pub complete: bool,
    /// The script's variables when the record was last written (the choices).
    #[serde(default)]
    pub vars: Vars,
    /// Values stored by `record` steps (`"set"`).
    #[serde(default)]
    pub values: Vars,
    /// pacman packages the script installed.
    #[serde(default)]
    pub packages: Vec<String>,
    /// Files / folders the script created (absolute paths).
    #[serde(default)]
    pub files: Vec<String>,
}

pub fn now() -> u64 {
    SystemTime::now().duration_since(UNIX_EPOCH).map(|d| d.as_secs()).unwrap_or(0)
}

fn path_in(dir: &Path, id: &str) -> Option<PathBuf> {
    is_valid_package_name(id).then(|| dir.join(format!("{id}.json")))
}

pub fn load_from(dir: &Path, id: &str) -> Option<Receipt> {
    let text = fs::read_to_string(path_in(dir, id)?).ok()?;
    match serde_json::from_str::<Receipt>(&text) {
        Ok(r) if r.id == id => Some(r),
        Ok(_) => None,
        Err(e) => {
            log::warn!("receipt {id}: {e}");
            None
        }
    }
}

/// Atomic write: a crash never leaves half a file.
pub fn save_to(dir: &Path, r: &Receipt) -> io::Result<()> {
    let path = path_in(dir, &r.id).ok_or_else(|| io::Error::new(io::ErrorKind::InvalidInput, "invalid add-on id"))?;
    fs::create_dir_all(dir)?;
    let tmp = path.with_extension("json.tmp");
    fs::write(&tmp, serde_json::to_vec_pretty(r).map_err(io::Error::other)?)?;
    fs::rename(tmp, path)
}

pub fn remove_from(dir: &Path, id: &str) -> io::Result<()> {
    match path_in(dir, id).map(fs::remove_file) {
        Some(Err(e)) if e.kind() != io::ErrorKind::NotFound => Err(e),
        _ => Ok(()),
    }
}

pub fn list_in(dir: &Path) -> Vec<Receipt> {
    let mut out: Vec<Receipt> = fs::read_dir(dir)
        .map(|rd| {
            rd.flatten()
                .filter_map(|e| {
                    let p = e.path();
                    let id = p.file_stem()?.to_str()?.to_string();
                    (p.extension()? == "json").then(|| load_from(dir, &id)).flatten()
                })
                .collect()
        })
        .unwrap_or_default();
    out.sort_by(|a, b| a.title.cmp(&b.title));
    out
}

pub fn load(id: &str) -> Option<Receipt> {
    load_from(&crate::paths::addons_state_dir(), id)
}
pub fn save(r: &Receipt) -> io::Result<()> {
    save_to(&crate::paths::addons_state_dir(), r)
}
pub fn remove(id: &str) -> io::Result<()> {
    remove_from(&crate::paths::addons_state_dir(), id)
}
pub fn list() -> Vec<Receipt> {
    list_in(&crate::paths::addons_state_dir())
}

/// Expand a leading `~/` and accept only plain absolute paths without `..`.
pub fn clean_recorded_path(raw: &str, home: &Path) -> Option<String> {
    let t = raw.trim();
    let p = match t.strip_prefix("~/") {
        Some(rest) => home.join(rest),
        None => PathBuf::from(t),
    };
    let ok = p.is_absolute()
        && p.as_os_str().len() <= 1000
        && !p.components().any(|c| matches!(c, std::path::Component::ParentDir))
        && !t.contains('\0')
        && p.parent().is_some(); // never "/"
    ok.then(|| p.to_string_lossy().into_owned())
}

#[cfg(test)]
mod tests {
    use super::*;

    fn tmp(name: &str) -> PathBuf {
        let d = std::env::temp_dir().join(format!("tux-receipt-{name}-{}", std::process::id()));
        let _ = fs::remove_dir_all(&d);
        d
    }

    #[test]
    fn save_load_list_remove() {
        let dir = tmp("a");
        let mut r = Receipt { id: "demo-1".into(), title: "Demo".into(), complete: true, ..Default::default() };
        r.packages.push("pkg".into());
        r.vars.insert("driver".into(), "open".into());
        save_to(&dir, &r).unwrap();
        assert_eq!(load_from(&dir, "demo-1"), Some(r.clone()));
        assert_eq!(list_in(&dir), vec![r]);
        remove_from(&dir, "demo-1").unwrap();
        assert_eq!(load_from(&dir, "demo-1"), None);
        remove_from(&dir, "demo-1").unwrap(); // removing twice is fine
        let _ = fs::remove_dir_all(&dir);
    }

    #[test]
    fn ids_cannot_escape_the_directory() {
        let dir = tmp("b");
        let r = Receipt { id: "../evil".into(), ..Default::default() };
        assert!(save_to(&dir, &r).is_err());
        assert_eq!(load_from(&dir, "../etc/passwd"), None);
    }

    #[test]
    fn recorded_paths_are_checked() {
        let home = Path::new("/home/u");
        assert_eq!(clean_recorded_path("~/games/mc", home).as_deref(), Some("/home/u/games/mc"));
        assert_eq!(clean_recorded_path("/opt/thing", home).as_deref(), Some("/opt/thing"));
        assert_eq!(clean_recorded_path("relative/x", home), None);
        assert_eq!(clean_recorded_path("~/../etc", home), None);
        assert_eq!(clean_recorded_path("/", home), None);
    }
}
