#!/bin/bash
set -e
u=$(id -nu "${PKEXEC_UID:-0}")
h=$(getent passwd "$u" | cut -d: -f6)
pacman -U --noconfirm "$h"/.cache/tux-store/yay-build/yay/yay-*.pkg.tar.zst
rm -rf "$h/.cache/tux-store/yay-build"
