#!/bin/bash
code=$(curl -fsL --max-time 20 https://www.rarlab.com/download.htm 2>/dev/null | grep -o 'winrar-x64-[0-9]*\.exe' | head -n 1 | sed 's/^winrar-x64-//; s/\.exe$//')
# If the page could not be read, fall back to a known good release.
case "$code" in ''|*[!0-9]*) code=713 ;; esac
echo "$code"
