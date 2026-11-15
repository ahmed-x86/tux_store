#!/bin/bash
set -e
BUILD_DIR="/tmp/tux-store-deckcraft-id-1"

PKG_FILE="$(ls "$BUILD_DIR"/native/*.pkg.tar.zst 2>/dev/null | head -n1)"
if [ -z "$PKG_FILE" ]; then
    echo "The downloaded package was not found."
    exit 1
fi

# The native package conflicts with the AppImage-wrapped one (same /usr/bin/deckcraft).
# Remove it first, but only when it really is ours (it ships /opt/deckcraft/deckcraft.AppImage).
if pacman -Qq deckcraft >/dev/null 2>&1 && [ -f /opt/deckcraft/deckcraft.AppImage ]; then
    echo "Removing the previously installed AppImage package first…"
    pacman -Rns --noconfirm deckcraft
fi

pacman -U --noconfirm "$PKG_FILE"
