#!/bin/bash
pacman -Q figcraft 2>/dev/null | awk '{print $2}'
exit 0
