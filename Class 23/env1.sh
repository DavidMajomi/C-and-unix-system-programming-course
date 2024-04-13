#!/bin/bash
echo "This is my amazing script!"
echo "Your home dir is: `pwd`"
clear
echo "Today's date is `date`"
echo "You are" `whoami`
echo "These users are currently connected:" `ls -la | grep -i example1`
echo "This is `uname -s` on a `uname -m` processor."
echo "This is the uptime information:" `uptime`
echo "That's all folks!"

exit 0