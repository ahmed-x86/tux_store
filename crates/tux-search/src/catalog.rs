//! The curated catalog: Home sections (`categories.json`) and add-on /
//! language-pack links (`special_case_packages/*.json`). Pure data, loaded
//! once at start-up.

use serde::Deserialize;
use std::collections::{BTreeMap, HashMap, HashSet};
use std::fs;
use std::path::Path;
use tux_abi::script::LoadedScript;
use tux_abi::text::is_valid_package_name;
use tux_abi::{paths, Addon, Package, SpecialCase};

#[derive(Debug, Deserialize)]
struct CategoriesFile {
    sections: Vec<SectionDef>,
}

#[derive(Debug, Clone, Deserialize)]
pub struct SectionDef {
    pub id: String,
    pub title: String,
    pub packages: Vec<String>,
}

#[derive(Debug, Deserialize)]
struct SpecialFile {
    package: Option<String>,
    #[serde(default)]
    language_packs: BTreeMap<String, String>,
    #[serde(default)]
    addons: BTreeMap<String, String>,
}

#[derive(Debug)]
struct SpecialDef {
    kind: &'static str,
    items: Vec<Addon>,
}

/// `hidden_packages.json` (shipped) and `~/.config/tux-store/hidden_packages.json`.
#[derive(Debug, Default, Deserialize)]
#[serde(deny_unknown_fields)]
struct HiddenFile {
    #[serde(default)]
    hidden_packages: Vec<String>,
    /// Also hide them in the *Installed* tab (default: no, so that something
    /// you installed can always be found and removed).
    #[serde(default)]
    hide_in_installed: bool,
    #[serde(default)]
    #[allow(dead_code)]
    note: Option<String>,
}

#[derive(Debug, Default)]
pub struct Catalog {
    pub sections: Vec<SectionDef>,
    specials: HashMap<String, SpecialDef>,
    addon_of: HashMap<String, String>,
    hidden: HashSet<String>,
    hide_in_installed: bool,
    pub scripts: Vec<LoadedScript>,
}

impl Catalog {
    pub fn load(data_dir: &Path) -> Self {
        let mut cat = Catalog::default();

        match fs::read_to_string(data_dir.join("categories.json"))
            .map_err(|e| e.to_string())
            .and_then(|t| serde_json::from_str::<CategoriesFile>(&t).map_err(|e| e.to_string()))
        {
            Ok(f) => cat.sections = f.sections,
            Err(e) => log::warn!("categories.json unusable: {e}"),
        }

        let mut files: Vec<_> = fs::read_dir(data_dir.join("special_case_packages"))
            .map(|rd| rd.flatten().map(|e| e.path()).collect())
            .unwrap_or_default();
        files.sort();

        for path in files.iter().filter(|p| p.extension().is_some_and(|e| e == "json")) {
            let parsed = fs::read_to_string(path)
                .map_err(|e| e.to_string())
                .and_then(|t| serde_json::from_str::<SpecialFile>(&t).map_err(|e| e.to_string()));
            let file = match parsed {
                Ok(f) => f,
                Err(e) => {
                    log::warn!("{}: {e}", path.display());
                    continue;
                }
            };
            let parent = file.package.clone().unwrap_or_else(|| {
                path.file_stem().map(|s| s.to_string_lossy().into_owned()).unwrap_or_default()
            });
            let (kind, map) = if !file.language_packs.is_empty() {
                ("Language Packs", file.language_packs)
            } else {
                ("Addons", file.addons)
            };
            if map.is_empty() || parent.is_empty() {
                continue;
            }
            let items: Vec<Addon> = map
                .into_iter()
                .map(|(label, package)| Addon { label, package })
                .collect();
            for it in &items {
                cat.addon_of.insert(it.package.clone(), parent.clone());
            }
            cat.specials.insert(parent, SpecialDef { kind, items });
        }

        for path in paths::hidden_packages_files() {
            let Ok(text) = fs::read_to_string(&path) else { continue };
            match serde_json::from_str::<HiddenFile>(&text) {
                Ok(f) => {
                    cat.hide_in_installed |= f.hide_in_installed;
                    for name in f.hidden_packages {
                        if is_valid_package_name(&name) {
                            cat.hidden.insert(name);
                        } else {
                            log::warn!("{}: ignoring invalid package name {name:?}", path.display());
                        }
                    }
                }
                Err(e) => log::warn!("{}: {e}", path.display()),
            }
        }

        cat.scripts = tux_abi::script::load_all();

        log::info!(
            "catalog: {} sections, {} packages with add-ons, {} hidden, {} scripts",
            cat.sections.len(),
            cat.specials.len(),
            cat.hidden.len(),
            cat.scripts.len()
        );
        cat
    }

    pub fn is_hidden(&self, name: &str) -> bool {
        self.hidden.contains(name)
    }

    /// Drop hidden packages from a list shown in search / Home / add-ons.
    pub fn filter_visible(&self, packages: Vec<Package>) -> Vec<Package> {
        if self.hidden.is_empty() {
            return packages;
        }
        packages.into_iter().filter(|p| !self.is_hidden(&p.name)).collect()
    }

    /// Same for the *Installed* tab (only when the file asks for it).
    pub fn filter_installed(&self, packages: Vec<Package>) -> Vec<Package> {
        if self.hide_in_installed {
            self.filter_visible(packages)
        } else {
            packages
        }
    }

    fn script_package(l: &LoadedScript) -> Package {
        Package {
            name: l.script.id.clone(),
            title: l.script.title.clone(),
            repo: "script".into(),
            version: l.script.version.fixed(),
            description: l.script.description.clone(),
            installed: tux_abi::receipt::load(&l.script.id).is_some_and(|r| r.complete),
        }
    }

    /// Scripts whose id, title or keywords match `query`.
    pub fn scripts_matching(&self, query: &str) -> Vec<Package> {
        let norm = |s: &str| -> String {
            s.chars().filter(|c| !matches!(c, ' ' | '-' | '_' | '.')).flat_map(char::to_lowercase).collect()
        };
        let needle = norm(query);
        if needle.is_empty() {
            return Vec::new();
        }
        self.scripts
            .iter()
            .filter(|l| l.script.matches(&needle, norm))
            .map(Self::script_package)
            .collect()
    }

    /// Add-on packages that were installed (they have an install record),
    /// for the *Installed* tab. Records whose script file is gone still show,
    /// so nothing installed can become invisible.
    pub fn installed_addons(&self) -> Vec<Package> {
        tux_abi::receipt::list()
            .into_iter()
            .filter(|r| r.complete)
            .map(|r| Package {
                title: if r.title.is_empty() { r.id.clone() } else { r.title.clone() },
                name: r.id,
                repo: "script".into(),
                version: r.installed_version,
                description: String::new(),
                installed: true,
            })
            .collect()
    }

    /// Scripts for the Home shelf.
    pub fn home_scripts(&self) -> Vec<Package> {
        self.scripts.iter().filter(|l| l.script.show_on_home).map(Self::script_package).collect()
    }

    /// Every curated package name once, in display order.
    pub fn all_package_names(&self) -> Vec<String> {
        let mut seen = HashSet::new();
        self.sections
            .iter()
            .flat_map(|s| s.packages.iter())
            .filter(|n| !self.hidden.contains(n.as_str()) && seen.insert(n.as_str()))
            .cloned()
            .collect()
    }

    pub fn special_for(&self, name: &str) -> Option<SpecialCase> {
        let own = self.specials.get(name);
        let parent = self.addon_of.get(name);
        if own.is_none() && parent.is_none() {
            return None;
        }
        Some(SpecialCase {
            kind: own.map(|s| s.kind.to_string()).unwrap_or_default(),
            items: own.map(|s| s.items.clone()).unwrap_or_default(),
            addon_for: parent.cloned(),
        })
    }

    pub fn addon_names(&self, parent: &str) -> Vec<String> {
        self.specials
            .get(parent)
            .map(|s| {
                s.items.iter().map(|a| a.package.clone()).filter(|n| !self.hidden.contains(n)).collect()
            })
            .unwrap_or_default()
    }
}
