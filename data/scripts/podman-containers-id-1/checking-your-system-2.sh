#!/bin/bash
command -v pkexec >/dev/null 2>&1 || { echo "The required tool 'pkexec' is missing."; exit 0; }
command -v pacman >/dev/null 2>&1 || { echo "The required tool 'pacman' is missing."; exit 0; }
[ ! -e /var/lib/pacman/db.lck ] || { echo "pacman is locked (/var/lib/pacman/db.lck exists). Another package manager may be running."; exit 0; }
if [ "$TUX_VAR_PURGE" != "yes" ] && command -v podman >/dev/null 2>&1 && [ -n "$(podman ps -q 2>/dev/null)" ]; then
  echo "Some containers are still running. Stop them first (podman stop --all), then try again."
  exit 0
fi
echo ""
