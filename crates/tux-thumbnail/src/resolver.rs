//! The icon resolution pipeline, split in two stages so cheap local lookups
//! are never queued behind slow network jobs:
//!
//! * **offline** — disk cache → bundled icons → system theme → negative cache
//! * **network** — exactly one request (Papirus) for the best-guess name

use crate::names::candidates;
use crate::themes::ThemeDirs;
use std::collections::HashMap;
use std::fs;
use std::io::Read;
use std::path::{Path, PathBuf};
use std::sync::OnceLock;
use std::time::{Duration, SystemTime};
use tux_abi::paths;

/// How long a "no icon found" verdict is trusted.
const NEGATIVE_TTL: Duration = Duration::from_secs(14 * 24 * 3600);
const MAX_ICON_BYTES: u64 = 2 * 1024 * 1024;

pub enum Offline {
    Hit(PathBuf),
    KnownMissing,
    Miss,
}

pub struct Resolver {
    cache_dir: PathBuf,
    local_root: PathBuf,
    /// `custom_icons.json`: candidate-name prefix → sub-directory.
    custom: Vec<(String, String)>,
    theme: OnceLock<ThemeDirs>,
    agent: ureq::Agent,
}

impl Resolver {
    pub fn new(cache_dir: PathBuf) -> Self {
        let local_root = paths::data_dir().join("images/icons");
        let custom: Vec<(String, String)> = fs::read_to_string(local_root.join("custom_icons.json"))
            .ok()
            .and_then(|t| serde_json::from_str::<HashMap<String, String>>(&t).ok())
            .map(|m| m.into_iter().collect())
            .unwrap_or_default();
        let agent = ureq::AgentBuilder::new()
            .timeout(Duration::from_secs(6))
            .user_agent(concat!("tux-store/", env!("CARGO_PKG_VERSION")))
            .build();
        Self { cache_dir, local_root, custom, theme: OnceLock::new(), agent }
    }

    pub fn warm_up(&self) {
        self.theme();
    }

    fn theme(&self) -> &ThemeDirs {
        self.theme.get_or_init(ThemeDirs::discover)
    }

    fn cached(&self, name: &str) -> Option<PathBuf> {
        ["svg", "png"]
            .iter()
            .map(|e| self.cache_dir.join(format!("{name}.{e}")))
            .find(|p| p.is_file())
    }

    fn bundled(&self, candidate: &str) -> Option<PathBuf> {
        for (prefix, dir) in &self.custom {
            if candidate.starts_with(prefix.as_str()) {
                for ext in ["svg", "png"] {
                    let p = self.local_root.join(dir).join(format!("{candidate}.{ext}"));
                    if p.is_file() {
                        return Some(p);
                    }
                }
            }
        }
        None
    }

    fn negative_marker(&self, name: &str) -> PathBuf {
        self.cache_dir.join(format!("{name}.notfound"))
    }

    fn is_known_missing(&self, name: &str) -> bool {
        fs::metadata(self.negative_marker(name))
            .and_then(|m| m.modified())
            .ok()
            .and_then(|t| SystemTime::now().duration_since(t).ok())
            .is_some_and(|age| age < NEGATIVE_TTL)
    }

    pub fn resolve_offline(&self, name: &str) -> Offline {
        if let Some(p) = self.cached(name) {
            return Offline::Hit(p);
        }
        for c in candidates(name) {
            if let Some(p) = self.bundled(&c) {
                return Offline::Hit(p);
            }
            if let Some(p) = self.theme().find(&c) {
                return Offline::Hit(p);
            }
        }
        if self.is_known_missing(name) {
            Offline::KnownMissing
        } else {
            Offline::Miss
        }
    }

    /// One HTTP request for the best candidate; caches the outcome either way.
    pub fn fetch(&self, name: &str) -> Option<PathBuf> {
        let best = candidates(name).into_iter().next().unwrap_or_else(|| name.to_string());
        match self.download(&best) {
            Some(bytes) => {
                let path = self.cache_dir.join(format!("{name}.svg"));
                let tmp = self.cache_dir.join(format!("{name}.svg.tmp"));
                if fs::write(&tmp, &bytes).is_ok() && fs::rename(&tmp, &path).is_ok() {
                    let _ = fs::remove_file(self.negative_marker(name));
                    return Some(path);
                }
                log::warn!("cannot write icon cache for {name}");
                None
            }
            None => {
                let _ = fs::write(self.negative_marker(name), b"");
                None
            }
        }
    }

    fn download(&self, candidate: &str) -> Option<Vec<u8>> {
        let url = format!(
            "https://raw.githubusercontent.com/PapirusDevelopmentTeam/papirus-icon-theme/master/Papirus/64x64/apps/{candidate}.svg"
        );
        let resp = self.agent.get(&url).call().ok()?;
        let mut buf = Vec::new();
        resp.into_reader().take(MAX_ICON_BYTES).read_to_end(&mut buf).ok()?;
        is_valid_image(&buf).then_some(buf)
    }

    /// Delete every cached icon / negative marker. Returns how many.
    pub fn clear_cache(&self) -> u32 {
        let mut removed = 0;
        if let Ok(rd) = fs::read_dir(&self.cache_dir) {
            for e in rd.flatten() {
                let p = e.path();
                if is_cache_file(&p) && fs::remove_file(&p).is_ok() {
                    removed += 1;
                }
            }
        }
        removed
    }
}

fn is_cache_file(p: &Path) -> bool {
    p.extension()
        .and_then(|e| e.to_str())
        .is_some_and(|e| matches!(e, "svg" | "png" | "notfound" | "tmp"))
}

/// Reject HTML error pages that were served with status 200.
pub fn is_valid_image(bytes: &[u8]) -> bool {
    if bytes.len() < 8 {
        return false;
    }
    if bytes.starts_with(b"\x89PNG") {
        return true;
    }
    let head = String::from_utf8_lossy(&bytes[..bytes.len().min(512)]).to_lowercase();
    let head = head.trim_start();
    if head.starts_with("<!doctype") || head.starts_with("<html") {
        return false;
    }
    head.contains("<svg") || head.starts_with("<?xml")
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn sniffing() {
        assert!(is_valid_image(b"<svg xmlns='x'></svg>"));
        assert!(is_valid_image(b"\x89PNG\r\n\x1a\n...."));
        assert!(!is_valid_image(b"<!DOCTYPE html><html></html>"));
        assert!(!is_valid_image(b"404: Not Found"));
    }
}
