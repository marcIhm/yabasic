#!/bin/bash

#
# Check, that yabasic can be invoked from a shell-script
#
set +x
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"
$DIR/../../yabasic -e 'input a$:print "Echo of ",a$'
