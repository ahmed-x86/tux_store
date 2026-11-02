//! `tux-store` — the host executable.
//!
//! It contains no application logic. It discovers `libtux_*.so` modules,
//! gives each one the message bus, then hands the main thread to the module
//! that owns the event loop (the UI). When that returns, everything is shut
//! down in reverse order.

mod hub;
mod loader;

use hub::Hub;
use std::process::ExitCode;
use std::sync::atomic::Ordering;

fn log_level_from_env() -> u32 {
    match std::env::var("TUX_LOG").unwrap_or_default().to_ascii_lowercase().as_str() {
        "off" => 0,
        "error" => 1,
        "warn" => 2,
        "debug" => 4,
        "trace" => 5,
        _ => 3,
    }
}

fn main() -> ExitCode {
    let arg = std::env::args().nth(1).unwrap_or_default();
    if arg == "--version" || arg == "-V" {
        println!("tux-store {}", env!("CARGO_PKG_VERSION"));
        return ExitCode::SUCCESS;
    }
    if arg == "--help" || arg == "-h" {
        println!(
            "tux-store {}\n\nUSAGE:\n  tux-store                   start the store\n  tux-store openpackage NAME  open a package page directly\n\nENVIRONMENT:\n  TUX_LOG=error|warn|info|debug|trace   log level (default info)\n  TUX_MODULE_DIR=DIR                    where to look for libtux_*.so\n  TUX_DATA_DIR=DIR                      where categories.json / images live",
            env!("CARGO_PKG_VERSION")
        );
        return ExitCode::SUCCESS;
    }

    let hub = Hub::leak(log_level_from_env());
    let api = hub.api();

    let Some(dir) = loader::module_dir() else {
        eprintln!("tux-store: no libtux_*.so modules found next to the executable.\nBuild everything with `cargo build --release` (or set TUX_MODULE_DIR).");
        return ExitCode::FAILURE;
    };

    for path in loader::list_modules(&dir) {
        // SAFETY: we only load files named libtux_*.so from the module dir.
        match unsafe { loader::load(&path, &api) } {
            Ok(m) => {
                eprintln!("[host] loaded module '{}' ({})", m.name, path.display());
                hub.add(loader::into_arc(m));
            }
            Err(e) => eprintln!("[host] skipped {}: {e}", path.display()),
        }
    }

    let modules = hub.snapshot();
    let Some(ui) = modules.iter().find(|m| m.main_loop) else {
        eprintln!("tux-store: no UI module (libtux_ui.so) with a main loop was loaded.");
        hub.shutdown();
        return ExitCode::FAILURE;
    };

    // Blocks until the window is closed.
    // SAFETY: `inst` is the live instance created by this very module.
    unsafe { (ui.run)(ui.inst) };

    ui.alive.store(false, Ordering::Release);
    hub.shutdown();
    ExitCode::SUCCESS
}
