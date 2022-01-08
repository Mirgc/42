#!/bin/sh
find . -name "*.sh" | awk -F/ '{print $(NF)}' | cut -d '.' -f 1 | tr -d ' '
