#!/bin/bash
# Root: installs the tools needed to build an AUR package.
set -e
pacman -S --needed --noconfirm base-devel git
