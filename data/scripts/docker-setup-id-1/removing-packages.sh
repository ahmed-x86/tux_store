#!/bin/bash
# Two passes: a package may only become removable after another one is gone.
for pass in 1 2; do
  for p in $TUX_VAR_RECORDED_PACKAGES; do
    pacman -Qq "$p" >/dev/null 2>&1 || continue
    if pacman -Rns --noconfirm "$p" >/dev/null 2>&1; then echo "removed $p"; elif [ "$pass" = 2 ]; then echo "kept $p (other software needs it)"; fi
  done
done
exit 0
