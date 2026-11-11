#!/bin/bash
P="${TUX_VAR_WINRAR_PREFIX:-${WINEPREFIX:-$HOME/.wine}}"
dir="$P/drive_c/Program Files/WinRAR"
if [ -d "$P/drive_c" ] && [ -d "$dir" ]; then rm -rf -- "$dir"; echo "removed $dir"; fi
apps="$HOME/.local/share/applications"
for d in "$apps/wine/Programs/WinRAR" "$HOME/Desktop/WinRAR.desktop" "$HOME/Desktop/WinRAR.lnk"; do
  if [ -e "$d" ]; then rm -rf -- "$d"; echo "removed $d"; fi
done
# File-association launchers Wine created for WinRAR (only those that mention it).
for f in "$apps"/wine-extension-*.desktop "$apps"/wine/*.desktop; do
  [ -f "$f" ] || continue
  if grep -qi winrar "$f"; then rm -f -- "$f"; echo "removed $f"; fi
done
find "$apps" -maxdepth 3 -type f -iname '*winrar*.desktop' -delete 2>/dev/null
find "$HOME/.local/share/icons" -type f -iname '*winrar*' -delete 2>/dev/null
command -v update-desktop-database >/dev/null 2>&1 && update-desktop-database "$apps" 2>/dev/null
exit 0
