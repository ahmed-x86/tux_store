#!/bin/bash
# Two passes: a package may only become removable after another one is gone.
for pass in 1 2; do
  for p in $TUX_VAR_RECORDED_PACKAGES; do
    pacman -Qq "$p" >/dev/null 2>&1 || continue
    pacman -Rns --noconfirm "$p" >/dev/null 2>&1 && echo "removed $p"
  done
done
exit 0
