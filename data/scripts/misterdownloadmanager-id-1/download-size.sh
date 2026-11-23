#!/bin/bash
# Prints the AppImage size in MB (rounded up) for the "Download size" line.
# Prints 0 when it cannot be found (the store then shows no size).
REPO="anefzaoui/misterdownloadmanager"
ver="$(bash "$(dirname "$0")/latest-version.sh" 2>/dev/null)"
if [ -z "$ver" ] || [ "$ver" = "unknown" ]; then echo 0; exit 0; fi

url="https://github.com/${REPO}/releases/download/v${ver}/MisterDownloadManager-${ver}-linux-x86_64.AppImage"
bytes="$(curl -sIL --max-time 15 "$url" 2>/dev/null | tr -d '\r' \
    | awk 'tolower($1)=="content-length:" {n=$2} END {print n+0}')"

if [ "${bytes:-0}" -gt 0 ] 2>/dev/null; then
    echo $(( (bytes + 1048575) / 1048576 ))
else
    echo 0
fi
exit 0
