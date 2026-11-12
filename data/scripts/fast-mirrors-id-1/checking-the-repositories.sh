#!/bin/bash
out=""
for p in $TUX_VAR_PKGS; do
  pacman -Si "$p" >/dev/null 2>&1 || out="$out $p"
done
printf '%s\n' $out
