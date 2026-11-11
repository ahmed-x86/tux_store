#!/bin/bash
set -e
[ -e /etc/pacman.d/mirrorlist.tux-backup ] || cp /etc/pacman.d/mirrorlist /etc/pacman.d/mirrorlist.tux-backup
reflector --latest 20 --protocol https --sort rate --save /etc/pacman.d/mirrorlist
