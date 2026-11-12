use std::sync::{Mutex, MutexGuard, PoisonError};

/// Lock a mutex and keep going even if another thread panicked while holding
/// it. Everything guarded this way is a plain cache, so this is always safe.
pub fn lock<T>(m: &Mutex<T>) -> MutexGuard<'_, T> {
    m.lock().unwrap_or_else(PoisonError::into_inner)
}
