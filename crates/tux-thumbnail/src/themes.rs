//! Zero-network icon lookup in the installed icon themes.
//!
//! Instead of indexing every file (tens of thousands) we only collect the
//! few hundred `…/apps` directories once, sorted by how close their size is
//! to 64 px (scalable first). A lookup is then a handful of `stat` calls.

use std::fs;
use std::path::{Path, PathBuf};
use tux_abi::paths;

pub struct ThemeDirs {
    dirs: Vec<PathBuf>,
}

impl ThemeDirs {
    pub fn discover() -> Self {
        let mut roots: Vec<PathBuf> = vec![
            paths::home().join(".local/share/icons"),
            paths::home().join(".icons"),
        ];
        match std::env::var_os("XDG_DATA_DIRS") {
            Some(dirs) => roots.extend(std::env::split_paths(&dirs).map(|d| d.join("icons"))),
            None => {
                roots.push(PathBuf::from("/usr/local/share/icons"));
                roots.push(PathBuf::from("/usr/share/icons"));
            }
        }

        let mut scored: Vec<(i64, PathBuf)> = Vec::new();
        for root in roots {
            let Ok(themes) = fs::read_dir(&root) else { continue };
            for theme in themes.flatten() {
                let path = theme.path();
                if path.is_dir() {
                    scan_theme(&path, &mut scored);
                }
            }
        }
        scored.sort_by(|a, b| b.0.cmp(&a.0));

        let mut dirs: Vec<PathBuf> = scored.into_iter().map(|(_, p)| p).collect();
        dirs.push(PathBuf::from("/usr/share/pixmaps"));
        dirs.push(PathBuf::from("/usr/local/share/pixmaps"));
        log::debug!("icon theme: {} directories indexed", dirs.len());
        Self { dirs }
    }

    pub fn find(&self, icon: &str) -> Option<PathBuf> {
        for dir in &self.dirs {
            for ext in ["svg", "png"] {
                let p = dir.join(format!("{icon}.{ext}"));
                if p.is_file() {
                    return Some(p);
                }
            }
        }
        None
    }
}

fn scan_theme(theme: &Path, out: &mut Vec<(i64, PathBuf)>) {
    let Ok(entries) = fs::read_dir(theme) else { return };
    for e in entries.flatten() {
        let p = e.path();
        let fname = e.file_name().to_string_lossy().into_owned();
        if fname == "apps" {
            // breeze style: <theme>/apps/<size>/
            if let Ok(sizes) = fs::read_dir(&p) {
                for s in sizes.flatten() {
                    let sp = s.path();
                    if sp.is_dir() {
                        out.push((score(&s.file_name().to_string_lossy()), sp));
                    }
                }
            }
        } else {
            // hicolor / Papirus style: <theme>/<size>/apps/
            let apps = p.join("apps");
            if apps.is_dir() {
                out.push((score(&fname), apps));
            }
        }
    }
}

fn score(size: &str) -> i64 {
    if size == "scalable" {
        return 1000;
    }
    let digits: String = size.chars().take_while(char::is_ascii_digit).collect();
    match digits.parse::<i64>() {
        Ok(n) if n > 0 => 500 - (n - 64).abs(),
        _ => 0,
    }
}
