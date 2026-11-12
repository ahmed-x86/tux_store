#!/bin/bash
y=0; p=0
command -v yay >/dev/null 2>&1 && y=1
command -v paru >/dev/null 2>&1 && p=1
if [ $y = 1 ] && [ $p = 1 ]; then echo both
elif [ $y = 1 ]; then echo yay
elif [ $p = 1 ]; then echo paru
else echo none; fi
