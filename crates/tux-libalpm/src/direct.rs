//! The original backend: every operation is a `pacman` process.
//!
//! This is the code that used to live in `tux-install`; it moved here so the
//! engine selection can switch between it and [`crate::libalpm`] without the
//! install module knowing anything about the difference.

use crate::Emitter;
use std::collections::HashMap;
use std::io::Read;
use std::process::{Command, Stdio};
use std::sync::{Arc, Mutex};
use std::thread;
use tux_abi::stream::{LineSplitter, Utf8Stream};
use tux_abi::sync::lock;
use tux_abi::text::shell_quote;
use tux_abi::{Operation, Package};
use tux_pacman::progress::{Kind, ProgressTracker};

pub fn search(query: &str, limit: usize) -> Vec<Package> {
    tux_pacman::queries::search(query, limit)
}

fn is_root() -> bool {
    // SAFETY: geteuid has no preconditions and cannot fail.
    unsafe { libc::geteuid() == 0 }
}

fn pacman_args(op: &Operation) -> (Kind, Vec<String>) {
    let mut args: Vec<String> = ["env", "LC_ALL=C", "pacman"].map(String::from).to_vec();
    let kind = match op {
        Operation::Install { name } => {
            args.extend(["-S", "--noconfirm", "--color=never", "--"].map(String::from));
            args.push(name.clone());
            Kind::Install
        }
        Operation::Remove { name, mode } => {
            args.extend([mode.flag(), "--noconfirm", "--color=never", "--"].map(String::from));
            args.push(name.clone());
            Kind::Remove
        }
        Operation::SystemUpgrade => {
            args.extend(["-Syu", "--noconfirm", "--color=never"].map(String::from));
            Kind::Upgrade
        }
    };
    (kind, args)
}

/// Returns the process exit code (`-1` if it could not even be started).
pub fn run_transaction(op: &Operation, weights: &HashMap<String, u64>, emitter: &Emitter) -> i32 {
    let (kind, args) = pacman_args(op);
    let inner = args.iter().map(|a| shell_quote(a)).collect::<Vec<_>>().join(" ");

    let (program, argv): (&str, Vec<String>) = if is_root() {
        ("script", vec!["-qec".into(), inner, "/dev/null".into()])
    } else {
        ("pkexec", vec!["script".into(), "-qec".into(), inner, "/dev/null".into()])
    };
    log::info!("starting {program} {argv:?}");

    // stdin stays open (never written): `script` would otherwise see EOF and
    // may tear the pty down before pacman is finished.
    let mut child = match Command::new(program)
        .args(&argv)
        .stdin(Stdio::piped())
        .stdout(Stdio::piped())
        .stderr(Stdio::piped())
        .spawn()
    {
        Ok(c) => c,
        Err(e) => {
            emitter.output(format!("failed to start {program}: {e}\n"));
            return -1;
        }
    };
    let _stdin_guard = child.stdin.take();

    let tracker = Arc::new(Mutex::new(ProgressTracker::new(kind, weights.clone())));
    let out_thread = child.stdout.take().map(|s| {
        let (emitter, tracker) = (emitter.clone(), tracker.clone());
        thread::spawn(move || pump(s, emitter, Some(tracker)))
    });
    let err_thread = child.stderr.take().map(|s| {
        let emitter = emitter.clone();
        thread::spawn(move || pump(s, emitter, None))
    });

    let code = child.wait().ok().and_then(|s| s.code()).unwrap_or(-1);
    for h in [out_thread, err_thread].into_iter().flatten() {
        let _ = h.join();
    }
    log::info!("transaction finished with exit code {code}");
    code
}

/// Forward everything `reader` produces and (for stdout) feed the progress
/// tracker line by line.
fn pump<R: Read>(mut reader: R, emitter: Emitter, tracker: Option<Arc<Mutex<ProgressTracker>>>) {
    let mut buf = [0u8; 8192];
    let mut utf8 = Utf8Stream::default();
    let mut splitter = LineSplitter::default();
    loop {
        let n = match reader.read(&mut buf) {
            Ok(0) => break,
            Ok(n) => n,
            Err(e) if e.kind() == std::io::ErrorKind::Interrupted => continue,
            Err(_) => break,
        };
        let text = utf8.push(&buf[..n]);
        if text.is_empty() {
            continue;
        }
        if let Some(tracker) = &tracker {
            for line in splitter.push(&text) {
                let fraction = lock(tracker).feed_line(&line);
                if let Some(fraction) = fraction {
                    emitter.progress(fraction);
                }
            }
        }
        emitter.output(text);
    }
}
