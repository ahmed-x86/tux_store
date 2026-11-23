#!/bin/bash
set -e
pkgs="$TUX_VAR_PROTON_PKGS $TUX_VAR_HELPER_PKGS"
pkgs="$(echo $pkgs)"   # squeeze spaces

if [ -z "$pkgs" ]; then
    echo "There is nothing to install."
    exit 1
fi

if [ -e /var/lib/pacman/db.lck ]; then
    echo "pacman is busy (/var/lib/pacman/db.lck exists). Close any other package manager and try again."
    exit 1
fi

echo "Installing: $pkgs"
pacman -S --needed --noconfirm $pkgs

if [ "${TUX_VAR_ENABLE_NM:-no}" = "yes" ]; then
    echo "Enabling NetworkManager…"
    systemctl enable --now NetworkManager
fi
