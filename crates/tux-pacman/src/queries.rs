//! High-level pacman questions the UI asks. Everything here is blocking and
//! meant to run on a worker thread.

use crate::info::{parse_info, parse_size, InfoBlock};
use crate::{localdb, runner};
use std::collections::{HashMap, HashSet};
use std::time::Duration;
use tux_abi::text::is_valid_package_name;
use tux_abi::{Dependency, Package, PackageDetails, UpdateEntry};

const T_INFO: Duration = Duration::from_secs(10);
const T_PLAN: Duration = Duration::from_secs(20);
const T_SEARCH: Duration = Duration::from_secs(8);
const T_LIST: Duration = Duration::from_secs(15);
const T_CHECK: Duration = Duration::from_secs(60);

/// Cap for search results (the UI paginates them).
pub const SEARCH_LIMIT: usize = 200;

fn package_from_block(b: &InfoBlock) -> Option<Package> {
    Some(Package {
        name: b.get("Name")?.clone(),
        repo: b.get("Repository").cloned().unwrap_or_default(),
        version: b.get("Version").cloned().unwrap_or_default(),
        description: b.get("Description").cloned().unwrap_or_default(),
        installed: false,
        ..Default::default()
    })
}

/// Package that pacman does not know in its sync databases.
fn fallback_package(name: &str) -> Package {
    if let Some(lp) = localdb::read_one(name) {
        return Package {
            name: lp.name,
            repo: "aur".into(),
            version: lp.version,
            description: lp.description,
            installed: true,
            ..Default::default()
        };
    }
    Package {
        name: name.to_string(),
        repo: "aur".into(),
        version: "unknown".into(),
        description: "Not found in the synced repositories (probably an AUR package).".into(),
        installed: false,
        ..Default::default()
    }
}

/// Look up many packages with a single `pacman -Si` call. The result has
/// exactly one entry per requested name, in order.
pub fn packages_by_name(names: &[String]) -> Vec<Package> {
    let valid: Vec<&str> = names
        .iter()
        .map(String::as_str)
        .filter(|n| is_valid_package_name(n))
        .collect();
    let installed = localdb::installed_names();

    let mut found: HashMap<String, Package> = HashMap::new();
    if !valid.is_empty() {
        let mut args: Vec<&str> = vec!["-Si", "--"];
        args.extend(valid.iter().copied());
        let out = runner::run_pacman(&args, T_INFO);
        for block in parse_info(&out.stdout) {
            if let Some(p) = package_from_block(&block) {
                found.insert(p.name.clone(), p);
            }
        }
    }

    names
        .iter()
        .map(|n| {
            let mut p = found
                .remove(n.as_str())
                .unwrap_or_else(|| fallback_package(n));
            p.installed = installed.contains(n.as_str());
            p
        })
        .collect()
}

pub fn exact(name: &str) -> Package {
    packages_by_name(&[name.to_string()])
        .pop()
        .unwrap_or_default()
}

fn normalize(s: &str) -> String {
    s.chars()
        .filter(|c| !matches!(c, ' ' | '-' | '_' | '.'))
        .flat_map(char::to_lowercase)
        .collect()
}

/// `pacman -Ss` arguments are POSIX regexes: escape what the user typed.
pub fn regex_escape(s: &str) -> String {
    let mut out = String::with_capacity(s.len() + 4);
    for c in s.chars() {
        if "\\.^$*+?()[]{}|".contains(c) {
            out.push('\\');
        }
        out.push(c);
    }
    out
}

/// Search the sync databases. Results are filtered to names that contain the
/// normalized query (ignoring case, spaces, `-`, `_`, `.`) and ranked: exact
/// match, then prefix, then shorter names first.
pub fn search(query: &str, limit: usize) -> Vec<Package> {
    let words: Vec<String> = query.split_whitespace().map(regex_escape).collect();
    if words.is_empty() {
        return Vec::new();
    }
    let mut args: Vec<&str> = vec!["-Ss", "--"];
    args.extend(words.iter().map(String::as_str));
    let out = runner::run_pacman(&args, T_SEARCH);
    parse_search(&out.stdout, query, limit, &localdb::installed_names())
}

fn parse_search(text: &str, query: &str, limit: usize, installed: &HashSet<String>) -> Vec<Package> {
    let nq = normalize(query);
    let mut found: Vec<(u8, Package)> = Vec::new();
    let mut seen: HashSet<String> = HashSet::new();
    let mut current: Option<Package> = None;

    let mut flush = |p: Option<Package>, found: &mut Vec<(u8, Package)>| {
        let Some(mut p) = p else { return };
        let nn = normalize(&p.name);
        if !nn.contains(&nq) || !seen.insert(p.name.clone()) {
            return;
        }
        p.installed = installed.contains(&p.name);
        let rank = if nn == nq { 0 } else if nn.starts_with(&nq) { 1 } else { 2 };
        found.push((rank, p));
    };

    for line in text.lines() {
        if line.is_empty() {
            continue;
        }
        if !line.starts_with(' ') {
            flush(current.take(), &mut found);
            let mut parts = line.split_whitespace();
            if let (Some(head), Some(version)) = (parts.next(), parts.next()) {
                if let Some((repo, name)) = head.split_once('/') {
                    current = Some(Package {
                        name: name.to_string(),
                        repo: repo.to_string(),
                        version: version.to_string(),
                        description: String::new(),
                        installed: false,
                        ..Default::default()
                    });
                }
            }
        } else if let Some(p) = current.as_mut() {
            p.description = line.trim().to_string();
        }
    }
    flush(current.take(), &mut found);

    found.sort_by(|a, b| {
        a.0.cmp(&b.0)
            .then(a.1.name.len().cmp(&b.1.name.len()))
            .then(a.1.name.cmp(&b.1.name))
    });
    found.into_iter().take(limit).map(|(_, p)| p).collect()
}

fn parse_plan(text: &str) -> Vec<(String, u64)> {
    text.lines()
        .filter_map(|l| {
            let (name, size) = l.split_once('|')?;
            let name = name.trim();
            if name.is_empty() || name.contains(' ') {
                return None;
            }
            Some((name.to_string(), size.trim().parse().unwrap_or(0)))
        })
        .collect()
}

/// Ask pacman's own resolver what installing `name` would do (two processes:
/// the plan, then one `-Si` for every planned package).
pub fn details(name: &str) -> PackageDetails {
    let mut d = PackageDetails::default();
    if !is_valid_package_name(name) {
        return d;
    }
    let installed = localdb::installed_names();

    let plan_out = runner::run_pacman(&["-Sp", "--print-format", "%n|%s", "--", name], T_PLAN);
    let planned = parse_plan(&plan_out.stdout);

    if planned.is_empty() {
        // Foreign / AUR / unresolvable: show at least what is on disk.
        if let Some(lp) = localdb::read_one(name) {
            d.app_size = lp.install_size;
            d.total_installed = lp.install_size;
        }
        return d;
    }

    let mut args: Vec<&str> = vec!["-Si", "--"];
    args.extend(planned.iter().map(|(n, _)| n.as_str()));
    let info_out = runner::run_pacman(&args, T_PLAN);
    let sizes: HashMap<String, u64> = parse_info(&info_out.stdout)
        .into_iter()
        .filter_map(|b| Some((b.get("Name")?.clone(), parse_size(b.get("Installed Size")?))))
        .collect();

    let mut deps: Vec<Dependency> = Vec::new();
    for (n, download) in &planned {
        let isz = sizes.get(n).copied().unwrap_or(0);
        let already = installed.contains(n);
        d.total_installed += isz;
        if !already {
            d.total_download += download;
            d.net_upgrade += isz;
        }
        if n == name {
            d.app_size = isz;
            continue;
        }
        if already {
            d.installed_deps += isz;
        } else {
            d.new_deps += isz;
        }
        deps.push(Dependency { name: n.clone(), size_bytes: isz, installed: already });
    }
    if d.app_size == 0 {
        if let Some(lp) = localdb::read_one(name) {
            d.app_size = lp.install_size;
        }
    }
    deps.sort_by_key(|x| !x.installed); // stable: installed first
    d.dependencies = deps;
    d.plan_ok = true;
    d
}

/// repo name per package (`pacman -Sl`), used to label installed packages.
fn repo_map() -> HashMap<String, String> {
    let out = runner::run_pacman(&["-Sl"], T_LIST);
    let mut map = HashMap::new();
    for line in out.stdout.lines() {
        let mut it = line.split_whitespace();
        if let (Some(repo), Some(name)) = (it.next(), it.next()) {
            map.entry(name.to_string()).or_insert_with(|| repo.to_string());
        }
    }
    map
}

/// Explicitly installed packages, read straight from the local database.
pub fn installed_packages() -> Vec<Package> {
    let repos = repo_map();
    let mut list: Vec<Package> = localdb::read_all()
        .into_iter()
        .filter(|p| p.explicit)
        .map(|p| Package {
            repo: repos.get(&p.name).cloned().unwrap_or_else(|| "aur".into()),
            name: p.name,
            version: p.version,
            description: p.description,
            installed: true,
            ..Default::default()
        })
        .collect();
    list.sort_by(|a, b| a.name.cmp(&b.name));
    list
}

fn parse_updates(text: &str) -> Vec<UpdateEntry> {
    text.lines()
        .filter_map(|l| {
            let mut it = l.split_whitespace();
            let (name, old, arrow, new) = (it.next()?, it.next()?, it.next()?, it.next()?);
            (arrow == "->").then(|| UpdateEntry {
                name: name.to_string(),
                old_version: old.to_string(),
                new_version: new.to_string(),
            })
        })
        .collect()
}

fn first_line(s: &str) -> String {
    s.lines().next().unwrap_or("unknown error").trim().to_string()
}

/// Pending upgrades. Prefers `checkupdates` (pacman-contrib): it syncs a
/// private copy of the databases, needs no root and cannot cause a partial
/// upgrade. Falls back to `pacman -Qu` (whatever was last synced).
pub fn updates() -> Result<Vec<UpdateEntry>, String> {
    let use_contrib = runner::in_path("checkupdates");
    let out = if use_contrib {
        runner::run("checkupdates", &[], T_CHECK)
    } else {
        runner::run_pacman(&["-Qu"], T_INFO)
    };

    let entries = parse_updates(&out.stdout);
    if !entries.is_empty() {
        return Ok(entries);
    }
    if out.timed_out {
        return Err("Timed out while checking for updates".into());
    }
    match (use_contrib, out.code) {
        (true, Some(0 | 2)) | (false, Some(0 | 1)) => Ok(entries),
        _ => Err(format!("Update check failed: {}", first_line(&out.stderr))),
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn escape() {
        assert_eq!(regex_escape("c++"), "c\\+\\+");
        assert_eq!(regex_escape("a.b"), "a\\.b");
    }

    #[test]
    fn search_ranking() {
        let text = "extra/vlc-plugin-x 1.0-1\n    plugin\nextra/vlc 3.0-1 (vlc-plugins)\n    The player\nextra/libvlc 3.0-1\n    lib\n";
        let r = parse_search(text, "vlc", 10, &HashSet::new());
        let names: Vec<_> = r.iter().map(|p| p.name.as_str()).collect();
        assert_eq!(names, ["vlc", "vlc-plugin-x", "libvlc"]);
        assert_eq!(r[0].description, "The player");
    }

    #[test]
    fn updates_parse() {
        let u = parse_updates("linux 6.1-1 -> 6.2-1\nbad line\n");
        assert_eq!(u.len(), 1);
        assert_eq!(u[0].new_version, "6.2-1");
    }

    #[test]
    fn plan_parse() {
        let p = parse_plan("foo|123\nwarning: x y|1\nbar|abc\n");
        assert_eq!(p, vec![("foo".to_string(), 123), ("bar".to_string(), 0)]);
    }
}
