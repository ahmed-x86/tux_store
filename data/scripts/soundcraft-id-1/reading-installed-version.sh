#!/bin/bash
pacman -Q soundcraft 2>/dev/null | awk '{print $2}'
exit 0
