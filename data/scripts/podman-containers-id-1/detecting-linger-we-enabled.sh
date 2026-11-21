#!/bin/bash
case " $TUX_VAR_SETUP " in *" linger "*) ;; *) echo no; exit 0 ;; esac
[ "$TUX_VAR_WAS_LINGER" != "yes" ] || { echo no; exit 0; }
v=$(loginctl show-user "$(id -un)" -p Linger --value 2>/dev/null)
if [ "$v" = "yes" ]; then echo yes; else echo no; fi
