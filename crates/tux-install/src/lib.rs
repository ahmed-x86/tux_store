//! `libtux_install.so` — runs pacman transactions as root and reports them.
//!
//! Handles: `InstallRequested`, `RemoveRequested`, `SystemUpgradeRequested`.
//! Emits: `OperationStarted/Output/Progress/Finished`.
//!
//! It also *overhears* `DetailsReady` on the bus to learn the size of every
//! package in the plan, which is what weights the progress bar — the UI never
//! has to pass that information along.
//!
//! pacman is run under `script`, which gives it a pseudo-terminal. Without a
//! tty glibc block-buffers stdout and the output would only arrive at the very
//! end. Privileges come from `pkexec` (polkit) unless we already are root.

mod stream;

use std::collections::HashMap;
use std::io::Read;
use std::process::{Command, Stdio};
use std::sync::atomic::{AtomicBool, Ordering};
use std::sync::{Arc, Mutex};
use std::thread;
use stream::{LineSplitter, Utf8Stream};
use tux_abi::sync::lock;
use tux_abi::text::is_valid_package_name;
use tux_abi::{Bus, Message, Module, Operation};
use tux_pacman::progress::{Kind, ProgressTracker};

type Weights = HashMap<String, u64>;
const PLAN_CACHE_MAX: usize = 16;

pub struct InstallModule {
    bus: Bus,
    busy: Arc<AtomicBool>,
    plans: Arc<Mutex<HashMap<String, Weights>>>,
}

impl Module for InstallModule {
    fn create(bus: Bus) -> Self {
        InstallModule { bus, busy: Arc::default(), plans: Arc::default() }
    }

    fn on_message(&self, msg: Message) {
        match msg {
            Message::DetailsReady { name, details, .. } => {
                let mut weights: Weights = details
                    .dependencies
                    .iter()
                    .filter(|d| !d.installed)
                    .map(|d| (d.name.clone(), d.size_bytes))
                    .collect();
                weights.insert(name.clone(), details.app_size);
                let mut plans = lock(&self.plans);
                if plans.len() >= PLAN_CACHE_MAX {
                    plans.clear();
                }
                plans.insert(name, weights);
            }
            Message::InstallRequested { name } => self.start(Operation::Install { name }),
            Message::RemoveRequested { name, mode } => {
                self.start(Operation::Remove { name, mode })
            }
            Message::SystemUpgradeRequested => self.start(Operation::SystemUpgrade),
            Message::ClearIconCache => lock(&self.plans).clear(),
            _ => {}
        }
    }
}

impl InstallModule {
    fn start(&self, op: Operation) {
        let bus = self.bus;

        let valid = match &op {
            Operation::Install { name } | Operation::Remove { name, .. } => is_valid_package_name(name),
            Operation::SystemUpgrade => true,
        };
        if !valid {
            reject(&bus, op, "invalid package name");
            return;
        }
        if self.busy.swap(true, Ordering::SeqCst) {
            reject(&bus, op, "another operation is already running");
            return;
        }

        let weights = match &op {
            Operation::Install { name } => lock(&self.plans).get(name).cloned().unwrap_or_default(),
            _ => Weights::new(),
        };
        let busy = self.busy.clone();
        thread::spawn(move || {
            bus.publish(&Message::OperationStarted { op: op.clone() });
            let code = run_transaction(&bus, &op, weights);
            let success = code == 0;
            busy.store(false, Ordering::SeqCst); // before Finished: UI may start the next one
            if success {
                bus.publish(&Message::OperationProgress { fraction: 1.0 });
            }
            bus.publish(&Message::OperationFinished { op, success, exit_code: code });
        });
    }
}

fn reject(bus: &Bus, op: Operation, why: &str) {
    bus.publish(&Message::OperationOutput { text: format!("{why}\n") });
    bus.publish(&Message::OperationFinished { op, success: false, exit_code: -1 });
}

fn shell_quote(s: &str) -> String {
    format!("'{}'", s.replace('\'', "'\\''"))
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
fn run_transaction(bus: &Bus, op: &Operation, weights: Weights) -> i32 {
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
            bus.publish(&Message::OperationOutput { text: format!("failed to start {program}: {e}\n") });
            return -1;
        }
    };
    let _stdin_guard = child.stdin.take();

    let tracker = Arc::new(Mutex::new(ProgressTracker::new(kind, weights)));
    let out_thread = child.stdout.take().map(|s| {
        let (bus, tracker) = (*bus, tracker.clone());
        thread::spawn(move || pump(s, bus, Some(tracker)))
    });
    let err_thread = child.stderr.take().map(|s| {
        let bus = *bus;
        thread::spawn(move || pump(s, bus, None))
    });

    let code = child.wait().ok().and_then(|s| s.code()).unwrap_or(-1);
    for h in [out_thread, err_thread].into_iter().flatten() {
        let _ = h.join();
    }
    log::info!("transaction finished with exit code {code}");
    code
}

/// Forward everything `reader` produces to the bus and (for stdout) feed the
/// progress tracker line by line.
fn pump<R: Read>(mut reader: R, bus: Bus, tracker: Option<Arc<Mutex<ProgressTracker>>>) {
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
                    bus.publish(&Message::OperationProgress { fraction });
                }
            }
        }
        bus.publish(&Message::OperationOutput { text });
    }
}

tux_abi::export_module!(InstallModule, "install");
