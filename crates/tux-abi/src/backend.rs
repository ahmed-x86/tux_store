//! Which package manager backs the store, and what it can do.
//!
//! This module is deliberately **data only**: the UI reads [`Backend`] and
//! [`Capabilities`], but never runs a package-manager command. Detection lives
//! in the `tux-backend` crate; the pacman-specific code lives in `tux-pacman`
//! and `tux-libalpm`.

use serde::{Deserialize, Serialize};

/// A package-manager family. `Pacman` and `Libalpm` are the two engines of the
/// Arch backend; the others are recognised so the app can say clearly that
/// they are not supported yet instead of showing a broken empty window.
#[derive(Debug, Clone, Copy, Default, PartialEq, Eq, Serialize, Deserialize)]
#[serde(rename_all = "lowercase")]
pub enum BackendKind {
    Pacman,
    Libalpm,
    Apt,
    Dnf,
    Zypper,
    Nix,
    #[default]
    None,
}

impl BackendKind {
    /// Stable key used by `TUX_BACKEND` and on the wire.
    pub fn key(self) -> &'static str {
        match self {
            BackendKind::Pacman => "pacman",
            BackendKind::Libalpm => "libalpm",
            BackendKind::Apt => "apt",
            BackendKind::Dnf => "dnf",
            BackendKind::Zypper => "zypper",
            BackendKind::Nix => "nix",
            BackendKind::None => "none",
        }
    }

    pub fn from_key(key: &str) -> Option<Self> {
        match key.trim().to_ascii_lowercase().as_str() {
            "pacman" => Some(BackendKind::Pacman),
            "libalpm" => Some(BackendKind::Libalpm),
            "apt" | "apt-get" => Some(BackendKind::Apt),
            "dnf" => Some(BackendKind::Dnf),
            "zypper" => Some(BackendKind::Zypper),
            "nix" => Some(BackendKind::Nix),
            "none" => Some(BackendKind::None),
            _ => None,
        }
    }

    /// Name shown in the UI.
    pub fn display_name(self) -> &'static str {
        match self {
            BackendKind::Pacman => "pacman",
            BackendKind::Libalpm => "libalpm",
            BackendKind::Apt => "APT",
            BackendKind::Dnf => "DNF",
            BackendKind::Zypper => "Zypper",
            BackendKind::Nix => "Nix",
            BackendKind::None => "No supported package manager",
        }
    }
}

/// One request a backend may or may not be able to answer.
#[derive(Debug, Clone, Copy, PartialEq, Eq, Serialize, Deserialize)]
#[serde(rename_all = "snake_case")]
pub enum Feature {
    Search,
    Details,
    Install,
    Remove,
    Updates,
    SystemUpgrade,
    Downgrade,
    TaxonomyGroups,
    TaxonomyRepositories,
    Categories,
    InstalledList,
    Addons,
}

/// What the active backend implements right now.
#[derive(Debug, Clone, Copy, Default, PartialEq, Eq, Serialize, Deserialize)]
pub struct Capabilities {
    pub search: bool,
    pub details: bool,
    pub install: bool,
    pub remove: bool,
    pub updates: bool,
    pub system_upgrade: bool,
    pub downgrade: bool,
    pub taxonomy_groups: bool,
    pub taxonomy_repositories: bool,
    pub categories: bool,
    pub installed_list: bool,
    pub addons: bool,
}

impl Capabilities {
    pub fn supports(self, feature: Feature) -> bool {
        match feature {
            Feature::Search => self.search,
            Feature::Details => self.details,
            Feature::Install => self.install,
            Feature::Remove => self.remove,
            Feature::Updates => self.updates,
            Feature::SystemUpgrade => self.system_upgrade,
            Feature::Downgrade => self.downgrade,
            Feature::TaxonomyGroups => self.taxonomy_groups,
            Feature::TaxonomyRepositories => self.taxonomy_repositories,
            Feature::Categories => self.categories,
            Feature::InstalledList => self.installed_list,
            Feature::Addons => self.addons,
        }
    }

    /// At least one feature works, i.e. the store has something to show.
    pub fn any(self) -> bool {
        self.search
            || self.details
            || self.install
            || self.remove
            || self.updates
            || self.system_upgrade
            || self.downgrade
            || self.taxonomy_groups
            || self.taxonomy_repositories
            || self.categories
            || self.installed_list
            || self.addons
    }

    /// Pacman / libalpm currently implement the whole vocabulary.
    pub const PACMAN: Capabilities = Capabilities {
        search: true,
        details: true,
        install: true,
        remove: true,
        updates: true,
        system_upgrade: true,
        downgrade: true,
        taxonomy_groups: true,
        taxonomy_repositories: true,
        categories: true,
        installed_list: true,
        addons: true,
    };

    /// A manager we can recognise but have no adapter for yet.
    pub const NONE: Capabilities = Capabilities {
        search: false,
        details: false,
        install: false,
        remove: false,
        updates: false,
        system_upgrade: false,
        downgrade: false,
        taxonomy_groups: false,
        taxonomy_repositories: false,
        categories: false,
        installed_list: false,
        addons: false,
    };
}

/// The active backend and its capabilities.
#[derive(Debug, Clone, Default, PartialEq, Eq, Serialize, Deserialize)]
pub struct Backend {
    pub kind: BackendKind,
    pub display_name: String,
    pub capabilities: Capabilities,
}

impl Backend {
    pub fn new(kind: BackendKind) -> Self {
        let capabilities = match kind {
            BackendKind::Pacman | BackendKind::Libalpm => Capabilities::PACMAN,
            _ => Capabilities::NONE,
        };
        Backend {
            kind,
            display_name: kind.display_name().to_string(),
            capabilities,
        }
    }

    /// The backend installed on this machine.
    pub fn pacman() -> Self {
        Self::new(BackendKind::Pacman)
    }

    /// No supported package manager.
    pub fn none() -> Self {
        Self::new(BackendKind::None)
    }

    pub fn supports(&self, feature: Feature) -> bool {
        self.capabilities.supports(feature)
    }

    /// Does this backend have any usable feature?
    pub fn is_supported(&self) -> bool {
        self.capabilities.any()
    }

    /// The single message the UI shows when the backend cannot be used.
    pub fn unsupported_message(&self) -> String {
        match self.kind {
            BackendKind::None => "No supported package manager was found".to_string(),
            _ if !self.is_supported() => {
                format!("{} is not supported yet.", self.display_name)
            }
            _ => String::new(),
        }
    }

    /// The same message for one feature of a partially supported backend.
    pub fn feature_message(&self, feature: Feature) -> String {
        if self.kind == BackendKind::None {
            return "No supported package manager was found".to_string();
        }
        if self.supports(feature) {
            return String::new();
        }
        format!("{} does not support this feature yet.", self.display_name)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn keys_roundtrip() {
        for kind in [
            BackendKind::Pacman,
            BackendKind::Libalpm,
            BackendKind::Apt,
            BackendKind::Dnf,
            BackendKind::Zypper,
            BackendKind::Nix,
            BackendKind::None,
        ] {
            assert_eq!(BackendKind::from_key(kind.key()), Some(kind));
        }
        assert_eq!(BackendKind::from_key("bogus"), None);
    }

    #[test]
    fn pacman_supports_everything() {
        let b = Backend::pacman();
        assert!(b.is_supported());
        for f in [
            Feature::Search,
            Feature::Details,
            Feature::Install,
            Feature::Remove,
            Feature::Updates,
            Feature::SystemUpgrade,
            Feature::Downgrade,
            Feature::TaxonomyGroups,
            Feature::TaxonomyRepositories,
            Feature::Categories,
            Feature::InstalledList,
            Feature::Addons,
        ] {
            assert!(b.supports(f), "{f:?}");
        }
        assert!(b.unsupported_message().is_empty());
    }

    #[test]
    fn unknown_managers_are_unsupported() {
        for kind in [
            BackendKind::Apt,
            BackendKind::Dnf,
            BackendKind::Zypper,
            BackendKind::Nix,
        ] {
            let b = Backend::new(kind);
            assert!(!b.is_supported());
            assert_eq!(
                b.unsupported_message(),
                format!("{} is not supported yet.", kind.display_name())
            );
        }
        assert_eq!(
            Backend::none().unsupported_message(),
            "No supported package manager was found"
        );
    }

    #[test]
    fn wire_names_are_stable() {
        assert_eq!(serde_json::to_string(&BackendKind::Nix).unwrap(), "\"nix\"");
        assert_eq!(
            serde_json::to_string(&Feature::InstalledList).unwrap(),
            "\"installed_list\""
        );
    }
}
