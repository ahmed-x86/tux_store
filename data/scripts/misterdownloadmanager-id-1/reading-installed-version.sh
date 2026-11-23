#!/bin/bash
# Prints the installed package version (empty when it is not installed).
pacman -Q misterdownloadmanager 2>/dev/null | awk '{print $2}'
exit 0
