//! Text helpers shared by several modules.

/// `1536` → `"1.50 KiB"`.
pub fn format_size(bytes: u64) -> String {
    const K: f64 = 1024.0;
    let b = bytes as f64;
    if bytes < 1024 {
        format!("{bytes} B")
    } else if b < K * K {
        format!("{:.2} KiB", b / K)
    } else if b < K * K * K {
        format!("{:.2} MiB", b / (K * K))
    } else {
        format!("{:.2} GiB", b / (K * K * K))
    }
}

/// `"libreoffice-fresh"` → `"Libreoffice Fresh"`.
pub fn prettify_name(raw: &str) -> String {
    let mut out = String::with_capacity(raw.len());
    for part in raw.split('-').filter(|p| !p.is_empty()) {
        if !out.is_empty() {
            out.push(' ');
        }
        let mut chars = part.chars();
        if let Some(first) = chars.next() {
            out.extend(first.to_uppercase());
            out.push_str(chars.as_str());
        }
    }
    out
}

/// Strict allow-list for package names. Names end up in command lines (some
/// run as root) and in cache file names, so anything unusual is rejected.
pub fn is_valid_package_name(name: &str) -> bool {
    !name.is_empty()
        && name.len() <= 128
        && !name.starts_with(|c| c == '-' || c == '.')
        && name
            .bytes()
            .all(|b| b.is_ascii_alphanumeric() || matches!(b, b'@' | b'.' | b'_' | b'+' | b'-'))
}

/// Remove ANSI escape sequences (`ESC [ ... final-byte`) from terminal output.
pub fn strip_ansi(s: &str) -> String {
    let mut out = String::with_capacity(s.len());
    let mut it = s.chars().peekable();
    while let Some(c) = it.next() {
        if c == '\u{1b}' {
            if it.peek() == Some(&'[') {
                it.next();
                for n in it.by_ref() {
                    if ('@'..='~').contains(&n) {
                        break;
                    }
                }
            }
        } else {
            out.push(c);
        }
    }
    out
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn sizes() {
        assert_eq!(format_size(12), "12 B");
        assert_eq!(format_size(1536), "1.50 KiB");
        assert_eq!(format_size(5 * 1024 * 1024), "5.00 MiB");
    }

    #[test]
    fn pretty() {
        assert_eq!(prettify_name("libreoffice-fresh"), "Libreoffice Fresh");
    }

    #[test]
    fn names() {
        assert!(is_valid_package_name("gtk+"));
        assert!(is_valid_package_name("lib32-mesa"));
        assert!(!is_valid_package_name("-Rns"));
        assert!(!is_valid_package_name("a b"));
        assert!(!is_valid_package_name("../x"));
    }

    #[test]
    fn ansi() {
        assert_eq!(strip_ansi("\u{1b}[1mhi\u{1b}[0m"), "hi");
    }
}
