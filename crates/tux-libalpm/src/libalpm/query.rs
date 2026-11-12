//! Read-only questions answered straight from libalpm's local and sync
//! databases.

use super::{answer_question, open};
use alpm::{Alpm, Package as AlpmPackage, TransFlag};
use std::collections::{HashMap, HashSet};
use tux_abi::text::is_valid_package_name;
use tux_abi::{Dependency, Package, PackageDetails, UpdateEntry};

fn normalize(s: &str) -> String {
    s.chars()
        .filter(|c| !matches!(c, ' ' | '-' | '_' | '.'))
        .flat_map(char::to_lowercase)
        .collect()
}

/// `alpm_db_search` takes POSIX regexes: escape what the user typed.
fn regex_escape(s: &str) -> String {
    let mut out = String::with_capacity(s.len() + 4);
    for c in s.chars() {
        if "\\.^$*+?()[]{}|".contains(c) {
            out.push('\\');
        }
        out.push(c);
    }
    out
}

fn installed_names(handle: &Alpm) -> HashSet<String> {
    handle
        .localdb()
        .pkgs()
        .iter()
        .map(|p| p.name().to_string())
        .collect()
}

fn repo_of(pkg: &alpm::Pkg) -> String {
    pkg.db().map(|db| db.name().to_string()).unwrap_or_default()
}

fn package_of(pkg: &alpm::Pkg, installed: bool) -> Package {
    Package {
        name: pkg.name().to_string(),
        repo: repo_of(pkg),
        version: pkg.version().to_string(),
        description: pkg.desc().unwrap_or_default().to_string(),
        installed,
        ..Default::default()
    }
}

fn fallback_package(handle: &Alpm, name: &str) -> Package {
    if let Ok(lp) = handle.localdb().pkg(name) {
        return Package {
            name: lp.name().to_string(),
            repo: "aur".into(),
            version: lp.version().to_string(),
            description: lp.desc().unwrap_or_default().to_string(),
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

/// Search every sync database. The ranking is the same as the direct engine:
/// exact normalized match first, then prefix, then the rest; shorter names win
/// ties.
pub fn search(query: &str, limit: usize) -> Vec<Package> {
    let words: Vec<String> = query.split_whitespace().map(regex_escape).collect();
    if words.is_empty() {
        return Vec::new();
    }
    let handle = match open() {
        Ok(h) => h,
        Err(e) => {
            log::warn!("{e}");
            return Vec::new();
        }
    };
    let installed = installed_names(&handle);
    let nq = normalize(query);
    let mut found: Vec<(u8, Package)> = Vec::new();
    let mut seen: HashSet<String> = HashSet::new();

    for db in handle.syncdbs().iter() {
        let packages = match db.search(words.iter().map(String::as_str)) {
            Ok(list) => list,
            Err(e) => {
                log::warn!("libalpm: cannot search {}: {e}", db.name());
                continue;
            }
        };
        for pkg in packages.iter() {
            let name = pkg.name().to_string();
            let nn = normalize(&name);
            if !nn.contains(&nq) || !seen.insert(name.clone()) {
                continue;
            }
            let mut p = package_of(pkg, installed.contains(&name));
            p.installed = installed.contains(&name);
            let rank = if nn == nq {
                0
            } else if nn.starts_with(&nq) {
                1
            } else {
                2
            };
            found.push((rank, p));
        }
    }

    found.sort_by(|a, b| {
        a.0.cmp(&b.0)
            .then(a.1.name.len().cmp(&b.1.name.len()))
            .then(a.1.name.cmp(&b.1.name))
    });
    found.into_iter().take(limit).map(|(_, p)| p).collect()
}

/// One entry per requested name, in the same order.
pub fn packages_by_name(names: &[String]) -> Vec<Package> {
    let handle = match open() {
        Ok(h) => h,
        Err(e) => {
            log::warn!("{e}");
            return names
                .iter()
                .map(|n| Package {
                    name: n.clone(),
                    repo: "aur".into(),
                    version: "unknown".into(),
                    description: "libalpm is unavailable.".into(),
                    ..Default::default()
                })
                .collect();
        }
    };
    let installed = installed_names(&handle);

    names
        .iter()
        .map(|name| {
            if is_valid_package_name(name) {
                for db in handle.syncdbs().iter() {
                    if let Ok(pkg) = db.pkg(name.as_str()) {
                        return package_of(pkg, installed.contains(name));
                    }
                }
            }
            fallback_package(&handle, name)
        })
        .collect()
}

pub fn exact(name: &str) -> Package {
    packages_by_name(&[name.to_string()])
        .pop()
        .unwrap_or_default()
}

fn sync_package<'a>(handle: &'a Alpm, name: &str) -> Option<&'a AlpmPackage> {
    handle
        .syncdbs()
        .iter()
        .find_map(|db| db.pkg(name).ok())
}

fn question_callback(handle: &Alpm) {
    handle.set_question_cb((), |mut q, _| answer_question(&mut q));
}

/// Ask libalpm's own resolver what installing `name` would do.
pub fn details(name: &str) -> PackageDetails {
    let mut d = PackageDetails::default();
    if !is_valid_package_name(name) {
        return d;
    }
    let mut handle = match open() {
        Ok(h) => h,
        Err(e) => {
            log::warn!("{e}");
            return d;
        }
    };

    let target_isize = match sync_package(&handle, name) {
        Some(target) => target.isize().max(0) as u64,
        None => {
            // Foreign / AUR / unknown: show at least what is on disk.
            if let Ok(lp) = handle.localdb().pkg(name) {
                d.app_size = lp.isize().max(0) as u64;
                d.total_installed = d.app_size;
            }
            return d;
        }
    };

    question_callback(&handle);
    let planned = match prepare_install(&mut handle, name) {
        Ok(list) => list,
        Err(e) => {
            log::warn!("libalpm: no plan for {name}: {e}");
            d.app_size = target_isize;
            d.total_installed = d.app_size;
            return d;
        }
    };
    let installed = installed_names(&handle);

    let mut deps: Vec<Dependency> = Vec::new();
    for entry in planned {
        let isz = entry.install_size;
        let already = installed.contains(&entry.name);
        d.total_installed += isz;
        if !already {
            d.total_download += entry.download_size;
            d.net_upgrade += isz;
        }
        if entry.name == name {
            d.app_size = isz;
            continue;
        }
        if already {
            d.installed_deps += isz;
        } else {
            d.new_deps += isz;
        }
        deps.push(Dependency {
            name: entry.name,
            size_bytes: isz,
            installed: already,
        });
    }
    if d.app_size == 0 {
        if let Ok(lp) = handle.localdb().pkg(name) {
            d.app_size = lp.isize().max(0) as u64;
        }
    }
    deps.sort_by_key(|x| !x.installed); // stable: installed first
    d.dependencies = deps;
    d.plan_ok = true;
    d
}

struct PlanEntry {
    name: String,
    download_size: u64,
    install_size: u64,
}

/// Run a transaction up to `trans_prepare` and return the packages it would
/// add. The transaction is released before returning.
fn prepare_install(handle: &mut Alpm, name: &str) -> Result<Vec<PlanEntry>, String> {
    let target = handle
        .syncdbs()
        .iter()
        .find_map(|db| db.pkg(name).ok())
        .ok_or_else(|| format!("package not found: {name}"))?;
    handle
        .trans_init(TransFlag::NO_LOCK)
        .map_err(|e| format!("transaction init failed: {e}"))?;
    handle
        .trans_add_pkg(target)
        .map_err(|e| format!("cannot add {name} to the transaction: {e}"))?;
    let result = prepare_plan(handle);
    let _ = handle.trans_release();
    result
}

fn prepare_plan(handle: &mut Alpm) -> Result<Vec<PlanEntry>, String> {
    if let Err(e) = handle.trans_prepare() {
        return Err(super::describe_prepare_error(&e));
    }

    Ok(handle
        .trans_add()
        .iter()
        .map(|pkg| PlanEntry {
            name: pkg.name().to_string(),
            download_size: pkg.download_size().max(0) as u64,
            install_size: pkg.isize().max(0) as u64,
        })
        .collect())
}

/// Explicitly installed packages, labelled with the repository that still
/// carries them (if any).
pub fn installed_packages() -> Vec<Package> {
    let handle = match open() {
        Ok(h) => h,
        Err(e) => {
            log::warn!("{e}");
            return Vec::new();
        }
    };

    let mut repos: HashMap<String, String> = HashMap::new();
    for db in handle.syncdbs().iter() {
        for pkg in db.pkgs().iter() {
            repos
                .entry(pkg.name().to_string())
                .or_insert_with(|| db.name().to_string());
        }
    }

    let mut list: Vec<Package> = handle
        .localdb()
        .pkgs()
        .iter()
        .filter(|p| p.reason() == alpm::PackageReason::Explicit)
        .map(|p| Package {
            name: p.name().to_string(),
            repo: repos
                .get(p.name())
                .cloned()
                .unwrap_or_else(|| "aur".into()),
            version: p.version().to_string(),
            description: p.desc().unwrap_or_default().to_string(),
            installed: true,
            ..Default::default()
        })
        .collect();
    list.sort_by(|a, b| a.name.cmp(&b.name));
    list
}

/// Pending upgrades, computed from the sync databases that were last updated
/// (the direct engine prefers `checkupdates`, which does its own private sync;
/// this path never touches the network).
pub fn updates() -> Result<Vec<UpdateEntry>, String> {
    let handle = open()?;
    let mut entries: Vec<UpdateEntry> = handle
        .localdb()
        .pkgs()
        .iter()
        .filter_map(|local| {
            let new = local.sync_new_version(handle.syncdbs())?;
            Some(UpdateEntry {
                name: local.name().to_string(),
                old_version: local.version().to_string(),
                new_version: new.version().to_string(),
            })
        })
        .collect();
    entries.sort_by(|a, b| a.name.cmp(&b.name));
    Ok(entries)
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
    fn normalization() {
        assert_eq!(normalize("Foo-Bar_baz.qux"), "foobarbazqux");
    }
}
