#!/bin/bash

#
# Test printing at specific position
# Use tmux as a remote control
#

# Prepare variables
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"
EXPECTED="abc"

# start tmux
tmux -u new-session -d -x 80 -y 20 -s print-at

# Start yabasic within tmux-session and supply input
tmux send -l -t print-at "./yabasic tests/resources/print-at.yab"
tmux send -t print-at ENTER
sleep 2

# Get and compare output of script from tmux
FOUND=`tmux capture-pane -p`
grep -q "$EXPECTED" <<EOF
$FOUND
EOF
RET=$?

# End tmux session
tmux kill-session -t print-at

# Evaluate result
if [ $RET -ne 0 ] ; then
    echo "Did not find expected string >>$EXPECTED<<"
    echo "Found this instead:"
    echo $FOUND
    exit 1
fi

echo "Found expected string >>$EXPECTED<<"
exit 0
