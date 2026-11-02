//! Parser for `pacman -Si/-Qi` output (one parser for every call site).

use std::collections::HashMap;

pub type InfoBlock = HashMap<String, String>;

/// Split `pacman -Si a b c` output into one key→value map per package.
/// Wrapped continuation lines (indented) are joined with a space.
pub fn parse_info(text: &str) -> Vec<InfoBlock> {
    let mut blocks = Vec::new();
    let mut cur = InfoBlock::new();
    let mut key = String::new();

    for line in text.lines() {
        if line.trim().is_empty() {
            if !cur.is_empty() {
                blocks.push(std::mem::take(&mut cur));
            }
            key.clear();
            continue;
        }
        if line.starts_with(' ') {
            if let Some(v) = cur.get_mut(&key) {
                v.push(' ');
                v.push_str(line.trim());
            }
        } else if let Some((k, v)) = line.split_once(':') {
            key = k.trim().to_string();
            cur.insert(key.clone(), v.trim().to_string());
        }
    }
    if !cur.is_empty() {
        blocks.push(cur);
    }
    blocks
}

/// `"12.34 MiB"` → bytes. Unknown/missing unit means bytes.
pub fn parse_size(s: &str) -> u64 {
    let mut it = s.split_whitespace();
    let Some(num) = it.next().and_then(|n| n.parse::<f64>().ok()) else {
        return 0;
    };
    let mult = match it.next().map(str::to_ascii_lowercase).as_deref() {
        Some("kib") => 1024.0,
        Some("mib") => 1024.0 * 1024.0,
        Some("gib") => 1024.0 * 1024.0 * 1024.0,
        Some("tib") => 1024.0 * 1024.0 * 1024.0 * 1024.0,
        _ => 1.0,
    };
    (num * mult).round() as u64
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn blocks() {
        let text = "Repository      : extra\nName            : vlc\nVersion         : 3.0-1\nDescription     : A player:\n                  with wrap\n\nName            : mpv\nInstalled Size  : 2.50 MiB\n";
        let b = parse_info(text);
        assert_eq!(b.len(), 2);
        assert_eq!(b[0]["Name"], "vlc");
        assert_eq!(b[0]["Description"], "A player: with wrap");
        assert_eq!(parse_size(&b[1]["Installed Size"]), 2_621_440);
    }

    #[test]
    fn sizes() {
        assert_eq!(parse_size("1.00 KiB"), 1024);
        assert_eq!(parse_size("512 B"), 512);
        assert_eq!(parse_size("junk"), 0);
    }
}
