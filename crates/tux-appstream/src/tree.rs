//! The system's AppStream category tree.
//!
//! AppStream ships one default tree that maps freedesktop category ids
//! (`AudioVideo`, `Development`, `Graphics`…) to display categories with a
//! localized name, an icon and children. On Arch the tree is compiled into
//! `libappstream` (there is no `categories.xml` file to read), so the store
//! asks the library itself through `as_get_default_categories`.
//!
//! If libappstream cannot be loaded the store falls back to one auto-created
//! category per raw id — never to a hand-written table.

use std::ffi::CStr;
use std::os::raw::{c_char, c_void};

/// glib's `GPtrArray` (the only glib type crossing this boundary).
#[repr(C)]
struct GPtrArray {
    pdata: *mut *mut c_void,
    len: u32,
}

/// One node of the discovered tree.
#[derive(Debug, Clone, Default, PartialEq, Eq)]
pub struct TreeCategory {
    /// Unique inside the tree (`audio-video`, `games/strategy`…).
    pub id: String,
    pub title: String,
    pub icon: String,
    pub depth: u32,
    pub parent: String,
    /// Raw ids this node claims, exactly as the system data spells them
    /// (`AudioVideo`, `Development::IDE`, `Development:Debugger`…).
    pub groups: Vec<String>,
}

struct Api {
    name: unsafe extern "C" fn(*mut c_void) -> *const c_char,
    id: unsafe extern "C" fn(*mut c_void) -> *const c_char,
    icon: unsafe extern "C" fn(*mut c_void) -> *const c_char,
    children: unsafe extern "C" fn(*mut c_void) -> *mut GPtrArray,
    desktop_groups: unsafe extern "C" fn(*mut c_void) -> *mut GPtrArray,
}

/// The tree if libappstream answers, else an empty list.
pub fn categories() -> Vec<TreeCategory> {
    via_libappstream().unwrap_or_default()
}

unsafe fn slice<'a>(array: *mut GPtrArray) -> &'a [*mut c_void] {
    if array.is_null() {
        return &[];
    }
    let a = &*array;
    if a.pdata.is_null() || a.len == 0 {
        return &[];
    }
    std::slice::from_raw_parts(a.pdata, a.len as usize)
}

unsafe fn cstr(p: *const c_char) -> String {
    if p.is_null() {
        String::new()
    } else {
        CStr::from_ptr(p).to_string_lossy().into_owned()
    }
}

unsafe fn string_array(array: *mut GPtrArray) -> Vec<String> {
    slice(array)
        .iter()
        .map(|&p| cstr(p.cast::<c_char>()))
        .filter(|s| !s.is_empty())
        .collect()
}

unsafe fn walk(array: *mut GPtrArray, depth: u32, parent: &str, api: &Api, out: &mut Vec<TreeCategory>) {
    for &node in slice(array) {
        if node.is_null() {
            continue;
        }
        let local = cstr((api.id)(node));
        if local.is_empty() {
            continue;
        }
        let title = cstr((api.name)(node));
        let id = if parent.is_empty() { local } else { format!("{parent}/{local}") };
        out.push(TreeCategory {
            id: id.clone(),
            title,
            icon: cstr((api.icon)(node)),
            depth,
            parent: parent.to_string(),
            groups: string_array((api.desktop_groups)(node)),
        });
        let children = (api.children)(node);
        if !children.is_null() {
            walk(children, depth + 1, &id, api, out);
        }
    }
}

fn via_libappstream() -> Option<Vec<TreeCategory>> {
    let lib = ["libappstream.so.5", "libappstream.so.1", "libappstream.so"]
        .iter()
        .find_map(|name| {
            // SAFETY: loading a system library by its soname.
            unsafe { libloading::Library::new(name).ok() }
        })?;

    // SAFETY: every symbol below is part of AppStream's public C API
    // (`as_category.h`); the library outlives the read-only walk below.
    unsafe {
        let default_categories: libloading::Symbol<unsafe extern "C" fn(i32) -> *mut GPtrArray> =
            lib.get(b"as_get_default_categories\0").ok()?;
        let api = Api {
            name: *lib.get::<unsafe extern "C" fn(*mut c_void) -> *const c_char>(b"as_category_get_name\0").ok()?,
            id: *lib.get::<unsafe extern "C" fn(*mut c_void) -> *const c_char>(b"as_category_get_id\0").ok()?,
            icon: *lib.get::<unsafe extern "C" fn(*mut c_void) -> *const c_char>(b"as_category_get_icon\0").ok()?,
            children: *lib
                .get::<unsafe extern "C" fn(*mut c_void) -> *mut GPtrArray>(b"as_category_get_children\0")
                .ok()?,
            desktop_groups: *lib
                .get::<unsafe extern "C" fn(*mut c_void) -> *mut GPtrArray>(b"as_category_get_desktop_groups\0")
                .ok()?,
        };
        // No "special" categories (screensavers, shell extensions…): the store
        // lists applications, exactly like the reference behaviour.
        let roots = default_categories(0);
        if roots.is_null() {
            return None;
        }
        let mut out = Vec::new();
        walk(roots, 0, "", &api, &mut out);
        // The array is intentionally leaked: it belongs to a process-wide
        // default tree and is a few kilobytes.
        (!out.is_empty()).then_some(out)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn tree_comes_from_the_system() {
        // On a machine without libappstream this is empty and the store falls
        // back to raw ids; on Arch it must contain the usual top-level rows.
        let tree = categories();
        if tree.is_empty() {
            return;
        }
        assert!(tree.iter().any(|c| c.depth == 0));
        assert!(tree.iter().any(|c| !c.groups.is_empty()));
        assert!(tree.iter().any(|c| !c.title.is_empty()));
    }
}
