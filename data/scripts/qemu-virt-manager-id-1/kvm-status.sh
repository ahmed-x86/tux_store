#!/bin/bash
# Prints a warning text when KVM acceleration is missing (empty when all is well).
if [ -e /dev/kvm ]; then echo ""; else
  echo "⚠ /dev/kvm is missing, so virtual machines would run without hardware acceleration (very slow). Enable Intel VT-x / AMD-V in your BIOS/UEFI and restart."
fi
