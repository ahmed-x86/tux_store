//! Finds and `dlopen`s the `libtux_*.so` module libraries.

use crate::hub::LoadedModule;
use libloading::Library;
use std::ffi::{c_char, c_void, CStr};
use std::path::{Path, PathBuf};
use std::sync::atomic::AtomicBool;
use std::sync::Arc;
use tux_abi::{paths, HostApi};

/// Directories searched for modules, first hit wins:
/// `$TUX_MODULE_DIR`, the executable's own directory (cargo build tree),
/// `<exe>/../lib/tux-store` (installed prefix).
pub fn module_dir() -> Option<PathBuf> {
    let exe = paths::exe_dir();
    let mut candidates = Vec::new();
    if let Some(p) = std::env::var_os("TUX_MODULE_DIR") {
        candidates.push(PathBuf::from(p));
    }
    candidates.push(exe.clone());
    candidates.push(exe.join("../lib").join(paths::APP_DIR));
    candidates.into_iter().find(|d| !list_modules(d).is_empty())
}

pub fn list_modules(dir: &Path) -> Vec<PathBuf> {
    let mut v: Vec<PathBuf> = std::fs::read_dir(dir)
        .map(|rd| {
            rd.flatten()
                .map(|e| e.path())
                .filter(|p| {
                    p.extension().is_some_and(|e| e == "so")
                        && p.file_name()
                            .and_then(|n| n.to_str())
                            .is_some_and(|n| n.starts_with("libtux_"))
                })
                .collect()
        })
        .unwrap_or_default();
    v.sort();
    v
}

/// Load one module library and create its instance.
///
/// # Safety
/// Runs foreign initialisation code; the library must really be a Tux Store
/// module (it is identified by the exported `tux_module_*` symbols).
pub unsafe fn load(path: &Path, api: &HostApi) -> Result<LoadedModule, String> {
    let lib = Library::new(path).map_err(|e| format!("dlopen: {e}"))?;

    type AbiFn = unsafe extern "C" fn() -> u32;
    type NameFn = unsafe extern "C" fn() -> *const c_char;
    type CreateFn = unsafe extern "C" fn(*const HostApi) -> *mut c_void;
    type MessageFn = unsafe extern "C" fn(*mut c_void, *const u8, usize);
    type InstFn = unsafe extern "C" fn(*mut c_void);

    let abi = *lib
        .get::<AbiFn>(b"tux_module_abi_version\0")
        .map_err(|_| "not a Tux Store module (no tux_module_abi_version)".to_string())?;
    let v = abi();
    if v != tux_abi::ABI_VERSION {
        return Err(format!("ABI version {v}, host expects {}", tux_abi::ABI_VERSION));
    }

    let name_fn = *lib.get::<NameFn>(b"tux_module_name\0").map_err(|e| e.to_string())?;
    let main_loop_fn = *lib.get::<AbiFn>(b"tux_module_main_loop\0").map_err(|e| e.to_string())?;
    let create = *lib.get::<CreateFn>(b"tux_module_create\0").map_err(|e| e.to_string())?;
    let message = *lib.get::<MessageFn>(b"tux_module_message\0").map_err(|e| e.to_string())?;
    let run = *lib.get::<InstFn>(b"tux_module_run\0").map_err(|e| e.to_string())?;
    let destroy = *lib.get::<InstFn>(b"tux_module_destroy\0").map_err(|e| e.to_string())?;

    let name_ptr = name_fn();
    let name = if name_ptr.is_null() {
        "?".to_string()
    } else {
        CStr::from_ptr(name_ptr).to_string_lossy().into_owned()
    };
    let main_loop = main_loop_fn() != 0;

    let inst = create(api);
    if inst.is_null() {
        return Err("module failed to initialise".into());
    }

    // Never dlclose: Slint/winit leave thread-local destructors and global
    // state behind that must outlive any unloading. The OS reclaims it at exit.
    std::mem::forget(lib);

    Ok(LoadedModule { name, main_loop, inst, message, run, destroy, alive: AtomicBool::new(true) })
}

pub fn into_arc(m: LoadedModule) -> Arc<LoadedModule> {
    Arc::new(m)
}
