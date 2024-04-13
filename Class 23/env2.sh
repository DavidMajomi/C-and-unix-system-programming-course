#!/bin/bash

# Accessing environment variables (printenv)
# and string manipulations (String Operations in online tutorial)

echo "Environment variable HOST: $LOGNAME"
echo "First 3 letters:           ${LOGNAME:0:3}"
echo "Length:                    ${#LOGNAME}"
# Care you don't accidentally use < or > here for integer comparison.
# Instead use -lt (less than) or -gt (greater than)
#             -le (less than or equal), -ge (greater than or equal)
#             -eq (equal to), -ne (not equal to)
# WARNING: Careful you don't forget the "then" (remove it to see the error)
# WARNING : Make sure you leave space after the [ and before the ]
if [ ${#LOGNAME} -lt 3 ]
then
  echo "Hostname is pretty small"
else
  if [ ${#LOGNAME} -ge 3 ] && [ ${#LOGNAME} -lt 8 ]
  then
    echo "Hostname is about normal size"
  else
    echo "Hostname is pretty big"
  fi
fi

echo ""
# Difference between integer (number) comparisons and string comparisons
A=1
B=1
C="A"
D="A"

if [ "$A" -eq "$B" ]; then
  echo "-eq: $A equals $B"
else
  echo "-eq: $A does not equal $B"
fi

if [ "$A" == "$B" ]; then
  echo "==: $A equals $B"
else
  echo "==: $A does not equal $B"
fi

# This will give an error: integer expression expected
#if [ "$C" -eq "$D" ]; then
#  echo "-eq: $C equals $D"
#else
#  echo "-eq: $C does not equal $D"
#fi

if [ "$C" == "$D" ]; then
  echo "==: $C equals $D"
else
  echo "==: $C does not equal $D"
fi

exit 0