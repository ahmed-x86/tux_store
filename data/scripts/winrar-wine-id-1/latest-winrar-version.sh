#!/bin/bash
code=$(curl -fsL --max-time 15 https://www.rarlab.com/download.htm 2>/dev/null | grep -o 'winrar-x64-[0-9]*\.exe' | head -n 1 | sed 's/^winrar-x64-//; s/\.exe$//')
case "$code" in ''|*[!0-9]*) echo unknown; exit 0 ;; esac
a=${code%??}
printf '%s.%s\n' "$a" "${code#"$a"}"
