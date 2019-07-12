#!/bin/bash

#
# Check that yabasic can be run from within a script
# Use tmux as a remote control
#

# Prepare variables
MARKER=45367
EXPECTED="Echo of $MARKER"
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"
SCRIPT=$DIR/resources/in_script.sh

echo "showing any existing sessions:"
tmux list-sessions

# start tmux
tmux -u new-session -d -x 80 -y 20 -s yabasic_in_script

# Start script within tmux-session and supply input
tmux send-keys -l -t yabasic_in_script $SCRIPT
tmux send-keys -t yabasic_in_script ENTER
sleep 2
tmux send-keys -l -t yabasic_in_script $MARKER
tmux send-keys -t yabasic_in_script ENTER
sleep 2

# Get and compare output of script from tmux
FOUND=`tmux capture-pane -t yabasic_in_script -p`
grep -q "$EXPECTED" <<EOF
$FOUND
EOF
RET=$?

# End tmux session
tmux kill-session -t yabasic_in_script

# Evaluate result
if [ $RET -ne 0 ] ; then
    echo "Did not find expected string >>$EXPECTED<<"
    echo "Found this instead:"
    echo "-- start of found output --"
    echo $FOUND
    echo "-- end of found output --"
    exit 1
fi

echo "Found expected string >>$EXPECTED<<"
exit 0
