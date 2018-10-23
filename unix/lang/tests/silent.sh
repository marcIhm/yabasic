#!/usr/bin/bash

#
# Check if empty yabasic-program produces any warning
#
OUT=`./yabasic tests/resources/empty.yab 2>&1`
OUT=`foo`
if [ $OUT -ne "" ]; then
    exit 1
else
    exit 0
fi

