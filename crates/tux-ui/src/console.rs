//! Terminal-like text buffer for the pacman console.
//!
//! pacman redraws progress bars with `\r`. A plain string would show every
//! redraw as a new line; this buffer lets `\r` rewind to the start of the
//! current line so only the latest state of each bar remains. It is also
//! size-capped, and the UI copies it into Slint at most ~10×/second.

use tux_abi::text::strip_ansi;

const MAX_BYTES: usize = 200_000;

#[derive(Default)]
pub struct ConsoleBuffer {
    text: String,
    line_start: usize,
    overwrite: bool,
}

impl ConsoleBuffer {
    pub fn clear(&mut self) {
        self.text.clear();
        self.line_start = 0;
        self.overwrite = false;
    }

    pub fn text(&self) -> &str {
        &self.text
    }

    pub fn push(&mut self, chunk: &str) {
        for c in strip_ansi(chunk).chars() {
            match c {
                '\r' => self.overwrite = true,
                '\n' => {
                    self.text.push('\n');
                    self.line_start = self.text.len();
                    self.overwrite = false;
                }
                c if c.is_control() && c != '\t' => {}
                c => {
                    if self.overwrite {
                        self.text.truncate(self.line_start);
                        self.overwrite = false;
                    }
                    self.text.push(c);
                }
            }
        }
        self.trim();
    }

    /// Drop the oldest half (at a line boundary) once the cap is exceeded.
    fn trim(&mut self) {
        if self.text.len() <= MAX_BYTES {
            return;
        }
        let mut cut = self.text.len() - MAX_BYTES / 2;
        while !self.text.is_char_boundary(cut) {
            cut += 1;
        }
        let cut = self.text[cut..].find('\n').map_or(cut, |i| cut + i + 1);
        self.text.drain(..cut);
        self.line_start = self.line_start.saturating_sub(cut);
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn carriage_return_rewrites_the_line() {
        let mut b = ConsoleBuffer::default();
        b.push("foo 10%\rfoo 55%\rfoo 100%\r\nnext\n");
        assert_eq!(b.text(), "foo 100%\nnext\n");
    }

    #[test]
    fn strips_escapes() {
        let mut b = ConsoleBuffer::default();
        b.push("\u{1b}[1mhello\u{1b}[0m\n");
        assert_eq!(b.text(), "hello\n");
    }
}
