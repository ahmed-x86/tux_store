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

/// Fold Arabic letter variations to their base forms so that a query typed in
/// one style still matches text written in another.
///
/// * `ا` `أ` `إ` `آ` `ٱ` → `ا`
/// * `ي` `ى` → `ي`
/// * `ة` `ه` → `ه`
///
/// Everything else (including Latin text, digits and diacritics) is unchanged.
/// The caller is responsible for case folding and whitespace/punctuation rules.
pub fn normalize_arabic(text: &str) -> String {
    text.chars()
        .map(|c| match c {
            'أ' | 'إ' | 'آ' | 'ٱ' => 'ا',
            'ى' => 'ي',
            'ة' => 'ه',
            other => other,
        })
        .collect()
}

/// Does `text` contain Arabic-script characters? Used by search to decide
/// whether a description fallback is worth trying (`pacman -Ss` already
/// searched descriptions, but the store normally ranks names only).
pub fn contains_arabic(text: &str) -> bool {
    text.chars().any(|c| {
        matches!(c,
            '\u{0600}'..='\u{06FF}'   // Arabic
            | '\u{0750}'..='\u{077F}' // Arabic Supplement
            | '\u{08A0}'..='\u{08FF}' // Arabic Extended-A
            | '\u{FB50}'..='\u{FDFF}' // Arabic Presentation Forms-A
            | '\u{FE70}'..='\u{FEFF}' // Arabic Presentation Forms-B
        )
    })
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

/// Accept only local Arch package archive names (`name.pkg.tar.zst|xz|gz|bz2`).
/// The path itself is checked separately (absolute, existing regular file).
pub fn is_local_package_file_name(name: &str) -> bool {
    !name.is_empty()
        && !name.chars().any(|c| c.is_control() || c == '/' || c == '\\')
        && [".pkg.tar.zst", ".pkg.tar.xz", ".pkg.tar.gz", ".pkg.tar.bz2"]
            .iter()
            .any(|ext| name.strip_suffix(ext).is_some_and(|stem| !stem.is_empty()))
}

/// Quote one word for `sh -c` (`it's` → `'it'\\''s'`).
pub fn shell_quote(s: &str) -> String {
    format!("'{}'", s.replace('\'', "'\\''"))
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
    fn local_package_files() {
        assert!(is_local_package_file_name("vlc-3.0-1-x86_64.pkg.tar.zst"));
        assert!(is_local_package_file_name("a.pkg.tar.xz"));
        assert!(!is_local_package_file_name("a.pkg.tar"));
        assert!(!is_local_package_file_name("../a.pkg.tar.gz"));
        assert!(!is_local_package_file_name("a.pkg.tar.gz\nrm -rf /"));
    }

    #[test]
    fn quoting() {
        assert_eq!(shell_quote("a b"), "'a b'");
        assert_eq!(shell_quote("it's"), "'it'\\''s'");
    }

    #[test]
    fn ansi() {
        assert_eq!(strip_ansi("\u{1b}[1mhi\u{1b}[0m"), "hi");
    }

    #[test]
    fn arabic_normalization_folds_letter_variants() {
        assert_eq!(normalize_arabic("أحمد"), "احمد");
        assert_eq!(normalize_arabic("إسلام"), "اسلام");
        assert_eq!(normalize_arabic("آية"), "ايه");
        assert_eq!(normalize_arabic("ٱلله"), "الله");
        assert_eq!(normalize_arabic("على"), "علي");
        assert_eq!(normalize_arabic("مدرسة"), "مدرسه");
    }

    #[test]
    fn arabic_detection_ignores_latin_text() {
        assert!(contains_arabic("أحمد"));
        assert!(!contains_arabic("firefox"));
    }
}
