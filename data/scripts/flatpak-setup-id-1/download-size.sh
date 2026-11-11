#!/bin/bash
pacman -Si flatpak 2>/dev/null | awk '/^Download Size/ {v=$4; u=$5; if (u=="KiB") v/=1024; else if (u=="GiB") v*=1024; else if (u=="B") v/=1048576; t+=v} END {printf "%d\n", t+0.5}'
