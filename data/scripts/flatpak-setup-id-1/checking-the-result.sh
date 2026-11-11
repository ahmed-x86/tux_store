#!/bin/bash
bad=""
for p in $TUX_VAR_NEW_PKGS; do
  pacman -Qq "$p" >/dev/null 2>&1 || bad="$bad $p"
done
[ -z "$bad" ] || { echo "Not installed:$bad"; exit 1; }
flatpak remotes --system --columns=name 2>/dev/null | grep -qx flathub || { echo "The Flathub remote was not added."; exit 1; }
echo ok
