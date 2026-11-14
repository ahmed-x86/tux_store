//! The side menu's data: repositories, groups and categories, joined with
//! pacman's sync database so every row carries real counts.
//!
//! Nothing is hardcoded here: repositories come from `pacman.conf`, groups from
//! `pacman -Sg` ∪ `pacman -Qg`, categories from the AppStream catalogs and the
//! system category tree (`libappstream`). See `DOCS/TAXONOMY.md`.

use std::collections::{BTreeMap, HashMap};
use tux_abi::{paths, Message, Package, Taxonomy, TaxonomyEntry, TaxonomyKind};
use tux_pacman::taxonomy::{self, SyncIndex};

/// Everything the side menu needs, discovered once and kept until the system
/// changes (install/remove, engine switch).
pub struct TaxonomyState {
    pub message: Taxonomy,
    pub index: SyncIndex,
    pub groups: BTreeMap<String, Vec<String>>,
    pub category_packages: HashMap<String, Vec<String>>,
    /// pkgname → (AppStream display name, summary)
    pub names: HashMap<String, (String, String)>,
    /// Add-on package id → the package row shown in category lists.
    pub scripts: HashMap<String, Package>,
}

/// Discover every section of the side menu. Blocking; runs on a worker thread.
pub fn build() -> TaxonomyState {
    let index = SyncIndex::load();
    let repositories = index.repository_entries();

    // Groups: sync databases UNION installed packages (local/AUR-only groups).
    let group_list = taxonomy::discover_groups();
    let groups: BTreeMap<String, Vec<String>> =
        group_list.iter().map(|g| (g.name.clone(), g.members.clone())).collect();
    let group_entries = taxonomy::group_entries(&group_list, &index);

    // Categories: AppStream catalogs joined with the system category tree.
    let (mut discovered, components) = tux_appstream::discover_with_components(&paths::cache_dir());
    let names: HashMap<String, (String, String)> = components
        .iter()
        .map(|c| (c.pkg.clone(), (c.name.clone(), c.summary.clone())))
        .collect();

    let is_pkg_hidden = |p: &str| {
        if tux_abi::hidden::is_hidden(p) {
            return true;
        }
        if let Some((name, _)) = names.get(p) {
            if tux_abi::hidden::is_hidden(name) {
                return true;
            }
        }
        false
    };

    // Add-on packages are not in AppStream: their JSON says which category
    // they belong to. Put them into the matching bucket before counting.
    let loaded_scripts = tux_abi::script::load_all();
    let scripts: HashMap<String, Package> =
        loaded_scripts.iter().map(|l| (l.script.id.clone(), l.script.package())).collect();
    for loaded in &loaded_scripts {
        let target = loaded.script.category.trim();
        if target.is_empty() {
            continue;
        }
        let Some(pkg) = scripts.get(&loaded.script.id) else { continue };
        if is_pkg_hidden(&pkg.name) || (!pkg.title.is_empty() && tux_abi::hidden::is_hidden(&pkg.title)) {
            continue;
        }
        let Some(bucket) =
            discovered.buckets.iter_mut().find(|b| category_matches(&b.id, &b.title, target))
        else {
            log::warn!(
                "script {}: category {:?} does not exist on this system",
                loaded.script.id,
                target
            );
            continue;
        };
        if !bucket.packages.iter().any(|p| p == &pkg.name) {
            bucket.packages.push(pkg.name.clone());
        }
    }

    let mut category_packages: HashMap<String, Vec<String>> = HashMap::new();
    let mut categories = Vec::new();
    for bucket in &discovered.buckets {
        // A stale catalog may list packages that no longer exist: join with
        // pacman. Add-on packages (scripts) are known without that join.
        let pkgs: Vec<String> = bucket
            .packages
            .iter()
            .filter(|p| {
                !is_pkg_hidden(p)
                    && (scripts.contains_key(p.as_str())
                        || index.get(p).is_some()
                        || index.is_installed(p))
            })
            .cloned()
            .collect();
        if pkgs.is_empty() {
            continue;
        }
        let installed = pkgs
            .iter()
            .filter(|p| {
                scripts
                    .get(p.as_str())
                    .map_or_else(|| index.is_installed(p), |s| s.installed)
            })
            .count();
        category_packages.insert(bucket.id.clone(), pkgs.clone());
        categories.push(TaxonomyEntry {
            id: bucket.id.clone(),
            title: bucket.title.clone(),
            subtitle: taxonomy::counts(pkgs.len(), installed),
            packages: pkgs.len(),
            installed,
            icon: bucket.icon.clone(),
            depth: bucket.depth,
            parent: bucket.parent.clone(),
            ..Default::default()
        });
    }

    let message = Taxonomy {
        repositories,
        groups: group_entries,
        categories,
        raw_categories: discovered.raw,
        category_source: discovered.source,
    };
    TaxonomyState { message, index, groups, category_packages, names, scripts }
}

/// AppStream ids and titles both work, in any case; spaces, `&`, `_`, `-`
/// and `/` are ignored so `Audio & Video`, `audio-video` and
/// `raw:AudioVideo` all name the same category.
fn category_matches(id: &str, title: &str, target: &str) -> bool {
    let id = id.strip_prefix("raw:").unwrap_or(id);
    let target = target.trim();
    !target.is_empty()
        && (id.eq_ignore_ascii_case(target)
            || title.eq_ignore_ascii_case(target)
            || category_key(id) == category_key(target)
            || category_key(title) == category_key(target))
}

fn category_key(s: &str) -> String {
    s.chars().filter(|c| c.is_ascii_alphanumeric()).flat_map(char::to_lowercase).collect()
}

pub fn display_name(p: &Package) -> &str {
    if p.title.is_empty() {
        &p.name
    } else {
        &p.title
    }
}

/// Installed first, then A-Z by display name, case-insensitive.
pub fn sort_by_display(list: &mut [Package]) {
    list.sort_by(|a, b| {
        b.installed
            .cmp(&a.installed)
            .then_with(|| display_name(a).to_lowercase().cmp(&display_name(b).to_lowercase()))
            .then_with(|| a.name.cmp(&b.name))
    });
}

/// The complete list of one repo / group / category (installed or not).
pub fn packages_for(state: &TaxonomyState, kind: TaxonomyKind, id: &str) -> Message {
    let list: Vec<Package> = match kind {
        TaxonomyKind::Repository => state.index.repo_packages(id),
        TaxonomyKind::Group => state
            .groups
            .get(id)
            .map(|members| {
                members
                    .iter()
                    .filter(|m| !tux_abi::hidden::is_hidden(m))
                    .map(|m| state.index.package(m))
                    .collect()
            })
            .unwrap_or_default(),
        TaxonomyKind::Category => state
            .category_packages
            .get(id)
            .map(|pkgs| {
                pkgs.iter()
                    .filter(|p| !tux_abi::hidden::is_hidden(p))
                    .map(|p| {
                        if let Some(pkg) = state.scripts.get(p) {
                            return pkg.clone();
                        }
                        let mut pkg = state.index.package(p);
                        if let Some((name, summary)) = state.names.get(p) {
                            pkg.title = name.clone();
                            if pkg.description.is_empty() {
                                pkg.description = summary.clone();
                            }
                        }
                        pkg
                    })
                    .collect()
            })
            .unwrap_or_default(),
    };

    let mut list = tux_abi::hidden::filter_packages(list);
    let installed = list.iter().filter(|p| p.installed).count();
    sort_by_display(&mut list);
    let title = match kind {
        TaxonomyKind::Category => state
            .message
            .categories
            .iter()
            .find(|c| c.id == id)
            .map(|c| c.title.clone())
            .unwrap_or_else(|| id.to_string()),
        _ => id.to_string(),
    };
    Message::TaxonomyPackagesReady {
        kind,
        id: id.to_string(),
        title,
        subtitle: taxonomy::counts(list.len(), installed),
        packages: list,
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn categories_match_ids_and_titles() {
        assert!(category_matches("audio-video", "Audio & Video", "audio-video"));
        assert!(category_matches("audio-video", "Audio & Video", "Audio & Video"));
        assert!(category_matches("audio-video", "Audio & Video", "Audio Video"));
        assert!(category_matches("raw:AudioVideo", "Audio Video", "audio-video"));
        assert!(category_matches("communication", "Communication & News", "communication"));
        assert!(category_matches("developer-tools", "Developer Tools", "developer-tools"));
        assert!(!category_matches("audio-video", "Audio & Video", "games"));
        assert!(!category_matches("audio-video", "Audio & Video", ""));
    }

    #[test]
    fn hidden_packages_filtered_from_taxonomy() {
        assert!(tux_abi::hidden::is_hidden("xiphos"));
        assert!(tux_abi::hidden::is_hidden("Xiphos"));
        assert!(tux_abi::hidden::is_hidden("bibletime"));
        assert!(tux_abi::hidden::is_hidden("BibleTime"));

        let state = build();
        for cat in &state.message.categories {
            if let Some(pkgs) = state.category_packages.get(&cat.id) {
                for p in pkgs {
                    assert!(!tux_abi::hidden::is_hidden(p), "Category {} contains hidden pkg {}", cat.id, p);
                }
            }
        }

        for (grp_name, members) in &state.groups {
            for m in members {
                assert!(!tux_abi::hidden::is_hidden(m), "Group {} contains hidden pkg {}", grp_name, m);
            }
        }

        let repo_msg = packages_for(&state, TaxonomyKind::Repository, "extra");
        if let Message::TaxonomyPackagesReady { packages, .. } = repo_msg {
            for p in &packages {
                assert!(!tux_abi::hidden::is_hidden(&p.name), "Repo extra contains hidden package {}", p.name);
            }
        }
    }
}
