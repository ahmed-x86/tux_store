//! Repositories, groups and group families — discovered, never hardcoded.
//!
//! The rules implemented here are the ones validated on a real Arch machine
//! (see `DOCS/TAXONOMY.md` and the `arch-store-taxonomy` skill):
//!
//! * **Repositories** come from `pacman.conf` in registration order; the
//!   "Official" badge is derived from the system mirrorlist, never from a name.
//! * **Groups** are the groups of all sync databases UNION the groups of all
//!   installed packages (so local/AUR-only groups such as `cs50` or `selinux`
//!   are listed too), sorted in plain byte order (C locale).
//! * **Families** collapse groups that share a whole leading word
//!   (`gnome`, `gnome-extra`, `gnome-circle` → one `gnome` row) without ever
//!   merging unrelated words (`kde` must not swallow `kdevelop`).

use crate::localdb;
use crate::runner;
use std::collections::{BTreeMap, BTreeSet, HashMap, HashSet};
use std::path::Path;
use std::time::Duration;
use tux_abi::paths;
use tux_abi::{Package, TaxonomyEntry};

const T_QUERY: Duration = Duration::from_secs(20);

// ───────────────────────────── URLs / mirrorlist ─────────────────────────────

/// Host of an HTTP(S) URL, lowercased. `$repo`/`$arch` variables do not touch
/// the host, so a raw `Server` line is enough.
pub fn url_host(url: &str) -> Option<String> {
    let (_, rest) = url.trim().split_once("://")?;
    let authority = rest.split('/').next()?.trim();
    let host = authority.rsplit('@').next()?; // drop any user:password@
    let host = host.split(':').next()?; // drop a port
    (!host.is_empty()).then(|| host.to_ascii_lowercase())
}

/// Hosts of `/etc/pacman.d/mirrorlist` — the mirrors the system itself uses.
pub fn mirrorlist_hosts() -> HashSet<String> {
    let text = std::fs::read_to_string("/etc/pacman.d/mirrorlist").unwrap_or_default();
    mirror_hosts_from(&text)
}

fn mirror_hosts_from(text: &str) -> HashSet<String> {
    text.lines()
        .filter_map(|l| {
            let l = l.trim();
            let rest = l.strip_prefix("Server")?;
            url_host(rest.split_once('=')?.1)
        })
        .collect()
}

/// `Server` URLs of one repository, as configured (expanded by pacman-conf).
pub fn repo_hosts(repo: &str) -> Vec<String> {
    let out = runner::run("pacman-conf", &["--repo", repo, "Server"], T_QUERY);
    out.stdout.lines().filter_map(url_host).collect()
}

/// The `[sections]` of `pacman.conf`, each with its own non-comment lines.
fn pacman_conf_sections() -> BTreeMap<String, Vec<String>> {
    let text = std::fs::read_to_string("/etc/pacman.conf").unwrap_or_default();
    conf_sections(&text)
}

fn conf_sections(text: &str) -> BTreeMap<String, Vec<String>> {
    let mut out: BTreeMap<String, Vec<String>> = BTreeMap::new();
    let mut current: Option<String> = None;
    for line in text.lines() {
        let line = line.trim();
        if line.is_empty() || line.starts_with('#') {
            continue;
        }
        if let Some(name) = line.strip_prefix('[').and_then(|l| l.strip_suffix(']')) {
            current = Some(name.trim().to_string());
            out.entry(name.trim().to_string()).or_default();
            continue;
        }
        if let Some(section) = &current {
            out.entry(section.clone()).or_default().push(line.to_string());
        }
    }
    out
}

/// A repo is official when its servers are the system's own mirrors. The
/// documented fallback is the repo including `/etc/pacman.d/mirrorlist`.
pub fn repo_is_official(repo: &str, mirrors: &HashSet<String>, conf: &BTreeMap<String, Vec<String>>) -> bool {
    let hosts = repo_hosts(repo);
    if !hosts.is_empty() && !mirrors.is_empty() && hosts.iter().all(|h| mirrors.contains(h)) {
        return true;
    }
    conf.get(repo).is_some_and(|lines| {
        lines.iter().any(|l| {
            l.strip_prefix("Include")
                .and_then(|r| r.split_once('='))
                .is_some_and(|(_, p)| p.trim() == "/etc/pacman.d/mirrorlist")
        })
    })
}

// ───────────────────────────── the sync index ─────────────────────────────

#[derive(Debug, Clone)]
pub struct SyncPackage {
    pub name: String,
    pub repo: String,
    pub version: String,
}

/// Every package of every configured sync database, plus the installed set.
/// Built from one `pacman -Sl` call and the local database on disk; it is the
/// join table for repos, groups and categories.
#[derive(Debug, Default, Clone)]
pub struct SyncIndex {
    /// `pacman.conf` order (priority order), never sorted.
    pub repos: Vec<String>,
    pub packages: Vec<SyncPackage>,
    /// name → position in `packages` (first repo wins, like pacman).
    by_name: HashMap<String, usize>,
    /// Installed packages read from `/var/lib/pacman/local`.
    local: HashMap<String, localdb::LocalPackage>,
}

impl SyncIndex {
    pub fn load() -> Self {
        let repos = repo_names();
        let local: HashMap<String, localdb::LocalPackage> =
            localdb::read_all().into_iter().map(|p| (p.name.clone(), p)).collect();

        let out = runner::run_pacman(&["-Sl"], T_QUERY);
        let mut packages = Vec::new();
        for line in out.stdout.lines() {
            let mut it = line.split_whitespace();
            let (Some(repo), Some(name), Some(version)) = (it.next(), it.next(), it.next()) else {
                continue;
            };
            packages.push(SyncPackage {
                name: name.to_string(),
                repo: repo.to_string(),
                version: version.to_string(),
            });
        }

        let mut index = SyncIndex { repos, packages, by_name: HashMap::new(), local };
        // `pacman -Sl` walks the databases in the configured order: first wins.
        for (i, p) in index.packages.iter().enumerate() {
            index.by_name.entry(p.name.clone()).or_insert(i);
        }
        if index.repos.is_empty() {
            let mut seen = Vec::new();
            for p in &index.packages {
                if !seen.iter().any(|r| r == &p.repo) {
                    seen.push(p.repo.clone());
                }
            }
            index.repos = seen;
        }
        index
    }

    pub fn get(&self, name: &str) -> Option<&SyncPackage> {
        self.by_name.get(name).map(|&i| &self.packages[i])
    }

    pub fn is_installed(&self, name: &str) -> bool {
        self.local.contains_key(name)
    }

    /// Every package of one repo, in `pacman -Sl` order.
    pub fn repo_packages(&self, repo: &str) -> Vec<Package> {
        self.packages
            .iter()
            .filter(|p| p.repo == repo && !tux_abi::hidden::is_hidden(&p.name))
            .map(|p| Package {
                name: p.name.clone(),
                repo: p.repo.clone(),
                version: p.version.clone(),
                installed: self.is_installed(&p.name),
                ..Default::default()
            })
            .collect()
    }

    /// One package, using the sync databases first and the local database for
    /// foreign/AUR packages; unknown names come back with repo `aur`.
    pub fn package(&self, name: &str) -> Package {
        if let Some(p) = self.get(name) {
            return Package {
                name: p.name.clone(),
                repo: p.repo.clone(),
                version: p.version.clone(),
                installed: self.is_installed(name),
                ..Default::default()
            };
        }
        match self.local.get(name) {
            Some(lp) => Package {
                name: lp.name.clone(),
                repo: "aur".into(),
                version: lp.version.clone(),
                description: lp.description.clone(),
                installed: true,
                ..Default::default()
            },
            None => Package {
                name: name.to_string(),
                repo: "aur".into(),
                version: "unknown".into(),
                installed: false,
                ..Default::default()
            },
        }
    }

    pub fn repository_entries(&self) -> Vec<TaxonomyEntry> {
        let mirrors = mirrorlist_hosts();
        let conf = pacman_conf_sections();
        self.repos
            .iter()
            .map(|repo| {
                let list = self.repo_packages(repo);
                let installed = list.iter().filter(|p| p.installed).count();
                let official = repo_is_official(repo, &mirrors, &conf);
                TaxonomyEntry {
                    id: repo.clone(),
                    title: repo.clone(),
                    subtitle: counts(list.len(), installed),
                    badge: if official { "Official".into() } else { "Third-party".into() },
                    packages: list.len(),
                    installed,
                    ..Default::default()
                }
            })
            .collect()
    }
}

pub fn repo_names() -> Vec<String> {
    let out = runner::run("pacman-conf", &["--repo-list"], T_QUERY);
    out.stdout
        .lines()
        .map(str::trim)
        .filter(|l| !l.is_empty())
        .map(String::from)
        .collect()
}

pub fn counts(packages: usize, installed: usize) -> String {
    let p = if packages == 1 { "package" } else { "packages" };
    format!("{packages} {p} · {installed} installed")
}

/// Installed first, then A-Z by display name, case-insensitive (the order the
/// reference behaviour uses inside every package list).
pub fn sort_packages(list: &mut [Package]) {
    list.sort_by(|a, b| {
        b.installed
            .cmp(&a.installed)
            .then_with(|| a.name.to_lowercase().cmp(&b.name.to_lowercase()))
            .then_with(|| a.name.cmp(&b.name))
    });
}

// ───────────────────────────── groups ─────────────────────────────

#[derive(Debug, Clone, Default, PartialEq, Eq)]
pub struct Group {
    pub name: String,
    /// Distinct package names (sync members UNION local members).
    pub members: Vec<String>,
    /// Declared only by an installed package that no repo provides (cs50…).
    pub local_only: bool,
}

fn pair(line: &str) -> Option<(String, String)> {
    let mut it = line.split_whitespace();
    Some((it.next()?.to_string(), it.next()?.to_string()))
}

/// `GROUP LIST = groups of all sync dbs UNION groups of all installed packages`.
pub fn discover_groups() -> Vec<Group> {
    let sync = runner::run_pacman(&["-Sgg"], T_QUERY);
    let local = runner::run_pacman(&["-Qg"], T_QUERY);

    let mut map: BTreeMap<String, BTreeSet<String>> = BTreeMap::new();
    for line in sync.stdout.lines() {
        if let Some((group, pkg)) = pair(line) {
            if !tux_abi::hidden::is_hidden(&pkg) {
                map.entry(group).or_default().insert(pkg);
            }
        }
    }
    // The local pass is what makes AUR-only groups visible at all.
    let mut local_groups: BTreeSet<String> = BTreeSet::new();
    let mut extra: BTreeMap<String, BTreeSet<String>> = BTreeMap::new();
    for line in local.stdout.lines() {
        if let Some((group, pkg)) = pair(line) {
            if !tux_abi::hidden::is_hidden(&pkg) {
                local_groups.insert(group.clone());
                extra.entry(group).or_default().insert(pkg);
            }
        }
    }
    let mut local_only = BTreeSet::new();
    for group in local_groups {
        if !map.contains_key(&group) {
            local_only.insert(group.clone());
        }
        let members = extra.remove(&group).unwrap_or_default();
        map.entry(group).or_default().extend(members);
    }

    map.into_iter()
        .filter(|(_, members)| !members.is_empty())
        .map(|(name, members)| Group {
            local_only: local_only.contains(&name),
            name,
            members: members.into_iter().collect(),
        })
        .collect()
}

// ───────────────────────────── group families ─────────────────────────────

#[derive(Debug, Clone, serde::Deserialize)]
#[serde(default)]
pub struct FamilyConfig {
    pub min_family_size: usize,
    pub min_key_len: usize,
    pub never: BTreeSet<String>,
    pub aliases: BTreeMap<String, String>,
    pub force: BTreeMap<String, String>,
    pub labels: BTreeMap<String, String>,
    /// Hand-made families whose members do not share a first word.
    pub bundles: BTreeMap<String, Vec<String>>,
}

impl Default for FamilyConfig {
    fn default() -> Self {
        FamilyConfig {
            min_family_size: 2,
            min_key_len: 2,
            never: ["lib", "python", "perl", "ruby", "go", "rust"].iter().map(|s| s.to_string()).collect(),
            aliases: BTreeMap::from([("kubectl".to_string(), "kubernetes".to_string())]),
            force: BTreeMap::new(),
            labels: BTreeMap::from([
                ("kde".to_string(), "KDE".to_string()),
                ("gnome".to_string(), "GNOME".to_string()),
                ("xorg".to_string(), "Xorg".to_string()),
                ("kf".to_string(), "KDE Frameworks".to_string()),
                ("qt".to_string(), "Qt".to_string()),
                ("vst".to_string(), "VST plugins".to_string()),
            ]),
            bundles: BTreeMap::new(),
        }
    }
}

impl FamilyConfig {
    /// `data/group-families.json`, overridden by the user's own copy in
    /// `~/.config/tux-store/group-families.json` when it exists.
    pub fn load() -> Self {
        for file in [paths::data_dir().join("group-families.json"), paths::config_dir().join("group-families.json")] {
            if let Ok(text) = std::fs::read_to_string(&file) {
                match serde_json::from_str::<FamilyConfig>(&text) {
                    Ok(cfg) => return cfg,
                    Err(e) => log::warn!("{}: {e}", file.display()),
                }
            }
        }
        Self::default()
    }

    pub fn load_from(path: &Path) -> Self {
        std::fs::read_to_string(path)
            .ok()
            .and_then(|t| serde_json::from_str(&t).ok())
            .unwrap_or_default()
    }
}

/// Runs of ASCII letters or runs of ASCII digits; everything else separates
/// tokens (`gnome-circle` → [`gnome`, `circle`]).
pub fn tokens(name: &str) -> Vec<String> {
    let mut out = Vec::new();
    let mut cur = String::new();
    let mut cur_is_digit = false;
    for ch in name.chars().map(|c| c.to_ascii_lowercase()) {
        if ch.is_ascii_alphanumeric() {
            let d = ch.is_ascii_digit();
            if !cur.is_empty() && d != cur_is_digit {
                out.push(std::mem::take(&mut cur));
            }
            cur_is_digit = d;
            cur.push(ch);
        } else if !cur.is_empty() {
            out.push(std::mem::take(&mut cur));
        }
    }
    if !cur.is_empty() {
        out.push(cur);
    }
    out
}

/// The family key of a group: a whole leading word, never a character prefix.
pub fn family_key(name: &str, cfg: &FamilyConfig) -> String {
    if let Some(k) = cfg.force.get(name) {
        return k.clone();
    }
    let first = tokens(name).into_iter().next().unwrap_or_else(|| name.to_string());
    cfg.aliases.get(&first).cloned().unwrap_or(first)
}

#[derive(Debug, Clone, PartialEq, Eq)]
pub enum Entry {
    Family { key: String, groups: Vec<String> },
    Single(String),
}

impl Entry {
    pub fn key(&self) -> &str {
        match self {
            Entry::Family { key, .. } => key,
            Entry::Single(name) => name,
        }
    }
}

/// `groups` is the complete group list (sync UNION local). Nothing is dropped:
/// every group either forms a family or stays a single entry. Result sorted in
/// byte order.
pub fn build_entries(groups: &BTreeSet<String>, cfg: &FamilyConfig) -> Vec<Entry> {
    let mut remaining = groups.clone();
    let mut entries: Vec<Entry> = Vec::new();

    // Hand-made bundles first; their members leave the automatic pass.
    for (name, members) in &cfg.bundles {
        let present: Vec<String> = members.iter().filter(|m| remaining.contains(*m)).cloned().collect();
        for m in &present {
            remaining.remove(m);
        }
        if present.len() >= cfg.min_family_size {
            entries.push(Entry::Family { key: name.clone(), groups: present });
        } else {
            entries.extend(present.into_iter().map(Entry::Single));
        }
    }

    let mut buckets: BTreeMap<String, Vec<String>> = BTreeMap::new();
    for g in &remaining {
        buckets.entry(family_key(g, cfg)).or_default().push(g.clone());
    }
    for (key, members) in buckets {
        let ok = members.len() >= cfg.min_family_size
            && key.chars().count() >= cfg.min_key_len
            && !cfg.never.contains(&key)
            && !key.chars().all(|c| c.is_ascii_digit());
        if ok {
            entries.push(Entry::Family { key, groups: members });
        } else {
            entries.extend(members.into_iter().map(Entry::Single));
        }
    }

    entries.sort_by(|a, b| a.key().cmp(b.key()));
    entries
}

/// Rows of the Groups page, families collapsed (member rows have depth 1 and
/// `parent` = the family key).
pub fn group_entries(groups: &[Group], index: &SyncIndex) -> Vec<TaxonomyEntry> {
    let cfg = FamilyConfig::load();
    let by_name: BTreeMap<&str, &Group> = groups.iter().map(|g| (g.name.as_str(), g)).collect();
    let names: BTreeSet<String> = groups.iter().map(|g| g.name.clone()).collect();

    let single = |g: &Group, depth: u32, parent: &str| -> TaxonomyEntry {
        let installed = g.members.iter().filter(|m| index.is_installed(m)).count();
        TaxonomyEntry {
            id: g.name.clone(),
            title: g.name.clone(),
            subtitle: counts(g.members.len(), installed),
            badge: if g.local_only { "Local only".into() } else { String::new() },
            packages: g.members.len(),
            installed,
            depth,
            parent: parent.to_string(),
            ..Default::default()
        }
    };

    let mut out = Vec::new();
    for entry in build_entries(&names, &cfg) {
        match entry {
            Entry::Single(name) => {
                if let Some(g) = by_name.get(name.as_str()) {
                    out.push(single(g, 0, ""));
                }
            }
            Entry::Family { key, groups: members } => {
                // Base group first (a group named exactly like the key), then A-Z.
                let mut ordered: Vec<String> = members.iter().filter(|g| **g != key).cloned().collect();
                ordered.sort();
                if members.iter().any(|g| *g == key) {
                    ordered.insert(0, key.clone());
                }
                let distinct: BTreeSet<&str> = members
                    .iter()
                    .filter_map(|g| by_name.get(g.as_str()))
                    .flat_map(|g| g.members.iter().map(String::as_str))
                    .collect();
                let installed = distinct.iter().filter(|m| index.is_installed(m)).count();
                let label = cfg.labels.get(&key).cloned().unwrap_or_else(|| key.clone());
                out.push(TaxonomyEntry {
                    id: key.clone(),
                    title: label,
                    subtitle: format!(
                        "{} groups · {} packages · {installed} installed",
                        members.len(),
                        distinct.len()
                    ),
                    badge: "Family".into(),
                    packages: distinct.len(),
                    installed,
                    expandable: true,
                    ..Default::default()
                });
                for g in ordered {
                    if let Some(group) = by_name.get(g.as_str()) {
                        out.push(single(group, 1, &key));
                    }
                }
            }
        }
    }
    out
}

#[cfg(test)]
mod tests {
    use super::*;

    fn set(names: &[&str]) -> BTreeSet<String> {
        names.iter().map(|s| s.to_string()).collect()
    }

    #[test]
    fn whole_words_only() {
        let groups = set(&[
            "gnome", "gnome-circle", "gnome-extra", "kde-games", "kde-pim", "kdevelop", "libastal",
            "libreoffice-extensions", "libretro", "kf5", "kf6", "i3", "x-apps", "xfce4", "xfce4-goodies",
            "kubectl-plugins", "kubernetes-node", "cs50",
        ]);
        let cfg = FamilyConfig::default();
        let e = build_entries(&groups, &cfg);
        let fam = |k: &str| {
            e.iter().find_map(|x| match x {
                Entry::Family { key, groups } if key == k => Some(groups.clone()),
                _ => None,
            })
        };
        assert_eq!(fam("gnome").unwrap().len(), 3);
        assert_eq!(fam("kde").unwrap(), vec!["kde-games", "kde-pim"]); // kdevelop NOT inside
        assert_eq!(fam("kf").unwrap(), vec!["kf5", "kf6"]);
        assert_eq!(fam("xfce").unwrap().len(), 2);
        assert_eq!(fam("kubernetes").unwrap().len(), 2); // via the kubectl alias
        for s in ["kdevelop", "libastal", "libreoffice-extensions", "libretro", "i3", "x-apps", "cs50"] {
            assert!(e.iter().any(|x| matches!(x, Entry::Single(n) if n == s)), "{s} must stay single");
        }
    }

    #[test]
    fn nothing_lost_or_duplicated() {
        let groups = set(&["a1", "a2", "gnome", "gnome-extra", "kde-games", "kde-pim", "kf5", "kf6", "z"]);
        let e = build_entries(&groups, &FamilyConfig::default());
        let mut seen: Vec<String> = Vec::new();
        for entry in &e {
            match entry {
                Entry::Single(n) => seen.push(n.clone()),
                Entry::Family { groups, .. } => seen.extend(groups.iter().cloned()),
            }
        }
        seen.sort();
        assert_eq!(seen, groups.iter().cloned().collect::<Vec<_>>());
        let mut sorted = e.clone();
        sorted.sort_by(|a, b| a.key().cmp(b.key()));
        assert_eq!(sorted, e, "entries are in byte order");
    }

    #[test]
    fn short_and_digit_keys_never_form_families() {
        let groups = set(&["i3", "i4", "x1", "x2", "2fa", "3fa"]);
        let e = build_entries(&groups, &FamilyConfig::default());
        assert!(e.iter().all(|x| matches!(x, Entry::Single(_))));
    }

    #[test]
    fn never_list_blocks_generic_words() {
        let groups = set(&["python-a", "python-b", "rust-a", "rust-b"]);
        let e = build_entries(&groups, &FamilyConfig::default());
        assert_eq!(e.len(), 4);
        assert!(e.iter().all(|x| matches!(x, Entry::Single(_))));
    }

    #[test]
    fn bundles_are_hand_made() {
        let mut cfg = FamilyConfig::default();
        cfg.bundles.insert("Audio plugins".into(), vec!["lv2-plugins".into(), "vst-plugins".into()]);
        let groups = set(&["lv2-plugins", "vst-plugins", "vst3-plugins"]);
        let e = build_entries(&groups, &cfg);
        assert!(e.iter().any(|x| matches!(x, Entry::Family { key, groups }
            if key == "Audio plugins" && groups == &vec!["lv2-plugins".to_string(), "vst-plugins".to_string()])));
        // vst3-plugins still collapses with vst-plugins? No: vst-plugins left the
        // automatic pass, so vst3-plugins is alone and stays single.
        assert!(e.iter().any(|x| matches!(x, Entry::Single(n) if n == "vst3-plugins")));
    }

    #[test]
    fn tokenizer() {
        assert_eq!(tokens("gnome-circle"), ["gnome", "circle"]);
        assert_eq!(tokens("xfce4-goodies"), ["xfce", "4", "goodies"]);
        assert_eq!(tokens("mingw-w64-toolchain"), ["mingw", "w", "64", "toolchain"]);
        assert_eq!(tokens("kf6"), ["kf", "6"]);
    }

    #[test]
    fn urls_and_conf() {
        assert_eq!(url_host("https://mirror.example.org/arch/$repo/os/$arch").as_deref(), Some("mirror.example.org"));
        assert_eq!(url_host("http://user:pw@host.tld:8080/x").as_deref(), Some("host.tld"));
        assert_eq!(url_host("nonsense"), None);

        let conf = conf_sections("[core]\nInclude = /etc/pacman.d/mirrorlist\n[shamela]\nServer = https://github.com/x\n");
        assert_eq!(conf["core"], vec!["Include = /etc/pacman.d/mirrorlist"]);
        assert!(conf.contains_key("shamela"));
        let mirrors = mirror_hosts_from("Server = https://a.example/$repo/os/$arch\n#Server = https://b.example\n");
        assert!(mirrors.contains("a.example"));
        assert!(!mirrors.contains("b.example"));
    }
}
