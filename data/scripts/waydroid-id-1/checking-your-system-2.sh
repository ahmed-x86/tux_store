#!/bin/bash
[ "$(id -u)" -ne 0 ] || { echo "Tux Store is running as root. Start it as a normal user; it asks for the password only when needed."; exit 0; }
for t in pkexec pacman systemctl; do
  command -v "$t" >/dev/null 2>&1 || { echo "The required tool '$t' is missing."; exit 0; }
done
[ ! -e /var/lib/pacman/db.lck ] || { echo "pacman is locked (/var/lib/pacman/db.lck exists). Another package manager may be running. Wait for it to finish, then try again."; exit 0; }
echo ""
