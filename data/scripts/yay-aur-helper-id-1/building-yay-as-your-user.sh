#!/bin/bash
set -e
d="${XDG_CACHE_HOME:-$HOME/.cache}/tux-store/yay-build"
rm -rf "$d"; mkdir -p "$d"
git clone --depth 1 https://aur.archlinux.org/yay.git "$d/yay"
cd "$d/yay"
makepkg -f --noconfirm
echo "$d/yay" > "$d/where"
