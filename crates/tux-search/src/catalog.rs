//! The curated catalog: Home sections (`categories.json`) and add-on /
//! language-pack links (`special_case_packages/*.json`). Pure data, loaded
//! once at start-up.

use serde::Deserialize;
use std::collections::{BTreeMap, HashMap, HashSet};
use std::fs;
use std::path::Path;
use tux_abi::{Addon, SpecialCase};

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

#[derive(Debug, Default)]
pub struct Catalog {
    pub sections: Vec<SectionDef>,
    specials: HashMap<String, SpecialDef>,
    addon_of: HashMap<String, String>,
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

        log::info!(
            "catalog: {} sections, {} packages with add-ons",
            cat.sections.len(),
            cat.specials.len()
        );
        cat
    }

    /// Every curated package name once, in display order.
    pub fn all_package_names(&self) -> Vec<String> {
        let mut seen = HashSet::new();
        self.sections
            .iter()
            .flat_map(|s| s.packages.iter())
            .filter(|n| seen.insert(n.as_str()))
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
            .map(|s| s.items.iter().map(|a| a.package.clone()).collect())
            .unwrap_or_default()
    }
}
