//! Which package-manager backend answers queries and runs transactions.

use serde::{Deserialize, Serialize};

/// The two interchangeable engines.
///
/// `Direct` is the original backend: every question is answered by spawning
/// `pacman` with the matching command-line flags. `Libalpm` talks to libalpm
/// in-process (and through a small privileged helper for transactions), so it
/// needs no `pacman` process per query.
#[derive(Debug, Clone, Copy, Default, PartialEq, Eq, Serialize, Deserialize)]
#[repr(u8)]
#[serde(rename_all = "lowercase")]
pub enum Engine {
    /// `pacman -Ss`, `pacman -Si`, `pacman -S …` and friends.
    #[default]
    Direct,
    /// In-process libalpm.
    Libalpm,
}

impl Engine {
    /// Stable key used in `config.json` and in the Slint UI.
    pub fn key(self) -> &'static str {
        match self {
            Engine::Direct => "direct",
            Engine::Libalpm => "libalpm",
        }
    }

    pub fn from_key(key: &str) -> Option<Self> {
        match key {
            "direct" => Some(Engine::Direct),
            "libalpm" => Some(Engine::Libalpm),
            _ => None,
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn keys_roundtrip() {
        for e in [Engine::Direct, Engine::Libalpm] {
            assert_eq!(Engine::from_key(e.key()), Some(e));
        }
        assert_eq!(Engine::from_key("nope"), None);
    }

    #[test]
    fn serde_names() {
        assert_eq!(serde_json::to_string(&Engine::Libalpm).unwrap(), "\"libalpm\"");
        let e: Engine = serde_json::from_str("\"direct\"").unwrap();
        assert_eq!(e, Engine::Direct);
    }
}
