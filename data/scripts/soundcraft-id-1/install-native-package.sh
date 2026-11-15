#!/bin/bash
set -e
BUILD_DIR="/tmp/tux-store-soundcraft-id-1"

PKG_FILE="$(ls "$BUILD_DIR"/native/*.pkg.tar.zst 2>/dev/null | head -n1)"
if [ -z "$PKG_FILE" ]; then
    echo "The downloaded package was not found."
    exit 1
fi

# The native package conflicts with the AppImage-wrapped one (same /usr/bin/soundcraft).
# Remove it first, but only when it really is ours (it ships /opt/soundcraft/soundcraft.AppImage).
if pacman -Qq soundcraft >/dev/null 2>&1 && [ -f /opt/soundcraft/soundcraft.AppImage ]; then
    echo "Removing the previously installed AppImage package first…"
    pacman -Rns --noconfirm soundcraft
fi

pacman -U --noconfirm "$PKG_FILE"
