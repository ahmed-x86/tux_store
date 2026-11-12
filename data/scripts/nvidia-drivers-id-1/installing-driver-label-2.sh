#!/bin/bash
set -e
B="$TUX_VAR_DRIVER"
case "$B" in 580xx|470xx|390xx|340xx) ;; *) echo "Unexpected driver branch: $B"; exit 2 ;; esac
L32=""
if pacman -Sl multilib >/dev/null 2>&1; then L32="lib32-nvidia-$B-utils"; fi
# yay must run as a normal user; --sudo pkexec makes it ask for the password in a graphical dialog.
yay -S --needed --noconfirm --ask 4 --sudo pkexec \
  --answerclean None --answerdiff None --answeredit None --answerupgrade None \
  "nvidia-$B-dkms" "nvidia-$B-utils" "nvidia-$B-settings" $L32
