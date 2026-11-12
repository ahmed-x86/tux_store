//! Tiny persistent user settings (`~/.config/tux-store/config.json`).

use serde::{Deserialize, Serialize};
use std::fs;
use tux_abi::paths;

#[derive(Debug, Clone, Serialize, Deserialize)]
pub struct Config {
    #[serde(default = "default_dark")]
    pub dark: bool,
}

fn default_dark() -> bool {
    true
}

impl Default for Config {
    fn default() -> Self {
        Config { dark: true }
    }
}

fn file() -> std::path::PathBuf {
    paths::config_dir().join("config.json")
}

pub fn load() -> Config {
    fs::read_to_string(file())
        .ok()
        .and_then(|t| serde_json::from_str(&t).ok())
        .unwrap_or_default()
}

pub fn save(cfg: &Config) {
    let path = file();
    if let Some(dir) = path.parent() {
        let _ = fs::create_dir_all(dir);
    }
    match serde_json::to_string_pretty(cfg) {
        Ok(text) => {
            if let Err(e) = fs::write(&path, text) {
                log::warn!("cannot save settings: {e}");
            }
        }
        Err(e) => log::warn!("cannot encode settings: {e}"),
    }
}
