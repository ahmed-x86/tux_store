#!/bin/bash
# Every installed kernel must now have an NVIDIA module (DKMS can fail without failing pacman).
bad=""
for f in /usr/lib/modules/*/pkgbase; do
  [ -r "$f" ] || continue
  v=${f%/pkgbase}; v=${v##*/}
  modinfo -k "$v" nvidia >/dev/null 2>&1 || bad="$bad $v"
done
[ -z "$bad" ] || { echo "The NVIDIA kernel module was NOT built for:$bad"; exit 1; }
echo ok
