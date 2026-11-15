#!/bin/bash
set -e
BUILD_DIR="/tmp/tux-store-designcraft-id-1"

PKG_FILE="$(ls "$BUILD_DIR"/native/*.pkg.tar.zst 2>/dev/null | head -n1)"
if [ -z "$PKG_FILE" ]; then
    echo "The downloaded package was not found."
    exit 1
fi

# The native package conflicts with the AppImage-wrapped one (same /usr/bin/designcraft).
# Remove it first, but only when it really is ours (it ships /opt/designcraft/designcraft.AppImage).
if pacman -Qq designcraft >/dev/null 2>&1 && [ -f /opt/designcraft/designcraft.AppImage ]; then
    echo "Removing the previously installed AppImage package first…"
    pacman -Rns --noconfirm designcraft
fi

pacman -U --noconfirm "$PKG_FILE"
