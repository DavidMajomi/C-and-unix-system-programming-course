#!/bin/bash
A=23              # Simple case
echo $A
B=$A
echo $B

# Now, getting a little bit fancier (command substitution).

A=`echo Hello!`   # Assigns result of 'echo' command to 'A' ...
echo $A

A=`ls -l`         # Assigns result of 'ls -l' command to 'A'
echo $A           # Unquoted, however, it removes tabs and newlines.
echo
echo "$A"         # The quoted variable preserves whitespace.
                  # (See the chapter on "Quoting.")

exit 0