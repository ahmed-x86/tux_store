#!/bin/bash
P="${TUX_VAR_WINRAR_PREFIX:-${WINEPREFIX:-$HOME/.wine}}"
export WINEPREFIX="$P" WINEDEBUG=-all WINEDLLOVERRIDES="mscoree,mshtml="
wine uninstaller
wineserver -w 2>/dev/null || true
exit 0
