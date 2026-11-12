#!/bin/bash
# Prints "yes" when php.new / Herd Lite is already installed for this user.
if [ -x "$HOME/.config/herd-lite/bin/php" ]; then echo yes; else echo no; fi
