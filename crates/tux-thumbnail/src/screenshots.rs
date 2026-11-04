//! Package screenshots (`ScreenshotsRequested` → `ScreenshotsReady`).
//!
//! A package `foo` has a folder `data/screenshots/foo/` (the user's own
//! `~/.config/tux-store/screenshots/foo/` is looked at first) holding a
//! manifest `foo.json` and, optionally, numbered pictures `foo-1.png`,
//! `foo-2.png`, … Two ways to provide the pictures:
//!
//! 1. **Local files** – the pictures sit next to the JSON. They are used as is.
//! 2. **Flathub** – the JSON has `"flathub": "<app id or flathub.org link>"`
//!    and no pictures. The store asks Flathub for the screenshot list, saves
//!    the pictures as `foo-1.png`, `foo-2.png`, … in `~/.cache/tux-store/
//!    screenshots/foo/` and uses them from then on (so "Clear cache" wipes them
//!    and they are fetched again).
//!
//! Downloads go through the system `curl`, like icons do. Only `https` links
//! on `flathub.org` hosts are ever followed.

use serde_json::Value;
use std::collections::HashSet;
use std::fs;
use std::path::{Path, PathBuf};
use std::process::{Command, Stdio};
use std::sync::Mutex;
use std::time::Duration;
use tux_abi::sync::lock;
use tux_abi::text::is_valid_package_name;
use tux_abi::{paths, Bus, Message};

/// Most pictures taken from local files.
const MAX_LOCAL: usize = 30;
/// Most pictures downloaded from Flathub (and the default of `count`).
const MAX_REMOTE: usize = 12;
const DEFAULT_REMOTE: usize = 8;
const MAX_IMAGE_BYTES: u64 = 8 * 1024 * 1024;
const MAX_JSON_BYTES: u64 = 2 * 1024 * 1024;
/// The widest version up to this width is downloaded (keeps files small).
const PREFERRED_WIDTH: u64 = 1600;
/// How long "Flathub has nothing for this app" is trusted.
const NEGATIVE_TTL: Duration = Duration::from_secs(7 * 24 * 3600);

/// Package names whose Flathub download is running right now.
pub type Inflight = Mutex<HashSet<String>>;

enum Fetch {
    Ok(Vec<u8>),
    /// HTTP 4xx: the server does not have it.
    NotFound,
    /// Network down, timeout, curl missing…
    Failed,
}

struct Manifest {
    flathub: Option<String>,
    count: usize,
}

fn publish(bus: &Bus, name: &str, files: &[PathBuf]) {
    bus.publish(&Message::ScreenshotsReady {
        name: name.to_string(),
        images: files.iter().map(|p| p.to_string_lossy().into_owned()).collect(),
    });
}

/// `<name>-<n>.png|jpg|jpeg` files of `dir`, sorted by `n` (1, 2, … 10, not 1, 10, 2).
pub fn numbered_images(dir: &Path, name: &str) -> Vec<PathBuf> {
    let prefix = format!("{name}-");
    let mut found: Vec<(u32, PathBuf)> = Vec::new();
    let Ok(rd) = fs::read_dir(dir) else {
        return Vec::new();
    };
    for e in rd.flatten() {
        let p = e.path();
        let ext_ok = p
            .extension()
            .and_then(|e| e.to_str())
            .is_some_and(|e| matches!(e.to_ascii_lowercase().as_str(), "png" | "jpg" | "jpeg"));
        if !ext_ok || !p.is_file() {
            continue;
        }
        let Some(stem) = p.file_stem().and_then(|s| s.to_str()) else {
            continue;
        };
        let Some(n) = stem.strip_prefix(prefix.as_str()).and_then(|n| n.parse::<u32>().ok()) else {
            continue;
        };
        if n >= 1 {
            found.push((n, p));
        }
    }
    found.sort_by_key(|(n, _)| *n);
    found.into_iter().map(|(_, p)| p).take(MAX_LOCAL).collect()
}

/// `org.mozilla.firefox` or `https://flathub.org/en/apps/org.mozilla.firefox` → the app id.
pub fn flathub_app_id(raw: &str) -> Option<String> {
    let t = raw.trim();
    let t = t.split(['?', '#']).next().unwrap_or("").trim_end_matches('/');
    let id = t.rsplit('/').next().unwrap_or("");
    let ok = !id.is_empty()
        && id.len() <= 128
        && !id.starts_with(['.', '-'])
        && id.bytes().all(|b| b.is_ascii_alphanumeric() || matches!(b, b'.' | b'_' | b'-'));
    ok.then(|| id.to_string())
}

fn read_manifest(dir: &Path, name: &str) -> Option<Manifest> {
    let path = dir.join(format!("{name}.json"));
    let text = fs::read_to_string(&path).ok()?;
    let v: Value = match serde_json::from_str(&text) {
        Ok(v) => v,
        Err(e) => {
            log::warn!("screenshots {}: {e}", path.display());
            return None;
        }
    };
    if let Some(p) = v.get("package").and_then(Value::as_str) {
        if p != name {
            log::warn!("screenshots {}: \"package\" is {p:?}, expected {name:?}", path.display());
            return None;
        }
    }
    let flathub = v.get("flathub").and_then(Value::as_str).and_then(flathub_app_id);
    let count = v
        .get("count")
        .and_then(Value::as_u64)
        .map(|c| c as usize)
        .unwrap_or(DEFAULT_REMOTE)
        .clamp(1, MAX_REMOTE);
    Some(Manifest { flathub, count })
}

/// Entry point, run on a worker thread: find the pictures and publish them.
/// Publishes nothing when the package has none.
pub fn serve(bus: &Bus, inflight: &Inflight, name: &str) {
    if !is_valid_package_name(name) {
        return;
    }
    for root in [paths::user_screenshots_dir(), paths::system_screenshots_dir()] {
        let dir = root.join(name);
        if !dir.is_dir() {
            continue;
        }
        let local = numbered_images(&dir, name);
        if !local.is_empty() {
            publish(bus, name, &local);
            return;
        }
        let Some(manifest) = read_manifest(&dir, name) else {
            continue;
        };
        if let Some(id) = manifest.flathub {
            from_flathub(bus, inflight, name, &id, manifest.count);
            return;
        }
    }
}

fn from_flathub(bus: &Bus, inflight: &Inflight, name: &str, id: &str, count: usize) {
    let cache = paths::cache_dir().join("screenshots").join(name);
    if cache.join(".complete").is_file() {
        let cached = numbered_images(&cache, name);
        if !cached.is_empty() {
            publish(bus, name, &cached);
            return;
        }
    }
    let nothing_there = fs::metadata(cache.join(".none"))
        .and_then(|m| m.modified())
        .ok()
        .and_then(|t| t.elapsed().ok())
        .is_some_and(|age| age < NEGATIVE_TTL);
    if nothing_there {
        return;
    }
    // One download per package at a time (the running one keeps publishing).
    if !lock(inflight).insert(name.to_string()) {
        return;
    }
    download_all(bus, name, id, count, &cache);
    lock(inflight).remove(name);
}

fn mark_none(cache: &Path) {
    if fs::create_dir_all(cache).is_ok() {
        let _ = fs::write(cache.join(".none"), b"none");
    }
}

fn download_all(bus: &Bus, name: &str, id: &str, count: usize, cache: &Path) {
    let api = format!("https://flathub.org/api/v2/appstream/{id}");
    let json = match fetch(&api, MAX_JSON_BYTES, 12) {
        Fetch::Ok(b) => b,
        Fetch::NotFound => {
            mark_none(cache);
            return;
        }
        Fetch::Failed => return,
    };
    let urls = screenshot_urls(&json, count);
    if urls.is_empty() {
        mark_none(cache);
        return;
    }
    let _ = fs::remove_dir_all(cache);
    if let Err(e) = fs::create_dir_all(cache) {
        log::warn!("cannot create {}: {e}", cache.display());
        return;
    }
    let mut saved: Vec<PathBuf> = Vec::new();
    let mut network_failed = false;
    for url in urls {
        match fetch(&url, MAX_IMAGE_BYTES, 20) {
            Fetch::Ok(bytes) => {
                let Some(ext) = sniff_ext(&bytes) else { continue };
                // Numbered by what was really saved, so there are no gaps.
                let path = cache.join(format!("{name}-{}.{ext}", saved.len() + 1));
                if fs::write(&path, &bytes).is_ok() {
                    saved.push(path);
                    publish(bus, name, &saved);
                }
            }
            Fetch::NotFound => {}
            Fetch::Failed => network_failed = true,
        }
    }
    if !saved.is_empty() && !network_failed {
        let _ = fs::write(cache.join(".complete"), b"ok");
    } else if saved.is_empty() && !network_failed {
        mark_none(cache);
    }
}

fn fetch(url: &str, max_bytes: u64, secs: u32) -> Fetch {
    let (t, m) = (secs.to_string(), max_bytes.to_string());
    let out = Command::new("curl")
        .args([
            "--silent",
            "--fail",
            "--location",
            "--proto",
            "=https",
            "--proto-redir",
            "=https",
            "--max-time",
            &t,
            "--max-filesize",
            &m,
            "--user-agent",
            concat!("tux-store/", env!("CARGO_PKG_VERSION")),
            "--output",
            "-",
            "--",
            url,
        ])
        .stdin(Stdio::null())
        .stderr(Stdio::null())
        .output();
    match out {
        Ok(o) if o.status.success() => Fetch::Ok(o.stdout),
        // curl exit code 22 = HTTP error status (404 …).
        Ok(o) if o.status.code() == Some(22) => Fetch::NotFound,
        Ok(_) => Fetch::Failed,
        Err(e) => {
            log::warn!("cannot run curl ({e}); screenshots cannot be downloaded");
            Fetch::Failed
        }
    }
}

/// `png` / `jpg` by magic bytes; anything else (HTML error page, WebP…) is rejected.
fn sniff_ext(b: &[u8]) -> Option<&'static str> {
    if b.starts_with(b"\x89PNG\r\n\x1a\n") {
        Some("png")
    } else if b.starts_with(&[0xFF, 0xD8, 0xFF]) {
        Some("jpg")
    } else {
        None
    }
}

/// Only plain `https://…flathub.org/…` links.
fn is_flathub_url(u: &str) -> bool {
    let Some(rest) = u.strip_prefix("https://") else {
        return false;
    };
    let host = rest.split('/').next().unwrap_or("");
    u.len() <= 500
        && !u.chars().any(|c| c.is_whitespace() || c.is_control())
        && !host.contains(['@', ':'])
        && (host == "flathub.org" || host.ends_with(".flathub.org"))
}

fn num(v: &Value) -> u64 {
    v.as_u64().or_else(|| v.as_str().and_then(|s| s.parse().ok())).unwrap_or(0)
}

/// The best picture of one screenshot entry: the widest not wider than
/// [`PREFERRED_WIDTH`], else the smallest available.
fn best_size(shot: &Value) -> Option<String> {
    if let Some(s) = shot.as_str() {
        return Some(s.to_string());
    }
    if let Some(sizes) = shot.get("sizes").and_then(Value::as_array) {
        let mut cands: Vec<(u64, &str)> = sizes
            .iter()
            .filter_map(|s| Some((s.get("width").map(num).unwrap_or(0), s.get("src")?.as_str()?)))
            .collect();
        cands.sort_by_key(|(w, _)| *w);
        let pick = cands.iter().rev().find(|(w, _)| *w > 0 && *w <= PREFERRED_WIDTH).or_else(|| cands.first())?;
        return Some(pick.1.to_string());
    }
    shot.get("src").or_else(|| shot.get("url")).and_then(Value::as_str).map(str::to_string)
}

/// Picture links from Flathub's appstream JSON (`"screenshots": [...]`).
fn screenshot_urls(json: &[u8], count: usize) -> Vec<String> {
    let Ok(v) = serde_json::from_slice::<Value>(json) else {
        return Vec::new();
    };
    let Some(list) = v.get("screenshots").and_then(Value::as_array) else {
        return Vec::new();
    };
    let mut out: Vec<String> = Vec::new();
    for shot in list {
        if let Some(u) = best_size(shot).filter(|u| is_flathub_url(u)) {
            if !out.contains(&u) {
                out.push(u);
            }
        }
        if out.len() >= count {
            break;
        }
    }
    out
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn app_ids() {
        assert_eq!(flathub_app_id("org.mozilla.firefox").as_deref(), Some("org.mozilla.firefox"));
        assert_eq!(
            flathub_app_id("https://flathub.org/en/apps/com.brave.Browser/").as_deref(),
            Some("com.brave.Browser")
        );
        assert_eq!(flathub_app_id("https://flathub.org/apps/x.y?z=1#a").as_deref(), Some("x.y"));
        assert_eq!(flathub_app_id("../evil/.."), None);
        assert_eq!(flathub_app_id(""), None);
    }

    #[test]
    fn urls_are_checked() {
        assert!(is_flathub_url("https://dl.flathub.org/media/a/b.png"));
        assert!(!is_flathub_url("http://dl.flathub.org/a.png"));
        assert!(!is_flathub_url("https://evil.com/flathub.org/a.png"));
        assert!(!is_flathub_url("https://flathub.org@evil.com/a.png"));
    }

    #[test]
    fn picks_the_right_size() {
        let j = br#"{"screenshots":[
            {"sizes":[{"src":"https://dl.flathub.org/a-small.png","width":"624"},
                      {"src":"https://dl.flathub.org/a-mid.png","width":"1248"},
                      {"src":"https://dl.flathub.org/a-big.png","width":2496}]},
            {"sizes":[{"src":"https://evil.com/x.png","width":"100"}]},
            {"sizes":[{"src":"https://dl.flathub.org/c.png","width":"2000"}]}]}"#;
        assert_eq!(
            screenshot_urls(j, 5),
            vec!["https://dl.flathub.org/a-mid.png".to_string(), "https://dl.flathub.org/c.png".to_string()]
        );
        assert_eq!(screenshot_urls(j, 1).len(), 1);
    }

    #[test]
    fn numbered_sort_and_filter() {
        let dir = std::env::temp_dir().join(format!("tux-shots-{}", std::process::id()));
        let _ = fs::remove_dir_all(&dir);
        fs::create_dir_all(&dir).unwrap();
        for f in ["foo-2.png", "foo-10.png", "foo-1.png", "foo-x.png", "bar-1.png", "foo.json", "foo-3.txt"] {
            fs::write(dir.join(f), b"x").unwrap();
        }
        let names: Vec<String> = numbered_images(&dir, "foo")
            .iter()
            .map(|p| p.file_name().unwrap().to_string_lossy().into_owned())
            .collect();
        assert_eq!(names, ["foo-1.png", "foo-2.png", "foo-10.png"]);
        let _ = fs::remove_dir_all(&dir);
    }

    #[test]
    fn magic_bytes() {
        assert_eq!(sniff_ext(b"\x89PNG\r\n\x1a\nrest"), Some("png"));
        assert_eq!(sniff_ext(&[0xFF, 0xD8, 0xFF, 0xE0]), Some("jpg"));
        assert_eq!(sniff_ext(b"<html>"), None);
    }
}
