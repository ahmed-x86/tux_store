//! Icon-name guessing: package name → ordered list of icon names to try.

const SUFFIXES: [&str; 6] = ["-git", "-bin", "-aur", "-patch", "-full", "-stable"];

/// `"foo-bin-git"` → `"foo"` (iteratively strips AUR-style suffixes).
pub fn sanitize(name: &str) -> &str {
    let mut n = name;
    loop {
        match SUFFIXES
            .iter()
            .find_map(|&s| n.strip_suffix(s).filter(|rest| !rest.is_empty()))
        {
            Some(rest) => n = rest,
            None => return n,
        }
    }
}

fn alias_for(name: &str) -> Option<&'static str> {
    Some(match name {
        "neovim" => "nvim",
        "libreoffice-fresh" | "libreoffice-still" | "libreoffice" => "libreoffice-main",
        "fastfetch" => "utilities-terminal",
        "telegram-desktop" => "telegram",
        "chromium" => "chromium-browser",
        "brave-browser" => "brave",
        "obs-studio" => "com.obsproject.Studio",
        "skypeforlinux" => "skype",
        "session-desktop-bin" => "session-desktop",
        _ => return None,
    })
}

fn fallback_hints(name: &str) -> &'static [&'static str] {
    match name {
        "yt-dlp" => &["youtube-dl", "youtube"],
        "htop" => &["htop", "utilities-system-monitor"],
        "fastfetch" => &["utilities-terminal", "terminal"],
        "kitty" => &["kitty", "terminal"],
        _ => &[],
    }
}

/// Ordered, de-duplicated candidates. `[0]` is the single best guess and the
/// only one ever sent over the network.
pub fn candidates(app: &str) -> Vec<String> {
    let mut out: Vec<String> = Vec::new();
    let mut add = |n: &str| {
        if !n.is_empty() && !out.iter().any(|x| x == n) {
            out.push(n.to_string());
        }
    };

    if let Some(a) = alias_for(app) {
        add(a);
    }
    add(app);
    let clean = sanitize(app);
    add(clean);
    if let Some(a) = alias_for(clean) {
        add(a);
    }
    let parts: Vec<&str> = clean.split('-').filter(|p| !p.is_empty()).collect();
    for end in (1..parts.len()).rev() {
        add(&parts[..end].join("-"));
    }
    for h in fallback_hints(app).iter().chain(fallback_hints(clean)) {
        add(h);
    }
    out
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn sanitize_strips_repeatedly() {
        assert_eq!(sanitize("foo-bin-git"), "foo");
        assert_eq!(sanitize("git"), "git");
        assert_eq!(sanitize("-bin"), "-bin");
    }

    #[test]
    fn candidate_order() {
        let c = candidates("libreoffice-fresh");
        assert_eq!(c[0], "libreoffice-main");
        assert_eq!(c[1], "libreoffice-fresh");
        assert!(c.contains(&"libreoffice".to_string()));
        let c = candidates("some-app-bin");
        assert_eq!(c, ["some-app-bin", "some-app", "some"]);
    }
}
