#!/bin/bash
# Version of the Proton VPN app in the sync databases of the user's own repositories.
v="$(pacman -Si proton-vpn-gtk-app 2>/dev/null | awk '/^Version/ {print $3; exit}')"
[ -z "$v" ] && v="$(pacman -Si proton-vpn-cli 2>/dev/null | awk '/^Version/ {print $3; exit}')"
printf '%s\n' "${v:-unknown}"
exit 0
