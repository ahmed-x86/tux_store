//! `libtux_ui.so` — the Slint front-end.
//!
//! Owns the application's main loop (`Module::run`). It never touches pacman
//! or the network: every request is a bus message, every result arrives as one
//! (see [`state::State::handle`]).

slint::include_modules!();

mod app;
mod config;
mod console;
mod convert;
mod links;
mod state;

use tux_abi::{Bus, Message, Module};

pub struct UiModule {
    bus: Bus,
}

impl Module for UiModule {
    fn create(bus: Bus) -> Self {
        UiModule { bus }
    }

    /// Called from any thread: just hop onto the UI thread.
    fn on_message(&self, msg: Message) {
        state::dispatch(msg);
    }

    fn run(&self) {
        if let Err(e) = app::run(self.bus) {
            log::error!("UI terminated with an error: {e}");
        }
    }
}

tux_abi::export_module!(UiModule, "ui", true);
