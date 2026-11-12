//! Privileged transactions.
//!
//! libalpm must run as root. When the store itself is root we commit in the
//! current process; otherwise we re-execute the host executable through
//! `pkexec` and stream the helper's JSON events back to the UI.

use crate::{forward_helper_line, Emitter, HELPER_FLAG};
use alpm::{Alpm, LogLevel, PackageOperation, Progress, TransFlag};
use std::io::Read;
use std::process::{Command, Stdio};
use std::thread;
use tux_abi::stream::{LineSplitter, Utf8Stream};
use tux_abi::{Operation, RemoveMode};

use super::{answer_question, describe_prepare_error, is_root, open_with};

/// Run a transaction, asking for privileges when necessary.
pub fn run_privileged(op: &Operation, emitter: &Emitter) -> i32 {
    if is_root() {
        return run_root(op, emitter);
    }

    let exe = match std::env::current_exe() {
        Ok(exe) => exe,
        Err(e) => {
            emitter.output(format!("cannot find the tux-store executable: {e}\n"));
            return -1;
        }
    };
    let json = match serde_json::to_string(op) {
        Ok(json) => json,
        Err(e) => {
            emitter.output(format!("cannot encode the transaction: {e}\n"));
            return -1;
        }
    };
    log::info!("starting pkexec {exe:?} {HELPER_FLAG}");

    let mut child = match Command::new("pkexec")
        .arg(&exe)
        .arg(HELPER_FLAG)
        .arg(json)
        .stdin(Stdio::null())
        .stdout(Stdio::piped())
        .stderr(Stdio::piped())
        .spawn()
    {
        Ok(child) => child,
        Err(e) => {
            emitter.output(format!("failed to start pkexec: {e}\n"));
            return -1;
        }
    };

    let out_thread = child.stdout.take().map(|stdout| {
        let emitter = emitter.clone();
        thread::spawn(move || pump_events(stdout, emitter))
    });
    let err_thread = child.stderr.take().map(|stderr| {
        let emitter = emitter.clone();
        thread::spawn(move || pump_text(stderr, emitter))
    });

    let code = child.wait().ok().and_then(|s| s.code()).unwrap_or(-1);
    for handle in [out_thread, err_thread].into_iter().flatten() {
        let _ = handle.join();
    }
    log::info!("helper finished with exit code {code}");
    code
}

/// Run the transaction as root, in this process.
pub fn run_root(op: &Operation, emitter: &Emitter) -> i32 {
    let cfg = super::config::load();
    let mut handle = match open_with(&cfg) {
        Ok(handle) => handle,
        Err(e) => {
            emitter.output(format!("{e}\n"));
            return 1;
        }
    };
    install_callbacks(&handle, emitter);

    match execute(&mut handle, op) {
        Ok(()) => 0,
        Err(e) => {
            emitter.output(format!("{e}\n"));
            let _ = handle.trans_release();
            1
        }
    }
}

fn install_callbacks(handle: &Alpm, emitter: &Emitter) {
    let out = emitter.clone();
    handle.set_log_cb(out, |level, message, out| {
        if !level.intersects(LogLevel::DEBUG | LogLevel::FUNCTION) {
            emit_line(out, message);
        }
    });

    let out = emitter.clone();
    handle.set_event_cb(out, |event, out| {
        if let alpm::Event::PackageOperationStart(operation) = event.event() {
            match operation.operation() {
                PackageOperation::Install(pkg) => {
                    emit_line(out, &format!("installing {}…", pkg.name()))
                }
                PackageOperation::Upgrade(new, old) => emit_line(
                    out,
                    &format!("upgrading {} ({} -> {})…", new.name(), old.version(), new.version()),
                ),
                PackageOperation::Reinstall(new, old) => emit_line(
                    out,
                    &format!("reinstalling {} ({})…", new.name(), old.version()),
                ),
                PackageOperation::Downgrade(new, old) => emit_line(
                    out,
                    &format!(
                        "downgrading {} ({} -> {})…",
                        new.name(),
                        old.version(),
                        new.version()
                    ),
                ),
                PackageOperation::Remove(pkg) => {
                    emit_line(out, &format!("removing {}…", pkg.name()))
                }
            }
        }
    });

    handle.set_progress_cb(emitter.clone(), |progress, _pkg, percent, howmany, current, out| {
        if howmany == 0 {
            return;
        }
        let counts = matches!(
            progress,
            Progress::AddStart
                | Progress::UpgradeStart
                | Progress::DowngradeStart
                | Progress::ReinstallStart
                | Progress::RemoveStart
        );
        if counts {
            let percent = percent.clamp(0, 100) as f64 / 100.0;
            out.progress((current as f64 + percent) / howmany as f64);
        }
    });

    handle.set_question_cb((), |mut question, _| answer_question(&mut question));
}

fn execute(handle: &mut Alpm, op: &Operation) -> Result<(), String> {
    let flags = match op {
        Operation::Remove { mode, .. } => remove_flags(*mode),
        _ => TransFlag::NONE,
    };
    handle
        .trans_init(flags)
        .map_err(|e| format!("cannot start the transaction: {e}"))?;

    match op {
        Operation::Install { name } => {
            let target = handle
                .syncdbs()
                .iter()
                .find_map(|db| db.pkg(name.as_str()).ok())
                .ok_or_else(|| format!("package not found: {name}"))?;
            handle
                .trans_add_pkg(target)
                .map_err(|e| format!("cannot add {name} to the transaction: {e}"))?;
        }
        Operation::Remove { name, .. } => {
            let target = handle
                .localdb()
                .pkg(name.as_str())
                .map_err(|e| format!("package is not installed: {name} ({e})"))?;
            handle
                .trans_remove_pkg(target)
                .map_err(|e| format!("cannot remove {name}: {e}"))?;
        }
        Operation::SystemUpgrade => {
            handle
                .sync_sysupgrade(false)
                .map_err(|e| format!("cannot prepare the system upgrade: {e}"))?;
        }
    }

    if let Err(e) = handle.trans_prepare() {
        return Err(describe_prepare_error(&e));
    }
    if let Err(e) = handle.trans_commit() {
        let mut msg = format!("{}", e.error());
        if let Some(data) = e.data() {
            use alpm::CommitData;
            if let CommitData::PkgInvalid(list) = data {
                for pkg in list.iter() {
                    msg.push_str(&format!("\n  invalid package: {pkg}"));
                }
            }
        }
        return Err(msg);
    }
    let _ = handle.trans_release();
    Ok(())
}

fn remove_flags(mode: RemoveMode) -> TransFlag {
    match mode {
        RemoveMode::Basic => TransFlag::NONE,
        RemoveMode::Reset => TransFlag::NO_SAVE,
        RemoveMode::Clean => TransFlag::RECURSE,
        RemoveMode::Force => TransFlag::NO_DEPS,
        RemoveMode::Complete => TransFlag::RECURSE | TransFlag::NO_SAVE,
    }
}

fn emit_line(emitter: &Emitter, message: &str) {
    if message.ends_with('\n') {
        emitter.output(message.to_string());
    } else {
        emitter.output(format!("{message}\n"));
    }
}

fn pump_events<R: Read>(mut reader: R, emitter: Emitter) {
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
        for line in splitter.push(&text) {
            forward_helper_line(&line, &emitter);
        }
    }
}

fn pump_text<R: Read>(mut reader: R, emitter: Emitter) {
    let mut buf = [0u8; 8192];
    let mut utf8 = Utf8Stream::default();
    loop {
        let n = match reader.read(&mut buf) {
            Ok(0) => break,
            Ok(n) => n,
            Err(e) if e.kind() == std::io::ErrorKind::Interrupted => continue,
            Err(_) => break,
        };
        let text = utf8.push(&buf[..n]);
        if !text.is_empty() {
            emitter.output(text);
        }
    }
}
