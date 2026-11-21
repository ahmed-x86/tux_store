#!/bin/bash
# yes = nested virtualization is already on (or already configured); no = off; unknown = module not loaded yet.
if grep -Erqs '^[[:space:]]*options[[:space:]]+kvm_(intel|amd)[[:space:]].*nested=(1|y|Y)' /etc/modprobe.d /usr/lib/modprobe.d 2>/dev/null; then echo yes; exit 0; fi
for m in kvm_intel kvm_amd; do
  f="/sys/module/$m/parameters/nested"
  if [ -r "$f" ]; then
    case "$(cat "$f")" in Y|y|1) echo yes ;; *) echo no ;; esac
    exit 0
  fi
done
echo unknown
