//! All UI state lives here, on the UI thread, in one `State` value.
//!
//! * Slint callbacks call `with_state(|st| st.some_method())`.
//! * Messages from the bus arrive on arbitrary threads; [`dispatch`] hops to
//!   the UI thread and calls [`State::handle`].
//!
//! Nothing here blocks: all slow work is a bus request answered later.

use crate::console::ConsoleBuffer;
use crate::convert;
use crate::{
    AppView, MainWindow, OpKind, OpPhase, UiDowngrade, UiInstallState, UiPackage,
    UiPackageDetails, UiScriptInfo, UiScriptOption, UiSection, UiTaxonomyEntry,
};
use slint::{Image, Model, ModelRc, VecModel, Weak};
use std::cell::RefCell;
use std::collections::{HashMap, HashSet};
use std::path::Path;
use std::rc::Rc;
use tux_abi::text::prettify_name;
use tux_abi::{
    Backend, BackendKind, Bus, Cover, DowngradeEntry, Engine, Feature, Message, Operation,
    Package, PackageDetails, RemoveMode, ScriptInfo, ScriptValues, ScriptViewData, Section,
    SpecialCase, Taxonomy, TaxonomyEntry, TaxonomyKind, UpdateEntry,
};

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

/// Counters for the lazy-loading system. They make it easy to prove that a
/// screen only loaded what it showed (`TUX_LAZY_STATS=1` prints them on exit).
#[derive(Default)]
struct LazyStats {
    icons_requested: u64,
    icons_loaded: u64,
    packages_materialized: u64,
    screenshots_loaded: u64,
    covers_shown: u64,
    cover_images_loaded: u64,
    taxonomy_sections: u64,
    operations_started: u64,
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

/// Move the next page of `paged` into `model`. Icons are *not* requested here:
/// the grid tells the UI which cards are on screen (see `visible_icons`).
/// Returns how many cards were materialized (for the lazy stats).
fn push_page(
    paged: &mut Paged,
    model: &VecModel<UiPackage>,
    icons: &HashMap<String, Image>,
    n: usize,
) -> usize {
    let page = paged.next(n);
    let count = page.len();
    for p in page {
        model.push(convert::to_ui(&p, icons.get(&p.name)));
    }
    count
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
    (0..model.row_count())
        .filter_map(|i| model.row_data(i))
        .collect()
}

/// Names of the rows in a visible index range (inclusive, clamped).
fn names_in_range(model: &VecModel<UiPackage>, first: i32, last: i32) -> Vec<String> {
    let len = model.row_count();
    if len == 0 {
        return Vec::new();
    }
    let start = first.max(0) as usize;
    let end = (last.max(0) as usize).min(len - 1);
    if start > end {
        return Vec::new();
    }
    (start..=end)
        .filter_map(|i| model.row_data(i))
        .map(|r| r.name.to_string())
        .collect()
}

/// Cover folders that are not package names.
fn cover_package(cover: &str) -> &str {
    match cover {
        "codium" => "vscodium",
        other => other,
    }
}

fn accent_for(name: &str) -> i32 {
    name.bytes()
        .fold(7i32, |a, b| a.wrapping_mul(31).wrapping_add(i32::from(b)))
        .rem_euclid(14)
}

/// Which page of the side menu is on screen.
#[derive(Clone, Copy, PartialEq, Eq)]
enum BrowseSection {
    Categories,
    Groups,
    Repositories,
}

impl BrowseSection {
    fn from_int(i: i32) -> Self {
        match i {
            1 => BrowseSection::Groups,
            2 => BrowseSection::Repositories,
            _ => BrowseSection::Categories,
        }
    }
    fn kind(self) -> TaxonomyKind {
        match self {
            BrowseSection::Categories => TaxonomyKind::Category,
            BrowseSection::Groups => TaxonomyKind::Group,
            BrowseSection::Repositories => TaxonomyKind::Repository,
        }
    }
    fn title(self) -> &'static str {
        match self {
            BrowseSection::Categories => "Categories",
            BrowseSection::Groups => "Groups",
            BrowseSection::Repositories => "Repositories",
        }
    }
}

/// The entry whose packages are open inside the browse page.
type BrowseTarget = (TaxonomyKind, String);

pub struct State {
    ui: Weak<MainWindow>,
    bus: Bus,
    /// Package-manager backend selected in Settings.
    engine: Engine,
    /// What this machine can actually do; read-only for the UI.
    backend: Backend,

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
    /// Screenshots of the package on display (the slider on its page).
    screenshots: Rc<VecModel<Image>>,
    updates: Rc<VecModel<crate::UiUpdate>>,

    // ── smart downgrade dialog ──
    /// A `DowngradeCheckRequested` is in flight; clicking Update all again
    /// must not start a second check.
    downgrade_check_pending: bool,
    downgrade_rows: Rc<VecModel<UiDowngrade>>,
    /// Index-aligned with `downgrade_rows`; kept in Rust so the selected
    /// package names can be published without reading Slint back.
    downgrade_checked: Vec<bool>,

    covers: Vec<Cover>,
    cover_idx: usize,

    current: Option<Package>,
    history: Vec<Package>,
    /// Pages left with Back; "Forward" returns to them (cleared by any new navigation).
    forward: Vec<Package>,
    /// Where Back goes when the package history is empty (the side-menu page,
    /// when the package was opened from there).
    return_view: Option<AppView>,
    last_details: PackageDetails,

    // ── side menu ──
    /// Each section is fetched only when its page is opened.
    taxonomy_sections: HashMap<TaxonomyKind, Vec<TaxonomyEntry>>,
    taxonomy_pending: HashSet<TaxonomyKind>,
    browse_section: BrowseSection,
    /// Every row of the current section, families included (members are hidden
    /// until their family is expanded).
    browse_all: Vec<TaxonomyEntry>,
    expanded: HashSet<String>,
    browse_entries: Rc<VecModel<UiTaxonomyEntry>>,
    browse_open: Option<BrowseTarget>,
    browse_packages: Rc<VecModel<UiPackage>>,
    browse_paged: Paged,

    console: ConsoleBuffer,
    console_dirty: bool,

    /// Interactive script: `seq` of the screen on display, and whether one is
    /// running at all (blocks pacman transactions and a second script).
    script_seq: u64,
    script_running: bool,
    /// The add-on package page on display: facts, computed values, status.
    script_page: Option<ScriptPage>,
    /// Options of the script screen on display (to tick boxes / add pictures).
    script_options: Option<Rc<VecModel<UiScriptOption>>>,

    /// Counters for `TUX_LAZY_STATS`; no behavioural effect.
    stats: LazyStats,
}

impl Drop for State {
    fn drop(&mut self) {
        if std::env::var_os("TUX_LAZY_STATS").is_none() {
            return;
        }
        let s = &self.stats;
        log::info!(
            "[lazy] icons {}/{} loaded/requested · {} packages materialized · {} screenshots · \
             {} covers shown ({} remote picture sets) · {} taxonomy sections · {} operations",
            s.icons_loaded,
            s.icons_requested,
            s.packages_materialized,
            s.screenshots_loaded,
            s.covers_shown,
            s.cover_images_loaded,
            s.taxonomy_sections,
            s.operations_started,
        );
    }
}

#[derive(Clone, Copy, PartialEq, Eq)]
enum ValuesState {
    /// Nothing to compute (or already written in the JSON).
    Static,
    Calculating,
    NeedsConfirm,
    Done,
}

struct ScriptPage {
    id: String,
    info: ScriptInfo,
    values: ScriptValues,
    state: ValuesState,
}

impl State {
    pub fn new(ui: Weak<MainWindow>, bus: Bus) -> Self {
        State {
            ui,
            bus,
            engine: crate::config::load().engine,
            backend: tux_backend::detect(),
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
            screenshots: Rc::new(VecModel::default()),
            updates: Rc::new(VecModel::default()),
            downgrade_check_pending: false,
            downgrade_rows: Rc::new(VecModel::default()),
            downgrade_checked: Vec::new(),
            covers: Vec::new(),
            cover_idx: 0,
            current: None,
            history: Vec::new(),
            forward: Vec::new(),
            return_view: None,
            last_details: PackageDetails::default(),
            taxonomy_sections: HashMap::new(),
            taxonomy_pending: HashSet::new(),
            browse_section: BrowseSection::Categories,
            browse_all: Vec::new(),
            expanded: HashSet::new(),
            browse_entries: Rc::new(VecModel::default()),
            browse_open: None,
            browse_packages: Rc::new(VecModel::default()),
            browse_paged: Paged::default(),
            console: ConsoleBuffer::default(),
            console_dirty: false,
            script_seq: 0,
            script_running: false,
            script_page: None,
            script_options: None,
            stats: LazyStats::default(),
        }
    }

    /// Hand the list models to the window (once).
    pub fn bind(&self, ui: &MainWindow) {
        ui.set_sections(ModelRc::from(self.sections.clone()));
        ui.set_search_results(ModelRc::from(self.search.clone()));
        ui.set_installed(ModelRc::from(self.installed.clone()));
        ui.set_addons_packages(ModelRc::from(self.addons.clone()));
        ui.set_current_suggestions(ModelRc::from(self.suggestions.clone()));
        ui.set_current_screenshots(ModelRc::from(self.screenshots.clone()));
        ui.set_updates(ModelRc::from(self.updates.clone()));
        ui.set_downgrade_packages(ModelRc::from(self.downgrade_rows.clone()));
        ui.set_browse_entries(ModelRc::from(self.browse_entries.clone()));
        ui.set_browse_packages(ModelRc::from(self.browse_packages.clone()));
        self.apply_backend(ui);
    }

    /// Tell Slint what the active manager can do. The UI only reads this; it
    /// never asks pacman itself.
    fn apply_backend(&self, ui: &MainWindow) {
        ui.set_backend_supported(self.backend.is_supported());
        ui.set_backend_message(self.backend.unsupported_message().into());
        ui.set_can_install(self.backend.capabilities.install);
        ui.set_can_remove(self.backend.capabilities.remove);
        ui.set_can_update(self.backend.capabilities.updates && self.backend.capabilities.system_upgrade);
        ui.set_engine_enabled(self.backend.is_supported());
    }

    // ───────────────────────── bus → UI ─────────────────────────

    pub fn handle(&mut self, msg: Message) {
        match msg {
            Message::HomeReady { sections } => self.on_home(sections),
            Message::SearchResults { query, packages } => self.on_search_results(query, packages),
            Message::DetailsReady {
                name,
                details,
                special,
            } => self.on_details(name, details, special),
            Message::ExactReady { package } => self.open_package(package, false),
            Message::ScreenshotsReady { name, images } => self.on_screenshots(name, images),
            Message::AddonsReady { package, packages } => self.on_addons(package, packages),
            Message::InstalledReady { packages } => {
                self.installed_all = packages;
                self.apply_installed_filter();
            }
            Message::UpdatesReady { updates, error } => self.on_updates(updates, error),
            Message::DowngradeCheckReady { packages, error } => {
                self.on_downgrade_check(packages, error)
            }
            Message::TaxonomyReady { taxonomy } => self.on_taxonomy(taxonomy),
            Message::TaxonomySectionReady { kind, entries } => {
                self.on_taxonomy_section(kind, entries)
            }
            Message::TaxonomyPackagesReady {
                kind,
                id,
                title,
                subtitle,
                packages,
            } => {
                self.on_taxonomy_packages(kind, id, title, subtitle, packages);
            }
            Message::CoversReady { covers } => {
                // Stay on the cover that is showing when the list is refreshed.
                let showing = self.covers.get(self.cover_idx).map(|c| c.name.clone());
                self.covers = covers;
                let kept = showing.and_then(|n| self.covers.iter().position(|c| c.name == n));
                self.cover_idx = match kept {
                    Some(i) => i,
                    None => {
                        // Prefer a cover whose pictures are already on disk.
                        let ready: Vec<usize> = self
                            .covers
                            .iter()
                            .enumerate()
                            .filter(|(_, c)| !c.images.is_empty())
                            .map(|(i, _)| i)
                            .collect();
                        if ready.is_empty() {
                            0
                        } else {
                            ready[fastrand::usize(..ready.len())]
                        }
                    }
                };
                if let Some(ui) = self.ui.upgrade() {
                    ui.set_cover_count(self.covers.len() as i32);
                }
                self.show_cover();
            }
            Message::CoverImagesReady { name, images } => self.on_cover_images(name, images),
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
            Message::ScriptInfoReady { id, info } => self.on_script_info(id, info),
            Message::ScriptValuesReady { id, values } => self.on_script_values(id, values),
            Message::ScriptView { view } => self.on_script_view(view),
            Message::ScriptOutput { text } => {
                self.console.push(&text);
                self.console_dirty = true;
                if let Some(ui) = self.ui.upgrade() {
                    ui.set_script_has_output(true);
                }
            }
            Message::ScriptProgress { fraction, label } => {
                if let Some(ui) = self.ui.upgrade() {
                    ui.set_script_progress(fraction as f32);
                    ui.set_script_progress_label(label.as_str().into());
                }
            }
            Message::ScriptEnded { success, .. } => self.on_script_ended(success),
            Message::Unsupported { backend, feature } => self.on_unsupported(backend, feature),
            _ => {}
        }
    }

    fn on_home(&mut self, sections: Vec<Section>) {
        let mut ui_sections = Vec::with_capacity(sections.len());
        let mut models = Vec::with_capacity(sections.len());
        for s in &sections {
            self.stats.packages_materialized += s.packages.len() as u64;
            let rows: Vec<UiPackage> = s
                .packages
                .iter()
                .map(|p| convert::to_ui(p, self.icons.get(&p.name)))
                .collect();
            let model = Rc::new(VecModel::from(rows));
            ui_sections.push(UiSection {
                title: s.title.as_str().into(),
                packages: ModelRc::from(model.clone()),
            });
            models.push(model);
        }
        self.section_models = models;
        self.sections.set_vec(ui_sections);
        // No icons and no screenshots are requested here: the shelves ask for
        // the icons of the cards they actually show, and a package page asks
        // for its screenshots when it is opened.
    }

    /// The Home shelves on screen ask for the icons of their visible cards.
    pub fn home_icons_needed(&mut self, row: i32, first: i32, last: i32) {
        let Some(model) = self.section_models.get(row.max(0) as usize) else {
            return;
        };
        let names = names_in_range(model, first, last);
        self.request_icons(names);
    }

    fn on_search_results(&mut self, query: String, packages: Vec<Package>) {
        if query != self.search_query {
            return; // a newer query is already on its way
        }
        self.search_paged.reset(packages);
        self.search.set_vec(Vec::new());
        self.stats.packages_materialized += push_page(
            &mut self.search_paged,
            &self.search,
            &self.icons,
            FIRST_PAGE,
        ) as u64;
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

    /// Screenshots arrive as complete lists (possibly several times while a
    /// Flathub download is running); the slider is simply replaced.
    fn on_screenshots(&mut self, name: String, images: Vec<String>) {
        if self.current.as_ref().map(|c| c.name.as_str()) != Some(name.as_str()) {
            return; // user already navigated elsewhere
        }
        let loaded: Vec<Image> = images
            .iter()
            .filter_map(|p| Image::load_from_path(Path::new(p)).ok())
            .collect();
        self.stats.screenshots_loaded += loaded.len() as u64;
        self.screenshots.set_vec(loaded);
    }

    fn on_addons(&mut self, package: String, packages: Vec<Package>) {
        if self.current.as_ref().map(|c| c.name.as_str()) != Some(package.as_str()) {
            return;
        }
        let rows: Vec<UiPackage> = packages
            .iter()
            .map(|p| convert::to_ui(p, self.icons.get(&p.name)))
            .collect();
        self.stats.packages_materialized += rows.len() as u64;
        self.addons.set_vec(rows);
    }

    /// The remote pictures of one cover arrived (only ever for a cover that
    /// was on screen). Merge them and refresh the banner if it still shows it.
    fn on_cover_images(&mut self, name: String, images: Vec<String>) {
        if images.is_empty() {
            return;
        }
        self.stats.cover_images_loaded += images.len() as u64;
        if let Some(cover) = self.covers.iter_mut().find(|c| c.name == name) {
            cover.images = images;
        } else {
            self.covers.push(Cover {
                name: name.clone(),
                images,
            });
        }
        if self
            .covers
            .get(self.cover_idx)
            .is_some_and(|c| c.name == name)
        {
            self.show_cover();
        }
    }

    fn on_updates(&mut self, updates: Vec<UpdateEntry>, error: Option<String>) {
        self.updates
            .set_vec(updates.iter().map(convert::update).collect::<Vec<_>>());
        if let Some(ui) = self.ui.upgrade() {
            ui.set_updates_loading(false);
            ui.set_updates_status(error.unwrap_or_default().into());
        }
    }

    /// A module answered that the active backend cannot serve a request. Clear
    /// whatever spinner that request started and show the reason.
    fn on_unsupported(&mut self, backend: BackendKind, feature: Feature) {
        let message = Backend::new(backend).feature_message(feature);
        log::warn!("{message}");
        match feature {
            Feature::Search => {
                if let Some(ui) = self.ui.upgrade() {
                    ui.set_search_busy(false);
                    ui.set_has_more_results(false);
                }
            }
            Feature::Details => {
                if let Some(ui) = self.ui.upgrade() {
                    ui.set_current_details(UiPackageDetails {
                        is_loading: false,
                        ..Default::default()
                    });
                }
            }
            Feature::Updates | Feature::SystemUpgrade | Feature::Downgrade => {
                self.downgrade_check_pending = false;
                if let Some(ui) = self.ui.upgrade() {
                    ui.set_updates_loading(false);
                    ui.set_updates_status(message.into());
                }
            }
            Feature::InstalledList => {
                self.installed_all.clear();
                self.installed_paged.reset(Vec::new());
                self.installed.set_vec(Vec::new());
                if let Some(ui) = self.ui.upgrade() {
                    ui.set_installed_loading(false);
                    ui.set_installed_total(0);
                    ui.set_installed_has_more(false);
                }
            }
            Feature::Categories | Feature::TaxonomyGroups | Feature::TaxonomyRepositories => {
                self.browse_all.clear();
                self.browse_entries.set_vec(Vec::new());
                self.browse_packages.set_vec(Vec::new());
                if let Some(ui) = self.ui.upgrade() {
                    ui.set_browse_loading(false);
                    ui.set_browse_status(message.into());
                }
            }
            Feature::Addons => {
                self.addons.set_vec(Vec::new());
            }
            Feature::Install | Feature::Remove => {
                self.console.push(&format!("{message}\n"));
                self.console_dirty = true;
            }
        }
    }

    /// Result of the pre-update check: no candidates → continue with the
    /// normal `-Syu`; otherwise show the dialog and wait for the user.
    fn on_downgrade_check(&mut self, packages: Vec<DowngradeEntry>, error: Option<String>) {
        self.downgrade_check_pending = false;
        if error.is_none() && packages.is_empty() {
            self.run_system_change(Message::SystemUpgradeRequested);
            return;
        }
        if let Some(error) = error {
            // Detection is best-effort: a failure must not block updates.
            log::warn!("downgrade check failed: {error}");
            if let Some(ui) = self.ui.upgrade() {
                ui.set_updates_status(error.into());
            }
            self.run_system_change(Message::SystemUpgradeRequested);
            return;
        }

        self.downgrade_checked = vec![true; packages.len()];
        self.downgrade_rows.set_vec(
            packages
                .iter()
                .map(|d| convert::downgrade(d, true))
                .collect::<Vec<_>>(),
        );
        if let Some(ui) = self.ui.upgrade() {
            ui.set_updates_status("".into());
            ui.set_downgrade_selected_count(packages.len() as i32);
            ui.set_downgrade_selecting(false);
            ui.set_downgrade_open(true);
        }
    }

    // ───────────────────────── side menu ─────────────────────────

    fn on_taxonomy(&mut self, taxonomy: Taxonomy) {
        self.stats.taxonomy_sections += 3;
        self.taxonomy_sections
            .insert(TaxonomyKind::Category, taxonomy.categories);
        self.taxonomy_sections
            .insert(TaxonomyKind::Group, taxonomy.groups);
        self.taxonomy_sections
            .insert(TaxonomyKind::Repository, taxonomy.repositories);
        self.taxonomy_pending.clear();
        if self
            .ui
            .upgrade()
            .is_some_and(|ui| ui.get_view() == AppView::Browse)
        {
            self.rebuild_browse();
            // The counts may have changed (install / remove): refresh the open list.
            if let Some((kind, id)) = self.browse_open.clone() {
                self.bus
                    .publish(&Message::TaxonomyPackagesRequested { kind, id });
            }
        }
    }

    fn on_taxonomy_section(&mut self, kind: TaxonomyKind, entries: Vec<TaxonomyEntry>) {
        self.stats.taxonomy_sections += 1;
        self.taxonomy_sections.insert(kind, entries);
        self.taxonomy_pending.remove(&kind);
        if self.browse_section.kind() == kind
            && self
                .ui
                .upgrade()
                .is_some_and(|ui| ui.get_view() == AppView::Browse)
        {
            self.rebuild_browse();
        }
    }

    fn on_taxonomy_packages(
        &mut self,
        kind: TaxonomyKind,
        id: String,
        title: String,
        subtitle: String,
        packages: Vec<Package>,
    ) {
        if !self
            .browse_open
            .as_ref()
            .is_some_and(|(k, i)| *k == kind && *i == id)
        {
            return; // the user already opened something else
        }
        self.browse_paged.reset(packages);
        self.browse_packages.set_vec(Vec::new());
        self.stats.packages_materialized += push_page(
            &mut self.browse_paged,
            &self.browse_packages,
            &self.icons,
            FIRST_PAGE + 25,
        ) as u64;
        if let Some(ui) = self.ui.upgrade() {
            ui.set_browse_loading(false);
            ui.set_browse_has_more(self.browse_paged.has_more());
            ui.set_browse_entry_title(title.as_str().into());
            ui.set_browse_entry_subtitle(subtitle.as_str().into());
        }
    }

    /// Ask the search module for one side-menu section (the page being opened).
    fn request_taxonomy(&mut self, kind: TaxonomyKind) {
        if !self.backend.supports(match kind {
            TaxonomyKind::Category => Feature::Categories,
            TaxonomyKind::Group => Feature::TaxonomyGroups,
            TaxonomyKind::Repository => Feature::TaxonomyRepositories,
        }) {
            if let Some(ui) = self.ui.upgrade() {
                ui.set_browse_loading(false);
            }
            return;
        }
        if self.taxonomy_sections.contains_key(&kind) {
            self.rebuild_browse();
            return;
        }
        if !self.taxonomy_pending.insert(kind) {
            return;
        }
        if let Some(ui) = self.ui.upgrade() {
            ui.set_browse_loading(true);
        }
        self.bus
            .publish(&Message::TaxonomySectionRequested { kind });
    }

    /// Put the rows of the current section on screen (families collapsed).
    fn rebuild_browse(&mut self) {
        let kind = self.browse_section.kind();
        let Some(all) = self.taxonomy_sections.get(&kind).cloned() else {
            self.request_taxonomy(kind);
            return;
        };
        self.browse_all = all;

        let mut rows = Vec::with_capacity(self.browse_all.len());
        let (mut top, mut deep) = (0usize, 0usize);
        for entry in &self.browse_all {
            // Member groups stay hidden until their family row is expanded.
            if entry.depth == 1 && !self.expanded.contains(&entry.parent) {
                continue;
            }
            if entry.depth == 0 {
                top += 1;
            } else {
                deep += 1;
            }
            let expanded = entry.expandable && self.expanded.contains(&entry.id);
            rows.push(convert::taxonomy(
                entry,
                self.icons.get(&entry.icon),
                expanded,
            ));
        }
        self.browse_entries.set_vec(rows);
        // Icon-theme pictures are requested by the rows that are actually on
        // screen (`browse_icon_needed`), not for the whole list.

        if let Some(ui) = self.ui.upgrade() {
            let status = match self.browse_section {
                BrowseSection::Categories => {
                    let custom = self
                        .browse_all
                        .iter()
                        .filter(|e| e.id.starts_with("addon:"))
                        .count();
                    if custom == 0 {
                        format!("{top} categories · {deep} subcategories · from AppStream")
                    } else {
                        format!(
                            "{top} categories · {deep} subcategories · {custom} add-on categories"
                        )
                    }
                }
                BrowseSection::Groups => {
                    format!("{top} entries · {} groups · from pacman", top + deep)
                }
                BrowseSection::Repositories => format!("{top} repositories · from pacman.conf"),
            };
            ui.set_browse_section(match self.browse_section {
                BrowseSection::Categories => 0,
                BrowseSection::Groups => 1,
                BrowseSection::Repositories => 2,
            });
            ui.set_browse_title(self.browse_section.title().into());
            ui.set_browse_status(status.into());
            ui.set_browse_loading(false);
        }
    }

    /// A drawer row was chosen: show that section, starting at its list.
    pub fn open_browse(&mut self, section: i32) {
        let next = BrowseSection::from_int(section);
        if self.browse_section != next {
            self.browse_open = None;
        }
        self.browse_section = next;
        self.return_view = None;
        let Some(ui) = self.ui.upgrade() else { return };
        ui.set_browse_section(section);
        ui.set_browse_title(next.title().into());
        ui.set_browse_entry_open(false);
        ui.set_browse_entry_title("".into());
        ui.set_browse_entry_subtitle("".into());
        ui.set_browse_has_more(false);
        self.browse_packages.set_vec(Vec::new());
        ui.set_view(AppView::Browse);
        self.request_taxonomy(next.kind());
    }

    /// A row of the browse page was clicked.
    pub fn browse_entry_clicked(&mut self, entry: crate::UiTaxonomyEntry) {
        let id = entry.id.to_string();
        // Families expand in place; their member groups then open normally.
        if entry.expandable {
            if !self.expanded.remove(&id) {
                self.expanded.insert(id);
            }
            self.rebuild_browse();
            return;
        }
        let Some(found) = self.browse_all.iter().find(|e| e.id == id).cloned() else {
            return;
        };
        let kind = self.browse_section.kind();
        self.browse_open = Some((kind, id.clone()));
        let Some(ui) = self.ui.upgrade() else { return };
        ui.set_browse_entry_open(true);
        ui.set_browse_entry_title(found.title.as_str().into());
        ui.set_browse_entry_subtitle(found.subtitle.as_str().into());
        ui.set_browse_loading(true);
        ui.set_browse_has_more(false);
        self.browse_packages.set_vec(Vec::new());
        self.bus
            .publish(&Message::TaxonomyPackagesRequested { kind, id });
    }

    /// Back of the browse page: close the open entry, then the page itself.
    pub fn browse_back(&mut self) {
        if self.browse_open.take().is_some() {
            let Some(ui) = self.ui.upgrade() else { return };
            ui.set_browse_entry_open(false);
            ui.set_browse_entry_title("".into());
            ui.set_browse_entry_subtitle("".into());
            ui.set_browse_loading(false);
            ui.set_browse_has_more(false);
            self.browse_packages.set_vec(Vec::new());
        } else if let Some(ui) = self.ui.upgrade() {
            ui.set_view(AppView::Main);
        }
    }

    pub fn browse_more(&mut self) {
        self.stats.packages_materialized += push_page(
            &mut self.browse_paged,
            &self.browse_packages,
            &self.icons,
            PAGE * 2,
        ) as u64;
        if let Some(ui) = self.ui.upgrade() {
            ui.set_browse_has_more(self.browse_paged.has_more());
        }
    }

    /// "Home" in the drawer.
    pub fn menu_home(&mut self) {
        self.return_view = None;
        self.start_search("");
        self.request_home();
        if let Some(ui) = self.ui.upgrade() {
            ui.set_view(AppView::Main);
        }
    }

    fn on_icon(&mut self, name: String, path: String) {
        let Ok(img) = Image::load_from_path(Path::new(&path)) else {
            return;
        };
        self.stats.icons_loaded += 1;
        self.each_model(|m| patch_rows(m, &name, |r| r.icon = img.clone()));
        // Side-menu rows ask for their icon-theme picture by icon name.
        for i in 0..self.browse_entries.row_count() {
            if let Some(mut row) = self
                .browse_entries
                .row_data(i)
                .filter(|r| r.icon_key.as_str() == name)
            {
                row.icon = img.clone();
                self.browse_entries.set_row_data(i, row);
            }
        }
        if let Some(m) = self.script_options.as_ref() {
            for i in 0..m.row_count() {
                if let Some(mut row) = m.row_data(i).filter(|r| r.icon_key.as_str() == name) {
                    row.icon = img.clone();
                    m.set_row_data(i, row);
                }
            }
        }
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
            Operation::SystemUpgrade
            | Operation::SystemDowngrade
            | Operation::Downgrade { .. } => self.request_updates(),
        }
        if self.ui.upgrade().is_some_and(|ui| ui.get_active_tab() == 2) {
            self.refresh_installed();
        }
        // Installed counts in the side menu changed. Only the section on screen
        // (if any) is discovered again.
        self.taxonomy_sections.clear();
        self.taxonomy_pending.clear();
        if self
            .ui
            .upgrade()
            .is_some_and(|ui| ui.get_view() == AppView::Browse)
        {
            self.request_taxonomy(self.browse_section.kind());
        }
    }

    // ───────────────────────── scripts ─────────────────────────

    fn on_script_view(&mut self, view: ScriptViewData) {
        self.script_seq = view.seq;
        let Some(ui) = self.ui.upgrade() else { return };
        ui.set_script_selected(view.preselected.map_or(-1, |i| i as i32));
        ui.set_script_checked_count(view.options.iter().filter(|o| o.checked).count() as i32);
        let (ui_view, options) = convert::script_view(&view, &self.icons);
        self.script_options = Some(options);
        ui.set_script_view(ui_view);
        let missing: Vec<String> = view
            .options
            .iter()
            .filter(|o| !o.icon.is_empty())
            .map(|o| o.icon.clone())
            .collect();
        if !view.busy {
            // a screen that needs the user always comes back to the front
            ui.set_script_minimized(false);
        }
        ui.set_script_active(true);
        self.request_icons(missing);
    }

    /// A check box was clicked.
    pub fn script_option_toggled(&mut self, i: usize) {
        let Some(m) = self.script_options.as_ref() else {
            return;
        };
        if let Some(mut row) = m.row_data(i) {
            row.checked = !row.checked;
            m.set_row_data(i, row);
        }
        let n = (0..m.row_count())
            .filter(|&j| m.row_data(j).is_some_and(|r| r.checked))
            .count();
        if let Some(ui) = self.ui.upgrade() {
            ui.set_script_checked_count(n as i32);
        }
    }

    fn on_script_ended(&mut self, success: bool) {
        self.script_running = false;
        let Some(ui) = self.ui.upgrade() else { return };
        ui.set_script_active(false);
        ui.set_script_minimized(false);
        ui.set_script_running_id("".into());
        // The install record may have changed: refresh the open add-on page.
        if let Some(cur) = self.current.clone().filter(|c| c.repo == "script") {
            self.bus
                .publish(&Message::ScriptInfoRequested { id: cur.name });
        }
        if success {
            // A script may have installed or removed packages.
            match ui.get_active_tab() {
                1 => self.request_updates(),
                2 => self.refresh_installed(),
                _ => {}
            }
        }
    }

    /// A card was clicked: packages and scripts both open their own page.
    pub fn app_clicked(&mut self, pkg: Package) {
        self.open_package(pkg, false);
    }

    /// "Run script" on a script's page.
    pub fn run_current_script(&mut self) {
        if let Some(cur) = self.current.clone().filter(|c| c.repo == "script") {
            self.start_script(cur.name);
        }
    }

    fn on_script_info(&mut self, id: String, info: Option<ScriptInfo>) {
        if self.current.as_ref().map(|c| c.name.as_str()) != Some(id.as_str()) {
            return; // the user already moved on
        }
        let Some(info) = info else {
            self.script_page = None;
            if let Some(ui) = self.ui.upgrade() {
                ui.set_current_script_info(UiScriptInfo {
                    loaded: true,
                    author: "—".into(),
                    source: "File not found".into(),
                    ..Default::default()
                });
            }
            return;
        };
        let dynamic = info.version_dynamic
            || info.download_dynamic
            || info.extracted_dynamic
            || info.installed_dynamic;
        // Keep values already computed for this add-on (e.g. when the page is refreshed after a run).
        let keep = self
            .script_page
            .take()
            .filter(|p| p.id == id && p.state == ValuesState::Done);
        let (values, state) = match keep {
            Some(p) => (p.values, ValuesState::Done),
            None if !dynamic => (ScriptValues::default(), ValuesState::Static),
            None if info.needs_confirm => (ScriptValues::default(), ValuesState::NeedsConfirm),
            None => {
                // Shipped with the store: safe to compute right away.
                self.bus.publish(&Message::ScriptEvalRequested {
                    id: id.clone(),
                    confirmed: false,
                });
                (ScriptValues::default(), ValuesState::Calculating)
            }
        };
        self.script_page = Some(ScriptPage {
            id,
            info,
            values,
            state,
        });
        self.show_script_page();
    }

    fn on_script_values(&mut self, id: String, values: ScriptValues) {
        let Some(page) = self.script_page.as_mut().filter(|p| p.id == id) else {
            return;
        };
        page.values = values;
        page.state = ValuesState::Done;
        self.show_script_page();
    }

    /// "Calculate size and version" on a script from the user's own folder.
    pub fn eval_current_script(&mut self) {
        let Some(page) = self.script_page.as_mut() else {
            return;
        };
        page.state = ValuesState::Calculating;
        let id = page.id.clone();
        self.bus.publish(&Message::ScriptEvalRequested {
            id,
            confirmed: true,
        });
        self.show_script_page();
    }

    /// Put the page's facts on screen: sizes, version, installed state.
    fn show_script_page(&mut self) {
        let Some(ui) = self.ui.upgrade() else { return };
        let Some(page) = self.script_page.as_ref() else {
            return;
        };
        let (i, v, st) = (&page.info, &page.values, page.state);

        let mb = |m: u64| -> String {
            if m >= 1024 {
                format!("{:.1} GB", m as f64 / 1024.0)
            } else {
                format!("{m} MB")
            }
        };
        // written value, or the computed one with a status text while it is missing
        let field =
            |written: Option<u64>, dynamic: bool, computed: Option<u64>| -> (String, Option<u64>) {
                if !dynamic {
                    return (written.map_or("Not specified".into(), mb), written);
                }
                match (st, computed) {
                    (ValuesState::Done, Some(m)) => (mb(m), Some(m)),
                    (ValuesState::Done, None) => ("Unavailable".into(), None),
                    (ValuesState::NeedsConfirm, _) => ("Not calculated".into(), None),
                    _ => ("Calculating…".into(), None),
                }
            };
        let (download, dl) = field(i.download_mb, i.download_dynamic, v.download_mb);
        let (extracted, ex) = field(i.extracted_mb, i.extracted_dynamic, v.extracted_mb);
        let (installed, ins) = field(i.installed_mb, i.installed_dynamic, v.installed_mb);

        let free_mb = i.free_bytes / (1024 * 1024);
        let needed = ex.or(ins).unwrap_or(0) + dl.unwrap_or(0);
        let version = if i.version_dynamic {
            match (st, v.version.clone()) {
                (ValuesState::Done, Some(x)) => x,
                (ValuesState::Done, None) => "unknown".into(),
                (ValuesState::NeedsConfirm, _) => "not calculated".into(),
                _ => "calculating…".into(),
            }
        } else {
            i.version.clone()
        };

        let installed_text = if i.installed {
            let date = ymd(i.installed_at);
            if i.installed_version.is_empty() {
                date
            } else {
                format!("{} · {date}", i.installed_version)
            }
        } else {
            String::new()
        };

        ui.set_current_script_info(UiScriptInfo {
            loaded: true,
            author: if i.author.is_empty() {
                "Unknown".into()
            } else {
                i.author.as_str().into()
            },
            source: if i.user_script {
                "Your own add-on package".into()
            } else {
                "Included with Tux Store".into()
            },
            admin: if i.root_commands == 0 {
                "Not required".into()
            } else {
                format!(
                    "Required ({} command{})",
                    i.root_commands,
                    if i.root_commands == 1 { "" } else { "s" }
                )
                .into()
            },
            path: if i.user_script {
                i.path.as_str().into()
            } else {
                "".into()
            },
            download: download.into(),
            extracted: extracted.into(),
            installed_size: installed.into(),
            free: if i.free_bytes == 0 {
                "Unknown".into()
            } else {
                mb(free_mb).into()
            },
            low_space: i.free_bytes != 0 && needed > 0 && free_mb < needed,
            space_ratio: if free_mb == 0 {
                0.0
            } else {
                (needed as f32 / free_mb as f32).min(1.0)
            },
            note: i.note.as_str().into(),
            installed: i.installed,
            installed_text: installed_text.into(),
            can_uninstall: i.can_uninstall,
            needs_confirm: st == ValuesState::NeedsConfirm,
        });

        // The header: version text and the green "Installed" pill.
        let mut cur = ui.get_current_package();
        cur.version = version.as_str().into();
        cur.installed = i.installed;
        ui.set_current_package(cur);
    }

    /// "Uninstall" on an installed add-on package's page.
    pub fn uninstall_current_script(&mut self) {
        if let Some(cur) = self.current.clone().filter(|c| c.repo == "script") {
            self.run_script(cur.name, true);
        }
    }

    fn start_script(&mut self, id: String) {
        self.run_script(id, false);
    }

    fn run_script(&mut self, id: String, uninstall: bool) {
        let Some(ui) = self.ui.upgrade() else { return };
        if self.script_running || ui.get_current_install().phase == OpPhase::Running {
            return;
        }
        self.stats.operations_started += 1;
        self.script_running = true;
        ui.set_script_minimized(false);
        ui.set_script_running_id(id.as_str().into());
        self.console.clear();
        self.console_dirty = true;
        ui.set_script_has_output(false);
        ui.set_script_progress(0.0);
        ui.set_script_progress_label("".into());
        if uninstall {
            self.bus.publish(&Message::ScriptUninstallRequested { id });
        } else {
            self.bus.publish(&Message::ScriptStartRequested { id });
        }
    }

    /// A button of the script dialog (the option selection lives in Slint).
    pub fn script_button(&mut self, button: usize) {
        let Some(ui) = self.ui.upgrade() else { return };
        let sel = ui.get_script_selected();
        let selected = usize::try_from(sel).ok();
        let checked: Vec<usize> = self
            .script_options
            .as_ref()
            .map(|m| {
                (0..m.row_count())
                    .filter(|&j| m.row_data(j).is_some_and(|r| r.checked))
                    .collect()
            })
            .unwrap_or_default();
        self.bus.publish(&Message::ScriptAction {
            seq: self.script_seq,
            button,
            selected,
            checked,
        });
    }

    // ───────────────────────── helpers ─────────────────────────

    fn each_model(&self, mut f: impl FnMut(&VecModel<UiPackage>)) {
        for m in self.section_models.iter().chain([
            &self.search,
            &self.installed,
            &self.addons,
            &self.suggestions,
            &self.browse_packages,
        ]) {
            f(m);
        }
    }

    /// Forget every loaded icon and ask the thumbnail module again for the ones
    /// on screen (after the cache was cleared / the icon theme changed).
    fn reload_icons(&mut self) {
        self.icons.clear();
        self.icon_requested.clear();

        self.each_model(|m| {
            for i in 0..m.row_count() {
                if let Some(mut row) = m.row_data(i) {
                    row.icon = Image::default();
                    m.set_row_data(i, row);
                }
            }
        });
        // Icon-theme pictures of the side-menu rows are cached under their icon
        // name, not a package name.
        for i in 0..self.browse_entries.row_count() {
            if let Some(mut row) = self.browse_entries.row_data(i) {
                row.icon = Image::default();
                self.browse_entries.set_row_data(i, row);
            }
        }
        let mut current = String::new();
        if let Some(ui) = self.ui.upgrade() {
            let mut cur = ui.get_current_package();
            if !cur.name.is_empty() {
                current = cur.name.to_string();
                cur.icon = Image::default();
                ui.set_current_package(cur);
            }
            // Cards on screen ask again; off-screen cards stay without a
            // picture until they are actually shown.
            ui.set_icon_refresh_tick(ui.get_icon_refresh_tick().wrapping_add(1));
        }
        if !current.is_empty() {
            self.request_icons(vec![current]);
        }
    }

    fn request_icons(&mut self, names: Vec<String>) {
        for name in names {
            if self.icon_requested.insert(name.clone()) {
                self.stats.icons_requested += 1;
                self.bus.publish(&Message::IconRequested { name, size: 64 });
            }
        }
    }

    /// Visible rows of the search grid.
    pub fn search_icons_needed(&mut self, first: i32, last: i32) {
        let names = names_in_range(&self.search, first, last);
        self.request_icons(names);
    }

    /// Visible rows of the Installed grid.
    pub fn installed_icons_needed(&mut self, first: i32, last: i32) {
        let names = names_in_range(&self.installed, first, last);
        self.request_icons(names);
    }

    /// Visible cards of the packages of one side-menu entry.
    pub fn browse_icons_needed(&mut self, first: i32, last: i32) {
        let names = names_in_range(&self.browse_packages, first, last);
        self.request_icons(names);
    }

    /// Visible cards of the add-ons list.
    pub fn addons_icons_needed(&mut self, first: i32, last: i32) {
        let names = names_in_range(&self.addons, first, last);
        self.request_icons(names);
    }

    /// One visible side-menu row asked for its icon-theme picture.
    pub fn browse_icon_needed(&mut self, key: String) {
        if !key.is_empty() {
            self.request_icons(vec![key]);
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
        // Before anything asks a question, tell every module which backend to use.
        self.bus.publish(&Message::EngineChanged {
            engine: self.engine,
        });
        self.bus.publish(&Message::UiReady);
        if !self.backend.is_supported() {
            // The window shows the unsupported state; asking for data would
            // only start spinners nobody can complete.
            return;
        }
        // Home (visible at start-up) and the cover already on screen. Nothing
        // else: the side menu, search, tabs and package pages ask for their
        // data when they are opened.
        self.bus.publish(&Message::HomeRequested);
        self.bus.publish(&Message::CoversRequested);
    }

    /// The Engine setting changed: persist it, tell the backends, and refresh
    /// everything that was answered by the old engine.
    pub fn set_engine(&mut self, key: &str) {
        let Some(engine) = Engine::from_key(key) else {
            return;
        };
        if engine == self.engine {
            return;
        }
        self.engine = engine;
        let mut cfg = crate::config::load();
        cfg.engine = engine;
        crate::config::save(&cfg);

        self.bus.publish(&Message::EngineChanged { engine });
        self.request_home();
        self.refresh_installed();
        self.request_updates();
        // Different backend = different repositories / groups / categories.
        self.taxonomy_sections.clear();
        self.taxonomy_pending.clear();
        if self
            .ui
            .upgrade()
            .is_some_and(|ui| ui.get_view() == AppView::Browse)
        {
            self.request_taxonomy(self.browse_section.kind());
        }
        if let Some(current) = self.current.clone() {
            self.bus
                .publish(&Message::DetailsRequested { name: current.name });
        }
    }

    pub fn request_home(&mut self) {
        if !self.backend.is_supported() {
            return;
        }
        self.bus.publish(&Message::HomeRequested);
    }

    pub fn open_by_name(&mut self, name: String) {
        if !self.backend.supports(Feature::Details) {
            return;
        }
        self.bus.publish(&Message::ExactRequested { name });
    }

    pub fn start_search(&mut self, raw: &str) {
        let q = raw.trim().to_string();
        self.search_query = q.clone();
        let Some(ui) = self.ui.upgrade() else { return };
        if q.is_empty() || !self.backend.supports(Feature::Search) {
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
        self.stats.packages_materialized +=
            push_page(&mut self.search_paged, &self.search, &self.icons, PAGE) as u64;
        if let Some(ui) = self.ui.upgrade() {
            ui.set_has_more_results(self.search_paged.has_more());
        }
    }

    pub fn refresh_installed(&mut self) {
        if !self.backend.supports(Feature::InstalledList) {
            if let Some(ui) = self.ui.upgrade() {
                ui.set_installed_loading(false);
            }
            return;
        }
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
                needle.is_empty()
                    || normalize(&p.name).contains(&needle)
                    || p.description.to_lowercase().contains(&lower)
            })
            .cloned()
            .collect();
        let total = list.len();
        self.installed_paged.reset(list);
        self.installed.set_vec(Vec::new());
        self.stats.packages_materialized += push_page(
            &mut self.installed_paged,
            &self.installed,
            &self.icons,
            FIRST_PAGE + 25,
        ) as u64;
        if let Some(ui) = self.ui.upgrade() {
            ui.set_installed_total(total as i32);
            ui.set_installed_has_more(self.installed_paged.has_more());
            ui.set_installed_loading(false);
        }
    }

    pub fn more_installed(&mut self) {
        self.stats.packages_materialized += push_page(
            &mut self.installed_paged,
            &self.installed,
            &self.icons,
            PAGE * 3,
        ) as u64;
        if let Some(ui) = self.ui.upgrade() {
            ui.set_installed_has_more(self.installed_paged.has_more());
        }
    }

    pub fn request_updates(&mut self) {
        if !self.backend.supports(Feature::Updates) {
            if let Some(ui) = self.ui.upgrade() {
                ui.set_updates_loading(false);
                ui.set_updates_status(self.backend.feature_message(Feature::Updates).into());
            }
            return;
        }
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
            self.forward.clear();
            if in_package_view {
                if let Some(cur) = self.current.clone().filter(|c| c.name != pkg.name) {
                    self.history.push(cur);
                }
            } else {
                self.history.clear();
                // Opened from the side menu: Back returns to that page.
                self.return_view = (ui.get_view() == AppView::Browse).then_some(AppView::Browse);
            }
        }

        ui.set_current_package(convert::to_ui(&pkg, self.icons.get(&pkg.name)));
        ui.set_current_details(UiPackageDetails {
            is_loading: true,
            ..Default::default()
        });
        ui.set_current_special_case(Default::default());
        ui.set_accent_idx(accent_for(&pkg.name));
        if ui.get_current_install().phase != OpPhase::Running {
            ui.set_current_install(UiInstallState::default());
        }
        let is_script = pkg.repo == "script";
        let backend_details = self.backend.supports(Feature::Details);
        self.screenshots.set_vec(Vec::new());
        if is_script {
            self.suggestions.set_vec(Vec::new());
            ui.set_current_script_info(UiScriptInfo::default());
            self.script_page = None;
        } else {
            self.build_suggestions(&pkg);
            if !backend_details {
                ui.set_current_details(UiPackageDetails {
                    is_loading: false,
                    ..Default::default()
                });
            }
        }
        // Add-on packages can have screenshots too (declared in their JSON).
        if backend_details {
            self.bus.publish(&Message::ScreenshotsRequested {
                name: pkg.name.clone(),
            });
        }
        ui.set_view(AppView::Details);

        let missing = if self.icons.contains_key(&pkg.name) {
            Vec::new()
        } else {
            vec![pkg.name.clone()]
        };
        self.request_icons(missing);
        if is_script {
            self.bus.publish(&Message::ScriptInfoRequested {
                id: pkg.name.clone(),
            });
        } else if backend_details {
            self.bus.publish(&Message::DetailsRequested {
                name: pkg.name.clone(),
            });
        }
        self.current = Some(pkg);
        self.sync_nav();
    }

    /// Tell the window whether a Forward button makes sense.
    fn sync_nav(&self) {
        if let Some(ui) = self.ui.upgrade() {
            ui.set_can_forward(!self.forward.is_empty());
        }
    }

    pub fn back(&mut self) {
        if let Some(cur) = self.current.clone() {
            self.forward.push(cur);
            if self.forward.len() > 50 {
                self.forward.remove(0);
            }
        }
        if let Some(prev) = self.history.pop() {
            self.open_package(prev, true);
        } else {
            let back_to = self.return_view.take().unwrap_or(AppView::Main);
            self.current = None;
            if let Some(ui) = self.ui.upgrade() {
                ui.set_view(back_to);
            }
        }
        self.sync_nav();
    }

    /// Undo a Back: reopen the page that was left.
    pub fn forward(&mut self) {
        let Some(next) = self.forward.pop() else {
            return;
        };
        if let Some(cur) = self.current.clone() {
            self.history.push(cur);
        }
        self.open_package(next, true);
        self.sync_nav();
    }

    pub fn show_addons(&mut self) {
        self.addons.set_vec(Vec::new());
        if !self.backend.supports(Feature::Addons) {
            return;
        }
        if let Some(cur) = &self.current {
            self.bus.publish(&Message::AddonsRequested {
                package: cur.name.clone(),
            });
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
        self.stats.packages_materialized += picks.len() as u64;
        let missing: Vec<String> = picks
            .iter()
            .filter(|p| !self.icons.contains_key(p.name.as_str()))
            .map(|p| p.name.to_string())
            .collect();
        self.suggestions.set_vec(picks);
        // The whole strip is part of the visible page; it is at most 8 cards.
        self.request_icons(missing);
    }

    // ── transactions ──

    fn begin_operation(&mut self, kind: OpKind, target: &str, deps_ratio: f32) -> bool {
        let Some(ui) = self.ui.upgrade() else {
            return false;
        };
        if self.script_running || ui.get_current_install().phase == OpPhase::Running {
            return false;
        }
        self.stats.operations_started += 1;
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
        if !self.backend.supports(Feature::Install) {
            return;
        }
        let Some(pkg) = self.current.clone() else {
            return;
        };
        if pkg.installed {
            return;
        }
        let d = &self.last_details;
        let denom = (d.new_deps + d.app_size) as f32;
        let ratio = if denom > 0.0 {
            d.new_deps as f32 / denom
        } else {
            0.0
        };
        if self.begin_operation(OpKind::Install, &pkg.name, ratio) {
            self.bus
                .publish(&Message::InstallRequested { name: pkg.name });
        }
    }

    pub fn remove_current(&mut self, flag: &str) {
        if !self.backend.supports(Feature::Remove) {
            return;
        }
        let (Some(pkg), Some(mode)) = (self.current.clone(), RemoveMode::from_flag(flag)) else {
            return;
        };
        if self.begin_operation(OpKind::Remove, &pkg.name, 0.0) {
            self.bus.publish(&Message::RemoveRequested {
                name: pkg.name,
                mode,
            });
        }
    }

    /// "Update all" no longer runs `pacman -Syu` blindly: check first whether
    /// installed packages are newer than the repositories. The answer decides
    /// between a plain update and the three-choice dialog.
    pub fn upgrade_all(&mut self) {
        if !self.backend.supports(Feature::Updates)
            || !self.backend.supports(Feature::SystemUpgrade)
        {
            return;
        }
        if self.downgrade_check_pending {
            return;
        }
        let busy = self.script_running
            || self
                .ui
                .upgrade()
                .is_some_and(|ui| ui.get_current_install().phase == OpPhase::Running);
        if busy {
            return;
        }
        self.downgrade_check_pending = true;
        if let Some(ui) = self.ui.upgrade() {
            ui.set_updates_status("Checking installed packages…".into());
        }
        self.bus.publish(&Message::DowngradeCheckRequested);
    }

    /// First choice: update normally (`-Syu`) and keep the newer packages.
    pub fn downgrade_continue(&mut self) {
        if !self.backend.supports(Feature::SystemUpgrade) {
            return;
        }
        self.close_downgrade();
        self.run_system_change(Message::SystemUpgradeRequested);
    }

    /// Second choice: replace every newer package (`-Syuu`).
    pub fn downgrade_all(&mut self) {
        if !self.backend.supports(Feature::Downgrade) {
            return;
        }
        self.close_downgrade();
        self.run_system_change(Message::SystemDowngradeRequested);
    }

    /// Third choice: downgrade only the ticked packages.
    pub fn downgrade_selected(&mut self) {
        if !self.backend.supports(Feature::Downgrade) {
            return;
        }
        let packages: Vec<String> = (0..self.downgrade_rows.row_count())
            .filter(|&i| self.downgrade_checked.get(i).copied().unwrap_or(false))
            .filter_map(|i| self.downgrade_rows.row_data(i))
            .map(|row| row.name.to_string())
            .collect();
        if packages.is_empty() {
            return;
        }
        self.close_downgrade();
        self.run_system_change(Message::DowngradeRequested { packages });
    }

    pub fn downgrade_cancel(&mut self) {
        self.close_downgrade();
        if let Some(ui) = self.ui.upgrade() {
            ui.set_updates_status("".into());
        }
    }

    pub fn downgrade_toggle(&mut self, i: usize) {
        let Some(checked) = self.downgrade_checked.get_mut(i) else {
            return;
        };
        *checked = !*checked;
        let checked = *checked;
        if let Some(mut row) = self.downgrade_rows.row_data(i) {
            row.checked = checked;
            self.downgrade_rows.set_row_data(i, row);
        }
        let count = self.downgrade_checked.iter().filter(|c| **c).count();
        if let Some(ui) = self.ui.upgrade() {
            ui.set_downgrade_selected_count(count as i32);
        }
    }

    fn close_downgrade(&mut self) {
        self.downgrade_check_pending = false;
        self.downgrade_rows.set_vec(Vec::new());
        self.downgrade_checked.clear();
        if let Some(ui) = self.ui.upgrade() {
            ui.set_downgrade_open(false);
            ui.set_downgrade_selecting(false);
            ui.set_downgrade_selected_count(0);
        }
    }

    fn run_system_change(&mut self, msg: Message) {
        if let Some(ui) = self.ui.upgrade() {
            ui.set_updates_status("".into());
        }
        if self.begin_operation(OpKind::Upgrade, "@upgrade", 0.0) {
            self.bus.publish(&msg);
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
        // Only the visible cover is ever decoded. A remote cover that has not
        // been downloaded yet shows a placeholder and asks for its pictures
        // now that it is on screen.
        let image = match cover
            .images
            .get(fastrand::usize(..cover.images.len().max(1)))
        {
            Some(pick) => {
                self.stats.covers_shown += 1;
                Image::load_from_path(Path::new(pick)).unwrap_or_default()
            }
            None => {
                self.bus.publish(&Message::CoverImagesRequested {
                    name: cover.name.clone(),
                });
                Image::default()
            }
        };
        ui.set_cover_name(prettify_name(&cover.name).as_str().into());
        ui.set_cover_image(image);
        ui.set_cover_count(self.covers.len() as i32);
    }

    pub fn step_cover(&mut self, forward: bool) {
        let n = self.covers.len();
        if n == 0 {
            return;
        }
        self.cover_idx = if forward {
            (self.cover_idx + 1) % n
        } else {
            (self.cover_idx + n - 1) % n
        };
        self.show_cover();
    }

    pub fn open_cover(&mut self) {
        if let Some(cover) = self.covers.get(self.cover_idx) {
            let name = cover_package(&cover.name).to_string();
            self.bus.publish(&Message::ExactRequested { name });
        }
    }
}

/// `2026-11-03` from Unix seconds (UTC), without a date library.
fn ymd(secs: u64) -> String {
    let z = (secs / 86_400) as i64 + 719_468;
    let era = z.div_euclid(146_097);
    let doe = z.rem_euclid(146_097);
    let yoe = (doe - doe / 1_460 + doe / 36_524 - doe / 146_096) / 365;
    let doy = doe - (365 * yoe + yoe / 4 - yoe / 100);
    let mp = (5 * doy + 2) / 153;
    let d = doy - (153 * mp + 2) / 5 + 1;
    let m = if mp < 10 { mp + 3 } else { mp - 9 };
    let y = yoe + era * 400 + i64::from(m <= 2);
    format!("{y:04}-{m:02}-{d:02}")
}

#[cfg(test)]
mod lazy_tests {
    use super::*;

    fn model(names: &[&str]) -> VecModel<UiPackage> {
        VecModel::from(
            names
                .iter()
                .map(|n| UiPackage {
                    name: (*n).into(),
                    ..Default::default()
                })
                .collect::<Vec<_>>(),
        )
    }

    #[test]
    fn visible_range_is_clamped_to_the_model() {
        let m = model(&["a", "b", "c"]);
        assert_eq!(names_in_range(&m, 1, 2), ["b", "c"]);
        assert_eq!(names_in_range(&m, -5, 0), ["a"]);
        assert_eq!(names_in_range(&m, 2, 99), ["c"]);
        assert!(names_in_range(&m, 3, 4).is_empty());
        assert!(names_in_range(&m, 2, 1).is_empty());
        assert!(names_in_range(&model(&[]), 0, 10).is_empty());
    }
}

#[cfg(test)]
mod date_tests {
    use super::ymd;

    #[test]
    fn civil_dates() {
        assert_eq!(ymd(0), "1970-01-01");
        assert_eq!(ymd(1_000_000_000), "2001-09-09");
        assert_eq!(ymd(1_793_664_000), "2026-11-03");
    }
}
