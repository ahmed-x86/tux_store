#!/bin/bash
podman --version 2>/dev/null | awk '{print $3}'
