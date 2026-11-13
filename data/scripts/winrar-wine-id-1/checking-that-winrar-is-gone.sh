#!/bin/bash
P="${TUX_VAR_WINRAR_PREFIX:-${WINEPREFIX:-$HOME/.wine}}"
[ ! -f "$P/drive_c/Program Files/WinRAR/WinRAR.exe" ]
