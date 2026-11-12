//! The libalpm backend.
//!
//! Queries open a handle on demand and read the databases that `pacman -Sy`
//! last downloaded; transactions run either in-process (when we are already
//! root) or inside a tiny privileged helper (see `tux-store
//! --engine-transaction`).

pub mod config;
mod query;
mod transaction;

pub use query::{details, exact, installed_packages, packages_by_name, search, updates};
pub use transaction::{run_privileged, run_root};

use alpm::{Alpm, SigLevel, Usage};
use config::Config;
use std::path::Path;

/// Default used by pacman when `pacman.conf` says nothing.
const DEFAULT_SIGLEVEL: &str = "Required DatabaseOptional";

/// Open a read-only handle for a query. Errors are reported by the caller.
pub(crate) fn open() -> Result<Alpm, String> {
    open_with(&config::load())
}

pub(crate) fn open_with(cfg: &Config) -> Result<Alpm, String> {
    let mut handle = Alpm::new(cfg.root.as_str(), cfg.dbpath.as_str())
        .map_err(|e| format!("cannot initialize libalpm: {e}"))?;

    if !cfg.cachedirs.is_empty() {
        handle
            .set_cachedirs(cfg.cachedirs.iter().map(String::as_str))
            .map_err(|e| format!("cannot set cache directories: {e}"))?;
    }

    // libalpm already knows its built-in hook directories; only add what the
    // configuration mentions and the handle does not have yet.
    let existing: Vec<String> = handle.hookdirs().iter().map(str::to_string).collect();
    for dir in &cfg.hookdirs {
        if !existing.iter().any(|e| e == dir) && Path::new(dir).is_dir() {
            if let Err(e) = handle.add_hookdir(dir.as_str()) {
                log::warn!("libalpm: cannot add hook directory {dir}: {e}");
            }
        }
    }

    if let Some(arch) = cfg.arch.as_deref() {
        handle
            .set_architectures(std::iter::once(arch))
            .map_err(|e| format!("cannot set architecture: {e}"))?;
    }
    if !cfg.ignore.is_empty() {
        handle
            .set_ignorepkgs(cfg.ignore.iter().map(String::as_str))
            .map_err(|e| format!("cannot set ignored packages: {e}"))?;
    }
    if let Some(user) = cfg.sandbox_user.as_deref() {
        if let Err(e) = handle.set_sandbox_user(Some(user)) {
            log::warn!("libalpm: cannot set sandbox user {user}: {e}");
        }
    }
    // The log file is only useful (and writable) for the privileged helper.
    if is_root() {
        if let Some(logfile) = cfg.logfile.as_deref() {
            if let Err(e) = handle.set_logfile(logfile) {
                log::warn!("libalpm: cannot open log file {logfile}: {e}");
            }
        }
        if let Some(gpgdir) = cfg.gpgdir.as_deref() {
            if let Err(e) = handle.set_gpgdir(gpgdir) {
                log::warn!("libalpm: cannot set gpg directory {gpgdir}: {e}");
            }
        }
    }

    let global = cfg
        .siglevel
        .as_deref()
        .map(parse_siglevel)
        .unwrap_or_else(|| parse_siglevel(DEFAULT_SIGLEVEL));

    for repo in &cfg.repos {
        let sig = repo
            .siglevel
            .as_deref()
            .map(parse_siglevel)
            .unwrap_or(global);
        let db = match handle.register_syncdb_mut(repo.name.as_str(), sig) {
            Ok(db) => db,
            Err(e) => {
                log::warn!("libalpm: cannot register repository {}: {e}", repo.name);
                continue;
            }
        };
        for server in &repo.servers {
            if let Err(e) = db.add_server(server.as_str()) {
                log::warn!("libalpm: bad server {server} for {}: {e}", repo.name);
            }
        }
        if let Err(e) = db.set_usage(Usage::ALL) {
            log::warn!("libalpm: cannot configure repository {}: {e}", repo.name);
        }
    }

    Ok(handle)
}

/// Translate `SigLevel = Required DatabaseOptional TrustAll …` into flags.
fn parse_siglevel(value: &str) -> SigLevel {
    use SigLevel as S;
    let mut level = S::NONE;
    for word in value.split_whitespace() {
        match word.to_ascii_lowercase().as_str() {
            "never" => level = S::NONE,
            "required" => {
                level.remove(S::PACKAGE_OPTIONAL | S::DATABASE_OPTIONAL);
                level.insert(S::PACKAGE | S::DATABASE);
            }
            "optional" => {
                level.remove(S::PACKAGE | S::DATABASE);
                level.insert(S::PACKAGE_OPTIONAL | S::DATABASE_OPTIONAL);
            }
            "packagerequired" => {
                level.remove(S::PACKAGE_OPTIONAL);
                level.insert(S::PACKAGE);
            }
            "packageoptional" => {
                level.remove(S::PACKAGE);
                level.insert(S::PACKAGE_OPTIONAL);
            }
            "databaserequired" => {
                level.remove(S::DATABASE_OPTIONAL);
                level.insert(S::DATABASE);
            }
            "databaseoptional" => {
                level.remove(S::DATABASE);
                level.insert(S::DATABASE_OPTIONAL);
            }
            "trustedonly" => {
                level.remove(
                    S::PACKAGE_MARGINAL_OK
                        | S::PACKAGE_UNKNOWN_OK
                        | S::DATABASE_MARGINAL_OK
                        | S::DATABASE_UNKNOWN_OK,
                );
            }
            "trustall" => {
                level.insert(
                    S::PACKAGE_MARGINAL_OK
                        | S::PACKAGE_UNKNOWN_OK
                        | S::DATABASE_MARGINAL_OK
                        | S::DATABASE_UNKNOWN_OK,
                );
            }
            "packagetrustall" => {
                level.insert(S::PACKAGE_MARGINAL_OK | S::PACKAGE_UNKNOWN_OK);
            }
            "databasetrustall" => {
                level.insert(S::DATABASE_MARGINAL_OK | S::DATABASE_UNKNOWN_OK);
            }
            "usedefault" => level.insert(S::USE_DEFAULT),
            other => log::warn!("libalpm: unknown SigLevel word {other:?}"),
        }
    }
    level
}

pub(crate) fn is_root() -> bool {
    // SAFETY: geteuid has no preconditions and cannot fail.
    unsafe { libc::geteuid() == 0 }
}

/// Answer the questions libalpm asks during `trans_prepare`/`trans_commit`.
///
/// This mirrors `pacman --noconfirm`: take the first provider, remove
/// conflicting packages, replace packages, and import unknown keys.
pub(crate) fn answer_question(question: &mut alpm::AnyQuestion<'_>) {
    use alpm::{Question, QuestionType};
    let mut answer = true;
    {
        match question.question() {
            Question::SelectProvider(mut q) => q.set_index(0),
            Question::Conflict(mut q) => q.set_remove(true),
            Question::Replace(q) => q.set_replace(true),
            Question::Corrupted(mut q) => q.set_remove(true),
            Question::RemovePkgs(mut q) => q.set_skip(false),
            Question::ImportKey(mut q) => q.set_import(true),
            // Ignored packages stay ignored (pacman's default answer is "no").
            Question::InstallIgnorepkg(mut q) => {
                q.set_install(false);
                answer = false;
            }
        }
    }
    if matches!(question.question_type(), QuestionType::InstallIgnorepkg) {
        answer = false;
    }
    question.set_answer(answer);
}

/// Turn a prepare failure into something the output pane can show.
pub(crate) fn describe_prepare_error(error: &alpm::PrepareError<'_>) -> String {
    use alpm::PrepareData;
    let mut msg = format!("{}", error.error());
    if let Some(data) = error.data() {
        match data {
            PrepareData::UnsatisfiedDeps(list) => {
                for missing in list.iter() {
                    let who = missing.causing_pkg().unwrap_or("?");
                    msg.push_str(&format!(
                        "\n  missing dependency '{}' required by {who}",
                        missing.depend().name()
                    ));
                }
            }
            PrepareData::ConflictingDeps(list) => {
                for conflict in list.iter() {
                    msg.push_str(&format!("\n  conflict: {}", conflict.reason().name()));
                }
            }
            PrepareData::PkgInvalidArch(list) => {
                for pkg in list.iter() {
                    msg.push_str(&format!("\n  wrong architecture: {}", pkg.name()));
                }
            }
        }
    }
    msg
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn siglevels() {
        let l = parse_siglevel("Required DatabaseOptional");
        assert!(l.contains(SigLevel::PACKAGE));
        assert!(l.contains(SigLevel::DATABASE_OPTIONAL));
        assert!(!l.contains(SigLevel::DATABASE));

        let l = parse_siglevel("Optional TrustAll");
        assert!(l.contains(SigLevel::PACKAGE_OPTIONAL));
        assert!(l.contains(SigLevel::PACKAGE_UNKNOWN_OK));
        assert!(l.contains(SigLevel::DATABASE_MARGINAL_OK));
    }
}
