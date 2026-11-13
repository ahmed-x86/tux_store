#!/bin/bash
# Normal user: downloads the AUR snapshot and builds the package (makepkg refuses to run as root).
set -e
[ "$(id -u)" -ne 0 ] || { echo "Must not run as root."; exit 1; }
B="$HOME/.cache/tux-store/waydroid-nvidia-bin"
rm -rf "$B"
mkdir -p "$(dirname "$B")"
git clone --depth 1 https://aur.archlinux.org/waydroid-nvidia-bin.git "$B"
cd "$B"
# --nodeps: runtime dependencies are resolved by pacman when the package is installed
makepkg -f --nodeps --noconfirm
ls ./*.pkg.tar.* >/dev/null 2>&1 || { echo "makepkg did not produce a package."; exit 1; }
