#!/bin/bash
[ -f "$TUX_VAR_WINE_PREFIX/drive_c/Program Files/WinRAR/WinRAR.exe" ] || { echo "WinRAR.exe was not found after the installation."; exit 1; }
echo ok
