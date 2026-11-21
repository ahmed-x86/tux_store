#!/bin/bash
v=$(pacman -Si podman 2>/dev/null | awk '/^Version/ {print $3; exit}')
printf '%s\n' "${v:-unknown}"
