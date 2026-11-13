#!/bin/bash
set -e
export WINEPREFIX="$TUX_VAR_WINE_PREFIX" WINEDEBUG=-all WINEDLLOVERRIDES="mscoree,mshtml="
cache="${XDG_CACHE_HOME:-$HOME/.cache}/tux-store/winrar"
wine "$cache/winrar-setup.exe" /S
wineserver -w 2>/dev/null || true
echo "The installer finished."
