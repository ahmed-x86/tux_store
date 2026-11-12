#!/bin/bash
P="${TUX_VAR_WINRAR_PREFIX:-${WINEPREFIX:-$HOME/.wine}}"
command -v wine >/dev/null 2>&1 || { echo "wine not found: skipping the registry cleanup"; exit 0; }
[ -d "$P/drive_c" ] || { echo "no Wine prefix: skipping the registry cleanup"; exit 0; }
export WINEPREFIX="$P" WINEDEBUG=-all WINEDLLOVERRIDES="mscoree,mshtml="
for k in 'HKCU\Software\WinRAR' 'HKLM\Software\WinRAR' 'HKLM\Software\Microsoft\Windows\CurrentVersion\Uninstall\WinRAR archiver'; do
  wine reg delete "$k" /f >/dev/null 2>&1 && echo "removed registry key $k"
done
wineserver -w 2>/dev/null || true
exit 0
