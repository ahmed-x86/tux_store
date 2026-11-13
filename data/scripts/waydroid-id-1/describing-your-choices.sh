#!/bin/bash
out=""
for x in $TUX_VAR_EXTRAS; do
  case "$x" in
    keep_awake) t="keep Android awake" ;;
    reverse_scroll) t="reverse scrolling" ;;
    hotplug) t="direct access to plugged-in devices" ;;
    *) continue ;;
  esac
  out="${out:+$out, }$t"
done
printf '%s\n' "${out:-none}"
