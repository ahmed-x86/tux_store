//! `libtux_search.so` — answers every "what packages are there?" question.
//!
//! Handles: `HomeRequested`, `SearchRequested`, `DetailsRequested`, `ScriptInfoRequested`,
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
use tux_abi::{
    paths, Bus, Message, Module, Package, PackageDetails, ScriptInfo, Section, TaxonomyKind,
};
use tux_pacman::localdb;
use tux_taxonomy::{packages_for, TaxonomyState};

const DETAILS_TTL: Duration = Duration::from_secs(60);
const DETAILS_CACHE_MAX: usize = 32;

pub struct SearchModule {
    bus: Bus,
    catalog: Arc<Catalog>,
    home_cache: Arc<Mutex<Option<Vec<Section>>>>,
    details_cache: Arc<Mutex<HashMap<String, (Instant, PackageDetails)>>>,
    /// Newest search wins: older ones skip publishing their (stale) results.
    search_gen: Arc<AtomicU64>,
    taxonomy: Arc<Mutex<Option<Arc<TaxonomyState>>>>,
}

impl Module for SearchModule {
    fn create(bus: Bus) -> Self {
        SearchModule {
            bus,
            catalog: Arc::new(Catalog::load(paths::data_dir())),
            home_cache: Arc::default(),
            details_cache: Arc::default(),
            search_gen: Arc::default(),
            taxonomy: Arc::default(),
        }
    }

    fn on_message(&self, msg: Message) {
        match msg {
            Message::EngineChanged { engine } => {
                tux_libalpm::set_active(engine);
                *lock(&self.home_cache) = None;
                lock(&self.details_cache).clear();
                *lock(&self.taxonomy) = None;
                self.search_gen.fetch_add(1, Ordering::SeqCst);
            }
            Message::HomeRequested => self.home(),
            Message::SearchRequested { query } => self.search(query),
            Message::DetailsRequested { name } => self.details(name),
            Message::ScriptInfoRequested { id } => {
                let info = self.catalog.scripts.iter().find(|l| l.script.id == id).map(script_info);
                self.bus.publish(&Message::ScriptInfoReady { id, info });
            }
            Message::ExactRequested { name } => self.exact(name),
            Message::AddonsRequested { package } => self.addons(package),
            Message::InstalledRequested => self.installed(),
            Message::UpdatesRequested => self.updates(),
            Message::TaxonomyRequested => self.taxonomy(),
            Message::TaxonomyPackagesRequested { kind, id } => self.taxonomy_packages(kind, id),
            Message::OperationFinished { .. } | Message::ScriptEnded { .. } | Message::ClearIconCache => {
                *lock(&self.home_cache) = None;
                lock(&self.details_cache).clear();
                *lock(&self.taxonomy) = None;
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
        let (bus, latest, catalog) = (self.bus, self.search_gen.clone(), self.catalog.clone());
        thread::spawn(move || {
            // Scripts that match come first, then the pacman results.
            let mut packages = catalog.scripts_matching(&query);
            packages.extend(catalog.filter_visible(tux_libalpm::search(
                &query,
                tux_pacman::queries::SEARCH_LIMIT,
            )));
            if latest.load(Ordering::SeqCst) == my_gen {
                bus.publish(&Message::SearchResults { query, packages });
            }
        });
    }

    fn details(&self, name: String) {
        if !is_valid_package_name(&name) || self.catalog.is_hidden(&name) {
            return;
        }
        let (bus, catalog, cache) = (self.bus, self.catalog.clone(), self.details_cache.clone());
        thread::spawn(move || {
            let fresh = lock(&cache)
                .get(&name)
                .filter(|(at, _)| at.elapsed() < DETAILS_TTL)
                .map(|(_, d)| d.clone());
            let details = fresh.unwrap_or_else(|| {
                let d = tux_libalpm::details(&name);
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
        if !is_valid_package_name(&name) || self.catalog.is_hidden(&name) {
            return;
        }
        let bus = self.bus;
        thread::spawn(move || {
            bus.publish(&Message::ExactReady { package: tux_libalpm::exact(&name) });
        });
    }

    fn addons(&self, package: String) {
        let names = self.catalog.addon_names(&package);
        if names.is_empty() {
            return;
        }
        let (bus, catalog) = (self.bus, self.catalog.clone());
        thread::spawn(move || {
            let packages = catalog.filter_visible(tux_libalpm::packages_by_name(&names));
            bus.publish(&Message::AddonsReady { package, packages });
        });
    }

    fn installed(&self) {
        let (bus, catalog) = (self.bus, self.catalog.clone());
        thread::spawn(move || {
            let mut packages = catalog.filter_installed(tux_libalpm::installed_packages());
            packages.extend(catalog.installed_addons());
            bus.publish(&Message::InstalledReady { packages });
        });
    }

    fn updates(&self) {
        let bus = self.bus;
        thread::spawn(move || {
            let msg = match tux_libalpm::updates() {
                Ok(updates) => Message::UpdatesReady { updates, error: None },
                Err(e) => Message::UpdatesReady { updates: Vec::new(), error: Some(e) },
            };
            bus.publish(&msg);
        });
    }

    // ── the side menu: repositories, groups, categories ──

    fn taxonomy(&self) {
        if let Some(state) = lock(&self.taxonomy).clone() {
            self.bus.publish(&Message::TaxonomyReady { taxonomy: state.message.clone() });
            return;
        }
        let (bus, slot) = (self.bus, self.taxonomy.clone());
        thread::spawn(move || {
            let state = Arc::new(tux_taxonomy::build());
            *lock(&slot) = Some(state.clone());
            bus.publish(&Message::TaxonomyReady { taxonomy: state.message.clone() });
        });
    }

    fn taxonomy_packages(&self, kind: TaxonomyKind, id: String) {
        let cached = lock(&self.taxonomy).clone();
        let bus = self.bus;
        match cached {
            Some(state) => {
                thread::spawn(move || bus.publish(&packages_for(&state, kind, &id)));
            }
            None => {
                let slot = self.taxonomy.clone();
                thread::spawn(move || {
                    let state = Arc::new(tux_taxonomy::build());
                    let answer = packages_for(&state, kind, &id);
                    *lock(&slot) = Some(state.clone());
                    bus.publish(&Message::TaxonomyReady { taxonomy: state.message.clone() });
                    bus.publish(&answer);
                });
            }
        }
    }
}

/// One `pacman -Si` for the whole curated list, then split into sections.
fn build_home(catalog: &Catalog) -> Vec<Section> {
    let all = catalog.all_package_names();
    let by_name: HashMap<String, Package> = tux_libalpm::packages_by_name(&all)
        .into_iter()
        .map(|p| (p.name.clone(), p))
        .collect();
    let mut sections: Vec<Section> = catalog
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
        .collect();
    let scripts = catalog.home_scripts();
    if !scripts.is_empty() {
        sections.push(Section { id: "scripts".into(), title: "Add-on packages".into(), packages: scripts });
    }
    sections
}

tux_abi::export_module!(SearchModule, "search");

/// Free space (for normal users) on `/`, or 0 when it cannot be read.
fn free_bytes_on_root() -> u64 {
    let mut st: libc::statvfs = unsafe { std::mem::zeroed() };
    // SAFETY: `st` is a valid out-pointer and the path is a NUL-terminated literal.
    let rc = unsafe { libc::statvfs(c"/".as_ptr(), &mut st) };
    if rc != 0 {
        return 0;
    }
    (st.f_bavail as u64).saturating_mul(st.f_frsize as u64)
}

fn script_info(l: &tux_abi::script::LoadedScript) -> ScriptInfo {
    let s = &l.script;
    let storage = s.info.clone().unwrap_or_default();
    let user = l.origin == tux_abi::script::Origin::User;
    let rc = tux_abi::receipt::load(&s.id).filter(|r| r.complete);
    ScriptInfo {
        author: s.author.clone(),
        user_script: user,
        root_commands: s.root_command_summaries().len(),
        path: l.path.display().to_string(),
        download_mb: storage.download_mb.as_ref().and_then(|d| d.fixed()),
        extracted_mb: storage.extracted_mb.as_ref().and_then(|d| d.fixed()),
        installed_mb: storage.installed_mb.as_ref().and_then(|d| d.fixed()),
        note: storage.note.clone(),
        version: s.version.fixed(),
        version_dynamic: s.version.command().is_some(),
        download_dynamic: storage.download_mb.as_ref().is_some_and(|d| d.command().is_some()),
        extracted_dynamic: storage.extracted_mb.as_ref().is_some_and(|d| d.command().is_some()),
        installed_dynamic: storage.installed_mb.as_ref().is_some_and(|d| d.command().is_some()),
        needs_confirm: user && s.has_dynamic_values(),
        free_bytes: free_bytes_on_root(),
        installed: rc.is_some(),
        installed_version: rc.as_ref().map(|r| r.installed_version.clone()).unwrap_or_default(),
        installed_at: rc.as_ref().map_or(0, |r| r.installed_at),
        can_uninstall: rc.is_some() && s.uninstall.is_some(),
    }
}
