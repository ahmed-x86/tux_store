//! The current local date and time (for log file names and headers).

use crate::logfile::Stamp;

/// Now, in the user's time zone. Falls back to the Unix epoch if the C
/// library cannot convert the time (never seen in practice).
pub fn now() -> Stamp {
    // SAFETY: `time` accepts a null pointer; `localtime_r` writes only into
    // the `tm` we own and reads the `time_t` we pass by reference.
    unsafe {
        let t: libc::time_t = libc::time(std::ptr::null_mut());
        let mut tm: libc::tm = std::mem::zeroed();
        if libc::localtime_r(&t, &mut tm).is_null() {
            return Stamp { year: 1970, month: 1, day: 1, hour: 0, min: 0, sec: 0 };
        }
        Stamp {
            year: tm.tm_year + 1900,
            month: (tm.tm_mon + 1).max(1) as u32,
            day: tm.tm_mday.max(1) as u32,
            hour: tm.tm_hour.max(0) as u32,
            min: tm.tm_min.max(0) as u32,
            sec: tm.tm_sec.clamp(0, 59) as u32,
        }
    }
}
