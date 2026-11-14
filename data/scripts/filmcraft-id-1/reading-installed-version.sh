#!/bin/bash
pacman -Q filmcraft 2>/dev/null | awk '{print $2}'
exit 0
