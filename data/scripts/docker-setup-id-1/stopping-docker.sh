#!/bin/bash
if [ -d /run/systemd/system ]; then
  systemctl disable --now docker.service docker.socket >/dev/null 2>&1 || true
elif command -v rc-update >/dev/null 2>&1 && command -v rc-service >/dev/null 2>&1; then
  rc-service docker stop >/dev/null 2>&1 || true
  rc-update del docker default >/dev/null 2>&1 || true
else
  echo "So far we do not support this init system write it in the issues https://github.com/ahmed-x86/tux_store/issues if you want it added"
  exit 1
fi
if [ -n "${PKEXEC_UID:-}" ]; then u=$(id -nu "$PKEXEC_UID"); gpasswd -d "$u" docker >/dev/null 2>&1 || true; fi
exit 0
