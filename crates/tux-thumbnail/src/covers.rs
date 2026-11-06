//! Home covers: `data/images/cover/<app>/*.{png,jpg,jpeg}` plus, since 0.10.0,
//! covers downloaded from the trusted links of `remote_images.json`.
//!
//! The local covers are published at once. Remote covers already in the cache
//! are added to that first answer; missing ones are downloaded in the
//! background and the (longer) list is published again after each success.
//! A local cover of the same name always wins over a remote one.

use crate::screenshots::{fetch, sniff_ext, Fetch};
use std::fs;
use std::path::{Path, PathBuf};
use std::sync::atomic::{AtomicBool, Ordering};
use std::time::{Duration, SystemTime};
use tux_abi::{paths, Bus, Cover, Message};

const MAX_COVER_BYTES: u64 = 6 * 1024 * 1024;
const NONE_TTL: Duration = Duration::from_secs(7 * 24 * 3600);
static DOWNLOADING: AtomicBool = AtomicBool::new(false);

fn is_image(p: &Path) -> bool {
    p.extension()
        .and_then(|e| e.to_str())
        .is_some_and(|e| matches!(e.to_ascii_lowercase().as_str(), "png" | "jpg" | "jpeg"))
}

fn images_in(dir: &Path) -> Vec<String> {
    let mut v: Vec<String> = fs::read_dir(dir)
        .map(|rd| rd.flatten().map(|e| e.path()).filter(|p| is_image(p)).map(|p| p.to_string_lossy().into_owned()).collect())
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
            covers.push(Cover { name: dir.file_name().to_string_lossy().into_owned(), images });
        }
    }
    covers.sort_by(|a, b| a.name.cmp(&b.name));
    covers
}

fn cache_for(name: &str) -> PathBuf {
    paths::cache_dir().join("covers").join(name)
}

/// Add `images` as the cover of `name` unless a (local) cover of that name exists.
fn merge(covers: &mut Vec<Cover>, name: &str, images: Vec<String>) {
    if images.is_empty() || covers.iter().any(|c| c.name == name && !c.images.iter().any(|i| i.contains("/covers/"))) {
        return;
    }
    covers.retain(|c| c.name != name);
    covers.push(Cover { name: name.to_string(), images });
    covers.sort_by(|a, b| a.name.cmp(&b.name));
}

fn recently_missing(dir: &Path) -> bool {
    fs::metadata(dir.join(".none"))
        .and_then(|m| m.modified())
        .ok()
        .and_then(|t| SystemTime::now().duration_since(t).ok())
        .is_some_and(|age| age < NONE_TTL)
}

pub fn serve(bus: &Bus) {
    let mut covers = scan_local();
    let remote: Vec<(String, Vec<String>)> = tux_abi::remote::load()
        .into_iter()
        .filter(|(_, e)| !e.covers.is_empty())
        .map(|(n, e)| (n, e.covers))
        .collect();
    let mut todo = Vec::new();
    for (name, urls) in remote {
        if covers.iter().any(|c| c.name == name) {
            continue; // shipped as files: those win
        }
        let cached = images_in(&cache_for(&name));
        if cached.is_empty() {
            todo.push((name, urls));
        } else {
            merge(&mut covers, &name, cached);
        }
    }
    bus.publish(&Message::CoversReady { covers: covers.clone() });
    if todo.is_empty() || DOWNLOADING.swap(true, Ordering::SeqCst) {
        return;
    }
    for (name, urls) in todo {
        let dir = cache_for(&name);
        if recently_missing(&dir) {
            continue;
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
                    let (path, tmp) = (dir.join(format!("{}.{ext}", i + 1)), dir.join(format!("{}.{ext}.tmp", i + 1)));
                    if fs::write(&tmp, &bytes).is_ok() && fs::rename(&tmp, &path).is_ok() {
                        saved += 1;
                    }
                }
                Fetch::NotFound => log::warn!("{url}: not found"),
                Fetch::Failed => {
                    network_down = true;
                    break;
                }
            }
        }
        if saved > 0 {
            merge(&mut covers, &name, images_in(&dir));
            bus.publish(&Message::CoversReady { covers: covers.clone() });
        } else if !network_down {
            let _ = fs::write(dir.join(".none"), b"");
        }
        if network_down {
            break; // offline: try again next start
        }
    }
    DOWNLOADING.store(false, Ordering::SeqCst);
}

#[cfg(test)]
mod tests {
    use super::*;

    fn c(name: &str, img: &str) -> Cover {
        Cover { name: name.into(), images: vec![img.into()] }
    }

    #[test]
    fn local_wins_remote_is_added_sorted() {
        let mut v = vec![c("firefox", "/data/images/cover/firefox/1.png")];
        merge(&mut v, "firefox", vec!["/home/u/.cache/tux-store/covers/firefox/1.png".into()]);
        assert_eq!(v[0].images[0], "/data/images/cover/firefox/1.png");
        merge(&mut v, "alacritty", vec!["/home/u/.cache/tux-store/covers/alacritty/1.png".into()]);
        assert_eq!(v.iter().map(|c| c.name.as_str()).collect::<Vec<_>>(), ["alacritty", "firefox"]);
        // a longer remote list replaces the earlier remote entry
        merge(&mut v, "alacritty", vec!["/c/covers/alacritty/1.png".into(), "/c/covers/alacritty/2.png".into()]);
        assert_eq!(v[0].images.len(), 2);
    }
}
