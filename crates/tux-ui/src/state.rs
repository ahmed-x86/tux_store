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
    AppView, MainWindow, OpKind, OpPhase, UiInstallState, UiPackage, UiPackageDetails, UiScriptInfo, UiScriptOption,
    UiSection,
};
use slint::{Image, Model, ModelRc, VecModel, Weak};
use std::cell::RefCell;
use std::collections::{HashMap, HashSet};
use std::path::Path;
use std::rc::Rc;
use tux_abi::text::prettify_name;
use tux_abi::{
    Bus, Cover, Engine, Message, Operation, Package, PackageDetails, RemoveMode, ScriptInfo, ScriptValues, ScriptViewData,
    Section, SpecialCase,
    UpdateEntry,
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
    /// Package-manager backend selected in Settings.
    engine: Engine,

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

    covers: Vec<Cover>,
    cover_idx: usize,

    current: Option<Package>,
    history: Vec<Package>,
    /// Pages left with Back; "Forward" returns to them (cleared by any new navigation).
    forward: Vec<Package>,
    last_details: PackageDetails,

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
            covers: Vec::new(),
            cover_idx: 0,
            current: None,
            history: Vec::new(),
            forward: Vec::new(),
            last_details: PackageDetails::default(),
            console: ConsoleBuffer::default(),
            console_dirty: false,
            script_seq: 0,
            script_running: false,
            script_page: None,
            script_options: None,
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
    }

    // ───────────────────────── bus → UI ─────────────────────────

    pub fn handle(&mut self, msg: Message) {
        match msg {
            Message::HomeReady { sections } => self.on_home(sections),
            Message::SearchResults { query, packages } => self.on_search_results(query, packages),
            Message::DetailsReady { name, details, special } => self.on_details(name, details, special),
            Message::ExactReady { package } => self.open_package(package, false),
            Message::ScreenshotsReady { name, images } => self.on_screenshots(name, images),
            Message::AddonsReady { package, packages } => self.on_addons(package, packages),
            Message::InstalledReady { packages } => {
                self.installed_all = packages;
                self.apply_installed_filter();
            }
            Message::UpdatesReady { updates, error } => self.on_updates(updates, error),
            Message::CoversReady { covers } => {
                // Remote covers arrive in later, longer lists: stay on the cover that is
                // showing instead of jumping to another one.
                let showing = self.covers.get(self.cover_idx).map(|c| c.name.clone());
                self.covers = covers;
                let kept = showing.and_then(|n| self.covers.iter().position(|c| c.name == n));
                match kept {
                    Some(i) => {
                        self.cover_idx = i;
                        if let Some(ui) = self.ui.upgrade() {
                            ui.set_cover_count(self.covers.len() as i32);
                        }
                    }
                    None => {
                        self.cover_idx = if self.covers.is_empty() { 0 } else { fastrand::usize(..self.covers.len()) };
                        self.show_cover();
                    }
                }
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

        // The first apps of the first shelves are the likeliest to be opened:
        // let the thumbnail module fetch their screenshots while the user looks around.
        let likely: Vec<String> = sections
            .iter()
            .take(4)
            .flat_map(|s| s.packages.iter().take(3))
            .filter(|p| p.repo != "script")
            .map(|p| p.name.clone())
            .collect();
        if !likely.is_empty() {
            self.bus.publish(&Message::ScreenshotsPrefetch { names: likely });
        }
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

    /// Screenshots arrive as complete lists (possibly several times while a
    /// Flathub download is running); the slider is simply replaced.
    fn on_screenshots(&mut self, name: String, images: Vec<String>) {
        if self.current.as_ref().map(|c| c.name.as_str()) != Some(name.as_str()) {
            return; // user already navigated elsewhere
        }
        let loaded: Vec<Image> = images.iter().filter_map(|p| Image::load_from_path(Path::new(p)).ok()).collect();
        self.screenshots.set_vec(loaded);
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
            Operation::SystemUpgrade => self.request_updates(),
        }
        if self.ui.upgrade().is_some_and(|ui| ui.get_active_tab() == 2) {
            self.refresh_installed();
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
        let missing: Vec<String> = view.options.iter().filter(|o| !o.icon.is_empty()).map(|o| o.icon.clone()).collect();
        if !view.busy {
            // a screen that needs the user always comes back to the front
            ui.set_script_minimized(false);
        }
        ui.set_script_active(true);
        self.request_icons(missing);
    }

    /// A check box was clicked.
    pub fn script_option_toggled(&mut self, i: usize) {
        let Some(m) = self.script_options.as_ref() else { return };
        if let Some(mut row) = m.row_data(i) {
            row.checked = !row.checked;
            m.set_row_data(i, row);
        }
        let n = (0..m.row_count()).filter(|&j| m.row_data(j).is_some_and(|r| r.checked)).count();
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
            self.bus.publish(&Message::ScriptInfoRequested { id: cur.name });
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
                ui.set_current_script_info(UiScriptInfo { loaded: true, author: "—".into(), source: "File not found".into(), ..Default::default() });
            }
            return;
        };
        let dynamic = info.version_dynamic || info.download_dynamic || info.extracted_dynamic || info.installed_dynamic;
        // Keep values already computed for this add-on (e.g. when the page is refreshed after a run).
        let keep = self.script_page.take().filter(|p| p.id == id && p.state == ValuesState::Done);
        let (values, state) = match keep {
            Some(p) => (p.values, ValuesState::Done),
            None if !dynamic => (ScriptValues::default(), ValuesState::Static),
            None if info.needs_confirm => (ScriptValues::default(), ValuesState::NeedsConfirm),
            None => {
                // Shipped with the store: safe to compute right away.
                self.bus.publish(&Message::ScriptEvalRequested { id: id.clone(), confirmed: false });
                (ScriptValues::default(), ValuesState::Calculating)
            }
        };
        self.script_page = Some(ScriptPage { id, info, values, state });
        self.show_script_page();
    }

    fn on_script_values(&mut self, id: String, values: ScriptValues) {
        let Some(page) = self.script_page.as_mut().filter(|p| p.id == id) else { return };
        page.values = values;
        page.state = ValuesState::Done;
        self.show_script_page();
    }

    /// "Calculate size and version" on a script from the user's own folder.
    pub fn eval_current_script(&mut self) {
        let Some(page) = self.script_page.as_mut() else { return };
        page.state = ValuesState::Calculating;
        let id = page.id.clone();
        self.bus.publish(&Message::ScriptEvalRequested { id, confirmed: true });
        self.show_script_page();
    }

    /// Put the page's facts on screen: sizes, version, installed state.
    fn show_script_page(&mut self) {
        let Some(ui) = self.ui.upgrade() else { return };
        let Some(page) = self.script_page.as_ref() else { return };
        let (i, v, st) = (&page.info, &page.values, page.state);

        let mb = |m: u64| -> String {
            if m >= 1024 { format!("{:.1} GB", m as f64 / 1024.0) } else { format!("{m} MB") }
        };
        // written value, or the computed one with a status text while it is missing
        let field = |written: Option<u64>, dynamic: bool, computed: Option<u64>| -> (String, Option<u64>) {
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
            if i.installed_version.is_empty() { date } else { format!("{} · {date}", i.installed_version) }
        } else {
            String::new()
        };

        ui.set_current_script_info(UiScriptInfo {
            loaded: true,
            author: if i.author.is_empty() { "Unknown".into() } else { i.author.as_str().into() },
            source: if i.user_script { "Your own add-on package".into() } else { "Included with Tux Store".into() },
            admin: if i.root_commands == 0 {
                "Not required".into()
            } else {
                format!("Required ({} command{})", i.root_commands, if i.root_commands == 1 { "" } else { "s" }).into()
            },
            path: if i.user_script { i.path.as_str().into() } else { "".into() },
            download: download.into(),
            extracted: extracted.into(),
            installed_size: installed.into(),
            free: if i.free_bytes == 0 { "Unknown".into() } else { mb(free_mb).into() },
            low_space: i.free_bytes != 0 && needed > 0 && free_mb < needed,
            space_ratio: if free_mb == 0 { 0.0 } else { (needed as f32 / free_mb as f32).min(1.0) },
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
            .map(|m| (0..m.row_count()).filter(|&j| m.row_data(j).is_some_and(|r| r.checked)).collect())
            .unwrap_or_default();
        self.bus.publish(&Message::ScriptAction { seq: self.script_seq, button, selected, checked });
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
        // Before anything asks a question, tell every module which backend to use.
        self.bus.publish(&Message::EngineChanged { engine: self.engine });
        self.bus.publish(&Message::UiReady);
        self.bus.publish(&Message::HomeRequested);
        self.bus.publish(&Message::CoversRequested);
    }

    /// The Engine setting changed: persist it, tell the backends, and refresh
    /// everything that was answered by the old engine.
    pub fn set_engine(&mut self, key: &str) {
        let Some(engine) = Engine::from_key(key) else { return };
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
        if let Some(current) = self.current.clone() {
            self.bus.publish(&Message::DetailsRequested { name: current.name });
        }
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
            self.forward.clear();
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
        let is_script = pkg.repo == "script";
        self.screenshots.set_vec(Vec::new());
        if is_script {
            self.suggestions.set_vec(Vec::new());
            ui.set_current_script_info(UiScriptInfo::default());
            self.script_page = None;
        } else {
            self.build_suggestions(&pkg);
        }
        // Add-on packages can have screenshots too (declared in their JSON).
        self.bus.publish(&Message::ScreenshotsRequested { name: pkg.name.clone() });
        ui.set_view(AppView::Details);

        let missing = if self.icons.contains_key(&pkg.name) { Vec::new() } else { vec![pkg.name.clone()] };
        self.request_icons(missing);
        if is_script {
            self.bus.publish(&Message::ScriptInfoRequested { id: pkg.name.clone() });
        } else {
            self.bus.publish(&Message::DetailsRequested { name: pkg.name.clone() });
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
            self.current = None;
            if let Some(ui) = self.ui.upgrade() {
                ui.set_view(AppView::Main);
            }
        }
        self.sync_nav();
    }

    /// Undo a Back: reopen the page that was left.
    pub fn forward(&mut self) {
        let Some(next) = self.forward.pop() else { return };
        if let Some(cur) = self.current.clone() {
            self.history.push(cur);
        }
        self.open_package(next, true);
        self.sync_nav();
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
        if self.script_running || ui.get_current_install().phase == OpPhase::Running {
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
mod date_tests {
    use super::ymd;

    #[test]
    fn civil_dates() {
        assert_eq!(ymd(0), "1970-01-01");
        assert_eq!(ymd(1_000_000_000), "2001-09-09");
        assert_eq!(ymd(1_793_664_000), "2026-11-03");
    }
}
