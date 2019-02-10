#!/bin/bash

#
# Check, if empty yabasic-program produces any warning
#
OUT=`./yabasic tests/resources/silent.yab 2>&1`
echo "$OUT"
if [ -n "$OUT" ]; then
    exit 1
else
    exit 0
fi

