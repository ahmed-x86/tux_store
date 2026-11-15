#!/bin/bash
pacman -Q effectcraft 2>/dev/null | awk '{print $2}'
exit 0
