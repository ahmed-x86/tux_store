//! Read the AppStream catalogs installed on this machine.
//!
//! Almost every Arch package has one AppStream component (`<pkgname>`,
//! `<name>`, `<summary>`, `<categories>`). The join key with pacman is
//! `<pkgname>` == package name. Nothing here is a fixed list: the catalog
//! files, the components and their categories are all discovered at runtime.

use flate2::read::GzDecoder;
use quick_xml::events::{BytesRef, Event};
use quick_xml::Reader;
use std::collections::BTreeMap;
use std::fs::File;
use std::io::{BufRead, BufReader};
use std::path::{Path, PathBuf};

/// One AppStream component as far as the store cares.
#[derive(Debug, Clone, Default, PartialEq, Eq, serde::Serialize, serde::Deserialize)]
pub struct Component {
    pub pkg: String,
    pub name: String,
    pub summary: String,
    pub categories: Vec<String>,
}

/// Catalog directories the skill lists. Every one that exists is scanned —
/// never assume a single path.
pub fn catalog_dirs() -> Vec<PathBuf> {
    ["/usr/share/swcatalog/xml", "/var/cache/swcatalog/xml", "/usr/share/app-info/xmls"]
        .iter()
        .map(PathBuf::from)
        .filter(|p| p.is_dir())
        .collect()
}

pub fn catalog_files() -> Vec<PathBuf> {
    let mut out = Vec::new();
    for dir in catalog_dirs() {
        let Ok(rd) = std::fs::read_dir(&dir) else { continue };
        let mut files: Vec<PathBuf> = rd
            .flatten()
            .map(|e| e.path())
            .filter(|p| {
                let name = p.file_name().and_then(|n| n.to_str()).unwrap_or("");
                (name.ends_with(".xml.gz") || name.ends_with(".xml")) && p.is_file()
            })
            .collect();
        files.sort(); // stable order: the first component for a package wins
        out.extend(files);
    }
    out
}

fn cache_key(files: &[PathBuf]) -> String {
    let mut key = String::new();
    for f in files {
        let (mtime, size) = std::fs::metadata(f)
            .ok()
            .map(|m| {
                let t = m
                    .modified()
                    .ok()
                    .and_then(|t| t.duration_since(std::time::UNIX_EPOCH).ok())
                    .map(|d| d.as_secs())
                    .unwrap_or(0);
                (t, m.len())
            })
            .unwrap_or((0, 0));
        key.push_str(&format!("{}:{mtime}:{size};", f.display()));
    }
    key
}

#[derive(serde::Serialize, serde::Deserialize)]
struct CacheFile {
    key: String,
    components: Vec<Component>,
}

/// Every component of every installed catalog, deduplicated by package name.
/// The parse reads ~8 MB gzipped XML, so the result is cached under
/// `~/.cache/tux-store/taxonomy/` until a catalog file changes.
pub fn load(cache_dir: &Path) -> Vec<Component> {
    let files = catalog_files();
    if files.is_empty() {
        return Vec::new();
    }
    let key = cache_key(&files);
    let cache = cache_dir.join("taxonomy").join("appstream-v1.json");
    if let Some(components) = read_cache(&cache, &key) {
        return components;
    }
    let components = parse_files(&files);
    write_cache(&cache, &key, &components);
    components
}

fn read_cache(path: &Path, key: &str) -> Option<Vec<Component>> {
    let text = std::fs::read_to_string(path).ok()?;
    let cached: CacheFile = serde_json::from_str(&text).ok()?;
    (cached.key == key).then_some(cached.components)
}

fn write_cache(path: &Path, key: &str, components: &[Component]) {
    let Some(dir) = path.parent() else { return };
    if std::fs::create_dir_all(dir).is_err() {
        return;
    }
    let file = CacheFile { key: key.to_string(), components: components.to_vec() };
    if let Ok(text) = serde_json::to_vec(&file) {
        let tmp = path.with_extension("tmp");
        if std::fs::write(&tmp, text).is_ok() {
            let _ = std::fs::rename(&tmp, path);
        }
    }
}

fn parse_files(files: &[PathBuf]) -> Vec<Component> {
    let mut merged: BTreeMap<String, Component> = BTreeMap::new();
    for file in files {
        let Ok(f) = File::open(file) else { continue };
        let reader: Box<dyn BufRead> = if file.extension().is_some_and(|e| e == "gz") {
            Box::new(BufReader::new(GzDecoder::new(f)))
        } else {
            Box::new(BufReader::new(f))
        };
        let mut found = Vec::new();
        if let Err(e) = parse_reader(reader, &mut found) {
            log::warn!("{}: {e}", file.display());
        }
        for c in found {
            merge(&mut merged, c);
        }
    }
    merged.into_values().collect()
}

fn merge(into: &mut BTreeMap<String, Component>, c: Component) {
    let entry = into.entry(c.pkg.clone()).or_insert_with(|| c.clone());
    if entry.name.is_empty() {
        entry.name = c.name;
    }
    if entry.summary.is_empty() {
        entry.summary = c.summary;
    }
    for cat in c.categories {
        if !entry.categories.contains(&cat) {
            entry.categories.push(cat);
        }
    }
}

#[derive(Clone, Copy, PartialEq, Eq)]
enum Field {
    Pkg,
    Name,
    Summary,
    Category,
}

fn has_lang(e: &quick_xml::events::BytesStart<'_>) -> bool {
    e.attributes().with_checks(false).flatten().any(|a| a.key.as_ref() == b"xml:lang")
}

fn entity_char(r: &BytesRef<'_>) -> Option<char> {
    let text = r.decode().ok()?;
    if let Some(num) = text.strip_prefix('#') {
        let value = match num.strip_prefix(['x', 'X']) {
            Some(hex) => u32::from_str_radix(hex, 16).ok()?,
            None => num.parse().ok()?,
        };
        return char::from_u32(value);
    }
    Some(match text.as_ref() {
        "amp" => '&',
        "lt" => '<',
        "gt" => '>',
        "quot" => '"',
        "apos" => '\'',
        _ => return None,
    })
}

/// Parse one catalog file. Only `desktop-application` and
/// `console-application` components are kept (the skill's rule).
fn parse_reader<R: BufRead>(reader: R, out: &mut Vec<Component>) -> Result<(), quick_xml::Error> {
    let mut xml = Reader::from_reader(reader);
    // Keep every byte of text events: `trim_text` would also eat the spaces
    // around entities (`htop &amp; friends`). Values are trimmed when stored.
    xml.config_mut().trim_text(false);
    let mut buf = Vec::new();
    let mut stack: Vec<Vec<u8>> = Vec::new();
    let mut cur = Component::default();
    let mut in_component = false;
    let mut keep = false;
    let mut field: Option<(Field, usize)> = None;
    let mut text = String::new();

    loop {
        match xml.read_event_into(&mut buf) {
            Ok(Event::Start(e)) => {
                let name = e.local_name().as_ref().to_vec();
                let parent = stack.last().map(Vec::as_slice).unwrap_or(b"");
                if name == b"component" {
                    in_component = true;
                    keep = e
                        .attributes()
                        .with_checks(false)
                        .flatten()
                        .find(|a| a.key.as_ref() == b"type")
                        .map(|a| a.value.as_ref().to_vec())
                        .is_some_and(|t| t == b"desktop-application" || t == b"console-application");
                    cur = Component::default();
                    field = None;
                } else if in_component && keep && field.is_none() {
                    let f = match name.as_slice() {
                        b"pkgname" if parent == b"component" => Some(Field::Pkg),
                        b"name" if parent == b"component" && !has_lang(&e) => Some(Field::Name),
                        b"summary" if parent == b"component" && !has_lang(&e) => Some(Field::Summary),
                        b"category" if parent == b"categories" => Some(Field::Category),
                        _ => None,
                    };
                    if let Some(f) = f {
                        field = Some((f, stack.len()));
                        text.clear();
                    }
                }
                stack.push(name);
            }
            Ok(Event::Empty(e)) => {
                // `<category/>` carries no text, nothing to collect.
                if e.local_name().as_ref() == b"component" {
                    in_component = false;
                    keep = false;
                    field = None;
                }
            }
            Ok(Event::Text(t)) => {
                if let Some((_, depth)) = field {
                    if depth + 1 == stack.len() {
                        if let Ok(s) = t.xml10_content() {
                            text.push_str(&s);
                        }
                    }
                }
            }
            Ok(Event::GeneralRef(r)) => {
                if let Some((_, depth)) = field {
                    if depth + 1 == stack.len() {
                        if let Some(ch) = entity_char(&r) {
                            text.push(ch);
                        }
                    }
                }
            }
            Ok(Event::End(e)) => {
                let name = e.local_name().as_ref().to_vec();
                if let Some((f, depth)) = field {
                    if stack.len() == depth + 1 {
                        let value = text.trim().to_string();
                        match f {
                            Field::Pkg => cur.pkg = value,
                            Field::Name => cur.name = value,
                            Field::Summary => cur.summary = value,
                            Field::Category if !value.is_empty() => cur.categories.push(value),
                            Field::Category => {}
                        }
                        field = None;
                        text.clear();
                    }
                }
                stack.pop();
                if name == b"component" {
                    if in_component && keep && !cur.pkg.is_empty() {
                        out.push(std::mem::take(&mut cur));
                    }
                    in_component = false;
                    keep = false;
                    field = None;
                }
            }
            Ok(Event::Eof) | Err(_) => break,
            _ => {}
        }
        buf.clear();
    }
    Ok(())
}

#[cfg(test)]
mod tests {
    use super::*;

    fn parse(text: &str) -> Vec<Component> {
        let mut out = Vec::new();
        parse_reader(BufReader::new(text.as_bytes()), &mut out).unwrap();
        out
    }

    #[test]
    fn components_keep_only_apps() {
        let xml = r#"<?xml version="1.0"?>
<components>
  <component type="desktop-application">
    <id>org.gimp.GIMP</id>
    <name>GNU Image Manipulation Program</name>
    <name xml:lang="fr">GIMP fr</name>
    <summary>Create images</summary>
    <pkgname>gimp</pkgname>
    <developer><name>Ignored developer</name></developer>
    <categories><category>Graphics</category><category>2DGraphics</category></categories>
    <description><p>Not a name</p></description>
  </component>
  <component type="addon">
    <name>Some addon</name>
    <pkgname>addon</pkgname>
    <categories><category>Graphics</category></categories>
  </component>
  <component type="console-application">
    <name>htop &amp; friends</name>
    <pkgname>htop</pkgname>
    <categories><category>System</category></categories>
  </component>
</components>"#;
        let c = parse(xml);
        assert_eq!(c.len(), 2);
        assert_eq!(c[0].pkg, "gimp");
        assert_eq!(c[0].name, "GNU Image Manipulation Program");
        assert_eq!(c[0].summary, "Create images");
        assert_eq!(c[0].categories, ["Graphics", "2DGraphics"]);
        assert_eq!(c[1].name, "htop & friends");
    }

    #[test]
    fn merge_unions_categories() {
        let mut map = BTreeMap::new();
        merge(
            &mut map,
            Component { pkg: "x".into(), name: "X".into(), summary: String::new(), categories: vec!["A".into()] },
        );
        merge(
            &mut map,
            Component { pkg: "x".into(), name: String::new(), summary: "s".into(), categories: vec!["A".into(), "B".into()] },
        );
        let c = &map["x"];
        assert_eq!(c.name, "X");
        assert_eq!(c.summary, "s");
        assert_eq!(c.categories, ["A", "B"]);
    }
}
