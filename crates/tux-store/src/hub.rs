//! The message hub: owns the loaded modules and fans every published message
//! out to all of them.

use std::ffi::c_void;
use std::panic::{catch_unwind, AssertUnwindSafe};
use std::sync::atomic::{AtomicBool, Ordering};
use std::sync::{Arc, RwLock};
use std::time::Instant;
use tux_abi::logging::level_name;
use tux_abi::HostApi;

pub struct LoadedModule {
    pub name: String,
    pub main_loop: bool,
    pub inst: *mut c_void,
    pub message: unsafe extern "C" fn(*mut c_void, *const u8, usize),
    pub run: unsafe extern "C" fn(*mut c_void),
    pub destroy: unsafe extern "C" fn(*mut c_void),
    /// Cleared before shutdown so no message reaches a dying module.
    pub alive: AtomicBool,
}

// SAFETY: `inst` is only ever used through the module's own thread-safe
// entry points (`Module: Send + Sync`).
unsafe impl Send for LoadedModule {}
unsafe impl Sync for LoadedModule {}

pub struct Hub {
    modules: RwLock<Vec<Arc<LoadedModule>>>,
    started: Instant,
    pub log_level: u32,
}

impl Hub {
    /// Leaked on purpose: the C callbacks hold a raw pointer to it for the
    /// whole life of the process.
    pub fn leak(log_level: u32) -> &'static Hub {
        Box::leak(Box::new(Hub {
            modules: RwLock::new(Vec::new()),
            started: Instant::now(),
            log_level,
        }))
    }

    pub fn api(&'static self) -> HostApi {
        HostApi {
            abi_version: tux_abi::ABI_VERSION,
            log_level: self.log_level,
            ctx: self as *const Hub as *mut c_void,
            publish: publish_cb,
            log: log_cb,
        }
    }

    pub fn add(&self, m: Arc<LoadedModule>) {
        self.modules.write().unwrap_or_else(|e| e.into_inner()).push(m);
    }

    pub fn snapshot(&self) -> Vec<Arc<LoadedModule>> {
        self.modules.read().unwrap_or_else(|e| e.into_inner()).clone()
    }

    fn dispatch(&self, bytes: &[u8]) {
        // Clone the list so the lock is not held while modules run (they may
        // publish again from inside their handler).
        for m in self.snapshot() {
            if !m.alive.load(Ordering::Acquire) {
                continue;
            }
            // SAFETY: `inst` is valid while `alive`; bytes outlive the call.
            let r = catch_unwind(AssertUnwindSafe(|| unsafe {
                (m.message)(m.inst, bytes.as_ptr(), bytes.len())
            }));
            if r.is_err() {
                eprintln!("[host] module '{}' panicked while handling a message", m.name);
            }
        }
    }

    pub fn shutdown(&self) {
        let mods = self.snapshot();
        for m in &mods {
            m.alive.store(false, Ordering::Release);
        }
        for m in mods.iter().rev() {
            // SAFETY: called once per module, after delivery was stopped.
            unsafe { (m.destroy)(m.inst) };
        }
    }
}

unsafe extern "C" fn publish_cb(ctx: *mut c_void, data: *const u8, len: usize) {
    if ctx.is_null() || data.is_null() {
        return;
    }
    let hub = &*(ctx as *const Hub);
    hub.dispatch(std::slice::from_raw_parts(data, len));
}

unsafe extern "C" fn log_cb(
    ctx: *mut c_void,
    level: u32,
    target: *const u8,
    target_len: usize,
    msg: *const u8,
    msg_len: usize,
) {
    if ctx.is_null() || target.is_null() || msg.is_null() {
        return;
    }
    let hub = &*(ctx as *const Hub);
    let target = String::from_utf8_lossy(std::slice::from_raw_parts(target, target_len));
    let msg = String::from_utf8_lossy(std::slice::from_raw_parts(msg, msg_len));
    eprintln!(
        "[{:8.3}s] {:<5} {:<22} {}",
        hub.started.elapsed().as_secs_f64(),
        level_name(level),
        target,
        msg
    );
}
