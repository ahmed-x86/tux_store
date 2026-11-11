//! Real progress of a running command, read from what it prints.
//!
//! Two sources, both optional:
//!
//! * **marker lines** — any command may print `TUX_PROGRESS=42` (or
//!   `TUX_PROGRESS 42.5`, `TUX_PROGRESS: 42%`). The line is *removed* from the
//!   text shown in the console and written to the log.
//! * **percentages** — with `"progress": "percent"` the last `NN%` found in the
//!   output is used (`curl -#`, `wget`, `rsync --info=progress2`, …). These
//!   lines are shown as usual.
//!
//! The scanner works on the decoded text stream in whatever pieces it
//! arrives, and understands both `\n` and `\r` (progress meters redraw their
//! line with `\r`). It only uses `std`.

/// Prefix of a marker line.
pub const MARKER: &str = "TUX_PROGRESS";

/// What one call to [`Scanner::feed`] produced.
#[derive(Debug, Default, PartialEq, Eq)]
pub struct Fed {
    /// The text to show / log (marker lines removed).
    pub text: String,
    /// Newest progress seen in this piece, in tenths of a percent (0..=1000).
    pub permille: Option<u32>,
}

pub struct Scanner {
    percent_mode: bool,
    /// The current line so far (all of it, used for scanning).
    seg: String,
    /// While the current line could still turn out to be a marker, its text
    /// is held back here instead of being shown.
    held: Option<String>,
    /// The current line was already judged "not a marker" and is being shown.
    open: bool,
    /// A marker line ended with `\r`: swallow the `\n` that follows.
    swallow_lf: bool,
}

fn to_permille(p: f64) -> u32 {
    (p * 10.0).round().clamp(0.0, 1000.0) as u32
}

/// `"  TUX_PROGRESS=42"` → 42.0. Must be the whole line (nothing but an
/// optional `%` after the number).
fn marker_value(line: &str) -> Option<f64> {
    let rest = line.trim().strip_prefix(MARKER)?;
    let rest = rest.trim_start_matches(|c: char| c == '=' || c == ':' || c == ' ' || c == '\t');
    let end = rest.find(|c: char| !(c.is_ascii_digit() || c == '.')).unwrap_or(rest.len());
    if end == 0 {
        return None;
    }
    let value: f64 = rest[..end].parse().ok()?;
    let tail = rest[end..].trim();
    if !(tail.is_empty() || tail == "%") {
        return None;
    }
    (0.0..=100.0).contains(&value).then_some(value)
}

/// Could a line that starts like this still become a marker line?
fn could_be_marker(line_so_far: &str) -> bool {
    let t = line_so_far.trim_start();
    MARKER.starts_with(t) || t.starts_with(MARKER)
}

/// The last `NN%` / `NN.N %` in `s` (values above 100 are ignored).
fn last_percent(s: &str) -> Option<f64> {
    let b = s.as_bytes();
    let mut best = None;
    for (i, &c) in b.iter().enumerate() {
        if c != b'%' {
            continue;
        }
        let mut end = i;
        while end > 0 && b[end - 1] == b' ' {
            end -= 1;
        }
        let mut start = end;
        while start > 0 && (b[start - 1].is_ascii_digit() || b[start - 1] == b'.') {
            start -= 1;
        }
        if start == end {
            continue;
        }
        // `start` and `end` sit next to ASCII bytes, so they are char boundaries.
        if let Ok(v) = s[start..end].parse::<f64>() {
            if (0.0..=100.0).contains(&v) {
                best = Some(v);
            }
        }
    }
    best
}

impl Scanner {
    pub fn new(percent_mode: bool) -> Self {
        Scanner { percent_mode, seg: String::new(), held: None, open: false, swallow_lf: false }
    }

    pub fn feed(&mut self, input: &str) -> Fed {
        let mut out = String::with_capacity(input.len());
        let mut permille = None;
        for ch in input.chars() {
            if self.swallow_lf {
                self.swallow_lf = false;
                if ch == '\n' {
                    continue;
                }
            }
            if ch == '\n' || ch == '\r' {
                let line = std::mem::take(&mut self.seg);
                self.open = false;
                if let Some(p) = marker_value(&line) {
                    permille = Some(to_permille(p));
                    self.held = None; // the marker line disappears
                    if ch == '\r' {
                        self.swallow_lf = true;
                    }
                } else {
                    if self.percent_mode {
                        if let Some(p) = last_percent(&line) {
                            permille = Some(to_permille(p));
                        }
                    }
                    if let Some(h) = self.held.take() {
                        out.push_str(&h);
                    }
                    out.push(ch);
                }
                continue;
            }

            let line_start = self.seg.is_empty();
            self.seg.push(ch);
            if let Some(h) = self.held.as_mut() {
                h.push(ch);
                if !could_be_marker(&self.seg) {
                    out.push_str(h);
                    self.held = None;
                    self.open = true;
                }
            } else if self.open {
                out.push(ch);
            } else if line_start && could_be_marker(&self.seg) {
                self.held = Some(self.seg.clone());
            } else {
                self.open = true;
                out.push(ch);
            }
        }
        // A progress meter redraws its line with `\r` and may not have ended it
        // yet: look at the unfinished line too (percent mode only; a half
        // written marker is waited for).
        if self.percent_mode && self.held.is_none() {
            if let Some(p) = last_percent(&self.seg) {
                permille = Some(to_permille(p));
            }
        }
        Fed { text: out, permille }
    }

    /// The command ended: release a held-back, unfinished line.
    pub fn finish(&mut self) -> String {
        self.seg.clear();
        self.open = false;
        self.held.take().unwrap_or_default()
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn feed_all(s: &mut Scanner, parts: &[&str]) -> (String, Option<u32>) {
        let mut text = String::new();
        let mut last = None;
        for p in parts {
            let f = s.feed(p);
            text.push_str(&f.text);
            if f.permille.is_some() {
                last = f.permille;
            }
        }
        text.push_str(&s.finish());
        (text, last)
    }

    #[test]
    fn marker_line_is_removed_and_reported() {
        let mut s = Scanner::new(false);
        let (text, p) = feed_all(&mut s, &["hello\nTUX_PROGRESS=42\nworld\n"]);
        assert_eq!(text, "hello\nworld\n");
        assert_eq!(p, Some(420));
    }

    #[test]
    fn marker_variants_and_pty_line_endings() {
        for (line, want) in [
            ("TUX_PROGRESS 7.5", 75),
            ("TUX_PROGRESS: 100%", 1000),
            ("  TUX_PROGRESS=0", 0),
            ("TUX_PROGRESS=33.34", 333),
        ] {
            let mut s = Scanner::new(false);
            let (text, p) = feed_all(&mut s, &[&format!("a\r\n{line}\r\nb\r\n")]);
            assert_eq!(text, "a\r\nb\r\n", "{line}");
            assert_eq!(p, Some(want), "{line}");
        }
    }

    #[test]
    fn marker_split_in_odd_places() {
        let mut s = Scanner::new(false);
        let (text, p) = feed_all(&mut s, &["x\nTUX_", "PROGRES", "S=5", "5\nrest\n"]);
        assert_eq!(text, "x\nrest\n");
        assert_eq!(p, Some(550));
    }

    #[test]
    fn lookalikes_are_shown_untouched() {
        let mut s = Scanner::new(false);
        let (text, p) = feed_all(&mut s, &["TUX_PROGRESS is a word\nTUX_PROGRESS=abc\nTUX_PROGRESS=150\nTUX_PROGRESS=5 apples\nTUX_X\n"]);
        assert_eq!(text, "TUX_PROGRESS is a word\nTUX_PROGRESS=abc\nTUX_PROGRESS=150\nTUX_PROGRESS=5 apples\nTUX_X\n");
        assert_eq!(p, None);
    }

    #[test]
    fn a_line_that_only_starts_like_a_marker_is_released_at_the_end() {
        let mut s = Scanner::new(false);
        let f = s.feed("TUX_PRO");
        assert_eq!(f.text, "", "held back while it might be a marker");
        assert_eq!(s.finish(), "TUX_PRO");
    }

    #[test]
    fn plain_text_streams_through_immediately() {
        let mut s = Scanner::new(false);
        assert_eq!(s.feed("abc").text, "abc");
        assert_eq!(s.feed("def\nxyz").text, "def\nxyz");
    }

    #[test]
    fn percent_mode_follows_a_curl_meter() {
        let mut s = Scanner::new(true);
        let f = s.feed("\r######                        21.3%");
        assert_eq!(f.permille, Some(213), "even before the line ends");
        let f = s.feed("\r##############                48.0%\r#########################     87.5%");
        assert_eq!(f.permille, Some(875));
        let f = s.feed("\r######################################## 100.0%\n");
        assert_eq!(f.permille, Some(1000));
    }

    #[test]
    fn percent_mode_is_opt_in() {
        let mut s = Scanner::new(false);
        assert_eq!(s.feed("downloading 45%\n").permille, None);
    }

    #[test]
    fn percent_ignores_nonsense() {
        assert_eq!(last_percent("100% done, then 250% and x%"), Some(100.0));
        assert_eq!(last_percent("no numbers here %"), None);
        assert_eq!(last_percent("wget 45%[=====>   ] 4.5M"), Some(45.0));
        assert_eq!(last_percent("rsync   12,345  67%  1.2MB/s"), Some(67.0));
        assert_eq!(last_percent("日本語 55 % 完了"), Some(55.0));
    }
}
