//! `libtux_install.so` — runs package transactions as root and reports them.
//!
//! Handles: `InstallRequested`, `RemoveRequested`, `SystemUpgradeRequested`,
//! `EngineChanged`. Emits: `OperationStarted/Output/Progress/Finished`.
//!
//! The actual work is delegated to `libtux_libalpm` (the selected engine): either
//! direct `pacman` processes or libalpm through a privileged helper. This
//! module only owns the UI-facing side — the busy flag, the weights learned
//! from `DetailsReady`, and the `Operation*` messages.
//!
//! It also *overhears* `DetailsReady` on the bus to learn the size of every
//! package in the plan, which is what weights the progress bar — the UI never
//! has to pass that information along.

use std::collections::HashMap;
use std::sync::atomic::{AtomicBool, Ordering};
use std::sync::{Arc, Mutex};
use std::thread;
use tux_abi::sync::lock;
use tux_abi::text::is_valid_package_name;
use tux_abi::{Bus, Message, Module, Operation};
use tux_libalpm::{Emitter, TxEvent};

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
            Message::EngineChanged { engine } => {
                tux_libalpm::set_active(engine);
                lock(&self.plans).clear();
            }
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
            let emitter = Emitter::new(move |event| match event {
                TxEvent::Output(text) => bus.publish(&Message::OperationOutput { text }),
                TxEvent::Progress(fraction) => {
                    bus.publish(&Message::OperationProgress { fraction })
                }
            });
            let code = tux_libalpm::run_transaction(&op, &weights, &emitter);
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

tux_abi::export_module!(InstallModule, "install");
