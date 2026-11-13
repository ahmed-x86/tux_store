#!/bin/bash
pacman -Q paper-desktop 2>/dev/null | awk '{print $2}'
exit 0
