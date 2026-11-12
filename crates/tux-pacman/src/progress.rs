//! Turns pacman's streamed console output into a monotonic 0..1 fraction.
//!
//! pacman's phases, in order:
//!
//! 1. resolving / conflict checks            →  0 – 5 %
//! 2. `Retrieving packages` (percent bars)   →  5 – 50 %   weighted by size
//! 3. keyring / integrity / file-conflict / disk-space checks  → 50 – 70 %
//! 4. `(n/m) installing foo`                 → 70 – 96 %
//! 5. post-transaction hooks                 → 96 %
//!
//! The tracker never reports 100 %: only the real process exit may do that.

use std::collections::HashMap;
use tux_abi::text::strip_ansi;

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum Kind {
    Install,
    Remove,
    Upgrade,
}

const DOWNLOAD: (f64, f64) = (0.05, 0.50);
const INSTALL: (f64, f64) = (0.70, 0.96);
const REMOVE: (f64, f64) = (0.30, 0.90);
const CEILING: f64 = 0.98;

const INSTALL_MILESTONES: &[(&str, f64)] = &[
    ("synchronizing package databases", 0.01),
    ("starting full system upgrade", 0.02),
    ("resolving dependencies", 0.03),
    ("looking for conflicting packages", 0.04),
    ("checking keys in keyring", 0.50),
    ("checking package integrity", 0.54),
    ("loading package files", 0.58),
    ("checking for file conflicts", 0.62),
    ("checking available disk space", 0.66),
    ("processing package changes", 0.70),
    ("running post-transaction hooks", 0.96),
];

const REMOVE_MILESTONES: &[(&str, f64)] = &[
    ("checking dependencies", 0.15),
    ("processing package changes", 0.30),
    ("running post-transaction hooks", 0.92),
];

pub struct ProgressTracker {
    kind: Kind,
    /// package → weight (installed size) for packages we know about.
    weights: HashMap<String, u64>,
    total_weight: u64,
    /// `Packages (N)` summary line.
    package_count: Option<u32>,
    /// download progress per package/file, 0..1.
    downloads: HashMap<String, f64>,
    /// last `(n/m) installing|removing …` step.
    step: Option<(u32, u32)>,
    floor: f64,
    last: f64,
}

impl ProgressTracker {
    pub fn new(kind: Kind, weights: HashMap<String, u64>) -> Self {
        let total_weight = weights.values().sum();
        Self {
            kind,
            weights,
            total_weight,
            package_count: None,
            downloads: HashMap::new(),
            step: None,
            floor: 0.0,
            last: 0.0,
        }
    }

    /// Feed one logical line. Returns the new fraction if it increased.
    pub fn feed_line(&mut self, raw: &str) -> Option<f64> {
        let clean = strip_ansi(raw);
        let line = clean.trim();
        if line.is_empty() {
            return None;
        }
        let lower = line.to_lowercase();

        let table = if self.kind == Kind::Remove { REMOVE_MILESTONES } else { INSTALL_MILESTONES };
        for (phrase, floor) in table {
            if lower.contains(phrase) {
                self.floor = self.floor.max(*floor);
            }
        }

        if let Some(n) = parse_package_count(line) {
            self.package_count = Some(n);
        } else if let Some(step) = parse_step(&lower) {
            self.step = Some(step);
        } else if let Some(pct) = parse_percent(line) {
            self.credit_download(line, pct);
        }

        let v = self.value();
        if v > self.last + 1e-6 {
            self.last = v;
            Some(v)
        } else {
            None
        }
    }

    fn credit_download(&mut self, line: &str, pct: u32) {
        let Some(token) = line.split_whitespace().next() else {
            return;
        };
        let frac = f64::from(pct.min(100)) / 100.0;
        let key = if self.weights.is_empty() {
            // Unknown sizes (e.g. system upgrade): count files, but only after
            // the `Packages (N)` line so database-sync bars are not mistaken
            // for package downloads.
            if self.package_count.is_none() {
                return;
            }
            token.to_string()
        } else {
            match self.match_known(token) {
                Some(k) => k,
                None => return,
            }
        };
        let e = self.downloads.entry(key).or_insert(0.0);
        if frac > *e {
            *e = frac;
        }
    }

    /// Longest known package name that prefixes `token` (`name-1.2-3-x86_64`).
    fn match_known(&self, token: &str) -> Option<String> {
        self.weights
            .keys()
            .filter(|n| token == n.as_str() || token.starts_with(&format!("{n}-")))
            .max_by_key(|n| n.len())
            .cloned()
    }

    fn download_fraction(&self) -> f64 {
        if !self.weights.is_empty() && self.total_weight > 0 {
            let done: f64 = self
                .downloads
                .iter()
                .map(|(name, pct)| *pct * self.weights.get(name).copied().unwrap_or(0) as f64)
                .sum();
            (done / self.total_weight as f64).clamp(0.0, 1.0)
        } else if let Some(n) = self.package_count.filter(|n| *n > 0) {
            let done: f64 = self.downloads.values().sum();
            (done / f64::from(n)).clamp(0.0, 1.0)
        } else {
            0.0
        }
    }

    fn value(&self) -> f64 {
        let mut v = self.floor;
        let band = |(lo, hi): (f64, f64), f: f64| lo + (hi - lo) * f;
        match self.kind {
            Kind::Remove => {
                if let Some((n, m)) = self.step.filter(|(_, m)| *m > 0) {
                    v = v.max(band(REMOVE, f64::from(n.saturating_sub(1)) / f64::from(m)));
                }
            }
            Kind::Install | Kind::Upgrade => {
                v = v.max(band(DOWNLOAD, self.download_fraction()));
                if let Some((n, m)) = self.step.filter(|(_, m)| *m > 0) {
                    v = v.max(band(INSTALL, f64::from(n.saturating_sub(1)) / f64::from(m)));
                }
            }
        }
        v.clamp(0.0, CEILING)
    }
}

/// `"Packages (3) a-1-1  b-2-1"` → `3`.
fn parse_package_count(line: &str) -> Option<u32> {
    let rest = line.strip_prefix("Packages (")?;
    rest.split(')').next()?.trim().parse().ok()
}

/// `"(2/5) installing foo"` → `(2, 5)`; only transaction verbs count, so
/// `"(1/5) checking keys…"` and hook lines are ignored. `lower` must be lowercase.
fn parse_step(lower: &str) -> Option<(u32, u32)> {
    let inner = lower.strip_prefix('(')?;
    let close = inner.find(')')?;
    let (a, b) = inner[..close].split_once('/')?;
    let rest = inner[close + 1..].trim_start();
    const VERBS: [&str; 5] = ["installing ", "upgrading ", "reinstalling ", "downgrading ", "removing "];
    if !VERBS.iter().any(|v| rest.starts_with(v)) {
        return None;
    }
    Some((a.trim().parse().ok()?, b.trim().parse().ok()?))
}

/// Trailing `NN%` of a pacman progress bar line.
fn parse_percent(line: &str) -> Option<u32> {
    let t = line.trim_end().strip_suffix('%')?;
    let start = t
        .char_indices()
        .rev()
        .take_while(|(_, c)| c.is_ascii_digit())
        .last()
        .map(|(i, _)| i)?;
    t[start..].parse().ok()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn parsers() {
        assert_eq!(parse_package_count("Packages (3) a-1-1  b-2-1"), Some(3));
        assert_eq!(parse_step("(2/5) installing foo"), Some((2, 5)));
        assert_eq!(parse_step("(1/5) checking keys in keyring"), None);
        assert_eq!(parse_percent(" foo-1-1-x86_64  1.0 MiB  [####] 45%"), Some(45));
        assert_eq!(parse_percent("no percent here"), None);
    }

    #[test]
    fn install_flow_is_monotonic_and_never_done() {
        let mut w = HashMap::new();
        w.insert("foo".to_string(), 1000u64);
        w.insert("bar".to_string(), 3000u64);
        let mut t = ProgressTracker::new(Kind::Install, w);
        let lines = [
            "resolving dependencies...",
            "Packages (2) bar-1.0-1  foo-2.0-1",
            "foo-2.0-1-x86_64   1.0 KiB  [####] 100%",
            "bar-1.0-1-x86_64   3.0 KiB  [##  ] 50%",
            "(1/2) checking keys in keyring",
            "(1/2) installing foo",
            "(2/2) installing bar",
            "running post-transaction hooks",
        ];
        let mut last = 0.0;
        for l in lines {
            if let Some(v) = t.feed_line(l) {
                assert!(v > last, "{l}: {v} <= {last}");
                last = v;
            }
        }
        assert!(last >= 0.9 && last <= CEILING);
    }

    #[test]
    fn remove_flow() {
        let mut t = ProgressTracker::new(Kind::Remove, HashMap::new());
        let a = t.feed_line("checking dependencies...").unwrap();
        let b = t.feed_line("(1/1) removing foo").unwrap();
        assert!(b > a);
    }
}
