#!/bin/bash
v="$TUX_VAR_WINRAR_CODE"
a=${v%??}
printf '%s.%s\n' "$a" "${v#"$a"}"
