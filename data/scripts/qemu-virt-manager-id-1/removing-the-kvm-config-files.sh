#!/bin/bash
# Runs as root. Delete only the files we created, and only if they still carry our marker.
for want in /etc/modules-load.d/tux-store-kvm.conf /etc/modprobe.d/tux-store-kvm-nested.conf; do
  if { [ "$TUX_VAR_KVM_CONF" = "$want" ] || [ "$TUX_VAR_NESTED_CONF" = "$want" ]; } \
     && [ -f "$want" ] && grep -q '^# Added by Tux Store' "$want"; then
    rm -f -- "$want"; echo "removed $want"
  fi
done
exit 0
