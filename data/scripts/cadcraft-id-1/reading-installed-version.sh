#!/bin/bash
pacman -Q cadcraft 2>/dev/null | awk '{print $2}'
exit 0
