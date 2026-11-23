#!/bin/bash
# Prints the version of the first selected package, but only when ALL selected packages are installed.
first=""
for p in $TUX_VAR_PROTON_PKGS; do
    pacman -Qq "$p" >/dev/null 2>&1 || exit 0
    [ -z "$first" ] && first="$p"
done
[ -n "$first" ] && pacman -Q "$first" 2>/dev/null | awk '{print $2}'
exit 0
