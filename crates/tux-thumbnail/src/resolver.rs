//! The icon resolution pipeline, split in two stages so cheap local lookups
//! are never queued behind slow network jobs:
//!
//! * **offline** — active system icon theme → bundled icons → hicolor/pixmaps
//!   → downloaded icons (disk cache) → negative cache
//! * **network** — exactly one request (Papirus) for the best-guess name
//!
//! The system theme is always consulted *before* the download cache, so icons
//! fetched earlier can never shadow the theme the user runs now.
//!
//! Downloads go through the system `curl` (a hard dependency of pacman, so it
//! is always present on Arch). This keeps TLS — and the C/asm code of `ring`
//! that used to be statically linked into this `.so` — out of the module.

use crate::names::candidates;
use crate::themes::ThemeDirs;
use std::collections::HashMap;
use std::fs;
use std::path::{Path, PathBuf};
use std::process::{Command, Stdio};
use std::sync::atomic::{AtomicBool, Ordering};
use std::sync::{Arc, Mutex};
use std::time::{Duration, SystemTime};
use tux_abi::paths;
use tux_abi::script::{is_valid_icon_file_name, IconSource};

/// How long a "no icon found" verdict is trusted.
const NEGATIVE_TTL: Duration = Duration::from_secs(14 * 24 * 3600);
const MAX_ICON_BYTES: u64 = 2 * 1024 * 1024;

pub enum Offline {
    Hit(PathBuf),
    KnownMissing,
    Miss,
}

enum Download {
    Ok(Vec<u8>),
    /// The server answered "no such icon" (HTTP 4xx).
    NotFound,
    /// Network down, curl missing, timeout… — not worth a negative marker.
    Failed,
}

/// An add-on package that declares where its icon comes from.
struct ScriptIcon {
    id: String,
    /// The folder holding the script's JSON (for `"file"` sources).
    dir: PathBuf,
    sources: Vec<IconSource>,
}

pub struct Resolver {
    /// `~/.cache/tux-store` — everything the app ever caches lives below it.
    cache_root: PathBuf,
    /// `~/.cache/tux-store/icons`
    cache_dir: PathBuf,
    local_root: PathBuf,
    /// `custom_icons.json`: candidate-name prefix → sub-directory.
    custom: Vec<(String, String)>,
    theme: Mutex<Option<Arc<ThemeDirs>>>,
    warned_curl: AtomicBool,
    script_icons: Mutex<Option<Arc<Vec<ScriptIcon>>>>,
}

impl Resolver {
    pub fn new(cache_root: PathBuf) -> Self {
        let local_root = paths::data_dir().join("images/icons");
        let custom: Vec<(String, String)> = fs::read_to_string(local_root.join("custom_icons.json"))
            .ok()
            .and_then(|t| serde_json::from_str::<HashMap<String, String>>(&t).ok())
            .map(|m| m.into_iter().collect())
            .unwrap_or_default();
        let cache_dir = cache_root.join("icons");
        Self {
            cache_root,
            cache_dir,
            local_root,
            custom,
            theme: Mutex::new(None),
            warned_curl: AtomicBool::new(false),
            script_icons: Mutex::new(None),
        }
    }

    pub fn warm_up(&self) {
        self.theme();
    }

    /// Discovered lazily, once, and again after the cache is cleared (so a
    /// theme change takes effect without restarting the store).
    fn theme(&self) -> Arc<ThemeDirs> {
        let mut g = tux_abi::sync::lock(&self.theme);
        g.get_or_insert_with(|| Arc::new(ThemeDirs::discover())).clone()
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

    /// Icon declarations of all add-on packages, read once (and again after
    /// the cache is cleared).
    fn script_icon_table(&self) -> Arc<Vec<ScriptIcon>> {
        let mut g = tux_abi::sync::lock(&self.script_icons);
        g.get_or_insert_with(|| {
            let list = tux_abi::script::load_all()
                .into_iter()
                .filter_map(|l| {
                    let icon = l.script.icon.as_ref()?;
                    Some(ScriptIcon {
                        id: l.script.id.clone(),
                        dir: l.path.parent()?.to_path_buf(),
                        sources: icon.sources().into_iter().cloned().collect(),
                    })
                })
                .collect();
            Arc::new(list)
        })
        .clone()
    }

    fn script_icon(&self, name: &str) -> Option<(PathBuf, Vec<IconSource>)> {
        self.script_icon_table().iter().find(|s| s.id == name).map(|s| (s.dir.clone(), s.sources.clone()))
    }

    /// `"file"` source: a picture next to the JSON. `.ico` files are unpacked
    /// (their embedded PNG) into the cache because the UI cannot show ICO.
    fn script_file_icon(&self, dir: &Path, file: &str, name: &str) -> Option<PathBuf> {
        if !is_valid_icon_file_name(file) {
            return None;
        }
        let path = dir.join(file);
        let meta = fs::metadata(&path).ok()?;
        if !meta.is_file() || meta.len() > MAX_ICON_BYTES {
            return None;
        }
        let bytes = fs::read(&path).ok()?;
        if file.to_ascii_lowercase().ends_with(".ico") {
            let png = ico_to_png(&bytes)?;
            let out = self.cache_dir.join(format!("{name}.png"));
            let _ = fs::create_dir_all(&self.cache_dir);
            fs::write(&out, png).ok()?;
            return Some(out);
        }
        is_valid_image(&bytes).then_some(path)
    }

    /// `"theme"` source: ask the icon theme the user runs.
    fn script_theme_icon(&self, icon: &str) -> Option<PathBuf> {
        let cands = [icon.to_string()];
        let theme = self.theme();
        theme.find_primary(&cands).or_else(|| theme.find_fallback(&cands))
    }

    /// An icon shipped for exactly this package (or script id). Looked up by
    /// the *exact* name only — never by a truncated guess.
    fn exact_bundled(&self, name: &str) -> Option<PathBuf> {
        if let Some(p) = self.bundled(name) {
            return Some(p);
        }
        // `images/icons/scripts/<id>.svg` (shipped) and
        // `~/.config/tux-store/scripts/icons/<id>.svg` (user scripts).
        let dirs = [self.local_root.join("scripts"), paths::user_scripts_dir().join("icons")];
        dirs.iter()
            .flat_map(|d| ["svg", "png"].map(|e| d.join(format!("{name}.{e}"))))
            .find(|p| p.is_file())
    }

    pub fn resolve_offline(&self, name: &str) -> Offline {
        let cands = candidates(name);

        // 00. an add-on package says in its JSON where its icon comes from:
        //     file next to the JSON, icon theme, or a link — tried in that order.
        if let Some((dir, sources)) = self.script_icon(name) {
            let mut wants_download = false;
            for src in &sources {
                if let Some(f) = &src.file {
                    if let Some(p) = self.script_file_icon(&dir, f, name) {
                        return Offline::Hit(p);
                    }
                } else if let Some(t) = &src.theme {
                    if let Some(p) = self.script_theme_icon(t) {
                        return Offline::Hit(p);
                    }
                } else if src.url.is_some() {
                    if let Some(p) = self.cached(name) {
                        return Offline::Hit(p);
                    }
                    wants_download = true;
                }
            }
            if wants_download && !self.is_known_missing(name) {
                return Offline::Miss; // the network stage fetches the link
            }
        }

        // 0. an icon made for exactly this package. This must come before the
        //    theme: for `libreoffice-fresh-ar` the candidate list also holds the
        //    shortened `libreoffice-fresh` / `libreoffice`, and the theme would
        //    answer with its generic icon, hiding the bundled one with the
        //    language letters on it.
        if let Some(p) = self.exact_bundled(name) {
            return Offline::Hit(p);
        }
        let theme = self.theme();

        // 1. the icon theme the user actually runs
        if let Some(p) = theme.find_primary(&cands) {
            return Offline::Hit(p);
        }
        // 2. icons shipped with the store (apps most themes lack)
        for c in &cands {
            if let Some(p) = self.bundled(c) {
                return Offline::Hit(p);
            }
        }
        // 3. hicolor / pixmaps
        if let Some(p) = theme.find_fallback(&cands) {
            return Offline::Hit(p);
        }
        // 4. earlier downloads — only when the theme has nothing
        if let Some(p) = self.cached(name) {
            return Offline::Hit(p);
        }
        if self.is_known_missing(name) {
            Offline::KnownMissing
        } else {
            Offline::Miss
        }
    }

    /// One HTTP request for the best candidate; caches the outcome.
    pub fn fetch(&self, name: &str) -> Option<PathBuf> {
        // An add-on package with a link gets exactly that link, not a guess.
        let declared = self
            .script_icon(name)
            .and_then(|(_, sources)| sources.into_iter().find_map(|s| s.url))
            .filter(|u| tux_abi::script::is_valid_icon_url(u));
        let result = match declared {
            Some(url) => self.download_url(&url),
            None => {
                let best = candidates(name).into_iter().next().unwrap_or_else(|| name.to_string());
                self.download(&best)
            }
        };
        match result {
            Download::Ok(bytes) => {
                let ext = if bytes.starts_with(b"\x89PNG") { "png" } else { "svg" };
                let path = self.cache_dir.join(format!("{name}.{ext}"));
                let tmp = self.cache_dir.join(format!("{name}.{ext}.tmp"));
                let _ = fs::create_dir_all(&self.cache_dir);
                if fs::write(&tmp, &bytes).is_ok() && fs::rename(&tmp, &path).is_ok() {
                    let _ = fs::remove_file(self.negative_marker(name));
                    return Some(path);
                }
                log::warn!("cannot write icon cache for {name}");
                None
            }
            Download::NotFound => {
                let _ = fs::create_dir_all(&self.cache_dir);
                let _ = fs::write(self.negative_marker(name), b"");
                None
            }
            Download::Failed => None,
        }
    }

    fn download(&self, candidate: &str) -> Download {
        let url = format!(
            "https://raw.githubusercontent.com/PapirusDevelopmentTeam/papirus-icon-theme/master/Papirus/64x64/apps/{candidate}.svg"
        );
        self.download_url(&url)
    }

    fn download_url(&self, url: &str) -> Download {
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
                "6",
                "--max-filesize",
                &MAX_ICON_BYTES.to_string(),
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
        let out = match out {
            Ok(o) => o,
            Err(e) => {
                if !self.warned_curl.swap(true, Ordering::Relaxed) {
                    log::warn!("cannot run curl ({e}); icons will only come from the system theme");
                }
                return Download::Failed;
            }
        };
        if out.status.success() {
            return if is_valid_image(&out.stdout) { Download::Ok(out.stdout) } else { Download::NotFound };
        }
        // curl exit code 22 = HTTP error status (404 …).
        if out.status.code() == Some(22) {
            Download::NotFound
        } else {
            Download::Failed
        }
    }

    /// Delete **everything** the store cached under `~/.cache/tux-store`
    /// (icons, negative markers, anything a future module adds) and forget the
    /// detected icon theme. Returns how many files were removed.
    pub fn clear_cache(&self) -> u32 {
        let removed = clear_dir_contents(&self.cache_root);
        let _ = fs::create_dir_all(&self.cache_dir);
        *tux_abi::sync::lock(&self.theme) = None;
        *tux_abi::sync::lock(&self.script_icons) = None;
        removed
    }
}

/// Remove every entry inside `root`, but only if `root` really is the store's
/// own cache directory. Symlinks are removed, never followed.
fn clear_dir_contents(root: &Path) -> u32 {
    let is_ours = root.is_absolute()
        && root.file_name().is_some_and(|n| n == paths::APP_DIR)
        && root.parent().is_some_and(|p| p.parent().is_some());
    if !is_ours {
        log::error!("refusing to clear unexpected cache path {}", root.display());
        return 0;
    }
    let mut removed = 0;
    let Ok(rd) = fs::read_dir(root) else { return 0 };
    for e in rd.flatten() {
        let p = e.path();
        let is_dir = fs::symlink_metadata(&p).map(|m| m.is_dir()).unwrap_or(false);
        if is_dir {
            let n = count_files(&p);
            if fs::remove_dir_all(&p).is_ok() {
                removed += n;
            }
        } else if fs::remove_file(&p).is_ok() {
            removed += 1;
        }
    }
    removed
}

fn count_files(dir: &Path) -> u32 {
    let mut n = 0;
    if let Ok(rd) = fs::read_dir(dir) {
        for e in rd.flatten() {
            match fs::symlink_metadata(e.path()) {
                Ok(m) if m.is_dir() => n += count_files(&e.path()),
                Ok(_) => n += 1,
                Err(_) => {}
            }
        }
    }
    n
}

/// The largest PNG image stored inside an `.ico` file (modern icons embed
/// PNGs). Old BMP-only icons are not supported and give `None`.
pub fn ico_to_png(bytes: &[u8]) -> Option<Vec<u8>> {
    let u16le = |o: usize| bytes.get(o..o + 2).map(|b| u16::from_le_bytes([b[0], b[1]]) as usize);
    let u32le = |o: usize| bytes.get(o..o + 4).map(|b| u32::from_le_bytes([b[0], b[1], b[2], b[3]]) as usize);
    if u16le(0)? != 0 || u16le(2)? != 1 {
        return None;
    }
    let count = u16le(4)?;
    let mut best: Option<(usize, &[u8])> = None;
    for i in 0..count.min(64) {
        let e = 6 + i * 16;
        let width = match *bytes.get(e)? {
            0 => 256,
            w => w as usize,
        };
        let (size, offset) = (u32le(e + 8)?, u32le(e + 12)?);
        let data = bytes.get(offset..offset.checked_add(size)?)?;
        if data.starts_with(b"\x89PNG") && best.map_or(true, |(w, _)| width > w) {
            best = Some((width, data));
        }
    }
    best.map(|(_, d)| d.to_vec())
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
    fn exact_bundled_icon_beats_everything() {
        let base = std::env::temp_dir().join(format!("tux-icon-test-{}", std::process::id()));
        let dir = base.join("libreoffice-fresh");
        fs::create_dir_all(&dir).unwrap();
        fs::write(dir.join("libreoffice-fresh-ar.svg"), b"<svg/>").unwrap();
        let r = Resolver {
            cache_root: base.clone(),
            cache_dir: base.join("icons"),
            local_root: base.clone(),
            custom: vec![("libreoffice-fresh".into(), "libreoffice-fresh".into())],
            theme: Mutex::new(None),
            warned_curl: AtomicBool::new(false),
            script_icons: Mutex::new(None),
        };
        assert_eq!(r.exact_bundled("libreoffice-fresh-ar"), Some(dir.join("libreoffice-fresh-ar.svg")));
        assert_eq!(r.exact_bundled("libreoffice-fresh-xx"), None);
        let _ = fs::remove_dir_all(&base);
    }

    #[test]
    fn ico_with_embedded_png_is_unpacked() {
        let png = b"\x89PNG\r\n\x1a\nDATA".to_vec();
        let mut ico = vec![0, 0, 1, 0, 1, 0]; // header: 1 image
        ico.extend([32, 32, 0, 0, 1, 0, 32, 0]); // entry: 32x32
        ico.extend((png.len() as u32).to_le_bytes());
        ico.extend(22u32.to_le_bytes()); // data offset
        ico.extend(&png);
        assert_eq!(ico_to_png(&ico), Some(png));
        assert_eq!(ico_to_png(b"not an icon"), None);
        // BMP payload: unsupported
        let mut bmp = ico.clone();
        bmp[22] = b'B';
        assert_eq!(ico_to_png(&bmp), None);
    }

    #[test]
    fn script_declares_file_then_theme_sources() {
        let base = std::env::temp_dir().join(format!("tux-script-icon-{}", std::process::id()));
        fs::create_dir_all(&base).unwrap();
        fs::write(base.join("logo.svg"), b"<svg xmlns='x'/>").unwrap();
        fs::write(base.join("fake.png"), b"<html>no</html>").unwrap();
        let r = Resolver::new(base.join("cache"));
        // a real picture next to the JSON is used
        assert_eq!(r.script_file_icon(&base, "logo.svg", "demo"), Some(base.join("logo.svg")));
        // wrong content, missing file and path tricks are refused
        assert_eq!(r.script_file_icon(&base, "fake.png", "demo"), None);
        assert_eq!(r.script_file_icon(&base, "missing.svg", "demo"), None);
        assert_eq!(r.script_file_icon(&base, "../logo.svg", "demo"), None);
        let _ = fs::remove_dir_all(&base);
    }

    #[test]
    fn sniffing() {
        assert!(is_valid_image(b"<svg xmlns='x'></svg>"));
        assert!(is_valid_image(b"\x89PNG\r\n\x1a\n...."));
        assert!(!is_valid_image(b"<!DOCTYPE html><html></html>"));
        assert!(!is_valid_image(b"404: Not Found"));
    }

    #[test]
    fn clear_refuses_foreign_paths() {
        assert_eq!(clear_dir_contents(Path::new("/")), 0);
        assert_eq!(clear_dir_contents(Path::new("/home/someone")), 0);
        assert_eq!(clear_dir_contents(Path::new("relative/tux-store")), 0);
    }

    #[test]
    fn clear_removes_nested_files() {
        let base = std::env::temp_dir().join(format!("tux-clear-test-{}", std::process::id()));
        let root = base.join(".cache").join(paths::APP_DIR);
        fs::create_dir_all(root.join("icons")).unwrap();
        fs::create_dir_all(root.join("other/deep")).unwrap();
        fs::write(root.join("icons/a.svg"), b"x").unwrap();
        fs::write(root.join("other/deep/b.bin"), b"x").unwrap();
        fs::write(root.join("c.txt"), b"x").unwrap();
        assert_eq!(clear_dir_contents(&root), 3);
        assert!(root.is_dir());
        assert_eq!(fs::read_dir(&root).unwrap().count(), 0);
        let _ = fs::remove_dir_all(&base);
    }
}
