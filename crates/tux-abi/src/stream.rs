//! Byte-stream helpers for reading a pty-backed process.

/// Re-assembles UTF-8 that a `read()` boundary may have split mid-character.
#[derive(Default)]
pub struct Utf8Stream {
    pending: Vec<u8>,
}

impl Utf8Stream {
    /// Feed raw bytes; get back every complete character received so far.
    pub fn push(&mut self, bytes: &[u8]) -> String {
        self.pending.extend_from_slice(bytes);
        let (valid, tail_incomplete) = match std::str::from_utf8(&self.pending) {
            Ok(s) => (s.len(), false),
            Err(e) => (e.valid_up_to(), e.error_len().is_none()),
        };
        if valid == self.pending.len() {
            String::from_utf8(std::mem::take(&mut self.pending)).unwrap_or_default()
        } else if tail_incomplete {
            let rest = self.pending.split_off(valid);
            let out = String::from_utf8_lossy(&self.pending).into_owned();
            self.pending = rest;
            out
        } else {
            let out = String::from_utf8_lossy(&self.pending).into_owned();
            self.pending.clear();
            out
        }
    }
}

/// Splits text on `\n` *and* `\r` (pacman redraws progress bars with `\r`).
#[derive(Default)]
pub struct LineSplitter {
    partial: String,
}

impl LineSplitter {
    pub fn push(&mut self, text: &str) -> Vec<String> {
        let mut lines = Vec::new();
        for ch in text.chars() {
            if ch == '\n' || ch == '\r' {
                if !self.partial.is_empty() {
                    lines.push(std::mem::take(&mut self.partial));
                }
            } else {
                self.partial.push(ch);
            }
        }
        lines
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn utf8_split_across_reads() {
        let bytes = "é".as_bytes(); // 2 bytes
        let mut s = Utf8Stream::default();
        assert_eq!(s.push(&bytes[..1]), "");
        assert_eq!(s.push(&bytes[1..]), "é");
    }

    #[test]
    fn lines() {
        let mut l = LineSplitter::default();
        assert_eq!(l.push("a\r\nb\rc"), vec!["a", "b"]);
        assert_eq!(l.push("d\n"), vec!["cd"]);
    }
}
