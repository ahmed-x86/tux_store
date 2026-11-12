//! Zero-network icon lookup in the **active** system icon theme.
//!
//! 1. Detect which theme the user actually runs (`$TUX_ICON_THEME`, GTK
//!    settings / gsettings, KDE `kdeglobals`).
//! 2. Follow its `Inherits=` chain from `index.theme`, as the freedesktop
//!    icon-theme spec says.
//! 3. `hicolor` and `/usr/share/pixmaps` are only a *fallback* tier.
//!
//! Themes that are merely installed but not selected are never searched, so
//! icons always match the theme the rest of the desktop uses. If no theme can
//! be detected at all we fall back to scanning every installed theme.
//!
//! Instead of indexing every file (tens of thousands) we only collect the few
//! hundred `…/apps` directories once, sorted by how close their size is to
//! 64 px (scalable first). A lookup is then a handful of `stat` calls.

use std::collections::HashSet;
use std::fs;
use std::io::Read;
use std::path::{Path, PathBuf};
use std::process::{Command, Stdio};
use std::time::{Duration, Instant};
use tux_abi::paths;

pub struct ThemeDirs {
    /// Active theme + everything it inherits (best theme first).
    primary: Vec<PathBuf>,
    /// `hicolor` and the pixmaps directories.
    fallback: Vec<PathBuf>,
    name: String,
}

impl ThemeDirs {
    pub fn discover() -> Self {
        let roots = icon_roots();
        let detected = detect_theme_name(&roots);

        let (primary, name) = match &detected {
            Some(theme) => {
                let mut dirs = Vec::new();
                for t in theme_chain(theme, &roots) {
                    dirs.extend(theme_dirs(&t, &roots));
                }
                (dirs, theme.clone())
            }
            None => {
                // Nothing configured: behave like before and use everything.
                let mut dirs = Vec::new();
                for t in all_theme_names(&roots) {
                    if t != "hicolor" {
                        dirs.extend(theme_dirs(&t, &roots));
                    }
                }
                (dirs, String::from("<any>"))
            }
        };

        let mut fallback = theme_dirs("hicolor", &roots);
        fallback.push(PathBuf::from("/usr/share/pixmaps"));
        fallback.push(PathBuf::from("/usr/local/share/pixmaps"));

        log::info!(
            "icon theme: '{name}' ({} dirs + {} fallback dirs)",
            primary.len(),
            fallback.len()
        );
        Self { primary, fallback, name }
    }

    #[allow(dead_code)]
    pub fn name(&self) -> &str {
        &self.name
    }

    /// First hit in the active theme (and its parents), trying candidates in order.
    pub fn find_primary(&self, candidates: &[String]) -> Option<PathBuf> {
        find_in(&self.primary, candidates)
    }

    /// First hit in `hicolor` / pixmaps.
    pub fn find_fallback(&self, candidates: &[String]) -> Option<PathBuf> {
        find_in(&self.fallback, candidates)
    }
}

fn find_in(dirs: &[PathBuf], candidates: &[String]) -> Option<PathBuf> {
    for icon in candidates {
        for dir in dirs {
            for ext in ["svg", "png"] {
                let p = dir.join(format!("{icon}.{ext}"));
                if p.is_file() {
                    return Some(p);
                }
            }
        }
    }
    None
}

// ───────────────────────── roots & detection ─────────────────────────

fn icon_roots() -> Vec<PathBuf> {
    let home = paths::home();
    let mut roots: Vec<PathBuf> = vec![home.join(".local/share/icons"), home.join(".icons")];
    if let Some(d) = std::env::var_os("XDG_DATA_HOME").filter(|d| !d.is_empty()) {
        roots.push(PathBuf::from(d).join("icons"));
    }
    match std::env::var_os("XDG_DATA_DIRS").filter(|d| !d.is_empty()) {
        Some(dirs) => roots.extend(std::env::split_paths(&dirs).map(|d| d.join("icons"))),
        None => {
            roots.push(PathBuf::from("/usr/local/share/icons"));
            roots.push(PathBuf::from("/usr/share/icons"));
        }
    }
    // /usr/share/icons is where Arch themes live; make sure it is always there.
    roots.push(PathBuf::from("/usr/share/icons"));
    let mut seen = HashSet::new();
    roots.retain(|r| seen.insert(r.clone()));
    roots
}

fn theme_exists(name: &str, roots: &[PathBuf]) -> bool {
    !name.is_empty()
        && !name.contains('/')
        && roots.iter().any(|r| r.join(name).is_dir())
}

fn detect_theme_name(roots: &[PathBuf]) -> Option<String> {
    let config = std::env::var_os("XDG_CONFIG_HOME")
        .filter(|p| Path::new(p).is_absolute())
        .map(PathBuf::from)
        .unwrap_or_else(|| paths::home().join(".config"));

    let is_kde = std::env::var("XDG_CURRENT_DESKTOP")
        .map(|d| d.to_ascii_uppercase().contains("KDE"))
        .unwrap_or(false);

    let kde = || ini_value(&read(&config.join("kdeglobals")), Some("Icons"), "Theme");
    let gtk = |v: &str| ini_value(&read(&config.join(v).join("settings.ini")), Some("Settings"), "gtk-icon-theme-name");
    let gsettings = || {
        run_with_timeout("gsettings", &["get", "org.gnome.desktop.interface", "icon-theme"], Duration::from_secs(2))
            .map(|s| s.trim().trim_matches('\'').trim_matches('"').to_string())
            .filter(|s| !s.is_empty())
    };

    let mut sources: Vec<Option<String>> = Vec::new();
    sources.push(std::env::var("TUX_ICON_THEME").ok());
    if is_kde {
        sources.push(kde());
        sources.push(gtk("gtk-4.0"));
        sources.push(gtk("gtk-3.0"));
    } else {
        sources.push(gsettings());
        sources.push(gtk("gtk-4.0"));
        sources.push(gtk("gtk-3.0"));
        sources.push(kde());
    }

    sources
        .into_iter()
        .flatten()
        .map(|s| s.trim().to_string())
        .find(|s| theme_exists(s, roots))
}

fn read(p: &Path) -> String {
    fs::read_to_string(p).unwrap_or_default()
}

/// Run a command, give up (and kill it) after `limit`. Returns stdout on success.
fn run_with_timeout(cmd: &str, args: &[&str], limit: Duration) -> Option<String> {
    let mut child = Command::new(cmd)
        .args(args)
        .stdin(Stdio::null())
        .stdout(Stdio::piped())
        .stderr(Stdio::null())
        .spawn()
        .ok()?;
    let start = Instant::now();
    loop {
        match child.try_wait() {
            Ok(Some(status)) => {
                if !status.success() {
                    return None;
                }
                let mut out = String::new();
                child.stdout.take()?.read_to_string(&mut out).ok()?;
                return Some(out);
            }
            Ok(None) if start.elapsed() < limit => std::thread::sleep(Duration::from_millis(15)),
            _ => {
                let _ = child.kill();
                let _ = child.wait();
                return None;
            }
        }
    }
}

/// Minimal INI reader: value of `key` inside `[section]` (or anywhere when `None`).
fn ini_value(text: &str, section: Option<&str>, key: &str) -> Option<String> {
    let mut current = String::new();
    for line in text.lines() {
        let line = line.trim();
        if line.starts_with('#') || line.starts_with(';') || line.is_empty() {
            continue;
        }
        if let Some(s) = line.strip_prefix('[').and_then(|l| l.strip_suffix(']')) {
            current = s.to_string();
            continue;
        }
        if section.is_some_and(|s| s != current) {
            continue;
        }
        if let Some((k, v)) = line.split_once('=') {
            if k.trim() == key {
                let v = v.trim().trim_matches('"').trim_matches('\'').trim();
                if !v.is_empty() {
                    return Some(v.to_string());
                }
            }
        }
    }
    None
}

// ───────────────────────── theme graph ─────────────────────────

/// `theme` followed by everything it (transitively) inherits, `hicolor` excluded.
fn theme_chain(theme: &str, roots: &[PathBuf]) -> Vec<String> {
    let mut order: Vec<String> = Vec::new();
    let mut queue: Vec<String> = vec![theme.to_string()];
    while !queue.is_empty() {
        let t = queue.remove(0);
        if t == "hicolor" || order.contains(&t) || !theme_exists(&t, roots) {
            continue;
        }
        for root in roots {
            let text = read(&root.join(&t).join("index.theme"));
            if let Some(list) = ini_value(&text, Some("Icon Theme"), "Inherits") {
                queue.extend(list.split(',').map(|s| s.trim().to_string()).filter(|s| !s.is_empty()));
            }
        }
        order.push(t);
    }
    order
}

fn all_theme_names(roots: &[PathBuf]) -> Vec<String> {
    let mut names: Vec<String> = Vec::new();
    for root in roots {
        if let Ok(rd) = fs::read_dir(root) {
            for e in rd.flatten() {
                if e.path().is_dir() {
                    let n = e.file_name().to_string_lossy().into_owned();
                    if !names.contains(&n) {
                        names.push(n);
                    }
                }
            }
        }
    }
    names.sort();
    names
}

/// All `apps` directories of one theme (across every root), best size first.
fn theme_dirs(theme: &str, roots: &[PathBuf]) -> Vec<PathBuf> {
    let mut scored: Vec<(i64, PathBuf)> = Vec::new();
    for root in roots {
        let path = root.join(theme);
        if path.is_dir() {
            scan_theme(&path, &mut scored);
        }
    }
    scored.sort_by(|a, b| b.0.cmp(&a.0));
    scored.into_iter().map(|(_, p)| p).collect()
}

fn scan_theme(theme: &Path, out: &mut Vec<(i64, PathBuf)>) {
    let Ok(entries) = fs::read_dir(theme) else { return };
    for e in entries.flatten() {
        let p = e.path();
        let fname = e.file_name().to_string_lossy().into_owned();
        if fname == "apps" {
            // breeze style: <theme>/apps/<size>/
            if let Ok(sizes) = fs::read_dir(&p) {
                for s in sizes.flatten() {
                    let sp = s.path();
                    if sp.is_dir() {
                        out.push((score(&s.file_name().to_string_lossy()), sp));
                    }
                }
            }
        } else {
            // hicolor / Papirus style: <theme>/<size>/apps/
            let apps = p.join("apps");
            if apps.is_dir() {
                out.push((score(&fname), apps));
            }
        }
    }
}

fn score(size: &str) -> i64 {
    if size == "scalable" {
        return 1000;
    }
    let digits: String = size.chars().take_while(char::is_ascii_digit).collect();
    match digits.parse::<i64>() {
        Ok(n) if n > 0 => 500 - (n - 64).abs(),
        _ => 0,
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn ini_sections() {
        let t = "[Settings]\ngtk-icon-theme-name = Papirus-Dark\n[Other]\ngtk-icon-theme-name=X\n";
        assert_eq!(ini_value(t, Some("Settings"), "gtk-icon-theme-name").as_deref(), Some("Papirus-Dark"));
        let k = "[General]\nTheme=no\n[Icons]\nTheme=breeze-dark\n";
        assert_eq!(ini_value(k, Some("Icons"), "Theme").as_deref(), Some("breeze-dark"));
        let i = "[Icon Theme]\nName=x\nInherits=Adwaita, hicolor\n";
        assert_eq!(ini_value(i, Some("Icon Theme"), "Inherits").as_deref(), Some("Adwaita, hicolor"));
    }

    #[test]
    fn size_scoring() {
        assert!(score("scalable") > score("64x64"));
        assert!(score("64x64") > score("48x48"));
        assert!(score("48") > score("16x16"));
    }
}
