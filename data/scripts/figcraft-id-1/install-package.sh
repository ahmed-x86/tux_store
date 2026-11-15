#!/bin/bash
set -e
BUILD_DIR="/tmp/tux-store-figcraft-id-1"

PKG_FILE="$(ls "$BUILD_DIR"/figcraft-*-x86_64.pkg.tar.zst 2>/dev/null | head -n1)"
if [ -z "$PKG_FILE" ]; then
    echo "The built package was not found."
    exit 1
fi

# The official native package (ai.storyteller.*) conflicts with this one.
# If it is installed, remove it first.
OWNER="$(pacman -Qqo /usr/bin/figcraft 2>/dev/null || true)"
case "$OWNER" in
    ai.storyteller.*)
        echo "Removing the previously installed native package ($OWNER) first…"
        pacman -Rns --noconfirm "$OWNER"
        ;;
esac

pacman -U --noconfirm "$PKG_FILE"
