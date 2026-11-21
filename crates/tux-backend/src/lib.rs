//! Detects the package manager installed on this machine.
//!
//! Detection is kept out of the UI: the UI only receives a [`Backend`] value
//! and reads its capabilities. The environment variable `TUX_BACKEND` forces a
//! manager (`pacman`, `libalpm`, `apt`, `dnf`, `zypper`, `nix`, `none`), which
//! is useful for testing the unsupported state without removing packages.

use std::env;
use std::os::unix::fs::PermissionsExt;
use std::path::Path;
use tux_abi::backend::{Backend, BackendKind};

/// The backend the store should use.
pub fn detect() -> Backend {
    if let Some(value) = env::var_os("TUX_BACKEND") {
        let value = value.to_string_lossy();
        if let Some(kind) = BackendKind::from_key(&value) {
            return Backend::new(kind);
        }
        log::warn!("TUX_BACKEND={value:?} is not a known manager; detecting automatically");
    }

    let kind = if pacman_present() {
        BackendKind::Pacman
    } else if in_path("apt-get") {
        BackendKind::Apt
    } else if in_path("dnf") {
        BackendKind::Dnf
    } else if in_path("zypper") {
        BackendKind::Zypper
    } else if in_path("nix") {
        BackendKind::Nix
    } else {
        BackendKind::None
    };
    Backend::new(kind)
}

/// The pacman database or the command. The database alone is enough: it makes
/// the store work even when pacman is temporarily not in `$PATH`.
fn pacman_present() -> bool {
    Path::new("/var/lib/pacman").exists() || in_path("pacman")
}

/// Is `name` an executable file in `$PATH`?
fn in_path(name: &str) -> bool {
    let Some(path) = env::var_os("PATH") else {
        return false;
    };
    env::split_paths(&path).any(|dir| {
        let candidate = dir.join(name);
        candidate
            .metadata()
            .map(|m| m.is_file() && m.permissions().mode() & 0o111 != 0)
            .unwrap_or(false)
    })
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn detect_never_panics() {
        let b = detect();
        assert!(b.is_supported() || !b.is_supported());
    }

    #[test]
    fn every_known_key_builds_a_backend() {
        for key in ["pacman", "libalpm", "apt", "dnf", "zypper", "nix", "none"] {
            let kind = BackendKind::from_key(key).unwrap();
            let b = Backend::new(kind);
            assert_eq!(b.kind, kind);
        }
    }
}
