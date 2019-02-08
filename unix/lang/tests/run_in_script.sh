#!/bin/bash

#
# Check that yabasic can be run from within a script
# Use tmux as a remote control
#

# Prepare variables
RAND=$RANDOM   ## $RANDOM returns a numeric random number
EXPECTED="Echo of $RAND"
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"
SCRIPT=$DIR/resources/in_script.sh

# start tmux
tmux -u new-session -d -x 80 -y 20 -s in_script

# Start script within tmux-session and supply input
tmux send -l -t in_script $SCRIPT
tmux send -t in_script ENTER
tmux send -l -t in_script $RAND
tmux send -t in_script ENTER
sleep .5

# Get and compare output of script from tmux
FOUND=`tmux capture-pane -t in_script -p`
grep -q "$EXPECTED" <<EOF
$FOUND
EOF
RET=$?

# End tmux session
tmux kill-session -t in_script

# Evaluate result
if [ $RET -ne 0 ] ; then
    echo "Did not find expected string >>$EXPECTED<<"
    echo "Found this instead:"
    echo $FOUND
    exit 1
fi

echo "Found expected string >>$EXPECTED<<"
exit 0
