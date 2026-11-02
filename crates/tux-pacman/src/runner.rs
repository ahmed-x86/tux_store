//! Run external commands with a hard timeout and without ever blocking on a
//! full pipe. Always forces the C locale so output is parseable.

use std::io::Read;
use std::process::{Command, Stdio};
use std::thread;
use std::time::{Duration, Instant};

#[derive(Debug, Default, Clone)]
pub struct Captured {
    pub stdout: String,
    pub stderr: String,
    pub code: Option<i32>,
    pub timed_out: bool,
}

impl Captured {
    pub fn success(&self) -> bool {
        self.code == Some(0)
    }
}

/// `pacman <args>` in the C locale.
pub fn run_pacman(args: &[&str], timeout: Duration) -> Captured {
    run("pacman", args, timeout)
}

pub fn run(program: &str, args: &[&str], timeout: Duration) -> Captured {
    let mut child = match Command::new(program)
        .args(args)
        .env("LC_ALL", "C")
        .env("LANG", "C")
        .stdin(Stdio::null())
        .stdout(Stdio::piped())
        .stderr(Stdio::piped())
        .spawn()
    {
        Ok(c) => c,
        Err(e) => {
            return Captured {
                stderr: format!("failed to start {program}: {e}"),
                ..Captured::default()
            }
        }
    };

    let out_h = drain(child.stdout.take());
    let err_h = drain(child.stderr.take());

    let deadline = Instant::now() + timeout;
    let mut nap = 1u64;
    let mut timed_out = false;
    let status = loop {
        match child.try_wait() {
            Ok(Some(st)) => break Some(st),
            Ok(None) => {
                if Instant::now() >= deadline {
                    timed_out = true;
                    let _ = child.kill();
                    break child.wait().ok();
                }
                thread::sleep(Duration::from_millis(nap));
                nap = (nap * 2).min(20);
            }
            Err(_) => break None,
        }
    };

    let stdout = out_h.join().unwrap_or_default();
    let stderr = err_h.join().unwrap_or_default();
    Captured {
        stdout: String::from_utf8_lossy(&stdout).into_owned(),
        stderr: String::from_utf8_lossy(&stderr).into_owned(),
        code: status.and_then(|s| s.code()),
        timed_out,
    }
}

fn drain<R: Read + Send + 'static>(reader: Option<R>) -> thread::JoinHandle<Vec<u8>> {
    thread::spawn(move || {
        let mut buf = Vec::new();
        if let Some(mut r) = reader {
            let _ = r.read_to_end(&mut buf);
        }
        buf
    })
}

/// Is `name` an executable somewhere in `$PATH`?
pub fn in_path(name: &str) -> bool {
    std::env::var_os("PATH")
        .map(|paths| std::env::split_paths(&paths).any(|dir| dir.join(name).is_file()))
        .unwrap_or(false)
}
