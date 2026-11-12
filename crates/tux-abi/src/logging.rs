//! One log sink for the whole process.
//!
//! Each `.so` has its own copy of the `log` crate's global state, so a plain
//! logger in the host would never see the modules' records. Each module
//! therefore installs [`HostLogger`], which forwards every record through the
//! host's C callback. The host prints them uniformly and owns the level filter
//! (`TUX_LOG=debug`).

use crate::module::HostApi;
use log::{LevelFilter, Log, Metadata, Record};
use std::sync::OnceLock;

struct HostLogger {
    api: HostApi,
}

// SAFETY: `HostApi` is plain data (function pointers + an opaque context
// pointer that the host keeps alive for the whole process).
unsafe impl Send for HostLogger {}
unsafe impl Sync for HostLogger {}

impl Log for HostLogger {
    fn enabled(&self, metadata: &Metadata) -> bool {
        metadata.level() <= log::max_level()
    }

    fn log(&self, record: &Record) {
        if !self.enabled(record.metadata()) {
            return;
        }
        let msg = record.args().to_string();
        let target = record.target();
        // SAFETY: both buffers outlive the call.
        unsafe {
            (self.api.log)(
                self.api.ctx,
                record.level() as usize as u32,
                target.as_ptr(),
                target.len(),
                msg.as_ptr(),
                msg.len(),
            );
        }
    }

    fn flush(&self) {}
}

static LOGGER: OnceLock<HostLogger> = OnceLock::new();

/// Route this module's `log` records to the host.
pub fn install(api: HostApi) {
    let logger = LOGGER.get_or_init(|| HostLogger { api });
    if log::set_logger(logger).is_ok() {
        log::set_max_level(filter_from_u32(api.log_level));
    }
}

/// `0..=5` → `Off..=Trace` (same numbering as `log::Level as usize`).
pub fn filter_from_u32(n: u32) -> LevelFilter {
    match n {
        0 => LevelFilter::Off,
        1 => LevelFilter::Error,
        2 => LevelFilter::Warn,
        3 => LevelFilter::Info,
        4 => LevelFilter::Debug,
        _ => LevelFilter::Trace,
    }
}

pub fn level_name(n: u32) -> &'static str {
    match n {
        1 => "ERROR",
        2 => "WARN",
        3 => "INFO",
        4 => "DEBUG",
        _ => "TRACE",
    }
}
