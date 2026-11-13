#!/bin/bash
set -e
case "$TUX_VAR_LANG_CODE" in ar) sfx=ar ;; *) sfx="" ;; esac
cache="${XDG_CACHE_HOME:-$HOME/.cache}/tux-store/winrar"
mkdir -p "$cache"
rm -f "$cache/winrar-setup.exe"
url="https://www.rarlab.com/rar/winrar-x64-${TUX_VAR_WINRAR_CODE}${sfx}.exe"
echo "Downloading $url"
curl -fL --retry 2 --connect-timeout 15 -o "$cache/winrar-setup.exe" "$url"
[ "$(head -c 2 "$cache/winrar-setup.exe")" = "MZ" ] || { echo "The downloaded file is not a Windows program."; exit 1; }
echo "Download finished."
