//! `libtux_script.so` — the interactive script engine.
//!
//! Handles: `ScriptStartRequested`, `ScriptAction`.
//! Emits: `ScriptView`, `ScriptOutput`, `ScriptProgress`, `ScriptEnded`.
//!
//! Scripts are JSON files (see `tux_abi::script` and `DOCS/SCRIPTS_SYSTEM.md`).
//! One session runs at a time, on its own thread; the UI only renders the
//! screens the session publishes and reports button clicks.

mod runner;
mod session;

use crossbeam_channel::{unbounded, Sender};
use session::{Input, Session};
use std::sync::atomic::{AtomicBool, Ordering};
use std::sync::{Arc, Mutex};
use std::thread;
use tux_abi::script::load_all;
use tux_abi::sync::lock;
use tux_abi::{Bus, Message, Module};

pub struct ScriptModule {
    bus: Bus,
    busy: Arc<AtomicBool>,
    input: Arc<Mutex<Option<Sender<Input>>>>,
}

impl Module for ScriptModule {
    fn create(bus: Bus) -> Self {
        ScriptModule { bus, busy: Arc::default(), input: Arc::default() }
    }

    fn on_message(&self, msg: Message) {
        match msg {
            Message::ScriptStartRequested { id } => self.start(id),
            Message::ScriptAction { seq, button, selected } => {
                if let Some(tx) = lock(&self.input).as_ref() {
                    let _ = tx.send(Input { seq, button, selected });
                }
            }
            _ => {}
        }
    }
}

impl ScriptModule {
    fn start(&self, id: String) {
        if self.busy.swap(true, Ordering::SeqCst) {
            log::warn!("script {id}: another script is already running");
            return;
        }
        let (bus, busy, input_slot) = (self.bus, self.busy.clone(), self.input.clone());
        let spawned = thread::Builder::new().name(format!("script-{id}")).spawn({
            let id = id.clone();
            move || {
                // Re-read the files on every start: edits apply without a restart.
                let loaded = load_all().into_iter().find(|s| s.script.id == id);
                let (tx, rx) = unbounded();
                *lock(&input_slot) = Some(tx);

                let outcome = match loaded {
                    Some(loaded) => {
                        log::info!("starting script {id} ({})", loaded.path.display());
                        Session::new(bus, loaded, rx).run()
                    }
                    None => {
                        log::warn!("script {id} not found or invalid");
                        Some(false)
                    }
                };
                *lock(&input_slot) = None;
                busy.store(false, Ordering::SeqCst); // before Ended: UI may start the next one
                if let Some(success) = outcome {
                    bus.publish(&Message::ScriptEnded { id, success });
                }
            }
        });
        if let Err(e) = spawned {
            log::error!("cannot start script thread: {e}");
            self.busy.store(false, Ordering::SeqCst);
        }
    }
}

tux_abi::export_module!(ScriptModule, "script");
