#!/bin/bash
# Runs as root. Only undo what this install turned on.
if [ "$TUX_VAR_WAS_ENABLED" != "yes" ]; then
  systemctl disable --now libvirtd.service libvirtd.socket libvirtd-ro.socket libvirtd-admin.socket 2>/dev/null || true
  echo "libvirt services stopped and disabled."
else
  echo "libvirt was already enabled before this install; leaving it as it was."
fi
case " $TUX_VAR_RECORDED_PACKAGES " in
  *" cockpit "*) systemctl disable --now cockpit.socket 2>/dev/null || true; echo "cockpit.socket disabled." ;;
esac
exit 0
