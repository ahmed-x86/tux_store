//! # libtux_libalpm — the package engine
//!
//! Tux Store started life by spawning `pacman` for every question and every
//! transaction. That backend still exists (and is still the default), but this
//! crate adds a second one that talks to **libalpm** directly.
//!
//! * [`Engine::Direct`] — the historical backend, moved here from
//!   `tux-install`/`tux-pacman` so both engines share one entry point.
//! * [`Engine::Libalpm`] — in-process libalpm for search / details / plans /
//!   installed / updates, and a small privileged helper for transactions
//!   (libalpm needs root, so the helper is launched through `pkexec`).
//!
//! The UI publishes [`tux_abi::Message::EngineChanged`] when the setting
//! changes; every module keeps its own copy of `ACTIVE` because the host
//! broadcasts the message to all loaded `.so` files.
//!
//! The crate builds both an `rlib` (linked into the host and the modules) and
//! a `cdylib`, so the build tree contains `libtux_libalpm.so` just like the
//! other libraries.

pub mod direct;
pub mod libalpm;

use serde::{Deserialize, Serialize};
use std::collections::HashMap;
use std::sync::atomic::{AtomicU8, Ordering};
use std::sync::Arc;
use tux_abi::{Engine, Operation, Package, PackageDetails, UpdateEntry};

static ACTIVE: AtomicU8 = AtomicU8::new(Engine::Direct as u8);

/// Remember which engine this module should use. Called from `on_message`.
pub fn set_active(engine: Engine) {
    ACTIVE.store(engine as u8, Ordering::SeqCst);
}

pub fn active() -> Engine {
    if ACTIVE.load(Ordering::SeqCst) == Engine::Libalpm as u8 {
        Engine::Libalpm
    } else {
        Engine::Direct
    }
}

/// One thing a running transaction wants to tell the UI.
#[derive(Debug, Clone)]
pub enum TxEvent {
    Output(String),
    Progress(f64),
}

/// Thread-safe sink used by both engines.
///
/// It is deliberately tiny: the direct backend's reader threads and libalpm's
/// C callbacks can call it from anywhere without borrowing the module state.
#[derive(Clone)]
pub struct Emitter(Arc<dyn Fn(TxEvent) + Send + Sync>);

impl Emitter {
    pub fn new(f: impl Fn(TxEvent) + Send + Sync + 'static) -> Self {
        Self(Arc::new(f))
    }

    pub fn output(&self, text: impl Into<String>) {
        (self.0)(TxEvent::Output(text.into()));
    }

    pub fn progress(&self, fraction: f64) {
        (self.0)(TxEvent::Progress(fraction.clamp(0.0, 1.0)));
    }
}

// ───────────────────────────── queries ─────────────────────────────

/// Search the sync databases. Blocking; run it on a worker thread.
pub fn search(query: &str, limit: usize) -> Vec<Package> {
    match active() {
        Engine::Direct => direct::search(query, limit),
        Engine::Libalpm => libalpm::search(query, limit),
    }
}

/// One entry per requested name, in the same order.
pub fn packages_by_name(names: &[String]) -> Vec<Package> {
    match active() {
        Engine::Direct => tux_pacman::queries::packages_by_name(names),
        Engine::Libalpm => libalpm::packages_by_name(names),
    }
}

pub fn exact(name: &str) -> Package {
    match active() {
        Engine::Direct => tux_pacman::queries::exact(name),
        Engine::Libalpm => libalpm::exact(name),
    }
}

/// The dependency plan of installing `name`.
pub fn details(name: &str) -> PackageDetails {
    match active() {
        Engine::Direct => tux_pacman::queries::details(name),
        Engine::Libalpm => libalpm::details(name),
    }
}

pub fn installed_packages() -> Vec<Package> {
    match active() {
        Engine::Direct => tux_pacman::queries::installed_packages(),
        Engine::Libalpm => libalpm::installed_packages(),
    }
}

pub fn updates() -> Result<Vec<UpdateEntry>, String> {
    match active() {
        Engine::Direct => tux_pacman::queries::updates(),
        Engine::Libalpm => libalpm::updates(),
    }
}

// ───────────────────────────── transactions ─────────────────────────────

/// Run a privileged transaction with the selected engine. Returns the exit
/// code (`-1` when it could not even start).
pub fn run_transaction(op: &Operation, weights: &HashMap<String, u64>, emitter: &Emitter) -> i32 {
    match active() {
        Engine::Direct => direct::run_transaction(op, weights, emitter),
        Engine::Libalpm => libalpm::run_privileged(op, emitter),
    }
}

// ───────────────────────────── privileged helper ─────────────────────────────

/// The host executable re-executes itself under `pkexec` with this flag. The
/// child runs libalpm as root and prints one JSON event per line, which the
/// parent turns back into [`TxEvent`]s.
pub const HELPER_FLAG: &str = "--engine-transaction";

#[derive(Debug, Serialize, Deserialize)]
#[serde(tag = "t", rename_all = "lowercase")]
enum HelperEvent {
    Output { s: String },
    Progress { f: f64 },
}

/// Entry point for `tux-store --engine-transaction '<json>'`.
pub fn run_helper(json: &str) -> i32 {
    let op: Operation = match serde_json::from_str(json) {
        Ok(op) => op,
        Err(e) => {
            eprintln!("tux-store: bad engine transaction: {e}");
            return 2;
        }
    };
    let emitter = Emitter::new(|event| {
        let line = match event {
            TxEvent::Output(s) => HelperEvent::Output { s },
            TxEvent::Progress(f) => HelperEvent::Progress { f },
        };
        if let Ok(text) = serde_json::to_string(&line) {
            // One event per line; stdout is a pipe, so flush explicitly.
            use std::io::Write;
            let mut out = std::io::stdout().lock();
            let _ = writeln!(out, "{text}");
            let _ = out.flush();
        }
    });
    libalpm::run_root(&op, &emitter)
}

/// Parse one line printed by the helper and forward it to `emitter`.
pub(crate) fn forward_helper_line(line: &str, emitter: &Emitter) {
    let line = line.trim();
    if line.is_empty() {
        return;
    }
    match serde_json::from_str::<HelperEvent>(line) {
        Ok(HelperEvent::Output { s }) => emitter.output(s),
        Ok(HelperEvent::Progress { f }) => emitter.progress(f),
        // Something that is not ours (a panic message, a stray line): show it.
        Err(_) => emitter.output(format!("{line}\n")),
    }
}
