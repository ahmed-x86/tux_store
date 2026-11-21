#!/bin/bash
set -e
[ -n "$TUX_VAR_NEW_PKGS" ] || { echo "Nothing to install."; exit 0; }
# --ask 4: let pacman replace conflicting packages (for example iptables -> iptables-nft)
# inside ONE transaction. -S without -y never refreshes the db alone (no partial upgrades).
# shellcheck disable=SC2086
pacman -S --needed --noconfirm --ask 4 $TUX_VAR_NEW_PKGS
