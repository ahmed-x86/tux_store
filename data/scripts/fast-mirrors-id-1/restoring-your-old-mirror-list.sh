#!/bin/bash
if [ -e /etc/pacman.d/mirrorlist.tux-backup ]; then mv -f /etc/pacman.d/mirrorlist.tux-backup /etc/pacman.d/mirrorlist && echo "restored"; fi
exit 0
