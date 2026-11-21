#!/bin/bash
case " $TUX_VAR_SETUP " in *" socket "*) ;; *) echo no; exit 0 ;; esac
[ "$TUX_VAR_WAS_SOCKET" != "yes" ] || { echo no; exit 0; }
if systemctl --user is-enabled --quiet podman.socket 2>/dev/null; then echo yes; else echo no; fi
