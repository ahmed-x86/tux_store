//! Shipped and user-configured hidden packages.
//!
//! Packages listed in `data/hidden_packages.json` (and optionally
//! `~/.config/tux-store/hidden_packages.json`) are hidden across Tux Store:
//! search, Home, add-ons, categories, groups, and repositories.

use std::collections::HashSet;
use std::fs;
use std::sync::OnceLock;
use serde::Deserialize;

use crate::paths;
use crate::text::is_valid_package_name;
use crate::Package;

#[derive(Debug, Default, Deserialize)]
#[serde(deny_unknown_fields)]
struct HiddenFile {
    #[serde(default)]
    hidden_packages: Vec<String>,
    #[serde(default)]
    hide_in_installed: bool,
    #[serde(default)]
    #[allow(dead_code)]
    note: Option<String>,
}

#[derive(Debug, Default, Clone)]
pub struct HiddenPackages {
    hidden: HashSet<String>,
    hide_in_installed: bool,
}

impl HiddenPackages {
    pub fn load() -> Self {
        let mut hidden = HashSet::new();
        let mut hide_in_installed = false;

        for path in paths::hidden_packages_files() {
            let Ok(text) = fs::read_to_string(&path) else { continue };
            match serde_json::from_str::<HiddenFile>(&text) {
                Ok(f) => {
                    hide_in_installed |= f.hide_in_installed;
                    for name in f.hidden_packages {
                        let trimmed = name.trim();
                        if is_valid_package_name(trimmed) {
                            hidden.insert(trimmed.to_ascii_lowercase());
                        } else {
                            log::warn!("{}: ignoring invalid package name {name:?}", path.display());
                        }
                    }
                }
                Err(e) => {
                    log::warn!("{}: cannot parse hidden packages: {e}", path.display());
                }
            }
        }

        Self {
            hidden,
            hide_in_installed,
        }
    }

    /// Whether this package name (or display title) is hidden.
    /// Comparisons are case-insensitive and ignore leading/trailing whitespace.
    pub fn is_hidden(&self, name: &str) -> bool {
        if self.hidden.is_empty() {
            return false;
        }
        let norm = name.trim().to_ascii_lowercase();
        self.hidden.contains(&norm)
    }

    pub fn hide_in_installed(&self) -> bool {
        self.hide_in_installed
    }

    pub fn len(&self) -> usize {
        self.hidden.len()
    }

    pub fn is_empty(&self) -> bool {
        self.hidden.is_empty()
    }

    /// Drop hidden packages from a package list.
    pub fn filter_packages(&self, packages: Vec<Package>) -> Vec<Package> {
        if self.hidden.is_empty() {
            return packages;
        }
        packages
            .into_iter()
            .filter(|p| !self.is_hidden(&p.name) && (p.title.is_empty() || !self.is_hidden(&p.title)))
            .collect()
    }

    /// Drop hidden packages if configured to hide them when installed.
    pub fn filter_installed(&self, packages: Vec<Package>) -> Vec<Package> {
        if self.hide_in_installed {
            self.filter_packages(packages)
        } else {
            packages
        }
    }
}

static INSTANCE: OnceLock<HiddenPackages> = OnceLock::new();

pub fn get() -> &'static HiddenPackages {
    INSTANCE.get_or_init(HiddenPackages::load)
}

pub fn is_hidden(name: &str) -> bool {
    get().is_hidden(name)
}

pub fn filter_packages(packages: Vec<Package>) -> Vec<Package> {
    get().filter_packages(packages)
}

pub fn filter_installed(packages: Vec<Package>) -> Vec<Package> {
    get().filter_installed(packages)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn case_insensitive_matching() {
        let mut hp = HiddenPackages::default();
        hp.hidden.insert("xiphos".into());
        hp.hidden.insert("bibletime".into());

        assert!(hp.is_hidden("xiphos"));
        assert!(hp.is_hidden("Xiphos"));
        assert!(hp.is_hidden("XIPHOS"));
        assert!(hp.is_hidden("bibletime"));
        assert!(hp.is_hidden("BibleTime"));
        assert!(hp.is_hidden("  BibleTime  "));
        assert!(!hp.is_hidden("firefox"));
    }

    #[test]
    fn filtering_packages() {
        let mut hp = HiddenPackages::default();
        hp.hidden.insert("xiphos".into());

        let pkgs = vec![
            Package { name: "firefox".into(), ..Default::default() },
            Package { name: "xiphos".into(), ..Default::default() },
            Package { name: "other".into(), title: "Xiphos".into(), ..Default::default() },
        ];
        let visible = hp.filter_packages(pkgs);
        assert_eq!(visible.len(), 1);
        assert_eq!(visible[0].name, "firefox");
    }
}
