#!/bin/bash
set -e
if [ "$TUX_VAR_DRIVER" = "open" ]; then
  base="nvidia-open-dkms"
elif [ "$TUX_VAR_DRIVER" = "nvidia" ]; then
  base="nvidia-dkms"
fi
L32=""
if pacman -Sl multilib >/dev/null 2>&1; then L32="lib32-nvidia-utils"; fi
# --ask 4: let pacman replace conflicting NVIDIA packages inside ONE transaction,
# so the system is never left without a driver in between.
pacman -S --needed --noconfirm --ask 4 "$base" nvidia-utils nvidia-settings $L32
