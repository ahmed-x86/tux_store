#!/bin/bash
pacman -Q vectorcraft 2>/dev/null | awk '{print $2}'
exit 0
