//! All UI state lives here, on the UI thread, in one `State` value.
//!
//! * Slint callbacks call `with_state(|st| st.some_method())`.
//! * Messages from the bus arrive on arbitrary threads; [`dispatch`] hops to
//!   the UI thread and calls [`State::handle`].
//!
//! Nothing here blocks: all slow work is a bus request answered later.

use crate::console::ConsoleBuffer;
use crate::convert;
use crate::{AppView, MainWindow, OpKind, OpPhase, UiInstallState, UiPackage, UiPackageDetails, UiSection};
use slint::{Image, Model, ModelRc, VecModel, Weak};
use std::cell::RefCell;
use std::collections::{HashMap, HashSet};
use std::path::Path;
use std::rc::Rc;
use tux_abi::text::prettify_name;
use tux_abi::{Bus, Cover, Message, Operation, Package, PackageDetails, RemoveMode, Section, SpecialCase, UpdateEntry};

const FIRST_PAGE: usize = 35;
const PAGE: usize = 20;
const SUGGESTION_COUNT: usize = 8;

thread_local! {
    static STATE: RefCell<Option<State>> = const { RefCell::new(None) };
}

pub fn install(state: State) {
    STATE.with(|c| *c.borrow_mut() = Some(state));
}

pub fn clear() {
    STATE.with(|c| *c.borrow_mut() = None);
}

/// Run `f` with the UI state. `None` if called off the UI thread, before
/// start-up, or re-entrantly.
pub fn with_state<R>(f: impl FnOnce(&mut State) -> R) -> Option<R> {
    STATE.with(|cell| {
        let mut guard = cell.try_borrow_mut().ok()?;
        let result = guard.as_mut().map(f);
        result
    })
}

/// Entry point for bus messages (any thread).
pub fn dispatch(msg: Message) {
    let _ = slint::invoke_from_event_loop(move || {
        with_state(|st| st.handle(msg));
    });
}

/// Growing window over a list: show a page, reveal more on demand.
#[derive(Default)]
struct Paged {
    all: Vec<Package>,
    cursor: usize,
}

impl Paged {
    fn reset(&mut self, all: Vec<Package>) {
        self.all = all;
        self.cursor = 0;
    }
    fn next(&mut self, n: usize) -> Vec<Package> {
        let end = (self.cursor + n).min(self.all.len());
        let page = self.all[self.cursor..end].to_vec();
        self.cursor = end;
        page
    }
    fn has_more(&self) -> bool {
        self.cursor < self.all.len()
    }
    fn patch_installed(&mut self, name: &str, installed: bool) {
        for p in self.all.iter_mut().filter(|p| p.name == name) {
            p.installed = installed;
        }
    }
}

fn normalize(s: &str) -> String {
    s.chars()
        .filter(|c| !matches!(c, ' ' | '-' | '_' | '.'))
        .flat_map(char::to_lowercase)
        .collect()
}

/// Move the next page of `paged` into `model`; returns names that still lack an icon.
fn push_page(paged: &mut Paged, model: &VecModel<UiPackage>, icons: &HashMap<String, Image>, n: usize) -> Vec<String> {
    let mut missing = Vec::new();
    for p in paged.next(n) {
        if !icons.contains_key(&p.name) {
            missing.push(p.name.clone());
        }
        model.push(convert::to_ui(&p, icons.get(&p.name)));
    }
    missing
}

fn patch_rows(model: &VecModel<UiPackage>, name: &str, mut patch: impl FnMut(&mut UiPackage)) {
    for i in 0..model.row_count() {
        if let Some(mut row) = model.row_data(i) {
            if row.name.as_str() == name {
                patch(&mut row);
                model.set_row_data(i, row);
            }
        }
    }
}

fn rows(model: &VecModel<UiPackage>) -> Vec<UiPackage> {
    (0..model.row_count()).filter_map(|i| model.row_data(i)).collect()
}

/// Cover folders that are not package names.
fn cover_package(cover: &str) -> &str {
    match cover {
        "codium" => "vscodium",
        other => other,
    }
}

fn accent_for(name: &str) -> i32 {
    name.bytes().fold(7i32, |a, b| a.wrapping_mul(31).wrapping_add(i32::from(b))).rem_euclid(14)
}

pub struct State {
    ui: Weak<MainWindow>,
    bus: Bus,

    icons: HashMap<String, Image>,
    icon_requested: HashSet<String>,

    sections: Rc<VecModel<UiSection>>,
    section_models: Vec<Rc<VecModel<UiPackage>>>,

    search: Rc<VecModel<UiPackage>>,
    search_paged: Paged,
    search_query: String,

    installed: Rc<VecModel<UiPackage>>,
    installed_all: Vec<Package>,
    installed_paged: Paged,
    installed_filter: String,

    addons: Rc<VecModel<UiPackage>>,
    suggestions: Rc<VecModel<UiPackage>>,
    updates: Rc<VecModel<crate::UiUpdate>>,

    covers: Vec<Cover>,
    cover_idx: usize,

    current: Option<Package>,
    history: Vec<Package>,
    last_details: PackageDetails,

    console: ConsoleBuffer,
    console_dirty: bool,
}

impl State {
    pub fn new(ui: Weak<MainWindow>, bus: Bus) -> Self {
        State {
            ui,
            bus,
            icons: HashMap::new(),
            icon_requested: HashSet::new(),
            sections: Rc::new(VecModel::default()),
            section_models: Vec::new(),
            search: Rc::new(VecModel::default()),
            search_paged: Paged::default(),
            search_query: String::new(),
            installed: Rc::new(VecModel::default()),
            installed_all: Vec::new(),
            installed_paged: Paged::default(),
            installed_filter: String::new(),
            addons: Rc::new(VecModel::default()),
            suggestions: Rc::new(VecModel::default()),
            updates: Rc::new(VecModel::default()),
            covers: Vec::new(),
            cover_idx: 0,
            current: None,
            history: Vec::new(),
            last_details: PackageDetails::default(),
            console: ConsoleBuffer::default(),
            console_dirty: false,
        }
    }

    /// Hand the list models to the window (once).
    pub fn bind(&self, ui: &MainWindow) {
        ui.set_sections(ModelRc::from(self.sections.clone()));
        ui.set_search_results(ModelRc::from(self.search.clone()));
        ui.set_installed(ModelRc::from(self.installed.clone()));
        ui.set_addons_packages(ModelRc::from(self.addons.clone()));
        ui.set_current_suggestions(ModelRc::from(self.suggestions.clone()));
        ui.set_updates(ModelRc::from(self.updates.clone()));
    }

    // ───────────────────────── bus → UI ─────────────────────────

    pub fn handle(&mut self, msg: Message) {
        match msg {
            Message::HomeReady { sections } => self.on_home(sections),
            Message::SearchResults { query, packages } => self.on_search_results(query, packages),
            Message::DetailsReady { name, details, special } => self.on_details(name, details, special),
            Message::ExactReady { package } => self.open_package(package, false),
            Message::AddonsReady { package, packages } => self.on_addons(package, packages),
            Message::InstalledReady { packages } => {
                self.installed_all = packages;
                self.apply_installed_filter();
            }
            Message::UpdatesReady { updates, error } => self.on_updates(updates, error),
            Message::CoversReady { covers } => {
                self.covers = covers;
                self.cover_idx = if self.covers.is_empty() { 0 } else { fastrand::usize(..self.covers.len()) };
                self.show_cover();
            }
            Message::IconReady { name, path } => self.on_icon(name, path),
            Message::IconCacheCleared { removed } => {
                self.reload_icons();
                if let Some(ui) = self.ui.upgrade() {
                    ui.set_cache_status(format!("Cleared {removed} cached files").into());
                }
            }
            Message::OperationStarted { .. } => {
                self.console.clear();
                self.console_dirty = true;
            }
            Message::OperationOutput { text } => {
                self.console.push(&text);
                self.console_dirty = true;
            }
            Message::OperationProgress { fraction } => {
                self.patch_install(|s| {
                    if s.phase == OpPhase::Running {
                        s.progress = fraction as f32;
                    }
                });
            }
            Message::OperationFinished { op, success, .. } => self.on_finished(op, success),
            _ => {}
        }
    }

    fn on_home(&mut self, sections: Vec<Section>) {
        let mut ui_sections = Vec::with_capacity(sections.len());
        let mut models = Vec::with_capacity(sections.len());
        let mut missing = Vec::new();
        for s in &sections {
            let mut rows = Vec::with_capacity(s.packages.len());
            for p in &s.packages {
                if !self.icons.contains_key(&p.name) {
                    missing.push(p.name.clone());
                }
                rows.push(convert::to_ui(p, self.icons.get(&p.name)));
            }
            let model = Rc::new(VecModel::from(rows));
            ui_sections.push(UiSection { title: s.title.as_str().into(), packages: ModelRc::from(model.clone()) });
            models.push(model);
        }
        self.section_models = models;
        self.sections.set_vec(ui_sections);
        self.request_icons(missing);
    }

    fn on_search_results(&mut self, query: String, packages: Vec<Package>) {
        if query != self.search_query {
            return; // a newer query is already on its way
        }
        self.search_paged.reset(packages);
        self.search.set_vec(Vec::new());
        let missing = push_page(&mut self.search_paged, &self.search, &self.icons, FIRST_PAGE);
        self.request_icons(missing);
        if let Some(ui) = self.ui.upgrade() {
            ui.set_search_busy(false);
            ui.set_has_more_results(self.search_paged.has_more());
        }
    }

    fn on_details(&mut self, name: String, details: PackageDetails, special: Option<SpecialCase>) {
        if self.current.as_ref().map(|c| c.name.as_str()) != Some(name.as_str()) {
            return; // user already navigated elsewhere
        }
        if let Some(ui) = self.ui.upgrade() {
            ui.set_current_details(convert::details(&details));
            ui.set_current_special_case(convert::special(special));
        }
        self.last_details = details;
    }

    fn on_addons(&mut self, package: String, packages: Vec<Package>) {
        if self.current.as_ref().map(|c| c.name.as_str()) != Some(package.as_str()) {
            return;
        }
        let mut missing = Vec::new();
        let rows: Vec<UiPackage> = packages
            .iter()
            .map(|p| {
                if !self.icons.contains_key(&p.name) {
                    missing.push(p.name.clone());
                }
                convert::to_ui(p, self.icons.get(&p.name))
            })
            .collect();
        self.addons.set_vec(rows);
        self.request_icons(missing);
    }

    fn on_updates(&mut self, updates: Vec<UpdateEntry>, error: Option<String>) {
        self.updates.set_vec(updates.iter().map(convert::update).collect::<Vec<_>>());
        if let Some(ui) = self.ui.upgrade() {
            ui.set_updates_loading(false);
            ui.set_updates_status(error.unwrap_or_default().into());
        }
    }

    fn on_icon(&mut self, name: String, path: String) {
        let Ok(img) = Image::load_from_path(Path::new(&path)) else {
            return;
        };
        self.each_model(|m| patch_rows(m, &name, |r| r.icon = img.clone()));
        if let Some(ui) = self.ui.upgrade() {
            let mut cur = ui.get_current_package();
            if cur.name.as_str() == name {
                cur.icon = img.clone();
                ui.set_current_package(cur);
            }
        }
        self.icons.insert(name, img);
    }

    fn on_finished(&mut self, op: Operation, success: bool) {
        self.flush_console();
        self.patch_install(|s| {
            s.phase = OpPhase::Done;
            s.success = success;
            if success {
                s.progress = 1.0;
            }
        });
        if !success {
            return;
        }
        match &op {
            Operation::Install { name } => self.set_installed(name, true),
            Operation::Remove { name, .. } => self.set_installed(name, false),
            Operation::SystemUpgrade => self.request_updates(),
        }
        if self.ui.upgrade().is_some_and(|ui| ui.get_active_tab() == 2) {
            self.refresh_installed();
        }
    }

    // ───────────────────────── helpers ─────────────────────────

    fn each_model(&self, mut f: impl FnMut(&VecModel<UiPackage>)) {
        for m in self
            .section_models
            .iter()
            .chain([&self.search, &self.installed, &self.addons, &self.suggestions])
        {
            f(m);
        }
    }

    /// Forget every loaded icon and ask the thumbnail module again for the ones
    /// on screen (after the cache was cleared / the icon theme changed).
    fn reload_icons(&mut self) {
        self.icons.clear();
        self.icon_requested.clear();

        let mut names: Vec<String> = Vec::new();
        self.each_model(|m| {
            for i in 0..m.row_count() {
                if let Some(mut row) = m.row_data(i) {
                    names.push(row.name.to_string());
                    row.icon = Image::default();
                    m.set_row_data(i, row);
                }
            }
        });
        if let Some(ui) = self.ui.upgrade() {
            let mut cur = ui.get_current_package();
            if !cur.name.is_empty() {
                names.push(cur.name.to_string());
                cur.icon = Image::default();
                ui.set_current_package(cur);
            }
        }
        names.sort();
        names.dedup();
        self.request_icons(names);
    }

    fn request_icons(&mut self, names: Vec<String>) {
        for name in names {
            if self.icon_requested.insert(name.clone()) {
                self.bus.publish(&Message::IconRequested { name, size: 64 });
            }
        }
    }

    fn patch_install(&self, f: impl FnOnce(&mut UiInstallState)) {
        if let Some(ui) = self.ui.upgrade() {
            let mut s = ui.get_current_install();
            f(&mut s);
            ui.set_current_install(s);
        }
    }

    fn set_installed(&mut self, name: &str, installed: bool) {
        self.each_model(|m| patch_rows(m, name, |r| r.installed = installed));
        self.search_paged.patch_installed(name, installed);
        if let Some(cur) = self.current.as_mut().filter(|c| c.name == name) {
            cur.installed = installed;
        }
        if let Some(ui) = self.ui.upgrade() {
            let mut cur = ui.get_current_package();
            if cur.name.as_str() == name {
                cur.installed = installed;
                ui.set_current_package(cur);
            }
        }
    }

    /// Copy the console buffer into Slint if it changed (called by a timer).
    pub fn flush_console(&mut self) {
        if self.console_dirty {
            self.console_dirty = false;
            if let Some(ui) = self.ui.upgrade() {
                ui.set_console_text(self.console.text().into());
            }
        }
    }

    // ───────────────────────── UI → bus ─────────────────────────

    pub fn startup(&mut self) {
        self.bus.publish(&Message::UiReady);
        self.bus.publish(&Message::HomeRequested);
        self.bus.publish(&Message::CoversRequested);
    }

    pub fn request_home(&mut self) {
        self.bus.publish(&Message::HomeRequested);
    }

    pub fn open_by_name(&mut self, name: String) {
        self.bus.publish(&Message::ExactRequested { name });
    }

    pub fn start_search(&mut self, raw: &str) {
        let q = raw.trim().to_string();
        self.search_query = q.clone();
        let Some(ui) = self.ui.upgrade() else { return };
        if q.is_empty() {
            self.search_paged.reset(Vec::new());
            self.search.set_vec(Vec::new());
            ui.set_has_more_results(false);
            ui.set_search_busy(false);
            return;
        }
        ui.set_search_busy(true);
        self.bus.publish(&Message::SearchRequested { query: q });
    }

    pub fn more_search(&mut self) {
        let missing = push_page(&mut self.search_paged, &self.search, &self.icons, PAGE);
        self.request_icons(missing);
        if let Some(ui) = self.ui.upgrade() {
            ui.set_has_more_results(self.search_paged.has_more());
        }
    }

    pub fn refresh_installed(&mut self) {
        if let Some(ui) = self.ui.upgrade() {
            ui.set_installed_loading(true);
        }
        self.bus.publish(&Message::InstalledRequested);
    }

    pub fn set_installed_filter(&mut self, filter: &str) {
        self.installed_filter = filter.trim().to_string();
        self.apply_installed_filter();
    }

    fn apply_installed_filter(&mut self) {
        let needle = normalize(&self.installed_filter);
        let lower = self.installed_filter.to_lowercase();
        let list: Vec<Package> = self
            .installed_all
            .iter()
            .filter(|p| {
                needle.is_empty() || normalize(&p.name).contains(&needle) || p.description.to_lowercase().contains(&lower)
            })
            .cloned()
            .collect();
        let total = list.len();
        self.installed_paged.reset(list);
        self.installed.set_vec(Vec::new());
        let missing = push_page(&mut self.installed_paged, &self.installed, &self.icons, FIRST_PAGE + 25);
        self.request_icons(missing);
        if let Some(ui) = self.ui.upgrade() {
            ui.set_installed_total(total as i32);
            ui.set_installed_has_more(self.installed_paged.has_more());
            ui.set_installed_loading(false);
        }
    }

    pub fn more_installed(&mut self) {
        let missing = push_page(&mut self.installed_paged, &self.installed, &self.icons, PAGE * 3);
        self.request_icons(missing);
        if let Some(ui) = self.ui.upgrade() {
            ui.set_installed_has_more(self.installed_paged.has_more());
        }
    }

    pub fn request_updates(&mut self) {
        if let Some(ui) = self.ui.upgrade() {
            ui.set_updates_loading(true);
            ui.set_updates_status("".into());
        }
        self.bus.publish(&Message::UpdatesRequested);
    }

    pub fn tab_changed(&mut self, tab: i32) {
        match tab {
            1 => self.request_updates(),
            2 => self.refresh_installed(),
            _ => {}
        }
    }

    pub fn open_package(&mut self, pkg: Package, from_history: bool) {
        let Some(ui) = self.ui.upgrade() else { return };
        let in_package_view = matches!(ui.get_view(), AppView::Details | AppView::Addons);
        if !from_history {
            if in_package_view {
                if let Some(cur) = self.current.clone().filter(|c| c.name != pkg.name) {
                    self.history.push(cur);
                }
            } else {
                self.history.clear();
            }
        }

        ui.set_current_package(convert::to_ui(&pkg, self.icons.get(&pkg.name)));
        ui.set_current_details(UiPackageDetails { is_loading: true, ..Default::default() });
        ui.set_current_special_case(Default::default());
        ui.set_accent_idx(accent_for(&pkg.name));
        if ui.get_current_install().phase != OpPhase::Running {
            ui.set_current_install(UiInstallState::default());
        }
        self.build_suggestions(&pkg);
        ui.set_view(AppView::Details);

        let missing = if self.icons.contains_key(&pkg.name) { Vec::new() } else { vec![pkg.name.clone()] };
        self.request_icons(missing);
        self.bus.publish(&Message::DetailsRequested { name: pkg.name.clone() });
        self.current = Some(pkg);
    }

    pub fn back(&mut self) {
        if let Some(prev) = self.history.pop() {
            self.open_package(prev, true);
        } else {
            self.current = None;
            if let Some(ui) = self.ui.upgrade() {
                ui.set_view(AppView::Main);
            }
        }
    }

    pub fn show_addons(&mut self) {
        self.addons.set_vec(Vec::new());
        if let Some(cur) = &self.current {
            self.bus.publish(&Message::AddonsRequested { package: cur.name.clone() });
        }
    }

    /// Prefer packages from the same Home shelf, then random others.
    fn build_suggestions(&mut self, pkg: &Package) {
        let mut same: Vec<UiPackage> = Vec::new();
        for m in &self.section_models {
            let r = rows(m);
            if r.iter().any(|x| x.name.as_str() == pkg.name) {
                same = r;
                break;
            }
        }
        let same_names: HashSet<String> = same.iter().map(|x| x.name.to_string()).collect();
        let mut others: Vec<UiPackage> = Vec::new();
        for m in &self.section_models {
            others.extend(rows(m));
        }
        others.extend(rows(&self.search));
        let mut seen: HashSet<String> = HashSet::new();
        others.retain(|x| !same_names.contains(x.name.as_str()) && seen.insert(x.name.to_string()));

        fastrand::shuffle(&mut same);
        fastrand::shuffle(&mut others);
        let picks: Vec<UiPackage> = same
            .into_iter()
            .chain(others)
            .filter(|x| x.name.as_str() != pkg.name)
            .take(SUGGESTION_COUNT)
            .collect();
        self.suggestions.set_vec(picks);
    }

    // ── transactions ──

    fn begin_operation(&mut self, kind: OpKind, target: &str, deps_ratio: f32) -> bool {
        let Some(ui) = self.ui.upgrade() else { return false };
        if ui.get_current_install().phase == OpPhase::Running {
            return false;
        }
        ui.set_current_install(UiInstallState {
            phase: OpPhase::Running,
            kind,
            success: false,
            progress: 0.0,
            deps_ratio,
            target: target.into(),
        });
        self.console.clear();
        self.console_dirty = true;
        true
    }

    pub fn install_current(&mut self) {
        let Some(pkg) = self.current.clone() else { return };
        if pkg.installed {
            return;
        }
        let d = &self.last_details;
        let denom = (d.new_deps + d.app_size) as f32;
        let ratio = if denom > 0.0 { d.new_deps as f32 / denom } else { 0.0 };
        if self.begin_operation(OpKind::Install, &pkg.name, ratio) {
            self.bus.publish(&Message::InstallRequested { name: pkg.name });
        }
    }

    pub fn remove_current(&mut self, flag: &str) {
        let (Some(pkg), Some(mode)) = (self.current.clone(), RemoveMode::from_flag(flag)) else {
            return;
        };
        if self.begin_operation(OpKind::Remove, &pkg.name, 0.0) {
            self.bus.publish(&Message::RemoveRequested { name: pkg.name, mode });
        }
    }

    pub fn upgrade_all(&mut self) {
        if self.begin_operation(OpKind::Upgrade, "@upgrade", 0.0) {
            self.bus.publish(&Message::SystemUpgradeRequested);
        }
    }

    pub fn clear_icon_cache(&mut self) {
        self.bus.publish(&Message::ClearIconCache);
    }

    // ── covers ──

    fn show_cover(&mut self) {
        let Some(ui) = self.ui.upgrade() else { return };
        let Some(cover) = self.covers.get(self.cover_idx) else {
            ui.set_cover_count(0);
            return;
        };
        let pick = &cover.images[fastrand::usize(..cover.images.len())];
        // Only the visible cover is ever decoded.
        let image = Image::load_from_path(Path::new(pick)).unwrap_or_default();
        ui.set_cover_name(prettify_name(&cover.name).as_str().into());
        ui.set_cover_image(image);
        ui.set_cover_count(self.covers.len() as i32);
    }

    pub fn step_cover(&mut self, forward: bool) {
        let n = self.covers.len();
        if n == 0 {
            return;
        }
        self.cover_idx = if forward { (self.cover_idx + 1) % n } else { (self.cover_idx + n - 1) % n };
        self.show_cover();
    }

    pub fn open_cover(&mut self) {
        if let Some(cover) = self.covers.get(self.cover_idx) {
            let name = cover_package(&cover.name).to_string();
            self.bus.publish(&Message::ExactRequested { name });
        }
    }
}
