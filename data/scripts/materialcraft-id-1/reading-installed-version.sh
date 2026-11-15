#!/bin/bash
pacman -Q materialcraft 2>/dev/null | awk '{print $2}'
exit 0
