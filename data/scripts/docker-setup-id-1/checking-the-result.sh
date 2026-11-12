#!/bin/bash
bad=""
for p in $TUX_VAR_NEW_PKGS; do
  pacman -Qq "$p" >/dev/null 2>&1 || bad="$bad $p"
done
[ -z "$bad" ] || { echo "Not installed:$bad"; exit 1; }
systemctl is-enabled docker.service >/dev/null 2>&1 || { echo "The docker service is not enabled."; exit 1; }
echo ok
