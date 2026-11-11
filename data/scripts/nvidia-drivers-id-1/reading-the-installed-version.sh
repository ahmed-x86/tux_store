#!/bin/bash
case "$TUX_VAR_DRIVER" in open) p=nvidia-utils ;; *) p="nvidia-$TUX_VAR_DRIVER-utils" ;; esac
pacman -Q "$p" 2>/dev/null | awk '{print $2}'
