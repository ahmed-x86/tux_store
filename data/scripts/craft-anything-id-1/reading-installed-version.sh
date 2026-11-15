#!/bin/bash
pacman -Q craft-anything 2>/dev/null | awk '{print $2}'
exit 0
