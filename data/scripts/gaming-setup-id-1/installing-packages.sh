#!/bin/bash
set -e
[ -n "$TUX_VAR_NEW_PKGS" ] || exit 0
# Steam needs a 32-bit Vulkan driver. With --noconfirm pacman silently takes the
# first provider in its list, which may not match this computer's GPU.
if ! pacman -Qq 2>/dev/null | grep -Eq '^lib32-(nvidia-utils|vulkan-radeon|vulkan-intel|vulkan-nouveau|amdvlk)$'; then
  gpu=$(lspci 2>/dev/null | grep -Ei 'vga|3d|display' || true)
  drv=""
  if echo "$gpu" | grep -qi nvidia; then
    if pacman -Qq nvidia-utils >/dev/null 2>&1; then drv="$drv lib32-nvidia-utils"; else drv="$drv lib32-vulkan-nouveau"; fi
  fi
  echo "$gpu" | grep -Eqi 'amd|ati|radeon' && drv="$drv lib32-vulkan-radeon"
  echo "$gpu" | grep -qi intel && drv="$drv lib32-vulkan-intel"
  [ -z "$drv" ] || pacman -S --needed --noconfirm $drv
fi
pacman -S --needed --noconfirm $TUX_VAR_NEW_PKGS
