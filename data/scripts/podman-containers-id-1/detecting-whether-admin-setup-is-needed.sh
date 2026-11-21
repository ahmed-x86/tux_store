#!/bin/bash
# yes = some step needs administrator rights (so the password dialog is worth showing).
need=no
[ -z "$TUX_VAR_SUBID_NEW" ] || need=yes
case " $TUX_VAR_SETUP " in
  *" ports "*)
    cur=$(cat /proc/sys/net/ipv4/ip_unprivileged_port_start 2>/dev/null || echo 1024)
    [ "$cur" -le 80 ] || need=yes ;;
esac
case " $TUX_VAR_SETUP " in
  *" linger "*) [ "$TUX_VAR_WAS_LINGER" = "yes" ] || need=yes ;;
esac
echo "$need"
