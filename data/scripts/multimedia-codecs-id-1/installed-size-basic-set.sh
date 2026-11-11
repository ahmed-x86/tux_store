#!/bin/bash
pacman -Si a52dec faac faad2 flac jasper lame libdca libdv libmad libmpeg2 libtheora libvorbis libxv wavpack x264 xvidcore 2>/dev/null | awk '/^Installed Size/ {v=$4; u=$5; if (u=="KiB") v/=1024; else if (u=="GiB") v*=1024; else if (u=="B") v/=1048576; t+=v} END {printf "%d\n", t+0.5}'
