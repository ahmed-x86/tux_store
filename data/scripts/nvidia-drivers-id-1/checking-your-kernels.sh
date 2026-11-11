#!/bin/bash
# One "<pkgbase>-headers" per installed kernel (pkgbase comes from the kernel package itself).
pk=""
for f in /usr/lib/modules/*/pkgbase; do
  [ -r "$f" ] || continue
  pk="$pk $(cat "$f")"
done
pk=$(printf '%s\n' $pk | sort -u)
[ -n "$pk" ] || { echo "No installed kernel package was found."; exit 2; }
out=""; miss=""
for b in $pk; do
  case "$b" in *[!a-z0-9@._+-]*) echo "Unexpected kernel package name: $b"; exit 4 ;; esac
  if pacman -Si "$b-headers" >/dev/null 2>&1 || pacman -Qq "$b-headers" >/dev/null 2>&1; then
    out="$out $b-headers"
  else
    miss="$miss $b"
  fi
done
[ -z "$miss" ] || { echo "No headers package could be found for the kernel(s):$miss. The NVIDIA module cannot be built for them. Install their headers (or use the official linux / linux-lts kernels) and try again."; exit 3; }
echo $out
