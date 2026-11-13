//! `tux-appstream` — the Categories section of Tux Store.
//!
//! AppStream is the only source of application categories: pacman has none.
//! Three things are discovered at runtime and joined here:
//!
//! 1. which components exist and which raw category ids they carry
//!    ([`catalog`], from `/usr/share/swcatalog/xml/*.xml.gz` and friends);
//! 2. how those raw ids become display categories ([`tree`], the system's own
//!    default category tree);
//! 3. which packages really exist (done by the caller with the pacman index).
//!
//! No category name, icon, count or membership is hardcoded.

pub mod catalog;
pub mod tree;

use catalog::Component;
use std::collections::{BTreeMap, BTreeSet};
use std::path::Path;

/// A display category with the packages that belong to it.
#[derive(Debug, Clone, Default, PartialEq, Eq)]
pub struct Bucket {
    /// Stable id (`audio-video`, `games/strategy`, `other`, `raw:AudioVideo`).
    pub id: String,
    pub title: String,
    pub icon: String,
    pub depth: u32,
    pub parent: String,
    /// Distinct package names, A-Z.
    pub packages: Vec<String>,
}

#[derive(Debug, Clone, Default)]
pub struct Discovered {
    pub buckets: Vec<Bucket>,
    /// Every raw category id found in the catalogs and its component count.
    pub raw: Vec<(String, usize)>,
    /// `"libappstream"` or `"raw-ids"`.
    pub source: String,
}

pub fn discover(cache_dir: &Path) -> Discovered {
    discover_with_components(cache_dir).0
}

/// Same, but also hands back the parsed components (the caller needs the
/// display name and summary of every package it lists).
pub fn discover_with_components(cache_dir: &Path) -> (Discovered, Vec<Component>) {
    let components = catalog::load(cache_dir);
    (build_from(&components), components)
}

fn build_from(components: &[Component]) -> Discovered {
    let mut raw: BTreeMap<String, BTreeSet<String>> = BTreeMap::new();
    for c in components {
        for cat in &c.categories {
            raw.entry(cat.clone()).or_default().insert(c.pkg.clone());
        }
    }

    let nodes = tree::categories();
    if nodes.is_empty() {
        return Discovered { buckets: raw_ids(&raw), raw: raw_counts(&raw), source: "raw-ids".into() };
    }

    let mut buckets = build(&nodes, components);
    if let Some(other) = other_bucket(&nodes, &raw) {
        buckets.push(other);
    }
    Discovered { buckets, raw: raw_counts(&raw), source: "libappstream".into() }
}

fn raw_counts(raw: &BTreeMap<String, BTreeSet<String>>) -> Vec<(String, usize)> {
    raw.iter().map(|(k, v)| (k.clone(), v.len())).collect()
}

/// The raw id a tree entry points at: `Development::IDE` and
/// `Development:Debugger` both name a leaf (`IDE`, `Debugger`), while a plain
/// `AudioVideo` names itself.
fn leaf(descriptor: &str) -> &str {
    descriptor.rsplit(':').next().unwrap_or(descriptor)
}

fn build(nodes: &[tree::TreeCategory], components: &[Component]) -> Vec<Bucket> {
    // raw id -> nodes that claim it
    let mut claim: BTreeMap<&str, Vec<usize>> = BTreeMap::new();
    for (i, node) in nodes.iter().enumerate() {
        for g in &node.groups {
            let id = leaf(g);
            if !id.is_empty() {
                claim.entry(id).or_default().push(i);
            }
        }
    }

    let mut sets: Vec<BTreeSet<String>> = vec![BTreeSet::new(); nodes.len()];
    for c in components {
        for cat in &c.categories {
            if let Some(indices) = claim.get(cat.as_str()) {
                for &i in indices {
                    sets[i].insert(c.pkg.clone());
                }
            }
        }
    }

    nodes
        .iter()
        .zip(sets)
        .filter(|(_, set)| !set.is_empty()) // hide empty categories
        .map(|(node, set)| Bucket {
            id: node.id.clone(),
            title: if node.title.is_empty() { node.id.clone() } else { node.title.clone() },
            icon: node.icon.clone(),
            depth: node.depth,
            parent: node.parent.clone(),
            packages: set.into_iter().collect(),
        })
        .collect()
}

/// Raw ids that no node claims, together in one "Other" row (never dropped).
fn other_bucket(nodes: &[tree::TreeCategory], raw: &BTreeMap<String, BTreeSet<String>>) -> Option<Bucket> {
    let claimed: BTreeSet<&str> = nodes.iter().flat_map(|n| n.groups.iter().map(|g| leaf(g))).collect();
    let mut packages: BTreeSet<String> = BTreeSet::new();
    let mut any = false;
    for (id, pkgs) in raw {
        if !claimed.contains(id.as_str()) {
            any = true;
            packages.extend(pkgs.iter().cloned());
        }
    }
    any.then(|| Bucket {
        id: "other".into(),
        title: "Other".into(),
        icon: "applications-other".into(),
        depth: 0,
        parent: String::new(),
        packages: packages.into_iter().collect(),
    })
}

/// Documented fallback: one category per raw id, the id humanized.
fn raw_ids(raw: &BTreeMap<String, BTreeSet<String>>) -> Vec<Bucket> {
    raw.iter()
        .filter(|(_, pkgs)| !pkgs.is_empty())
        .map(|(id, pkgs)| Bucket {
            id: format!("raw:{id}"),
            title: humanize(id),
            icon: String::new(),
            depth: 0,
            parent: String::new(),
            packages: pkgs.iter().cloned().collect(),
        })
        .collect()
}

fn humanize(id: &str) -> String {
    let mut out = String::new();
    let mut prev_lower = false;
    for ch in id.chars() {
        if ch == '_' || ch == '-' {
            out.push(' ');
            prev_lower = false;
            continue;
        }
        if ch.is_uppercase() && prev_lower {
            out.push(' ');
        }
        out.push(ch);
        prev_lower = ch.is_lowercase();
    }
    out
}

#[cfg(test)]
mod tests {
    use super::*;

    fn node(id: &str, title: &str, depth: u32, parent: &str, groups: &[&str]) -> tree::TreeCategory {
        tree::TreeCategory {
            id: id.into(),
            title: title.into(),
            icon: String::new(),
            depth,
            parent: parent.into(),
            groups: groups.iter().map(|s| s.to_string()).collect(),
        }
    }

    #[test]
    fn every_raw_id_ends_up_somewhere() {
        let nodes = vec![
            node("audio-video", "Audio & Video", 0, "", &["AudioVideo"]),
            node("audio-video/music", "Music Players", 1, "audio-video", &["AudioVideo::Music", "AudioVideo::Player"]),
            node("development", "Developer Tools", 0, "", &["Development:Debugger", "Development"]),
            node("development/ide", "IDEs", 1, "development", &["Development::IDE"]),
            node("empty", "Empty", 0, "", &["Nothing"]),
        ];
        let components = vec![
            Component {
                pkg: "gimp".into(),
                name: "GIMP".into(),
                summary: "s".into(),
                categories: vec!["AudioVideo".into(), "Music".into()],
            },
            Component {
                pkg: "code".into(),
                name: "Code".into(),
                summary: "s".into(),
                categories: vec!["Development".into(), "IDE".into()],
            },
            Component {
                pkg: "weird".into(),
                name: String::new(),
                summary: String::new(),
                categories: vec!["Unclaimed".into()],
            },
        ];
        let mut raw: BTreeMap<String, BTreeSet<String>> = BTreeMap::new();
        for c in &components {
            for cat in &c.categories {
                raw.entry(cat.clone()).or_default().insert(c.pkg.clone());
            }
        }

        let buckets = build(&nodes, &components);
        let find = |id: &str| buckets.iter().find(|b| b.id == id).unwrap();
        assert_eq!(find("audio-video").packages.len(), 1);
        assert_eq!(find("audio-video/music").packages.len(), 1);
        // gimp has Music + AudioVideo, so it is in both; code is in Development + IDE.
        assert_eq!(find("development").packages, vec!["code".to_string()]);
        assert_eq!(find("development/ide").packages, vec!["code".to_string()]);
        // Empty categories are hidden.
        assert!(!buckets.iter().any(|b| b.id == "empty"));

        let other = other_bucket(&nodes, &raw).unwrap();
        assert_eq!(other.packages, vec!["weird".to_string()]);
        assert!(!buckets.iter().any(|b| b.id == "other"));
    }

    #[test]
    fn humanized_fallback() {
        assert_eq!(humanize("AudioVideo"), "Audio Video");
        assert_eq!(humanize("X-GNOME-Settings-Panel"), "X GNOME Settings Panel");
    }

    #[test]
    fn leaves() {
        assert_eq!(leaf("AudioVideo"), "AudioVideo");
        assert_eq!(leaf("AudioVideo::Music"), "Music");
        assert_eq!(leaf("Development:Debugger"), "Debugger");
    }
}
