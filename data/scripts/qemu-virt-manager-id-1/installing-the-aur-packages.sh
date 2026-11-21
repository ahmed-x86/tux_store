#!/bin/bash
set -e
[ -n "$TUX_VAR_NEW_AUR" ] || { echo "Nothing to install."; exit 0; }
for p in $TUX_VAR_NEW_AUR; do
  case "$p" in virtio-win|quickgui-bin|quickemu) ;; *) echo "Unexpected AUR package: $p"; exit 2 ;; esac
done
# yay must run as a normal user; --sudo pkexec makes it ask for the password in a graphical dialog.
# shellcheck disable=SC2086
yay -S --needed --noconfirm --ask 4 --sudo pkexec \
  --answerclean None --answerdiff None --answeredit None --answerupgrade None \
  $TUX_VAR_NEW_AUR
