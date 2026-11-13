#!/bin/bash
# Removes peazip via pacman if it is still installed.
if pacman -Qq peazip >/dev/null 2>&1; then
  pacman -Rns --noconfirm peazip
else
  echo "peazip is not installed, nothing to remove."
fi
