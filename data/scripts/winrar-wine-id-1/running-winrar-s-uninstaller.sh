#!/bin/bash
P="${TUX_VAR_WINRAR_PREFIX:-${WINEPREFIX:-$HOME/.wine}}"
export WINEPREFIX="$P" WINEDEBUG=-all WINEDLLOVERRIDES="mscoree,mshtml="
exe="$P/drive_c/Program Files/WinRAR/uninstall.exe"
if [ -f "$exe" ]; then
  wine "$exe" /S || echo "The uninstaller reported an error."
  wineserver -w 2>/dev/null || true
  sleep 2
else
  echo "uninstall.exe was not found."
fi
exit 0
