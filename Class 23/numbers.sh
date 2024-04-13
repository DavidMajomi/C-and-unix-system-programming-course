#!/bin/bash
# NOTE: We have to escaping the quotes
A=879
echo "The value of \"a\" is $A."

# Assignment using 'let'
set A=16+5
echo "The value of \"set a=16+5\" is now $A."

# Assignment without using 'let'
A=16+5
echo "The value of \"a=16+5\" is now $A."
echo
# Simple for loop
echo -n "Values of \"a\" in the loop are: "
for A in 7 8 9 11
do
  echo -n "$A "
done

echo
# In a 'read' statement (also a type of assignment):
echo -n "Enter \"A\": "
read A
echo "The value of \"A\" is now $A."

exit 0