//! Custom **add-on categories** (since 0.15.0): a folder per category below
//! `data/addon_categories/` (shipped) or `~/.config/tux-store/addon_categories/`
//! (the user's, which wins):
//!
//! ```text
//! data/addon_categories/artcraft/
//! ├── artcraft.json      ← the metadata (this file's name = folder name = id)
//! └── artcraft.svg       ← the thumbnail, when "file" is used
//! ```
//!
//! ```json
//! {
//!   "schema": 1,
//!   "id": "artcraft",
//!   "title": "ArtCraft",
//!   "description": "Apps from the ArtCraft suite.",
//!   "icon": { "file": "artcraft.svg" }
//! }
//! ```
//!
//! The `icon` object names exactly one source, like an add-on package's icon:
//!
//! | Key | Where the thumbnail comes from |
//! |---|---|
//! | `file` | a `.svg` / `.png` / `.ico` **next to the JSON** (bare file name) |
//! | `url`  | a plain `https://` link, downloaded once and cached |
//! | `flathub` | a Flathub **app id** (`org.gnome.Builder`) — the store builds the link itself |
//!
//! Add-on packages join a custom category by naming it in their own JSON
//! (`"categories": ["artcraft", "graphics"]`). Nothing here is a list of
//! packages: the membership lives in each add-on, exactly like AppStream
//! categories. See `DOCS/TAXONOMY.md`.

use crate::paths;
use crate::script::{is_valid_icon_file_name, is_valid_icon_url, IconSource};
use serde::{Deserialize, Serialize};
use std::collections::HashSet;
use std::fs;
use std::path::{Path, PathBuf};

/// Most custom categories the store reads (a runaway folder is ignored).
pub const MAX_CATEGORIES: usize = 100;
/// Longest accepted `id` (it is also part of an icon cache key).
pub const MAX_ID: usize = 64;
const MAX_FILE_BYTES: u64 = 512 * 1024;
const MAX_TEXT: usize = 2000;

/// Where a custom category's thumbnail comes from. Exactly one field is set.
#[derive(Debug, Clone, Default, PartialEq, Eq, Serialize, Deserialize)]
#[serde(deny_unknown_fields)]
pub struct CategoryIcon {
    /// A `.svg` / `.png` / `.ico` file **in the category's folder**.
    #[serde(default)]
    pub file: Option<String>,
    /// A plain `https://` link, downloaded once and cached.
    #[serde(default)]
    pub url: Option<String>,
    /// A Flathub app id (`org.gnome.Builder`) or a flathub.org link. The
    /// download link is built here — only the id is ever written by hand.
    #[serde(default)]
    pub flathub: Option<String>,
}

impl CategoryIcon {
    /// The sources in the order the thumbnail module tries them. A `flathub`
    /// id becomes the link of Flathub's own 128×128 icon, so the resolver
    /// needs no Flathub-specific code.
    pub fn sources(&self) -> Vec<IconSource> {
        if let Some(f) = self.file.clone() {
            return vec![IconSource { file: Some(f), theme: None, url: None }];
        }
        if let Some(u) = self.url.clone() {
            return vec![IconSource { file: None, theme: None, url: Some(u) }];
        }
        if let Some(id) = self.flathub.as_deref().and_then(crate::remote::flathub_icon_url) {
            return vec![IconSource { file: None, theme: None, url: Some(id) }];
        }
        Vec::new()
    }

    fn validate(&self) -> Result<(), String> {
        let set = [self.file.is_some(), self.url.is_some(), self.flathub.is_some()]
            .iter()
            .filter(|b| **b)
            .count();
        if set != 1 {
            return Err("icon needs exactly one of file / url / flathub".into());
        }
        if self.file.as_deref().is_some_and(|f| !is_valid_icon_file_name(f)) {
            return Err("icon file must be a bare .svg/.png/.ico file name in the category's folder".into());
        }
        if self.url.as_deref().is_some_and(|u| !is_valid_icon_url(u)) {
            return Err("icon url must be a plain https:// link".into());
        }
        if self.flathub.as_deref().is_some_and(|f| crate::remote::flathub_app_id(f).is_none()) {
            return Err("icon flathub must be an app id like org.gnome.Builder or a flathub.org link".into());
        }
        Ok(())
    }
}

/// One custom add-on category, as written in `<folder>/<folder>.json`.
#[derive(Debug, Clone, PartialEq, Eq, Serialize, Deserialize)]
#[serde(deny_unknown_fields)]
pub struct AddonCategory {
    #[serde(default = "default_schema")]
    pub schema: u32,
    /// The folder name and the word add-on packages use in `categories`.
    pub id: String,
    pub title: String,
    #[serde(default)]
    pub description: String,
    /// The category row's picture. Without one the first letter is shown.
    #[serde(default)]
    pub icon: Option<CategoryIcon>,
}

fn default_schema() -> u32 {
    1
}

/// A category that was read and validated, plus where it came from.
#[derive(Debug, Clone)]
pub struct LoadedCategory {
    pub category: AddonCategory,
    /// The JSON's path (its folder holds the `file` icons).
    pub path: PathBuf,
}

impl LoadedCategory {
    /// The folder holding the JSON (and its `file` pictures).
    pub fn dir(&self) -> Option<&Path> {
        self.path.parent()
    }
}

/// A category id is the folder name: lowercase letters, digits and `- _ . +`
/// only (the same rule as an add-on id, so it is also a valid icon cache key).
pub fn is_valid_category_id(id: &str) -> bool {
    !id.is_empty()
        && id.len() <= MAX_ID
        && !id.starts_with(['-', '.'])
        && id.bytes().all(|b| b.is_ascii_lowercase() || b.is_ascii_digit() || matches!(b, b'-' | b'_' | b'.' | b'+'))
}

/// Cache key of a category's thumbnail (`addon-category-<id>`). It passes
/// `is_valid_package_name`, so the UI may request it like any package icon.
pub fn category_icon_key(id: &str) -> String {
    format!("addon-category-{id}")
}

impl AddonCategory {
    pub fn validate(&self) -> Result<(), String> {
        if self.schema != 1 {
            return Err(format!("unsupported schema {} (supported: 1)", self.schema));
        }
        if !is_valid_category_id(&self.id) {
            return Err(format!("invalid id {:?} (lowercase letters, digits, - _ . + only)", self.id));
        }
        let title = self.title.trim();
        if title.is_empty() || self.title.len() > 80 {
            return Err("title must be 1..=80 characters".into());
        }
        if self.description.len() > MAX_TEXT {
            return Err("description is too long".into());
        }
        if let Some(icon) = &self.icon {
            icon.validate()?;
        }
        Ok(())
    }
}

/// Read every category in one directory. A folder is read when it holds
/// `<folder>.json` (or exactly one `.json`); anything invalid is logged and
/// skipped so one broken category never hides the others.
pub fn load_dir(dir: &Path) -> Vec<LoadedCategory> {
    let mut folders: Vec<PathBuf> = fs::read_dir(dir)
        .map(|rd| rd.flatten().map(|e| e.path()).filter(|p| p.is_dir()).collect())
        .unwrap_or_default();
    folders.sort();
    let mut out = Vec::new();
    for folder in folders {
        let Some(name) = folder.file_name().and_then(|n| n.to_str()).map(str::to_string) else {
            continue;
        };
        let path = if folder.join(format!("{name}.json")).is_file() {
            folder.join(format!("{name}.json"))
        } else {
            let mut jsons: Vec<PathBuf> = fs::read_dir(&folder)
                .map(|rd| rd.flatten().map(|e| e.path()).filter(|p| p.extension().is_some_and(|e| e == "json")).collect())
                .unwrap_or_default();
            jsons.sort();
            match jsons.as_slice() {
                [only] => only.clone(),
                _ => {
                    log::warn!("add-on category {:?}: expected {name}.json or exactly one .json", folder);
                    continue;
                }
            }
        };
        match load_file(&path) {
            Ok(category) => {
                if category.id != name {
                    log::warn!(
                        "add-on category {}: id {:?} must match the folder name {:?}",
                        path.display(),
                        category.id,
                        name
                    );
                    continue;
                }
                out.push(LoadedCategory { category, path });
            }
            Err(e) => log::warn!("add-on category {}: {e}", path.display()),
        }
        if out.len() >= MAX_CATEGORIES {
            log::warn!("add-on categories under {}: only the first {MAX_CATEGORIES} are read", dir.display());
            break;
        }
    }
    out
}

fn load_file(path: &Path) -> Result<AddonCategory, String> {
    let meta = fs::metadata(path).map_err(|e| e.to_string())?;
    if !meta.is_file() {
        return Err("not a file".into());
    }
    if meta.len() > MAX_FILE_BYTES {
        return Err(format!("file is larger than {} KiB", MAX_FILE_BYTES / 1024));
    }
    let text = fs::read_to_string(path).map_err(|e| e.to_string())?;
    let category: AddonCategory = serde_json::from_str(&text).map_err(|e| e.to_string())?;
    category.validate()?;
    Ok(category)
}

/// Shipped categories first, then the user's. The first category with a given
/// id wins, so a user folder can add a category but never replace a shipped one.
pub fn load_all() -> Vec<LoadedCategory> {
    let mut all = load_dir(&paths::system_addon_categories_dir());
    all.extend(load_dir(&paths::user_addon_categories_dir()));
    let mut seen = HashSet::new();
    all.retain(|l| {
        let fresh = seen.insert(l.category.id.clone());
        if !fresh {
            log::warn!("add-on category {}: duplicate id {:?} ignored", l.path.display(), l.category.id);
        }
        fresh
    });
    all
}

#[cfg(test)]
mod tests {
    use super::*;

    fn sample() -> AddonCategory {
        serde_json::from_str(
            r#"{"id":"artcraft","title":"ArtCraft","description":"Craft apps",
                "icon":{"file":"artcraft.svg"}}"#,
        )
        .unwrap()
    }

    #[test]
    fn valid_category_loads() {
        let c = sample();
        c.validate().unwrap();
        assert_eq!(c.schema, 1);
        assert_eq!(c.icon.as_ref().unwrap().sources()[0].file.as_deref(), Some("artcraft.svg"));
    }

    #[test]
    fn icon_needs_exactly_one_source() {
        let mut c = sample();
        c.icon = Some(CategoryIcon {
            file: Some("x.svg".into()),
            url: Some("https://a/b.png".into()),
            flathub: None,
        });
        assert!(c.validate().is_err());
        c.icon = Some(CategoryIcon::default());
        assert!(c.validate().is_err());
    }

    #[test]
    fn flathub_icon_becomes_a_trusted_link() {
        let icon = CategoryIcon { flathub: Some("org.gnome.Builder".into()), ..Default::default() };
        let sources = icon.sources();
        assert_eq!(sources.len(), 1);
        let url = sources[0].url.as_deref().unwrap();
        assert_eq!(url, "https://dl.flathub.org/media/icons/128x128/org.gnome.Builder.png");
        assert!(crate::remote::is_trusted_image_url(url));
    }

    #[test]
    fn ids_are_folder_safe() {
        assert!(is_valid_category_id("artcraft"));
        assert!(is_valid_category_id("craft-2"));
        assert!(!is_valid_category_id("ArtCraft"));
        assert!(!is_valid_category_id("../etc"));
        assert!(!is_valid_category_id(""));
        let key = category_icon_key("artcraft");
        assert!(crate::text::is_valid_package_name(&key));
    }

    #[test]
    fn shipped_categories_are_valid() {
        let dir = Path::new(env!("CARGO_MANIFEST_DIR")).join("../../data/addon_categories");
        if !dir.is_dir() {
            return;
        }
        let folders = fs::read_dir(&dir).unwrap().flatten().filter(|e| e.path().is_dir()).count();
        let found = load_dir(&dir);
        assert_eq!(found.len(), folders, "a shipped add-on category failed to validate (see warnings)");
        for l in &found {
            // A "file" icon must really exist next to the JSON.
            if let Some(icon) = &l.category.icon {
                if let Some(f) = &icon.file {
                    let p = l.dir().unwrap().join(f);
                    assert!(p.is_file(), "missing icon {}", p.display());
                }
            }
        }
    }
}
