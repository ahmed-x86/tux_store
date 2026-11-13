#!/bin/bash
cache="${XDG_CACHE_HOME:-$HOME/.cache}/tux-store/winrar"
rm -f "$cache/winrar-setup.exe"
rmdir "$cache" 2>/dev/null || true
exit 0
