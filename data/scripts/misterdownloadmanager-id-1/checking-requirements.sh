#!/bin/bash
# Prints a message when something is missing (the JSON branches on a non-empty output).
missing=""
command -v curl     >/dev/null 2>&1 || missing="$missing curl"
command -v makepkg  >/dev/null 2>&1 || missing="$missing makepkg"
command -v fakeroot >/dev/null 2>&1 || missing="$missing fakeroot"
command -v pacman   >/dev/null 2>&1 || missing="$missing pacman"

if [ -n "$missing" ]; then
    echo "Missing required tools:$missing. Install them with: sudo pacman -S --needed base-devel curl"
fi
exit 0
