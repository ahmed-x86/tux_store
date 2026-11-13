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
    let (discovered, components) = tux_appstream::discover_with_components(&paths::cache_dir());
    let names: HashMap<String, (String, String)> = components
        .iter()
        .map(|c| (c.pkg.clone(), (c.name.clone(), c.summary.clone())))
        .collect();

    let mut category_packages: HashMap<String, Vec<String>> = HashMap::new();
    let mut categories = Vec::new();
    for bucket in &discovered.buckets {
        // A stale catalog may list packages that no longer exist: join with pacman.
        let pkgs: Vec<String> = bucket
            .packages
            .iter()
            .filter(|p| index.get(p).is_some() || index.is_installed(p))
            .cloned()
            .collect();
        if pkgs.is_empty() {
            continue;
        }
        let installed = pkgs.iter().filter(|p| index.is_installed(p)).count();
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
    TaxonomyState { message, index, groups, category_packages, names }
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
    let mut list: Vec<Package> = match kind {
        TaxonomyKind::Repository => state.index.repo_packages(id),
        TaxonomyKind::Group => state
            .groups
            .get(id)
            .map(|members| members.iter().map(|m| state.index.package(m)).collect())
            .unwrap_or_default(),
        TaxonomyKind::Category => state
            .category_packages
            .get(id)
            .map(|pkgs| {
                pkgs.iter()
                    .map(|p| {
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
