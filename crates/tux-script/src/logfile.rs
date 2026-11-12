//! The log file of one add-on install / uninstall.
//!
//! Everything the console ("Show details") shows is also written, cleaned up
//! (colours removed, progress meters collapsed to their last state), to
//!
//! ```text
//! <logs dir>/tux-store-<HH-MM-SS>-<YYYY-MM-DD>-<add-on name>.log
//! ```
//!
//! The file is created lazily, the first time there is something worth
//! keeping (a command ran or something failed), so cancelling at the first
//! dialog leaves no empty files behind. It only uses `std`.

use std::fs::{self, File, OpenOptions};
use std::io::Write;
use std::os::unix::fs::OpenOptionsExt;
use std::path::{Path, PathBuf};

/// A local date and time.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct Stamp {
    pub year: i32,
    pub month: u32,
    pub day: u32,
    pub hour: u32,
    pub min: u32,
    pub sec: u32,
}

impl Stamp {
    /// `2026-11-11`
    pub fn date(&self) -> String {
        format!("{:04}-{:02}-{:02}", self.year, self.month, self.day)
    }
    /// `09-05-12` (no colons: safe in every file name)
    pub fn time_for_file(&self) -> String {
        format!("{:02}-{:02}-{:02}", self.hour, self.min, self.sec)
    }
    /// `2026-11-11 09:05:12`
    pub fn pretty(&self) -> String {
        format!("{} {:02}:{:02}:{:02}", self.date(), self.hour, self.min, self.sec)
    }
}

/// A name that is safe in a file name: letters and digits of any language,
/// `-`, `_` and `.` are kept, runs of anything else become one `-`.
/// Falls back to `fallback` when nothing is left.
pub fn safe_name(title: &str, fallback: &str) -> String {
    let mut out = String::new();
    let mut dash = false;
    for c in title.trim().chars() {
        if c.is_alphanumeric() || c == '_' || c == '.' {
            out.push(c);
            dash = false;
        } else if !dash && !out.is_empty() {
            out.push('-');
            dash = true;
        }
    }
    let out: String = out.trim_matches(|c| c == '-' || c == '.').chars().take(60).collect();
    if out.is_empty() {
        if fallback.is_empty() {
            "addon".into()
        } else {
            safe_name(fallback, "addon")
        }
    } else {
        out
    }
}

/// `tux-store-09-05-12-2026-11-11-Install-Ventoy.log`
pub fn file_name(stamp: &Stamp, addon: &str) -> String {
    format!("tux-store-{}-{}-{addon}.log", stamp.time_for_file(), stamp.date())
}

// ───────────────────────────── text cleaning ─────────────────────────────

#[derive(Clone, Copy, PartialEq, Eq)]
enum Esc {
    None,
    /// Saw ESC.
    Seen,
    /// Inside `ESC [ … <final>`.
    Csi,
    /// Inside `ESC ] … BEL` / `ESC ] … ESC \`.
    Osc,
    /// Inside an OSC, saw ESC (expecting `\`).
    OscEsc,
    /// `ESC ( B`, `ESC ) 0`… : one more byte to drop.
    Charset,
}

/// Turns raw terminal output into plain lines: escape sequences are dropped,
/// `\r` rewinds to the start of the line (so a progress bar leaves only its
/// last state), other control characters are dropped. Works on pieces, a
/// sequence may be cut anywhere.
pub struct LineCleaner {
    line: String,
    overwrite: bool,
    esc: Esc,
}

impl Default for LineCleaner {
    fn default() -> Self {
        LineCleaner { line: String::new(), overwrite: false, esc: Esc::None }
    }
}

impl LineCleaner {
    /// Feed a piece; returns the lines that were completed by it
    /// (each ends with `\n`).
    pub fn push(&mut self, chunk: &str) -> String {
        let mut done = String::new();
        for c in chunk.chars() {
            match self.esc {
                Esc::Seen => {
                    self.esc = match c {
                        '[' => Esc::Csi,
                        ']' => Esc::Osc,
                        '(' | ')' | '*' | '+' => Esc::Charset,
                        _ => Esc::None,
                    };
                    continue;
                }
                Esc::Csi => {
                    if ('@'..='~').contains(&c) {
                        self.esc = Esc::None;
                    }
                    continue;
                }
                Esc::Osc => {
                    match c {
                        '\u{7}' => self.esc = Esc::None,
                        '\u{1b}' => self.esc = Esc::OscEsc,
                        _ => {}
                    }
                    continue;
                }
                Esc::OscEsc => {
                    self.esc = if c == '\\' { Esc::None } else { Esc::Osc };
                    continue;
                }
                Esc::Charset => {
                    self.esc = Esc::None;
                    continue;
                }
                Esc::None => {}
            }
            match c {
                '\u{1b}' => self.esc = Esc::Seen,
                '\r' => self.overwrite = true,
                '\n' => {
                    done.push_str(self.line.trim_end());
                    done.push('\n');
                    self.line.clear();
                    self.overwrite = false;
                }
                c if c.is_control() && c != '\t' => {}
                c => {
                    if self.overwrite {
                        self.line.clear();
                        self.overwrite = false;
                    }
                    self.line.push(c);
                }
            }
        }
        done
    }

    /// The unfinished last line (without `\n`), and forget it.
    pub fn flush(&mut self) -> String {
        self.overwrite = false;
        self.esc = Esc::None;
        std::mem::take(&mut self.line).trim_end().to_string()
    }
}

// ───────────────────────────── the file ─────────────────────────────

pub struct LogFile {
    dir: PathBuf,
    file_name: String,
    /// Written first, when the file is created.
    header: String,
    /// Lines noted before the file existed.
    pending: String,
    file: Option<File>,
    path: Option<PathBuf>,
    cleaner: LineCleaner,
    /// Creating or writing failed once: do not keep trying (and do not spam).
    broken: bool,
}

impl LogFile {
    pub fn new(dir: PathBuf, stamp: &Stamp, addon_name: &str, header: String) -> Self {
        LogFile {
            dir,
            file_name: file_name(stamp, addon_name),
            header,
            pending: String::new(),
            file: None,
            path: None,
            cleaner: LineCleaner::default(),
            broken: false,
        }
    }

    /// Where the log is (once it exists).
    pub fn path(&self) -> Option<&Path> {
        self.path.as_deref()
    }

    pub fn exists(&self) -> bool {
        self.file.is_some()
    }

    /// Create the file now (idempotent). Returns whether it exists.
    pub fn create(&mut self) -> bool {
        if self.file.is_some() {
            return true;
        }
        if self.broken {
            return false;
        }
        match self.open_new() {
            Ok((file, path)) => {
                self.file = Some(file);
                self.path = Some(path);
                let first = format!("{}{}", self.header, std::mem::take(&mut self.pending));
                self.raw(&first);
                true
            }
            Err(e) => {
                self.broken = true;
                eprintln!("[tux-store] cannot create the add-on log in {}: {e}", self.dir.display());
                false
            }
        }
    }

    fn open_new(&self) -> std::io::Result<(File, PathBuf)> {
        fs::create_dir_all(&self.dir)?;
        let stem = self.file_name.strip_suffix(".log").unwrap_or(&self.file_name);
        for n in 0..100u32 {
            let name = if n == 0 { format!("{stem}.log") } else { format!("{stem}-{}.log", n + 1) };
            let path = self.dir.join(name);
            // 0600: a log may hold anything a command printed.
            match OpenOptions::new().write(true).create_new(true).mode(0o600).open(&path) {
                Ok(f) => return Ok((f, path)),
                Err(e) if e.kind() == std::io::ErrorKind::AlreadyExists => continue,
                Err(e) => return Err(e),
            }
        }
        Err(std::io::Error::new(std::io::ErrorKind::AlreadyExists, "too many logs with the same name"))
    }

    fn raw(&mut self, text: &str) {
        if text.is_empty() {
            return;
        }
        if let Some(f) = self.file.as_mut() {
            if f.write_all(text.as_bytes()).is_err() && !self.broken {
                self.broken = true;
                eprintln!("[tux-store] cannot write to the add-on log");
            }
        }
    }

    /// Close an unfinished output line so a note starts on its own line.
    fn end_partial_line(&mut self) {
        let rest = self.cleaner.flush();
        if !rest.is_empty() {
            let line = format!("{rest}\n");
            self.raw(&line);
        }
    }

    /// One line of the store's own notes (a choice that was made, a check that
    /// failed…). Kept in memory until the log file exists.
    pub fn note(&mut self, line: &str) {
        let clean: String = line.chars().map(|c| if c == '\n' || c == '\r' { ' ' } else { c }).collect();
        if self.file.is_some() {
            self.end_partial_line();
            self.raw(&format!("{clean}\n"));
        } else {
            self.pending.push_str(&clean);
            self.pending.push('\n');
        }
    }

    /// Output of a command. Creates the file.
    pub fn output(&mut self, chunk: &str) {
        if !self.create() {
            return;
        }
        let done = self.cleaner.push(chunk);
        self.raw(&done);
    }

    /// Write the footer and close. Returns the path (if a file exists).
    pub fn finish(&mut self, footer: &str) -> Option<PathBuf> {
        if self.file.is_some() {
            self.end_partial_line();
            self.raw(&format!("{footer}\n"));
            self.file = None; // closes it
        }
        self.path.clone()
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn stamp() -> Stamp {
        Stamp { year: 2026, month: 11, day: 11, hour: 9, min: 5, sec: 7 }
    }

    fn tmp(name: &str) -> PathBuf {
        let d = std::env::temp_dir().join(format!("tux-log-test-{name}-{}", std::process::id()));
        let _ = fs::remove_dir_all(&d);
        d
    }

    #[test]
    fn names() {
        assert_eq!(file_name(&stamp(), "Install-Ventoy"), "tux-store-09-05-07-2026-11-11-Install-Ventoy.log");
        assert_eq!(safe_name("Install Ventoy", "id"), "Install-Ventoy");
        assert_eq!(safe_name("  Docker / Compose: setup!! ", "id"), "Docker-Compose-setup");
        assert_eq!(safe_name("../../etc/passwd", "id"), "etc-passwd");
        assert_eq!(safe_name("أداة الفلاشة", "id"), "أداة-الفلاشة");
        assert_eq!(safe_name("!!!", "my-id-1"), "my-id-1");
        assert_eq!(safe_name("", ""), "addon");
        assert!(safe_name(&"x".repeat(200), "id").chars().count() <= 60);
        assert!(!safe_name("a/b\\c\0d", "id").contains(['/', '\\', '\0']));
    }

    #[test]
    fn cleaner_collapses_progress_and_strips_escapes() {
        let mut c = LineCleaner::default();
        let out = c.push("\u{1b}[1;32mok\u{1b}[0m\nfoo 10%\rfoo 55%\rfoo 100%\r\nnext\n");
        assert_eq!(out, "ok\nfoo 100%\nnext\n");
    }

    #[test]
    fn cleaner_handles_pieces_and_other_sequences() {
        let mut c = LineCleaner::default();
        let mut out = String::new();
        for piece in ["\u{1b}", "[3", "1mred\u{1b}[0", "m\n", "\u{1b}]0;title\u{7}after", " osc\u{1b}]2;x\u{1b}\\!\n", "\u{1b}(Bplain\n", "tab\there\n"] {
            out.push_str(&c.push(piece));
        }
        assert_eq!(out, "red\nafter osc!\nplain\ntab\there\n");
        assert_eq!(c.push("partial"), "");
        assert_eq!(c.flush(), "partial");
        assert_eq!(c.flush(), "");
    }

    #[test]
    fn nothing_is_written_until_there_is_output() {
        let dir = tmp("lazy");
        let mut log = LogFile::new(dir.clone(), &stamp(), "Demo", "HEAD\n".into());
        log.note("[choice] driver = open");
        assert!(!log.exists());
        assert!(log.finish("END").is_none(), "no file, no path");
        assert!(!dir.exists(), "not even the folder");
    }

    #[test]
    fn file_has_header_notes_output_and_footer() {
        let dir = tmp("full");
        let mut log = LogFile::new(dir.clone(), &stamp(), "Demo", "HEAD\n".into());
        log.note("[choice] driver = open");
        log.output("==> step one\n");
        log.output("pct 10%\rpct 90%\rpct 100%\r\ndone\n");
        log.output("half a li");
        log.note("[check failed] pacman locked");
        let path = log.finish("RESULT: ok").unwrap();
        assert_eq!(path, dir.join("tux-store-09-05-07-2026-11-11-Demo.log"));
        let text = fs::read_to_string(&path).unwrap();
        assert_eq!(
            text,
            "HEAD\n[choice] driver = open\n==> step one\npct 100%\ndone\nhalf a li\n[check failed] pacman locked\nRESULT: ok\n"
        );
        use std::os::unix::fs::PermissionsExt;
        assert_eq!(fs::metadata(&path).unwrap().permissions().mode() & 0o777, 0o600);
        let _ = fs::remove_dir_all(&dir);
    }

    #[test]
    fn same_name_in_the_same_second_gets_a_suffix() {
        let dir = tmp("dup");
        let mut a = LogFile::new(dir.clone(), &stamp(), "Demo", String::new());
        let mut b = LogFile::new(dir.clone(), &stamp(), "Demo", String::new());
        a.output("one\n");
        b.output("two\n");
        let pa = a.finish("").unwrap();
        let pb = b.finish("").unwrap();
        assert_ne!(pa, pb);
        assert!(pb.to_string_lossy().ends_with("Demo-2.log"));
        let _ = fs::remove_dir_all(&dir);
    }

    #[test]
    fn unwritable_folder_never_panics() {
        let mut log = LogFile::new(PathBuf::from("/proc/definitely/not/writable"), &stamp(), "Demo", "H\n".into());
        log.output("x\n");
        log.note("n");
        assert!(log.finish("end").is_none());
    }
}
