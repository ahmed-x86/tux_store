//! The C ABI between the host executable and the module libraries, plus the
//! safe Rust layer on top of it.
//!
//! ```text
//!   host (tux-store)                       module (libtux_xxx.so)
//!   ────────────────                       ──────────────────────
//!   dlopen ───────────────────────────────▶ tux_module_abi_version()
//!   tux_module_create(&HostApi) ──────────▶ Module::create(Bus)
//!   tux_module_message(inst, json) ───────▶ Module::on_message(Message)
//!   HostApi.publish(ctx, json)  ◀───────── Bus::publish(&Message)
//!   tux_module_run(inst)  (main thread) ──▶ Module::run()      (UI only)
//!   tux_module_destroy(inst) ─────────────▶ Module::shutdown() + drop
//! ```

use crate::message::Message;
use std::ffi::c_void;
use std::panic::{catch_unwind, AssertUnwindSafe};

/// Bump when the C ABI below changes incompatibly.
pub const ABI_VERSION: u32 = 1;

/// Function table the host hands to every module.
#[repr(C)]
#[derive(Clone, Copy)]
pub struct HostApi {
    pub abi_version: u32,
    /// Max log level: 0 off, 1 error … 5 trace.
    pub log_level: u32,
    /// Opaque host context, passed back verbatim to the callbacks.
    pub ctx: *mut c_void,
    /// Deliver a JSON-encoded [`Message`] to every module. Thread-safe.
    pub publish: unsafe extern "C" fn(ctx: *mut c_void, data: *const u8, len: usize),
    /// Print one log record.
    pub log: unsafe extern "C" fn(
        ctx: *mut c_void,
        level: u32,
        target: *const u8,
        target_len: usize,
        msg: *const u8,
        msg_len: usize,
    ),
}

/// Run `f`; if it panics, log nothing more (the panic hook already printed)
/// and return `default`. Panics must never unwind across the C boundary.
pub fn ffi_guard<R>(default: R, f: impl FnOnce() -> R) -> R {
    catch_unwind(AssertUnwindSafe(f)).unwrap_or(default)
}

/// Cheap, copyable, thread-safe handle for publishing messages.
#[derive(Clone, Copy)]
pub struct Bus {
    api: HostApi,
}

// SAFETY: the host guarantees `publish` is callable from any thread and that
// `ctx` stays valid until the process exits.
unsafe impl Send for Bus {}
unsafe impl Sync for Bus {}

impl Bus {
    pub fn new(api: HostApi) -> Self {
        Self { api }
    }

    /// Deliver `msg` to every module (including the caller). Delivery is
    /// synchronous, so handlers must return quickly — hand real work to a
    /// thread of your own.
    pub fn publish(&self, msg: &Message) {
        match msg.encode() {
            // SAFETY: buffer is valid for the call; host copies what it keeps.
            Ok(buf) => unsafe { (self.api.publish)(self.api.ctx, buf.as_ptr(), buf.len()) },
            Err(e) => log::error!("cannot encode message: {e}"),
        }
    }
}

/// What a module implements. Wire it up with [`export_module!`].
pub trait Module: Send + Sync + Sized + 'static {
    /// Called once, on the host's main thread.
    fn create(bus: Bus) -> Self;

    /// Called for every message on the bus, from arbitrary threads. Must not
    /// block; ignore anything you do not care about.
    fn on_message(&self, msg: Message);

    /// Only for the module that owns the main loop (the UI). Called on the
    /// main thread and expected to block until the application should exit.
    fn run(&self) {}

    /// Called once before the module is dropped.
    fn shutdown(&self) {}
}

/// Generate the `extern "C"` entry points of a module library.
///
/// ```ignore
/// tux_abi::export_module!(SearchModule, "search");
/// tux_abi::export_module!(UiModule, "ui", true); // owns the main loop
/// ```
/// Invoke it at the crate root (`lib.rs`) of a `cdylib`.
#[macro_export]
macro_rules! export_module {
    ($ty:ty, $name:literal) => {
        $crate::export_module!($ty, $name, false);
    };
    ($ty:ty, $name:literal, $main_loop:expr) => {
        #[no_mangle]
        pub extern "C" fn tux_module_abi_version() -> u32 {
            $crate::ABI_VERSION
        }

        #[no_mangle]
        pub extern "C" fn tux_module_name() -> *const ::std::os::raw::c_char {
            concat!($name, "\0").as_ptr() as *const ::std::os::raw::c_char
        }

        #[no_mangle]
        pub extern "C" fn tux_module_main_loop() -> u32 {
            if $main_loop {
                1
            } else {
                0
            }
        }

        #[no_mangle]
        pub unsafe extern "C" fn tux_module_create(
            host: *const $crate::HostApi,
        ) -> *mut ::std::ffi::c_void {
            $crate::ffi_guard(::std::ptr::null_mut(), || {
                if host.is_null() {
                    return ::std::ptr::null_mut();
                }
                let api = *host;
                $crate::logging::install(api);
                let module: $ty = <$ty as $crate::Module>::create($crate::Bus::new(api));
                Box::into_raw(Box::new(module)) as *mut ::std::ffi::c_void
            })
        }

        #[no_mangle]
        pub unsafe extern "C" fn tux_module_message(
            inst: *mut ::std::ffi::c_void,
            data: *const u8,
            len: usize,
        ) {
            if inst.is_null() || data.is_null() {
                return;
            }
            let module = &*(inst as *const $ty);
            let bytes = ::std::slice::from_raw_parts(data, len);
            $crate::ffi_guard((), || match $crate::Message::decode(bytes) {
                Ok(msg) => <$ty as $crate::Module>::on_message(module, msg),
                Err(e) => $crate::log::debug!("ignoring undecodable message: {e}"),
            });
        }

        #[no_mangle]
        pub unsafe extern "C" fn tux_module_run(inst: *mut ::std::ffi::c_void) {
            if inst.is_null() {
                return;
            }
            let module = &*(inst as *const $ty);
            $crate::ffi_guard((), || <$ty as $crate::Module>::run(module));
        }

        #[no_mangle]
        pub unsafe extern "C" fn tux_module_destroy(inst: *mut ::std::ffi::c_void) {
            if inst.is_null() {
                return;
            }
            let module = Box::from_raw(inst as *mut $ty);
            $crate::ffi_guard((), || {
                <$ty as $crate::Module>::shutdown(&module);
            });
            $crate::ffi_guard((), || drop(module));
        }
    };
}
