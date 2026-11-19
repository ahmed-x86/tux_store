#!/bin/bash
set -e
if [ -d /run/systemd/system ]; then
  systemctl enable --now docker.service
elif command -v rc-update >/dev/null 2>&1 && command -v rc-service >/dev/null 2>&1; then
  rc-update add docker default
  rc-service docker start
else
  echo "So far we do not support this init system write it in the issues https://github.com/ahmed-x86/tux_store/issues if you want it added"
  exit 1
fi
if [ -n "${PKEXEC_UID:-}" ]; then u=$(id -nu "$PKEXEC_UID"); usermod -aG docker "$u"; echo "added $u to the docker group"; fi
