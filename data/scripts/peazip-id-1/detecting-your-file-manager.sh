#!/bin/bash
# Prints the default file manager: nautilus nemo caja thunar dolphin pcmanfm (or nothing).
d=$(xdg-mime query default inode/directory 2>/dev/null | tr 'A-Z' 'a-z')
case "$d" in
  *nautilus*) echo nautilus; exit 0 ;;
  *nemo*)     echo nemo; exit 0 ;;
  *caja*)     echo caja; exit 0 ;;
  *thunar*)   echo thunar; exit 0 ;;
  *dolphin*)  echo dolphin; exit 0 ;;
  *pcmanfm*)  echo pcmanfm; exit 0 ;;
esac
# Fallback: guess from the desktop environment.
de=$(printf '%s' "${XDG_CURRENT_DESKTOP:-}" | tr 'A-Z' 'a-z')
case "$de" in
  *gnome*)        echo nautilus ;;
  *cinnamon*)     echo nemo ;;
  *mate*)         echo caja ;;
  *xfce*)         echo thunar ;;
  *kde*)          echo dolphin ;;
  *lxqt*|*lxde*) echo pcmanfm ;;
esac
exit 0
