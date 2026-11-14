//! Remote image links (since 0.10.0): icons and Home covers that are not
//! shipped as files but downloaded once from a **trusted host** and cached.
//!
//! Mappings live in `data/images/remote_images.json` (shipped) and
//! `~/.config/tux-store/remote_images.json` (the user's; its entries win):
//!
//! ```json
//! { "images": { "gcc": { "icon": "https://raw.githubusercontent.com/…/gcc-original.svg",
//!                        "covers": ["https://raw.githubusercontent.com/…/shot.png"] } } }
//! ```
//!
//! Only plain `https://` links on the hosts of [`TRUSTED_HOSTS`] are ever
//! followed, so a mapping file can never make the store contact an arbitrary
//! server. Invalid entries are skipped and logged; the rest still load.

use crate::paths;
use crate::text::is_valid_package_name;
use serde::Deserialize;
use std::collections::BTreeMap;
use std::fs;
use std::path::Path;

/// Hosts that may serve pictures. A host matches itself and its sub-domains.
pub const TRUSTED_HOSTS: [&str; 9] = [
    "raw.githubusercontent.com",
    "user-images.githubusercontent.com",
    "github.com",
    "gitlab.com",
    "upload.wikimedia.org",
    "dl.flathub.org",
    "flathub.org",
    "cdn.jsdelivr.net",
    "invent.kde.org",
];

/// Most Home cover pictures taken from one package's `covers` list.
pub const MAX_COVERS: usize = 3;
const MAX_FILE_BYTES: u64 = 512 * 1024;

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

/// The download link of a Flathub app's icon: the id alone is enough
/// (`org.mozilla.firefox` → `https://dl.flathub.org/media/icons/128x128/…png`).
pub fn flathub_icon_url(raw: &str) -> Option<String> {
    let id = flathub_app_id(raw)?;
    Some(format!("https://dl.flathub.org/media/icons/128x128/{id}.png"))
}

/// A plain `https://` link (no credentials, no port, no spaces) on a trusted host.
pub fn is_trusted_image_url(u: &str) -> bool {
    let Some(rest) = u.strip_prefix("https://") else {
        return false;
    };
    let host = rest.split(['/', '?', '#']).next().unwrap_or("");
    u.len() <= 500
        && !u.chars().any(|c| c.is_whitespace() || c.is_control())
        && !host.contains(['@', ':'])
        && TRUSTED_HOSTS.iter().any(|t| host == *t || host.ends_with(&format!(".{t}")))
}

/// What is known remotely about one package.
#[derive(Debug, Clone, Default, PartialEq, Eq)]
pub struct RemoteEntry {
    /// Link of the icon (last resort: used only if no theme / file source matched).
    pub icon: Option<String>,
    /// Icon names to look up in the icon theme the user runs (tried first).
    pub theme: Vec<String>,
    /// Icon file name (tried after the theme names): looked up next to the
    /// `remote_images.json` that declares it, then below `data/images/icons/`.
    pub file: Option<String>,
    /// Folder of the `remote_images.json` that declared this entry (set by [`load`]).
    pub dir: Option<std::path::PathBuf>,
    pub covers: Vec<String>,
}

impl RemoteEntry {
    /// Does this entry say anything about the *icon* (as opposed to covers only)?
    pub fn has_icon_source(&self) -> bool {
        self.icon.is_some() || !self.theme.is_empty() || self.file.is_some()
    }
}

/// An icon-theme name such as `onlyoffice-desktopeditors` or `org.gnome.Epiphany`.
pub fn is_valid_icon_name(n: &str) -> bool {
    !n.is_empty()
        && n.len() <= 100
        && !n.starts_with('.')
        && n.chars().all(|c| c.is_ascii_alphanumeric() || matches!(c, '.' | '_' | '-' | '+'))
}

/// A file name (or relative path without `..`) ending in `.svg` / `.png` / `.jpg`.
pub fn is_valid_icon_file(f: &str) -> bool {
    !f.is_empty()
        && f.len() <= 200
        && !f.starts_with('/')
        && !f.contains(['\\', '\0'])
        && f.split('/').all(|seg| !seg.is_empty() && seg != "." && seg != "..")
        && f.rsplit_once('.').is_some_and(|(_, e)| matches!(e.to_ascii_lowercase().as_str(), "svg" | "png" | "jpg"))
}

pub type RemoteMap = BTreeMap<String, RemoteEntry>;

#[derive(Debug, Deserialize)]
#[serde(deny_unknown_fields)]
struct RawEntry {
    #[serde(default)]
    icon: Option<String>,
    #[serde(default)]
    theme: Vec<String>,
    #[serde(default)]
    file: Option<String>,
    #[serde(default)]
    covers: Vec<String>,
}

#[derive(Debug, Deserialize)]
struct RawFile {
    #[serde(default)]
    images: BTreeMap<String, RawEntry>,
    #[allow(dead_code)]
    #[serde(default)]
    note: Option<String>,
}

/// Parse one mapping file. Bad names / links are dropped with a warning.
pub fn parse(text: &str, origin: &str) -> Result<RemoteMap, String> {
    let raw: RawFile = serde_json::from_str(text).map_err(|e| e.to_string())?;
    let mut out = RemoteMap::new();
    for (name, e) in raw.images {
        if !is_valid_package_name(&name) {
            log::warn!("{origin}: invalid package name {name:?} ignored");
            continue;
        }
        let icon = e.icon.filter(|u| {
            let ok = is_trusted_image_url(u);
            if !ok {
                log::warn!("{origin}: {name}: icon link is not https on a trusted host, ignored");
            }
            ok
        });
        let theme: Vec<String> = e
            .theme
            .into_iter()
            .filter(|t| {
                let ok = is_valid_icon_name(t);
                if !ok {
                    log::warn!("{origin}: {name}: invalid icon theme name {t:?} ignored");
                }
                ok
            })
            .take(8)
            .collect();
        let file = e.file.filter(|f| {
            let ok = is_valid_icon_file(f);
            if !ok {
                log::warn!("{origin}: {name}: icon file {f:?} must be a relative .svg/.png/.jpg path, ignored");
            }
            ok
        });
        let covers: Vec<String> = e
            .covers
            .into_iter()
            .filter(|u| {
                let ok = is_trusted_image_url(u);
                if !ok {
                    log::warn!("{origin}: {name}: cover link is not https on a trusted host, ignored");
                }
                ok
            })
            .take(MAX_COVERS)
            .collect();
        let entry = RemoteEntry { icon, theme, file, dir: None, covers };
        if entry.has_icon_source() || !entry.covers.is_empty() {
            out.insert(name, entry);
        }
    }
    Ok(out)
}

fn load_file(path: &Path) -> RemoteMap {
    let Ok(meta) = fs::metadata(path) else { return RemoteMap::new() };
    if meta.len() > MAX_FILE_BYTES {
        log::warn!("{}: larger than {MAX_FILE_BYTES} bytes, ignored", path.display());
        return RemoteMap::new();
    }
    match fs::read_to_string(path).map_err(|e| e.to_string()).and_then(|t| parse(&t, &path.display().to_string())) {
        Ok(mut m) => {
            let dir = path.parent().map(Path::to_path_buf);
            m.values_mut().for_each(|e| e.dir = dir.clone());
            m
        }
        Err(e) => {
            log::warn!("{}: {e}", path.display());
            RemoteMap::new()
        }
    }
}

/// Shipped mappings, overridden per package by the user's own file.
pub fn load() -> RemoteMap {
    let mut all = load_file(&paths::system_remote_images_file());
    all.extend(load_file(&paths::user_remote_images_file()));
    all
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn trusted_urls() {
        assert!(is_trusted_image_url("https://raw.githubusercontent.com/a/b/master/x.svg"));
        assert!(is_trusted_image_url("https://objects.github.com/x.png"));
        assert!(!is_trusted_image_url("http://raw.githubusercontent.com/x.svg"));
        assert!(!is_trusted_image_url("https://evil.com/raw.githubusercontent.com/x.svg"));
        assert!(!is_trusted_image_url("https://raw.githubusercontent.com@evil.com/x.svg"));
        assert!(!is_trusted_image_url("https://raw.githubusercontent.com:8443/x.svg"));
        assert!(!is_trusted_image_url("https://notgithub.com/x.svg"));
        assert!(!is_trusted_image_url("https://github.com/a b.svg"));
    }

    #[test]
    fn mapping_file_is_filtered() {
        let m = parse(
            r#"{"note":"n","images":{
              "gcc":{"icon":"https://raw.githubusercontent.com/a/gcc.svg"},
              "bad name":{"icon":"https://raw.githubusercontent.com/a/x.svg"},
              "evil":{"icon":"https://evil.com/x.svg"},
              "alacritty":{"icon":"https://github.com/a.svg","covers":["https://raw.githubusercontent.com/1.png","https://evil.com/2.png","https://github.com/3.png","https://github.com/4.png","https://github.com/5.png"]}}}"#,
            "test",
        )
        .unwrap();
        assert_eq!(m.keys().map(String::as_str).collect::<Vec<_>>(), ["alacritty", "gcc"]);
        assert_eq!(m["alacritty"].covers.len(), MAX_COVERS);
        assert!(parse(r#"{"images":{"x":{"icn":"y"}}}"#, "t").is_err(), "typos are errors");
    }

    #[test]
    fn theme_and_file_sources() {
        let m = parse(
            r#"{"images":{"a":{"theme":["onlyoffice-desktopeditors","org.gnome.Epiphany","bad name","../x"],"file":"sub/a.svg"},
                          "b":{"file":"../evil.svg"},"c":{"file":"/etc/passwd.png"}}}"#,
            "t",
        )
        .unwrap();
        assert_eq!(m["a"].theme, ["onlyoffice-desktopeditors", "org.gnome.Epiphany"]);
        assert_eq!(m["a"].file.as_deref(), Some("sub/a.svg"));
        assert!(!m.contains_key("b") && !m.contains_key("c"), "unsafe file paths are dropped");
    }

    #[test]
    fn shipped_mapping_is_valid() {
        let p = Path::new(env!("CARGO_MANIFEST_DIR")).join("../../data/images/remote_images.json");
        let text = fs::read_to_string(&p).unwrap();
        let raw: RawFile = serde_json::from_str(&text).unwrap();
        let parsed = parse(&text, "shipped").unwrap();
        assert_eq!(raw.images.len(), parsed.len(), "a shipped entry was rejected (bad name or link)");
        for (n, e) in &parsed {
            assert!(e.has_icon_source() || !e.covers.is_empty(), "{n}");
        }
    }
}
