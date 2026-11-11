#!/bin/bash
command -v paccache >/dev/null 2>&1 || pacman -S --needed --noconfirm pacman-contrib
paccache -rk2 || true
o=$(pacman -Qdtq 2>/dev/null || true)
[ -z "$o" ] || pacman -Rns --noconfirm $o || true
journalctl --vacuum-time=2weeks >/dev/null 2>&1 || true
exit 0
