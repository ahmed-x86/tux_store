#!/bin/bash
# Prints only the packages that are still missing (one line, space separated).
want="$TUX_VAR_QEMU_PKGS libvirt dnsmasq $TUX_VAR_FRONTEND_PKGS $TUX_VAR_EXTRAS"
missing=""; unknown=""
for p in $want; do
  [[ "$p" =~ ^[a-z0-9@._+-]+$ ]] || { echo "Invalid package name: $p"; exit 1; }
  case " $missing " in *" $p "*) continue ;; esac
  if [ "$p" = "iptables-nft" ]; then
    pacman -T "$p" >/dev/null 2>&1 && continue      # already provided (maybe by "iptables")
  else
    pacman -Qq "$p" >/dev/null 2>&1 && continue
  fi
  pacman -Si "$p" >/dev/null 2>&1 || { unknown="$unknown $p"; continue; }
  missing="$missing $p"
done
if [ -n "$unknown" ]; then
  echo "These packages were not found in your repositories:$unknown"
  echo "Make sure the 'extra' repository is enabled in /etc/pacman.conf and your package databases are synced."
  exit 1
fi
printf '%s\n' "${missing# }"
