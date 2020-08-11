#!/bin/bash

#
# Check, if yabasic-program can read stdin until eof
#
./yabasic tests/resources/read_stdin.yab <tests/resources/read_stdin.yab

./yabasic tests/resources/read_stdin2.yab <tests/resources/read_stdin2.yab
