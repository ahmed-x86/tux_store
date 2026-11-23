#!/bin/bash
# Download size (MB, rounded up) of both Proton VPN apps plus whatever they still need.
bytes="$(pacman -Sp --needed --print-format '%s' proton-vpn-gtk-app proton-vpn-cli 2>/dev/null \
    | awk '/^[0-9]+$/ {s+=$1} END {print s+0}')"
if [ "${bytes:-0}" -gt 0 ] 2>/dev/null; then
    echo $(( (bytes + 1048575) / 1048576 ))
else
    echo 0
fi
exit 0
