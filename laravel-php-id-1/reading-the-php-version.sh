#!/bin/bash
# Prints only the installed PHP version (e.g. 8.5.1). Fails if php does not run.
"$HOME/.config/herd-lite/bin/php" -r 'echo PHP_VERSION;'
