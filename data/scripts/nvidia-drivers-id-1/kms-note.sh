#!/bin/bash
if grep -Eq '^[[:space:]]*HOOKS=.*[( ]kms[) ]' /etc/mkinitcpio.conf 2>/dev/null; then
  echo "Optional: your /etc/mkinitcpio.conf HOOKS contains 'kms'. Removing it keeps nouveau out of the initramfs (then run: sudo mkinitcpio -P)."
else
  echo ""
fi
