#!/bin/bash
# TUX_VAR_METHOD: "appimage" (wrap the AppImage with makepkg) or "native" (official .pkg.tar.zst)
missing=""
command -v curl >/dev/null 2>&1 || missing="$missing curl"

if [ "${TUX_VAR_METHOD:-appimage}" = "native" ]; then
    command -v pacman >/dev/null 2>&1 || missing="$missing pacman"
    hint="sudo pacman -S --needed curl"
else
    command -v makepkg  >/dev/null 2>&1 || missing="$missing makepkg"
    command -v fakeroot >/dev/null 2>&1 || missing="$missing fakeroot"
    hint="sudo pacman -S --needed base-devel curl"
fi

if [ -n "$missing" ]; then
    echo "Missing required tools:$missing. Install them with: $hint"
fi
exit 0
