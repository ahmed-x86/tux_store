#!/bin/bash
# Prints a message when something is wrong (the JSON branches on a non-empty output).
command -v pacman    >/dev/null 2>&1 || { echo "pacman was not found on this system."; exit 0; }
command -v systemctl >/dev/null 2>&1 || { echo "systemd (systemctl) was not found. Proton VPN needs NetworkManager running under systemd."; exit 0; }

if [ -z "$TUX_VAR_PROTON_PKGS" ]; then
    echo "Nothing is selected. Go back and tick the desktop app, the command-line tool, or both."
    exit 0
fi

for p in $TUX_VAR_PROTON_PKGS; do
    if ! pacman -Si "$p" >/dev/null 2>&1; then
        echo "The package “$p” was not found in your repositories. Make sure the [extra] repository is enabled and that your system is up to date (sudo pacman -Syu), then try again."
        exit 0
    fi
done

if [ -e /var/lib/pacman/db.lck ]; then
    echo "pacman is busy (/var/lib/pacman/db.lck exists). Close any other package manager and try again."
fi
exit 0
