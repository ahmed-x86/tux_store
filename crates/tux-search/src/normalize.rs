//! Search-text normalization.
//!
//! Arabic users type the same word with different letter forms: `أحمد` and
//! `احمد`, `على` and `علي`, `مدرسة` and `مدرسه`. The package databases mostly
//! use Latin names, but add-on descriptions and user scripts can be Arabic,
//! so both sides of every comparison are folded before matching.

pub use tux_abi::text::normalize_arabic;

/// Fold one piece of text into the form used for search comparisons:
/// Arabic variants first, then lower-case, then the same separators the
/// pacman search ignores (` `, `-`, `_`, `.`).
pub(crate) fn search_key(text: &str) -> String {
    normalize_arabic(text)
        .chars()
        .filter(|c| !matches!(c, ' ' | '-' | '_' | '.'))
        .flat_map(char::to_lowercase)
        .collect()
}

/// Does `text` match `query` after normalization? Either side may use any of
/// the Arabic variants listed in [`normalize_arabic`].
#[cfg(test)]
pub(crate) fn matches_normalized(text: &str, query: &str) -> bool {
    let needle = search_key(query);
    !needle.is_empty() && search_key(text).contains(&needle)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn alef_variants_match_plain_alef() {
        assert!(matches_normalized("أحمد", "احمد"));
        assert!(matches_normalized("احمد", "أحمد"));
    }

    #[test]
    fn alef_maksura_matches_yaa() {
        assert!(matches_normalized("على", "علي"));
        assert!(matches_normalized("علي", "على"));
    }

    #[test]
    fn taa_marbuta_matches_haa() {
        assert!(matches_normalized("مدرسة", "مدرسه"));
    }

    #[test]
    fn separators_and_case_are_ignored() {
        assert!(matches_normalized("LibreOffice-Fresh", "libreoffice fresh"));
    }

    #[test]
    fn empty_query_never_matches() {
        assert!(!matches_normalized("أحمد", ""));
    }
}
