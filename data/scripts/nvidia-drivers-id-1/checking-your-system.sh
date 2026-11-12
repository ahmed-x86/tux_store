#!/bin/bash
[ "$(id -u)" -ne 0 ] || { echo "Tux Store is running as root. yay refuses to build packages as root, so start Tux Store as a normal user."; exit 0; }
for t in lspci pkexec script curl pacman; do
  command -v "$t" >/dev/null 2>&1 || { echo "The required tool '$t' is missing (lspci comes from the 'pciutils' package)."; exit 0; }
done
[ ! -e /var/lib/pacman/db.lck ] || { echo "pacman is locked (/var/lib/pacman/db.lck exists). Another package manager may be running. Wait for it to finish, then try again."; exit 0; }
[ -d "/usr/lib/modules/$(uname -r)" ] || { echo "The kernel you are running ($(uname -r)) was replaced by an update and its modules are gone. Restart your computer first, then run this again."; exit 0; }
avail=$(df -Pk / | awk 'NR==2 {print $4}')
[ "${avail:-0}" -ge 4194304 ] || { echo "Less than 4 GiB of free space on /. Free some space first: building a kernel module needs room."; exit 0; }
n=$(pacman -Qu 2>/dev/null | wc -l)
[ "$n" -eq 0 ] || { echo "$n package update(s) are waiting. Update your system first (Updates tab), restart if the kernel was updated, then run this again. Installing drivers on a half-updated system can break the graphics stack."; exit 0; }
curl -fsI --max-time 10 https://archlinux.org >/dev/null 2>&1 || { echo "No internet connection (archlinux.org is unreachable)."; exit 0; }
echo ""
