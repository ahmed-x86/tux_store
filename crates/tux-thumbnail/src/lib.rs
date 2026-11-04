//! `libtux_thumbnail.so` — turns package names into icon files and lists the
//! home-page cover images.
//!
//! Handles: `IconRequested`, `CoversRequested`, `ScreenshotsRequested`, `ClearIconCache` (wipes the
//! whole `~/.cache/tux-store`), `UiReady` (warm-up). Answers: `IconReady`,
//! `IconFailed`, `CoversReady`, `IconCacheCleared`.
//!
//! Pipeline: requests are coalesced per package, resolved offline by one
//! "local" thread (cache / bundled / theme), and only true misses go to a pool
//! of network workers — so a slow GitHub never delays a local icon.

mod names;
mod resolver;
mod screenshots;
mod themes;

use crossbeam_channel::{unbounded, Receiver, Sender};
use resolver::{Offline, Resolver};
use std::collections::HashSet;
use std::fs;
use std::path::PathBuf;
use std::sync::{Arc, Mutex};
use std::thread;
use tux_abi::sync::lock;
use tux_abi::text::is_valid_package_name;
use tux_abi::{paths, Bus, Cover, Message, Module};

const NET_WORKERS: usize = 8;

pub struct ThumbnailModule {
    bus: Bus,
    resolver: Arc<Resolver>,
    inflight: Arc<Mutex<HashSet<String>>>,
    /// Screenshot downloads running right now.
    shots: Arc<screenshots::Inflight>,
    local_tx: Sender<String>,
}

type Inflight = Arc<Mutex<HashSet<String>>>;

fn finish(bus: &Bus, inflight: &Inflight, name: String, path: Option<PathBuf>) {
    lock(inflight).remove(&name);
    match path {
        Some(p) => bus.publish(&Message::IconReady { name, path: p.to_string_lossy().into_owned() }),
        None => bus.publish(&Message::IconFailed { name }),
    }
}

fn spawn_named<F: FnOnce() + Send + 'static>(name: String, f: F) {
    if let Err(e) = thread::Builder::new().name(name).spawn(f) {
        log::error!("cannot spawn worker thread: {e}");
    }
}

impl Module for ThumbnailModule {
    fn create(bus: Bus) -> Self {
        // Everything cached by the store lives under ~/.cache/tux-store
        // (XDG_CACHE_HOME respected); icons are in its `icons/` sub-directory.
        let cache_root = paths::cache_dir();
        let icons_dir = cache_root.join("icons");
        if let Err(e) = fs::create_dir_all(&icons_dir) {
            log::warn!("cannot create {}: {e}", icons_dir.display());
        }
        let resolver = Arc::new(Resolver::new(cache_root));
        let inflight: Inflight = Arc::default();
        let (local_tx, local_rx) = unbounded::<String>();
        let (net_tx, net_rx) = unbounded::<String>();

        // Stage 1: offline lookups (single thread, never blocks on network).
        {
            let (resolver, inflight) = (resolver.clone(), inflight.clone());
            spawn_named("thumb-local".into(), move || {
                for name in local_rx {
                    match resolver.resolve_offline(&name) {
                        Offline::Hit(p) => finish(&bus, &inflight, name, Some(p)),
                        Offline::KnownMissing => finish(&bus, &inflight, name, None),
                        Offline::Miss => {
                            if net_tx.send(name.clone()).is_err() {
                                finish(&bus, &inflight, name, None);
                            }
                        }
                    }
                }
            });
        }

        // Stage 2: network pool.
        for i in 0..NET_WORKERS {
            let (resolver, inflight, rx): (_, _, Receiver<String>) =
                (resolver.clone(), inflight.clone(), net_rx.clone());
            spawn_named(format!("thumb-net-{i}"), move || {
                for name in rx {
                    let path = resolver.fetch(&name);
                    finish(&bus, &inflight, name, path);
                }
            });
        }

        ThumbnailModule { bus, resolver, inflight, shots: Arc::default(), local_tx }
    }

    fn on_message(&self, msg: Message) {
        match msg {
            Message::UiReady => {
                let resolver = self.resolver.clone();
                spawn_named("thumb-warmup".into(), move || resolver.warm_up());
            }
            Message::IconRequested { name, .. } => {
                if !is_valid_package_name(&name) {
                    return;
                }
                // Coalesce: one job per package until it finishes.
                if lock(&self.inflight).insert(name.clone()) {
                    let _ = self.local_tx.send(name);
                }
            }
            Message::CoversRequested => {
                let bus = self.bus;
                spawn_named("thumb-covers".into(), move || {
                    bus.publish(&Message::CoversReady { covers: scan_covers() });
                });
            }
            Message::ScreenshotsRequested { name } => {
                let (bus, shots) = (self.bus, self.shots.clone());
                spawn_named("thumb-shots".into(), move || screenshots::serve(&bus, &shots, &name));
            }
            Message::ClearIconCache => {
                let (bus, resolver) = (self.bus, self.resolver.clone());
                spawn_named("thumb-clear".into(), move || {
                    bus.publish(&Message::IconCacheCleared { removed: resolver.clear_cache() });
                });
            }
            _ => {}
        }
    }
}

/// `data/images/cover/<app>/*.{png,jpg,jpeg}` → one [`Cover`] per app, sorted.
fn scan_covers() -> Vec<Cover> {
    let root = paths::data_dir().join("images/cover");
    let mut covers: Vec<Cover> = Vec::new();
    let Ok(rd) = fs::read_dir(&root) else {
        return covers;
    };
    for dir in rd.flatten().filter(|d| d.path().is_dir()) {
        let mut images: Vec<String> = fs::read_dir(dir.path())
            .map(|rd| {
                rd.flatten()
                    .map(|e| e.path())
                    .filter(|p| {
                        p.extension()
                            .and_then(|e| e.to_str())
                            .is_some_and(|e| matches!(e.to_ascii_lowercase().as_str(), "png" | "jpg" | "jpeg"))
                    })
                    .map(|p| p.to_string_lossy().into_owned())
                    .collect()
            })
            .unwrap_or_default();
        if images.is_empty() {
            continue;
        }
        images.sort();
        covers.push(Cover { name: dir.file_name().to_string_lossy().into_owned(), images });
    }
    covers.sort_by(|a, b| a.name.cmp(&b.name));
    covers
}

tux_abi::export_module!(ThumbnailModule, "thumbnail");
