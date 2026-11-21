#!/bin/bash
# Download size in MB of podman and the dependencies that are still missing.
pacman -Sp --needed --print-format '%s' podman podman-compose 2>/dev/null | awk '{t+=$1} END {printf "%d\n", t/1048576+0.5}'
