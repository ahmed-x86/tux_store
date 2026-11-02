//! The one vocabulary every module speaks.
//!
//! Naming convention: `XxxRequested` flows *towards* a backend module,
//! `XxxReady` / `Operation*` flows back to whoever is listening (normally the
//! UI, but any module may listen — e.g. the installer overhears
//! [`Message::DetailsReady`] to learn package sizes for its progress bar).

use serde::{Deserialize, Serialize};

// ───────────────────────────── data types ─────────────────────────────

#[derive(Debug, Clone, Default, PartialEq, Eq, Serialize, Deserialize)]
pub struct Package {
    pub name: String,
    pub repo: String,
    pub version: String,
    pub description: String,
    pub installed: bool,
}

#[derive(Debug, Clone, Default, PartialEq, Eq, Serialize, Deserialize)]
pub struct Dependency {
    pub name: String,
    pub size_bytes: u64,
    pub installed: bool,
}

/// Real transaction plan from pacman's own resolver.
#[derive(Debug, Clone, Default, PartialEq, Eq, Serialize, Deserialize)]
pub struct PackageDetails {
    /// Installed size of the package itself.
    pub app_size: u64,
    /// Dependencies of the plan that are already on disk.
    pub installed_deps: u64,
    /// Dependencies that still have to be installed.
    pub new_deps: u64,
    pub total_download: u64,
    pub total_installed: u64,
    pub net_upgrade: u64,
    /// Installed first, then new ones.
    pub dependencies: Vec<Dependency>,
    /// `false` when pacman could not produce a plan (AUR / foreign package…).
    pub plan_ok: bool,
}

impl PackageDetails {
    pub fn total_footprint(&self) -> u64 {
        self.app_size + self.installed_deps + self.new_deps
    }
}

#[derive(Debug, Clone, Default, PartialEq, Eq, Serialize, Deserialize)]
pub struct Addon {
    pub label: String,
    pub package: String,
}

/// Addons / language packs attached to a package, and the reverse link.
#[derive(Debug, Clone, Default, PartialEq, Eq, Serialize, Deserialize)]
pub struct SpecialCase {
    /// `"Language Packs"` or `"Addons"` (empty when only `addon_for` is set).
    pub kind: String,
    pub items: Vec<Addon>,
    /// The parent package when the viewed package is itself an addon.
    pub addon_for: Option<String>,
}

#[derive(Debug, Clone, Default, PartialEq, Eq, Serialize, Deserialize)]
pub struct Section {
    pub id: String,
    pub title: String,
    pub packages: Vec<Package>,
}

#[derive(Debug, Clone, Default, PartialEq, Eq, Serialize, Deserialize)]
pub struct Cover {
    pub name: String,
    pub images: Vec<String>,
}

#[derive(Debug, Clone, Default, PartialEq, Eq, Serialize, Deserialize)]
pub struct UpdateEntry {
    pub name: String,
    pub old_version: String,
    pub new_version: String,
}

/// The five uninstall flavours offered by the UI.
#[derive(Debug, Clone, Copy, PartialEq, Eq, Serialize, Deserialize)]
pub enum RemoveMode {
    Basic,
    Reset,
    Clean,
    Force,
    Complete,
}

impl RemoveMode {
    pub fn flag(self) -> &'static str {
        match self {
            RemoveMode::Basic => "-R",
            RemoveMode::Reset => "-Rn",
            RemoveMode::Clean => "-Rs",
            RemoveMode::Force => "-Rdd",
            RemoveMode::Complete => "-Rns",
        }
    }

    pub fn from_flag(flag: &str) -> Option<Self> {
        Some(match flag {
            "-R" => RemoveMode::Basic,
            "-Rn" => RemoveMode::Reset,
            "-Rs" => RemoveMode::Clean,
            "-Rdd" => RemoveMode::Force,
            "-Rns" => RemoveMode::Complete,
            _ => return None,
        })
    }
}

/// A privileged pacman transaction.
#[derive(Debug, Clone, PartialEq, Eq, Serialize, Deserialize)]
pub enum Operation {
    Install { name: String },
    Remove { name: String, mode: RemoveMode },
    SystemUpgrade,
}

// ───────────────────────────── the bus message ─────────────────────────────

#[derive(Debug, Clone, Serialize, Deserialize)]
#[serde(tag = "type")]
pub enum Message {
    // ── lifecycle ──
    /// UI window exists; backends may warm up.
    UiReady,

    // ── requests (UI → backends) ──
    HomeRequested,
    SearchRequested { query: String },
    DetailsRequested { name: String },
    ExactRequested { name: String },
    AddonsRequested { package: String },
    InstalledRequested,
    UpdatesRequested,
    CoversRequested,
    IconRequested { name: String, size: u32 },
    ClearIconCache,
    InstallRequested { name: String },
    RemoveRequested { name: String, mode: RemoveMode },
    SystemUpgradeRequested,

    // ── answers (backends → UI) ──
    HomeReady { sections: Vec<Section> },
    SearchResults { query: String, packages: Vec<Package> },
    DetailsReady { name: String, details: PackageDetails, special: Option<SpecialCase> },
    ExactReady { package: Package },
    AddonsReady { package: String, packages: Vec<Package> },
    InstalledReady { packages: Vec<Package> },
    UpdatesReady { updates: Vec<UpdateEntry>, error: Option<String> },
    CoversReady { covers: Vec<Cover> },
    IconReady { name: String, path: String },
    IconFailed { name: String },
    IconCacheCleared { removed: u32 },

    // ── transaction progress (installer → everyone) ──
    OperationStarted { op: Operation },
    OperationOutput { text: String },
    OperationProgress { fraction: f64 },
    OperationFinished { op: Operation, success: bool, exit_code: i32 },
}

impl Message {
    pub fn encode(&self) -> Result<Vec<u8>, serde_json::Error> {
        serde_json::to_vec(self)
    }

    pub fn decode(bytes: &[u8]) -> Result<Self, serde_json::Error> {
        serde_json::from_slice(bytes)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn roundtrip() {
        let m = Message::RemoveRequested { name: "vlc".into(), mode: RemoveMode::Complete };
        let bytes = m.encode().unwrap();
        match Message::decode(&bytes).unwrap() {
            Message::RemoveRequested { name, mode } => {
                assert_eq!(name, "vlc");
                assert_eq!(mode, RemoveMode::Complete);
            }
            other => panic!("unexpected {other:?}"),
        }
    }

    #[test]
    fn unit_variant() {
        let bytes = Message::UiReady.encode().unwrap();
        assert!(matches!(Message::decode(&bytes).unwrap(), Message::UiReady));
    }

    #[test]
    fn flags() {
        for m in [RemoveMode::Basic, RemoveMode::Reset, RemoveMode::Clean, RemoveMode::Force, RemoveMode::Complete] {
            assert_eq!(RemoveMode::from_flag(m.flag()), Some(m));
        }
        assert_eq!(RemoveMode::from_flag("-Syu"), None);
    }
}
