#!/bin/bash
# Root: installs the package built by building-waydroid-nvidia.sh. It replaces/conflicts with waydroid.
set -e
H=$(getent passwd "${PKEXEC_UID:-}" 2>/dev/null | cut -d: -f6)
[ -n "$H" ] && [ "$H" != "/" ] || { echo "Could not find your home folder."; exit 1; }
B="$H/.cache/tux-store/waydroid-nvidia-bin"
set -- "$B"/*.pkg.tar.*
[ -e "$1" ] || { echo "The built package was not found in $B."; exit 1; }
# --ask 4: answer "yes" to removing the conflicting official waydroid package
pacman -U --needed --noconfirm --ask 4 "$1"
rm -rf "$B"
