#!/bin/bash
qemu-system-x86_64 --version 2>/dev/null | awk 'NR==1 {print $4}'
