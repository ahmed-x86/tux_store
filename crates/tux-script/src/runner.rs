//! Process execution for scripts.
//!
//! Two flavours:
//! * [`run_check`] — silent, no terminal, bounded time, stdout captured. Never
//!   privileged (the format forbids `root` on checks).
//! * [`run_visible`] — runs under `script` (a pseudo-terminal, so tools such as
//!   pacman and yay flush their output live) and streams everything to the bus.
//!   Privileged commands go through `pkexec`, exactly like the installer.
//!
//! Variables reach the command as environment variables
//! (`TUX_VAR_<NAME>`), never by pasting text into a shell line, so a value can
//! not change the structure of a command.

use std::io::Read;
use std::os::unix::process::CommandExt;
use std::process::{Command, Stdio};
use std::thread;
use std::time::{Duration, Instant};
use tux_abi::script::{interpolate, CommandSpec, Vars};
use tux_abi::stream::Utf8Stream;
use tux_abi::text::shell_quote;
use tux_abi::{Bus, Message};

pub const DEFAULT_CHECK_TIMEOUT: Duration = Duration::from_secs(20);
const CAPTURE_LIMIT: usize = 64 * 1024;
/// Variables bigger than this are not exported (argument-size limits).
const MAX_EXPORTED_VAR: usize = 8 * 1024;

pub struct Outcome {
    /// Exit code; `-1` when the process could not start or was killed.
    pub code: i32,
    pub stdout: String,
    pub timed_out: bool,
}

pub fn is_root() -> bool {
    // SAFETY: geteuid has no preconditions and cannot fail.
    unsafe { libc::geteuid() == 0 }
}

/// `env LC_ALL=C TUX_VAR_X=… [spec.env…] <program…>` as an argv vector.
pub fn build_inner(spec: &CommandSpec, vars: &Vars) -> Vec<String> {
    let mut v: Vec<String> = vec!["env".into(), "LC_ALL=C".into()];
    for (k, val) in vars {
        if val.len() <= MAX_EXPORTED_VAR {
            v.push(format!("TUX_VAR_{}={val}", k.to_ascii_uppercase()));
        }
    }
    for (k, val) in &spec.env {
        v.push(format!("{k}={}", interpolate(val, vars)));
    }
    match (&spec.shell, &spec.argv) {
        (Some(text), _) => {
            v.extend(["sh".to_string(), "-c".to_string(), text.joined()]);
        }
        (None, Some(argv)) => v.extend(argv.iter().map(|a| interpolate(a, vars))),
        (None, None) => {}
    }
    v
}

fn read_capped<R: Read>(mut r: R) -> Vec<u8> {
    let mut kept = Vec::new();
    let mut buf = [0u8; 4096];
    loop {
        match r.read(&mut buf) {
            Ok(0) | Err(_) => break,
            Ok(n) => {
                // keep draining so the child never blocks on a full pipe
                let room = CAPTURE_LIMIT.saturating_sub(kept.len());
                kept.extend_from_slice(&buf[..n.min(room)]);
            }
        }
    }
    kept
}

fn kill_group(pid: u32) {
    // SAFETY: plain syscall on a process group we created with process_group(0).
    unsafe {
        libc::killpg(pid as libc::pid_t, libc::SIGKILL);
    }
}

pub fn run_check(spec: &CommandSpec, vars: &Vars) -> Outcome {
    let argv = build_inner(spec, vars);
    let timeout = spec.timeout_secs.map(Duration::from_secs).unwrap_or(DEFAULT_CHECK_TIMEOUT);
    let mut child = match Command::new(&argv[0])
        .args(&argv[1..])
        .stdin(Stdio::null())
        .stdout(Stdio::piped())
        .stderr(Stdio::piped())
        .process_group(0)
        .spawn()
    {
        Ok(c) => c,
        Err(e) => return Outcome { code: -1, stdout: format!("cannot start {}: {e}", argv[0]), timed_out: false },
    };
    let out = child.stdout.take().map(|s| thread::spawn(move || read_capped(s)));
    let err = child.stderr.take().map(|s| thread::spawn(move || read_capped(s)));

    let started = Instant::now();
    let mut timed_out = false;
    let code = loop {
        match child.try_wait() {
            Ok(Some(status)) => break status.code().unwrap_or(-1),
            Ok(None) if started.elapsed() >= timeout => {
                timed_out = true;
                kill_group(child.id());
                let _ = child.kill();
                let _ = child.wait();
                break -1;
            }
            Ok(None) => thread::sleep(Duration::from_millis(30)),
            Err(_) => break -1,
        }
    };
    let mut stdout = out.and_then(|h| h.join().ok()).unwrap_or_default();
    let stderr = err.and_then(|h| h.join().ok()).unwrap_or_default();
    if stdout.is_empty() {
        stdout = stderr; // a failing tool usually explains itself on stderr
    }
    Outcome { code, stdout: String::from_utf8_lossy(&stdout).trim().to_string(), timed_out }
}

/// Run `spec` with live output on the bus; returns the exit code.
pub fn run_visible(spec: &CommandSpec, vars: &Vars, bus: &Bus) -> i32 {
    let inner = build_inner(spec, vars).iter().map(|a| shell_quote(a)).collect::<Vec<_>>().join(" ");
    let (program, argv): (&str, Vec<String>) = if spec.root && !is_root() {
        ("pkexec", vec!["script".into(), "-qec".into(), inner, "/dev/null".into()])
    } else {
        ("script", vec!["-qec".into(), inner, "/dev/null".into()])
    };
    log::info!("script command: {program} (root: {})", spec.root);

    // stdin stays open and unused: `script` would tear the pty down on EOF.
    let mut cmd = Command::new(program);
    cmd.args(&argv).stdin(Stdio::piped()).stdout(Stdio::piped()).stderr(Stdio::piped());
    if !spec.root {
        cmd.process_group(0);
    }
    let mut child = match cmd.spawn() {
        Ok(c) => c,
        Err(e) => {
            bus.publish(&Message::ScriptOutput { text: format!("failed to start {program}: {e}\n") });
            return -1;
        }
    };
    let _stdin_guard = child.stdin.take();
    let pumps: Vec<_> = [child.stdout.take().map(|s| Box::new(s) as Box<dyn Read + Send>), child.stderr.take().map(|s| Box::new(s) as Box<dyn Read + Send>)]
        .into_iter()
        .flatten()
        .map(|s| {
            let bus = *bus;
            thread::spawn(move || pump(s, bus))
        })
        .collect();

    // A timeout is only enforceable for commands we own (not for pkexec'd ones).
    let deadline = spec.timeout_secs.filter(|_| !spec.root).map(|s| Instant::now() + Duration::from_secs(s));
    let code = loop {
        match child.try_wait() {
            Ok(Some(status)) => break status.code().unwrap_or(-1),
            Ok(None) if deadline.is_some_and(|d| Instant::now() >= d) => {
                bus.publish(&Message::ScriptOutput { text: "\n[timed out — stopping the command]\n".into() });
                kill_group(child.id());
                let _ = child.kill();
                let _ = child.wait();
                break -1;
            }
            Ok(None) => thread::sleep(Duration::from_millis(50)),
            Err(_) => break -1,
        }
    };
    for h in pumps {
        let _ = h.join();
    }
    code
}

fn pump(mut reader: Box<dyn Read + Send>, bus: Bus) {
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
            bus.publish(&Message::ScriptOutput { text });
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use tux_abi::script::Text;

    fn shell(text: &str) -> CommandSpec {
        serde_json::from_value(serde_json::json!({ "shell": text })).unwrap()
    }

    #[test]
    fn variables_become_environment_not_shell_text() {
        let mut vars = Vars::new();
        vars.insert("name".into(), "a; echo INJECTED".into());
        let out = run_check(&shell("printf '%s' \"$TUX_VAR_NAME\""), &vars);
        assert_eq!(out.code, 0);
        assert_eq!(out.stdout, "a; echo INJECTED");
    }

    #[test]
    fn argv_is_interpolated_without_a_shell() {
        let mut vars = Vars::new();
        vars.insert("x".into(), "$(echo no)".into());
        let spec: CommandSpec = serde_json::from_value(serde_json::json!({ "argv": ["echo", "v=${x}"] })).unwrap();
        let out = run_check(&spec, &vars);
        assert_eq!(out.stdout, "v=$(echo no)");
    }

    #[test]
    fn exit_code_and_stderr_fallback() {
        let out = run_check(&shell("echo oops >&2; exit 3"), &Vars::new());
        assert_eq!(out.code, 3);
        assert_eq!(out.stdout, "oops");
    }

    #[test]
    fn timeout_kills_the_command() {
        let mut spec = shell("sleep 5");
        spec.timeout_secs = Some(1);
        let t = Instant::now();
        let out = run_check(&spec, &Vars::new());
        assert!(out.timed_out);
        assert!(t.elapsed() < Duration::from_secs(4));
    }

    #[test]
    fn missing_program_is_reported() {
        let spec: CommandSpec = serde_json::from_value(serde_json::json!({ "argv": ["definitely-not-a-program"] })).unwrap();
        let out = run_check(&spec, &Vars::new());
        // `env` itself starts, then fails to exec the program.
        assert_ne!(out.code, 0);
    }

    #[test]
    fn multi_line_shell_text() {
        let spec = CommandSpec { shell: Some(Text::Lines(vec!["a=1".into(), "echo $a".into()])), ..shell("") };
        assert_eq!(run_check(&spec, &Vars::new()).stdout, "1");
    }
}
