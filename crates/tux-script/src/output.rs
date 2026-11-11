//! Where a running script's text goes: the console ("Show details") and the
//! log file, always together.
//!
//! One `Output` is shared (in an `Arc`) by the session thread and the threads
//! that read the commands' output, so the two destinations can never differ.

use crate::logfile::LogFile;
use std::path::PathBuf;
use std::sync::Mutex;
use tux_abi::sync::lock;
use tux_abi::{Bus, Message};

pub struct Output {
    bus: Bus,
    log: Mutex<LogFile>,
}

impl Output {
    pub fn new(bus: Bus, log: LogFile) -> Self {
        Output { bus, log: Mutex::new(log) }
    }

    /// Text for the console **and** the log. The first call creates the log file.
    pub fn text(&self, s: &str) {
        if s.is_empty() {
            return;
        }
        self.bus.publish(&Message::ScriptOutput { text: s.to_string() });
        lock(&self.log).output(s);
    }

    /// Text for the console only.
    pub fn console(&self, s: &str) {
        self.bus.publish(&Message::ScriptOutput { text: s.to_string() });
    }

    /// One line for the log only (a choice that was made, a check that failed…).
    /// Kept until the log file exists, so the log starts with the story so far.
    pub fn note(&self, line: &str) {
        lock(&self.log).note(line);
    }

    /// Make sure the log file exists now (something worth keeping happened).
    pub fn ensure_log(&self) {
        lock(&self.log).create();
    }

    /// Where the log is, once it exists.
    pub fn log_path(&self) -> Option<PathBuf> {
        lock(&self.log).path().map(PathBuf::from)
    }

    /// Write the footer and close the file; returns its path (if any).
    pub fn finish(&self, footer: &str) -> Option<PathBuf> {
        lock(&self.log).finish(footer)
    }
}
