#!/bin/bash
# Prints the installed Podman version (empty if Podman is not installed).
pacman -Q podman 2>/dev/null | awk '{print $2}'
exit 0
