#!/bin/bash
set -e
[ -z "$TUX_VAR_NEW_PKGS" ] || pacman -S --needed --noconfirm $TUX_VAR_NEW_PKGS
