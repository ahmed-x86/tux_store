//! Where things live. Works from a cargo build tree and from an installed
//! prefix such as `/usr`.

use std::ffi::{c_char, CStr, OsStr};
use std::os::unix::ffi::OsStrExt;
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

/// The user's home directory: `$HOME`, else the passwd entry of the current
/// user. (Never a temp directory — caches must land in the user's `~/.cache`.)
pub fn home() -> PathBuf {
    if let Some(h) = std::env::var_os("HOME").filter(|h| !h.is_empty()) {
        return PathBuf::from(h);
    }
    passwd_home().unwrap_or_else(|| PathBuf::from("/tmp"))
}

fn passwd_home() -> Option<PathBuf> {
    let mut buf = vec![0u8; 4096];
    // SAFETY: all pointers are valid for the duration of the call; `pw_dir`
    // points into `buf`, which outlives the copy made below.
    unsafe {
        let mut pwd: libc::passwd = std::mem::zeroed();
        let mut res: *mut libc::passwd = std::ptr::null_mut();
        let rc = libc::getpwuid_r(libc::getuid(), &mut pwd, buf.as_mut_ptr().cast::<c_char>(), buf.len(), &mut res);
        if rc != 0 || res.is_null() || pwd.pw_dir.is_null() {
            return None;
        }
        let dir = CStr::from_ptr(pwd.pw_dir).to_bytes();
        (!dir.is_empty()).then(|| PathBuf::from(OsStr::from_bytes(dir)))
    }
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
        if let Some(m) = std::env::var_os("CARGO_MANIFEST_DIR") {
            let m = PathBuf::from(m);
            candidates.push(m.join("../../data"));
            candidates.push(m.join("data"));
        }
        candidates.push(exe.join("../share").join(APP_DIR));
        candidates.push(exe.join("../../../data"));
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
    // The XDG spec says relative values must be ignored.
    match std::env::var_os(var).filter(|p| Path::new(p).is_absolute()) {
        Some(p) => PathBuf::from(p).join(APP_DIR),
        None => home().join(fallback).join(APP_DIR),
    }
}

/// `~/.cache/tux-store` (or `$XDG_CACHE_HOME/tux-store`) — the one place the
/// store caches anything. "Clear cache" wipes this whole directory.
pub fn cache_dir() -> PathBuf {
    xdg("XDG_CACHE_HOME", ".cache")
}

/// `~/.config/tux-store`
pub fn config_dir() -> PathBuf {
    xdg("XDG_CONFIG_HOME", ".config")
}

/// Scripts shipped with the store (`<data>/scripts/*.json`, root-owned).
pub fn system_scripts_dir() -> PathBuf {
    data_dir().join("scripts")
}

/// Scripts written by the user (`~/.config/tux-store/scripts/*.json`).
pub fn user_scripts_dir() -> PathBuf {
    config_dir().join("scripts")
}

/// Custom add-on categories shipped with the store
/// (`<data>/addon_categories/<id>/<id>.json`).
pub fn system_addon_categories_dir() -> PathBuf {
    data_dir().join("addon_categories")
}

/// Custom add-on categories written by the user
/// (`~/.config/tux-store/addon_categories/<id>/<id>.json`).
pub fn user_addon_categories_dir() -> PathBuf {
    config_dir().join("addon_categories")
}

/// Screenshots shipped with the store (`<data>/screenshots/<package>/…`).
pub fn system_screenshots_dir() -> PathBuf {
    data_dir().join("screenshots")
}

/// Screenshots added by the user (`~/.config/tux-store/screenshots/<package>/…`).
pub fn user_screenshots_dir() -> PathBuf {
    config_dir().join("screenshots")
}

/// Remote image links shipped with the store (`<data>/images/remote_images.json`).
pub fn system_remote_images_file() -> PathBuf {
    data_dir().join("images/remote_images.json")
}

/// The user's own remote image links (`~/.config/tux-store/remote_images.json`).
pub fn user_remote_images_file() -> PathBuf {
    config_dir().join("remote_images.json")
}

/// Packages to hide: shipped list and the user's own list.
pub fn hidden_packages_files() -> Vec<PathBuf> {
    vec![data_dir().join("hidden_packages.json"), config_dir().join("hidden_packages.json")]
}

/// Where the log of every add-on install / uninstall is saved:
/// `$XDG_STATE_HOME/tux-store/logs` (default `~/.local/state/tux-store/logs`).
/// Files are named `tux-store-<HH-MM-SS>-<YYYY-MM-DD>-<add-on name>.log`.
pub fn logs_dir() -> PathBuf {
    xdg("XDG_STATE_HOME", ".local/state").join("logs")
}

/// Where install records ("receipts") of add-on packages are kept:
/// `$XDG_DATA_HOME/tux-store/addons` (default `~/.local/share/tux-store/addons`).
pub fn addons_state_dir() -> PathBuf {
    let base = std::env::var_os("XDG_DATA_HOME")
        .filter(|d| !d.is_empty())
        .map(PathBuf::from)
        .unwrap_or_else(|| home().join(".local/share"));
    base.join(APP_DIR).join("addons")
}
