//! Home covers: `data/images/cover/<app>/*.{png,jpg,jpeg}` plus, since 0.10.0,
//! covers downloaded from the trusted links of `remote_images.json`.
//!
//! Lazy loading: [`serve`] only scans what is already on disk (local folders
//! and earlier downloads) and publishes that list. A remote cover that was
//! never downloaded is listed with an empty `images` list; the UI asks for it
//! with `CoverImagesRequested` only when that cover is actually on screen, and
//! [`serve_one`] downloads that single cover. Nothing is downloaded for the
//! covers the user has not seen.

use crate::screenshots::{fetch, sniff_ext, Fetch};
use std::collections::HashSet;
use std::fs;
use std::path::{Path, PathBuf};
use std::sync::LazyLock;
use std::time::{Duration, SystemTime};
use tux_abi::{paths, Bus, Cover, Message};

const MAX_COVER_BYTES: u64 = 6 * 1024 * 1024;
const NONE_TTL: Duration = Duration::from_secs(7 * 24 * 3600);

/// Covers whose download is running right now (one job per name).
static DOWNLOADING: LazyLock<std::sync::Mutex<HashSet<String>>> =
    LazyLock::new(|| std::sync::Mutex::new(HashSet::new()));

fn is_image(p: &Path) -> bool {
    p.extension()
        .and_then(|e| e.to_str())
        .is_some_and(|e| matches!(e.to_ascii_lowercase().as_str(), "png" | "jpg" | "jpeg"))
}

fn images_in(dir: &Path) -> Vec<String> {
    let mut v: Vec<String> = fs::read_dir(dir)
        .map(|rd| {
            rd.flatten()
                .map(|e| e.path())
                .filter(|p| is_image(p))
                .map(|p| p.to_string_lossy().into_owned())
                .collect()
        })
        .unwrap_or_default();
    v.sort();
    v
}

/// `data/images/cover/<app>/` → one [`Cover`] per app, sorted by name.
pub fn scan_local() -> Vec<Cover> {
    let mut covers: Vec<Cover> = Vec::new();
    let Ok(rd) = fs::read_dir(paths::data_dir().join("images/cover")) else {
        return covers;
    };
    for dir in rd.flatten().filter(|d| d.path().is_dir()) {
        let images = images_in(&dir.path());
        if !images.is_empty() {
            covers.push(Cover {
                name: dir.file_name().to_string_lossy().into_owned(),
                images,
            });
        }
    }
    covers.sort_by(|a, b| a.name.cmp(&b.name));
    covers
}

fn cache_for(name: &str) -> PathBuf {
    paths::cache_dir().join("covers").join(name)
}

/// Replace (or add) one cover, keeping the list sorted by name.
fn upsert(covers: &mut Vec<Cover>, name: &str, images: Vec<String>) {
    covers.retain(|c| c.name != name);
    covers.push(Cover {
        name: name.to_string(),
        images,
    });
    covers.sort_by(|a, b| a.name.cmp(&b.name));
}

fn recently_missing(dir: &Path) -> bool {
    fs::metadata(dir.join(".none"))
        .and_then(|m| m.modified())
        .ok()
        .and_then(|t| SystemTime::now().duration_since(t).ok())
        .is_some_and(|age| age < NONE_TTL)
}

/// The complete cover list known without touching the network. Remote covers
/// that have not been downloaded yet are present with an empty `images` list
/// so the carousel can show their name and ask for them when they appear.
pub fn scan_all() -> Vec<Cover> {
    let mut covers = scan_local();
    for (name, entry) in tux_abi::remote::load() {
        if entry.covers.is_empty() || covers.iter().any(|c| c.name == name) {
            continue; // a shipped folder always wins
        }
        upsert(&mut covers, &name, images_in(&cache_for(&name)));
    }
    covers
}

/// Startup answer: everything already on disk, no downloads.
pub fn serve(bus: &Bus) {
    bus.publish(&Message::CoversReady { covers: scan_all() });
}

/// The cover on screen changed: make sure its remote pictures are available.
/// Local covers and already cached ones answer at once; only a never-downloaded
/// remote cover uses the network.
pub fn serve_one(bus: &Bus, name: &str) {
    if !tux_abi::text::is_valid_package_name(name) {
        return;
    }
    // A local folder wins and needs nothing.
    if images_in(&paths::data_dir().join("images/cover").join(name)).is_empty() {
        let entry = tux_abi::remote::load()
            .into_iter()
            .find(|(n, _)| n == name)
            .map(|(_, e)| e);
        let Some(urls) = entry.map(|e| e.covers).filter(|c| !c.is_empty()) else {
            return;
        };
        let dir = cache_for(name);
        let cached = images_in(&dir);
        if !cached.is_empty() {
            bus.publish(&Message::CoverImagesReady {
                name: name.to_string(),
                images: cached,
            });
            return;
        }
        if recently_missing(&dir) {
            return;
        }
        // One download per cover at a time.
        {
            let mut running = match DOWNLOADING.lock() {
                Ok(g) => g,
                Err(e) => e.into_inner(),
            };
            if !running.insert(name.to_string()) {
                return;
            }
        }

        // Another thread may have finished while we waited for the lock.
        let cached = images_in(&dir);
        if !cached.is_empty() {
            bus.publish(&Message::CoverImagesReady {
                name: name.to_string(),
                images: cached,
            });
            finished(name);
            return;
        }

        let _ = fs::create_dir_all(&dir);
        let (mut saved, mut network_down) = (0usize, false);
        for (i, url) in urls.iter().enumerate() {
            match fetch(url, MAX_COVER_BYTES, 20) {
                Fetch::Ok(bytes) => {
                    let Some(ext) = sniff_ext(&bytes) else {
                        log::warn!("{url}: not a PNG/JPEG picture");
                        continue;
                    };
                    let (path, tmp) = (
                        dir.join(format!("{}.{ext}", i + 1)),
                        dir.join(format!("{}.{ext}.tmp", i + 1)),
                    );
                    if fs::write(&tmp, &bytes).is_ok() && fs::rename(&tmp, &path).is_ok() {
                        saved += 1;
                        // Show the pictures as they arrive on the visible cover.
                        bus.publish(&Message::CoverImagesReady {
                            name: name.to_string(),
                            images: images_in(&dir),
                        });
                    }
                }
                Fetch::NotFound => log::warn!("{url}: not found"),
                Fetch::Failed => {
                    network_down = true;
                    break;
                }
            }
        }
        if saved == 0 && !network_down {
            let _ = fs::write(dir.join(".none"), b"");
        }
        finished(name);
    }
}

fn finished(name: &str) {
    let mut running = match DOWNLOADING.lock() {
        Ok(g) => g,
        Err(e) => e.into_inner(),
    };
    running.remove(name);
}

#[cfg(test)]
mod tests {
    use super::*;

    fn c(name: &str, img: &str) -> Cover {
        Cover {
            name: name.into(),
            images: vec![img.into()],
        }
    }

    #[test]
    fn upsert_replaces_and_sorts() {
        let mut v = vec![c("firefox", "/data/images/cover/firefox/1.png")];
        upsert(
            &mut v,
            "alacritty",
            vec!["/c/covers/alacritty/1.png".into()],
        );
        assert_eq!(
            v.iter().map(|c| c.name.as_str()).collect::<Vec<_>>(),
            ["alacritty", "firefox"]
        );
        // a longer remote list replaces the earlier entry, in the same slot
        upsert(
            &mut v,
            "alacritty",
            vec![
                "/c/covers/alacritty/1.png".into(),
                "/c/covers/alacritty/2.png".into(),
            ],
        );
        assert_eq!(v[0].images.len(), 2);
        assert_eq!(v.len(), 2);
    }

    #[test]
    fn empty_remote_cover_is_kept_for_lazy_download() {
        let mut v = Vec::new();
        upsert(&mut v, "future", Vec::new());
        assert_eq!(v.len(), 1);
        assert!(v[0].images.is_empty());
    }
}
