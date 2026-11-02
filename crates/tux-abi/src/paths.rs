//! Where things live. Works from a cargo build tree and from an installed
//! prefix such as `/usr`.

use std::path::{Path, PathBuf};
use std::sync::OnceLock;

pub const APP_DIR: &str = "tux-store";

/// Directory containing the running executable.
pub fn exe_dir() -> PathBuf {
    std::env::current_exe()
        .ok()
        .and_then(|p| p.parent().map(Path::to_path_buf))
        .unwrap_or_else(|| PathBuf::from("."))
}

pub fn home() -> PathBuf {
    std::env::var_os("HOME")
        .map(PathBuf::from)
        .unwrap_or_else(|| PathBuf::from("/tmp"))
}

/// Read-only application data (`categories.json`, bundled icons, covers…).
///
/// Order: `$TUX_DATA_DIR`, `<exe>/../share/tux-store` (installed),
/// `<exe>/../../data` (cargo `target/<profile>/`), `<exe>/data`, `./data`.
pub fn data_dir() -> &'static Path {
    static DIR: OnceLock<PathBuf> = OnceLock::new();
    DIR.get_or_init(|| {
        let exe = exe_dir();
        let mut candidates: Vec<PathBuf> = Vec::new();
        if let Some(p) = std::env::var_os("TUX_DATA_DIR") {
            candidates.push(PathBuf::from(p));
        }
        candidates.push(exe.join("../share").join(APP_DIR));
        candidates.push(exe.join("../../data"));
        candidates.push(exe.join("data"));
        candidates.push(PathBuf::from("data"));
        candidates
            .into_iter()
            .find(|c| c.join("categories.json").is_file())
            .map(|p| p.canonicalize().unwrap_or(p))
            .unwrap_or_else(|| PathBuf::from("data"))
    })
}

fn xdg(var: &str, fallback: &str) -> PathBuf {
    match std::env::var_os(var).filter(|p| !p.is_empty()) {
        Some(p) => PathBuf::from(p).join(APP_DIR),
        None => home().join(fallback).join(APP_DIR),
    }
}

/// `~/.cache/tux-store`
pub fn cache_dir() -> PathBuf {
    xdg("XDG_CACHE_HOME", ".cache")
}

/// `~/.config/tux-store`
pub fn config_dir() -> PathBuf {
    xdg("XDG_CONFIG_HOME", ".config")
}
