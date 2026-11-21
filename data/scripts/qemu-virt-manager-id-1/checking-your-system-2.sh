#!/bin/bash
command -v pkexec >/dev/null 2>&1 || { echo "The required tool 'pkexec' is missing."; exit 0; }
command -v pacman >/dev/null 2>&1 || { echo "The required tool 'pacman' is missing."; exit 0; }
[ ! -e /var/lib/pacman/db.lck ] || { echo "pacman is locked (/var/lib/pacman/db.lck exists). Another package manager may be running."; exit 0; }
if pgrep -f '^(/usr/bin/)?qemu-system-' >/dev/null 2>&1; then
  echo "A virtual machine is still running. Shut it down first, then try again."
  exit 0
fi
echo ""
