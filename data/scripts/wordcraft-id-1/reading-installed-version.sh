#!/bin/bash
pacman -Q wordcraft 2>/dev/null | awk '{print $2}'
exit 0
