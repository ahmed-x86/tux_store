#!/bin/bash
# yes = "linger" (user services keep running without a login) was already on.
v=$(loginctl show-user "$(id -un)" -p Linger --value 2>/dev/null)
if [ "$v" = "yes" ]; then echo yes; else echo no; fi
