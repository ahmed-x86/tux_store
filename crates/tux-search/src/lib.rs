//! `libtux_search.so` — answers every "what packages are there?" question.
//!
//! Handles: `HomeRequested`, `SearchRequested`, `DetailsRequested`,
//! `ExactRequested`, `AddonsRequested`, `InstalledRequested`,
//! `UpdatesRequested`. Drops its caches on `OperationFinished`.
//! Each request runs on its own short-lived thread so `on_message` never
//! blocks the bus.

mod catalog;

use catalog::Catalog;
use std::collections::HashMap;
use std::sync::atomic::{AtomicU64, Ordering};
use std::sync::{Arc, Mutex};
use std::thread;
use std::time::{Duration, Instant};
use tux_abi::sync::lock;
use tux_abi::text::is_valid_package_name;
use tux_abi::{paths, Bus, Message, Module, Package, PackageDetails, Section};
use tux_pacman::{localdb, queries};

const DETAILS_TTL: Duration = Duration::from_secs(60);
const DETAILS_CACHE_MAX: usize = 32;

pub struct SearchModule {
    bus: Bus,
    catalog: Arc<Catalog>,
    home_cache: Arc<Mutex<Option<Vec<Section>>>>,
    details_cache: Arc<Mutex<HashMap<String, (Instant, PackageDetails)>>>,
    /// Newest search wins: older ones skip publishing their (stale) results.
    search_gen: Arc<AtomicU64>,
}

impl Module for SearchModule {
    fn create(bus: Bus) -> Self {
        SearchModule {
            bus,
            catalog: Arc::new(Catalog::load(paths::data_dir())),
            home_cache: Arc::default(),
            details_cache: Arc::default(),
            search_gen: Arc::default(),
        }
    }

    fn on_message(&self, msg: Message) {
        match msg {
            Message::HomeRequested => self.home(),
            Message::SearchRequested { query } => self.search(query),
            Message::DetailsRequested { name } => self.details(name),
            Message::ExactRequested { name } => self.exact(name),
            Message::AddonsRequested { package } => self.addons(package),
            Message::InstalledRequested => self.installed(),
            Message::UpdatesRequested => self.updates(),
            Message::OperationFinished { .. } | Message::ClearIconCache => {
                *lock(&self.home_cache) = None;
                lock(&self.details_cache).clear();
            }
            _ => {}
        }
    }
}

impl SearchModule {
    fn home(&self) {
        let (bus, catalog, cache) = (self.bus, self.catalog.clone(), self.home_cache.clone());
        thread::spawn(move || {
            let cached = lock(&cache).clone();
            let sections = match cached {
                Some(mut secs) => {
                    // Cheap: refresh only the installed flags.
                    let installed = localdb::installed_names();
                    for p in secs.iter_mut().flat_map(|s| s.packages.iter_mut()) {
                        p.installed = installed.contains(&p.name);
                    }
                    secs
                }
                None => {
                    let secs = build_home(&catalog);
                    *lock(&cache) = Some(secs.clone());
                    secs
                }
            };
            bus.publish(&Message::HomeReady { sections });
        });
    }

    fn search(&self, query: String) {
        let my_gen = self.search_gen.fetch_add(1, Ordering::SeqCst) + 1;
        let (bus, latest) = (self.bus, self.search_gen.clone());
        thread::spawn(move || {
            let packages = queries::search(&query, queries::SEARCH_LIMIT);
            if latest.load(Ordering::SeqCst) == my_gen {
                bus.publish(&Message::SearchResults { query, packages });
            }
        });
    }

    fn details(&self, name: String) {
        if !is_valid_package_name(&name) {
            return;
        }
        let (bus, catalog, cache) = (self.bus, self.catalog.clone(), self.details_cache.clone());
        thread::spawn(move || {
            let fresh = lock(&cache)
                .get(&name)
                .filter(|(at, _)| at.elapsed() < DETAILS_TTL)
                .map(|(_, d)| d.clone());
            let details = fresh.unwrap_or_else(|| {
                let d = queries::details(&name);
                let mut g = lock(&cache);
                if g.len() >= DETAILS_CACHE_MAX {
                    g.clear();
                }
                g.insert(name.clone(), (Instant::now(), d.clone()));
                d
            });
            let special = catalog.special_for(&name);
            bus.publish(&Message::DetailsReady { name, details, special });
        });
    }

    fn exact(&self, name: String) {
        if !is_valid_package_name(&name) {
            return;
        }
        let bus = self.bus;
        thread::spawn(move || {
            bus.publish(&Message::ExactReady { package: queries::exact(&name) });
        });
    }

    fn addons(&self, package: String) {
        let names = self.catalog.addon_names(&package);
        if names.is_empty() {
            return;
        }
        let bus = self.bus;
        thread::spawn(move || {
            let packages = queries::packages_by_name(&names);
            bus.publish(&Message::AddonsReady { package, packages });
        });
    }

    fn installed(&self) {
        let bus = self.bus;
        thread::spawn(move || {
            bus.publish(&Message::InstalledReady { packages: queries::installed_packages() });
        });
    }

    fn updates(&self) {
        let bus = self.bus;
        thread::spawn(move || {
            let msg = match queries::updates() {
                Ok(updates) => Message::UpdatesReady { updates, error: None },
                Err(e) => Message::UpdatesReady { updates: Vec::new(), error: Some(e) },
            };
            bus.publish(&msg);
        });
    }
}

/// One `pacman -Si` for the whole curated list, then split into sections.
fn build_home(catalog: &Catalog) -> Vec<Section> {
    let all = catalog.all_package_names();
    let by_name: HashMap<String, Package> = queries::packages_by_name(&all)
        .into_iter()
        .map(|p| (p.name.clone(), p))
        .collect();
    catalog
        .sections
        .iter()
        .map(|def| Section {
            id: def.id.clone(),
            title: def.title.clone(),
            packages: def
                .packages
                .iter()
                .filter_map(|n| by_name.get(n).cloned())
                .collect(),
        })
        .collect()
}

tux_abi::export_module!(SearchModule, "search");
