#!/bin/bash
# Prints the AUR packages that are not installed yet (one line, space separated).
missing=""
for p in $TUX_VAR_AUR_PKGS; do
  [[ "$p" =~ ^[a-z0-9@._+-]+$ ]] || { echo "Invalid package name: $p"; exit 1; }
  pacman -Qq "$p" >/dev/null 2>&1 && continue
  case " $missing " in *" $p "*) continue ;; esac
  missing="$missing $p"
done
printf '%s\n' "${missing# }"
