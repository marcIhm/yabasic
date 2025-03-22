#!/bin/bash

#
# Check option --docu
#
./yabasic --docu tests/resources/docu.yab | grep -q one
