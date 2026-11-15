#!/bin/bash
pacman -Q photocraft 2>/dev/null | awk '{print $2}'
exit 0
