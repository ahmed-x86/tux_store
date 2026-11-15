#!/bin/bash
pacman -Q gridcraft 2>/dev/null | awk '{print $2}'
exit 0
