#!/bin/bash
# yes = the real Docker is installed (podman-docker would conflict with it).
if pacman -Qq docker >/dev/null 2>&1 || pacman -Qq docker-cli >/dev/null 2>&1; then echo yes; else echo no; fi
