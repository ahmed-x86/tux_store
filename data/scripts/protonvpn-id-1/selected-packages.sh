#!/bin/bash
# TUX_VAR_COMPONENTS holds the ticked options ("gui", "cli"); prints the matching pacman packages.
out=""
for c in $TUX_VAR_COMPONENTS; do
    case "$c" in
        gui) out="$out proton-vpn-gtk-app" ;;
        cli) out="$out proton-vpn-cli" ;;
    esac
done
printf '%s\n' "${out# }"
exit 0
