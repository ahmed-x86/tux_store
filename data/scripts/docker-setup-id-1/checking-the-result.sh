#!/bin/bash
bad=""
for p in $TUX_VAR_NEW_PKGS; do
  pacman -Qq "$p" >/dev/null 2>&1 || bad="$bad $p"
done
[ -z "$bad" ] || { echo "Not installed:$bad"; exit 1; }
if [ -d /run/systemd/system ]; then
  systemctl is-enabled docker.service >/dev/null 2>&1 || { echo "The docker service is not enabled."; exit 1; }
elif command -v rc-update >/dev/null 2>&1 && command -v rc-service >/dev/null 2>&1; then
  rc-update show default 2>/dev/null | awk '{print $1}' | grep -qx docker || { echo "The docker service is not enabled."; exit 1; }
else
  echo "So far we do not support this init system write it in the issues https://github.com/ahmed-x86/tux_store/issues if you want it added"
  exit 1
fi
echo ok
