#!/bin/bash
command -v pkexec >/dev/null 2>&1 || { echo "The required tool 'pkexec' is missing."; exit 0; }
[ ! -e /var/lib/pacman/db.lck ] || { echo "pacman is locked (/var/lib/pacman/db.lck exists). Another package manager may be running."; exit 0; }
echo ""
