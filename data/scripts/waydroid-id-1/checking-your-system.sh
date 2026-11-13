#!/bin/bash
[ "$(id -u)" -ne 0 ] || { echo "Tux Store is running as root. Start it as a normal user; it asks for the password only when needed."; exit 0; }
for t in pkexec pacman curl systemctl; do
  command -v "$t" >/dev/null 2>&1 || { echo "The required tool '$t' is missing."; exit 0; }
done
[ ! -e /var/lib/pacman/db.lck ] || { echo "pacman is locked (/var/lib/pacman/db.lck exists). Another package manager may be running. Wait for it to finish, then try again."; exit 0; }
[ "$XDG_SESSION_TYPE" != "x11" ] || { echo "You are in an X11 session. Waydroid needs a Wayland session. Log out and choose a Wayland session, then try again."; exit 0; }
pacman -Si waydroid >/dev/null 2>&1 || { echo "The 'waydroid' package was not found in your repositories. Make sure the [extra] repository is enabled and your package databases are synchronised."; exit 0; }
for dir in /var/lib "$HOME"; do
  avail=$(df -Pk "$dir" 2>/dev/null | awk 'NR==2 {print $4}')
  [ "${avail:-0}" -ge 3145728 ] || { echo "Less than 3 GiB of free space on the disk that holds $dir. Waydroid's Android image and data need room; free some space first."; exit 0; }
done
curl -fsI --max-time 10 https://archlinux.org >/dev/null 2>&1 || { echo "No internet connection (archlinux.org is unreachable)."; exit 0; }
echo ""
