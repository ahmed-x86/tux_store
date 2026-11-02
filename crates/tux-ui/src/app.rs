//! Window creation and wiring of every Slint callback to [`State`].

use crate::config::{self, Config};
use crate::state::{self, with_state, State};
use crate::{convert, links, MainWindow, Theme};
use slint::{ComponentHandle, PlatformError, Timer, TimerMode};
use std::rc::Rc;
use std::time::Duration;
use tux_abi::Bus;

const SEARCH_DEBOUNCE: Duration = Duration::from_millis(250);
const CONSOLE_FLUSH: Duration = Duration::from_millis(100);

pub fn run(bus: Bus) -> Result<(), PlatformError> {
    let ui = MainWindow::new()?;

    let cfg = config::load();
    ui.global::<Theme>().set_is_dark(cfg.dark);
    ui.set_app_version(env!("CARGO_PKG_VERSION").into());

    let st = State::new(ui.as_weak(), bus);
    st.bind(&ui);
    state::install(st);

    wire(&ui);

    // Copy the pacman console into Slint a few times per second instead of on
    // every output chunk. Must stay alive while the event loop runs.
    let flush_timer = Timer::default();
    flush_timer.start(TimerMode::Repeated, CONSOLE_FLUSH, || {
        with_state(|st| st.flush_console());
    });

    with_state(|st| {
        st.startup();
        // `tux-store openpackage <name>` deep link.
        let mut args = std::env::args().skip(1);
        if args.next().as_deref() == Some("openpackage") {
            if let Some(name) = args.next() {
                st.open_by_name(name);
            }
        }
    });

    let result = ui.run();
    drop(flush_timer);
    state::clear();
    result
}

fn wire(ui: &MainWindow) {
    // ── search (debounced while typing, immediate on Enter) ──
    let debounce = Rc::new(Timer::default());
    ui.on_search_edited({
        let debounce = debounce.clone();
        move |text| {
            let text = text.to_string();
            debounce.start(TimerMode::SingleShot, SEARCH_DEBOUNCE, move || {
                with_state(|st| st.start_search(&text));
            });
        }
    });
    ui.on_search_submitted({
        let debounce = debounce.clone();
        move |text| {
            debounce.stop();
            with_state(|st| st.start_search(&text));
        }
    });
    ui.on_home_clicked({
        let debounce = debounce.clone();
        move || {
            debounce.stop();
            with_state(|st| {
                st.start_search("");
                st.request_home();
            });
        }
    });
    ui.on_request_more_results(|| {
        with_state(|st| st.more_search());
    });

    // ── tabs ──
    ui.on_tab_changed(|tab| {
        with_state(|st| st.tab_changed(tab));
    });
    ui.on_installed_filter_edited(|text| {
        with_state(|st| st.set_installed_filter(&text));
    });
    ui.on_request_more_installed(|| {
        with_state(|st| st.more_installed());
    });
    ui.on_refresh_updates(|| {
        with_state(|st| st.request_updates());
    });
    ui.on_upgrade_all(|| {
        with_state(|st| st.upgrade_all());
    });

    // ── details ──
    ui.on_app_clicked(|pkg| {
        with_state(|st| st.open_package(convert::from_ui(&pkg), false));
    });
    ui.on_back_clicked(|| {
        with_state(|st| st.back());
    });
    ui.on_install_clicked(|| {
        with_state(|st| st.install_current());
    });
    ui.on_remove_clicked(|flag| {
        with_state(|st| st.remove_current(&flag));
    });
    ui.on_addon_clicked(|name| {
        with_state(|st| st.open_by_name(name.to_string()));
    });
    ui.on_view_all_addons_clicked(|| {
        with_state(|st| st.show_addons());
    });
    ui.on_open_url(|repo, name| {
        links::open(&links::package_url(&repo, &name));
    });

    // ── home banner ──
    ui.on_cover_prev(|| {
        with_state(|st| st.step_cover(false));
    });
    ui.on_cover_next(|| {
        with_state(|st| st.step_cover(true));
    });
    ui.on_cover_clicked(|| {
        with_state(|st| st.open_cover());
    });

    // ── settings ──
    ui.on_theme_changed(|dark| {
        config::save(&Config { dark });
    });
    ui.on_clear_icon_cache(|| {
        with_state(|st| st.clear_icon_cache());
    });

}
