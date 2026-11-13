#!/bin/bash
# Prints the name of the first non-NVIDIA display device (Intel / AMD integrated graphics), or nothing.
for d in /sys/bus/pci/devices/*; do
  [ -r "$d/class" ] && [ -r "$d/vendor" ] || continue
  case "$(cat "$d/class")" in 0x03*) ;; *) continue ;; esac
  [ "$(cat "$d/vendor")" != "0x10de" ] || continue
  n=$(lspci -s "${d##*/}" -mm 2>/dev/null | awk -F'"' '{print $4" "$6}')
  printf '%s\n' "${n:-Integrated graphics}"
  exit 0
done
echo ""
