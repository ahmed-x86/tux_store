//! "Open this package on the web" and generic URL opening.

use std::fs;
use std::process::{Command, Stdio};

const OFFICIAL: [&str; 6] = ["core", "extra", "multilib", "testing", "extra-testing", "multilib-testing"];

fn encode(s: &str) -> String {
    let mut out = String::with_capacity(s.len());
    for b in s.bytes() {
        if b.is_ascii_alphanumeric() || matches!(b, b'-' | b'.' | b'_' | b'~') {
            out.push(b as char);
        } else {
            out.push_str(&format!("%{b:02X}"));
        }
    }
    out
}

/// First `Server =` line of `[repo]` in pacman.conf, with `$repo`/`$arch` filled in.
fn repo_server(repo: &str) -> Option<String> {
    let conf = fs::read_to_string("/etc/pacman.conf").ok()?;
    let mut in_repo = false;
    for line in conf.lines().map(str::trim) {
        if let Some(section) = line.strip_prefix('[').and_then(|l| l.strip_suffix(']')) {
            in_repo = section == repo;
        } else if in_repo {
            if let Some(url) = line.strip_prefix("Server").and_then(|l| l.trim_start().strip_prefix('=')) {
                return Some(url.trim().replace("$repo", repo).replace("$arch", "x86_64"));
            }
        }
    }
    None
}

pub fn package_url(repo: &str, name: &str) -> String {
    let n = encode(name);
    if OFFICIAL.contains(&repo) {
        return format!("https://archlinux.org/packages/{repo}/x86_64/{n}/");
    }
    if repo.contains("aur") {
        return format!("https://aur.archlinux.org/packages/{n}");
    }
    repo_server(repo).unwrap_or_else(|| format!("https://archlinux.org/packages/?q={n}"))
}

/// Open with the desktop's default handler; the child is reaped in the
/// background so it never lingers as a zombie.
pub fn open(url: &str) {
    match Command::new("xdg-open")
        .arg(url)
        .stdin(Stdio::null())
        .stdout(Stdio::null())
        .stderr(Stdio::null())
        .spawn()
    {
        Ok(mut child) => {
            std::thread::spawn(move || {
                let _ = child.wait();
            });
        }
        Err(e) => log::warn!("xdg-open failed: {e}"),
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn urls() {
        assert_eq!(package_url("extra", "vlc"), "https://archlinux.org/packages/extra/x86_64/vlc/");
        assert_eq!(package_url("aur", "foo"), "https://aur.archlinux.org/packages/foo");
        assert_eq!(encode("gtk+"), "gtk%2B");
    }
}
