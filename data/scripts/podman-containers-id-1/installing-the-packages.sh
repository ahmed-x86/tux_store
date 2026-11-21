#!/bin/bash
set -e
[ -n "$TUX_VAR_NEW_PKGS" ] || { echo "Nothing to install."; exit 0; }
# No --ask: if a package conflicts with something installed, pacman refuses (the safe answer).
# -S without -y never refreshes the db alone (no partial upgrades).
# shellcheck disable=SC2086
pacman -S --needed --noconfirm $TUX_VAR_NEW_PKGS
