#!/bin/bash

# Sort a file, and display first 5 lines
OUPUT=`cat /proc/meminfo | sort | head -n 5`
echo "command: cat /proc/meminfo | sort | head -n 5"
echo "---------------------------------------------"
echo "$OUTPUT"
echo "---------------------------------------------"

echo
# Search for "Free" in a file, sort it, then display last line
TEMP_OUTPUT=`grep Free /proc/meminfo`
OUTPUT=`echo "$TEMP_OUTPUT" | sort | tail -n 1`
echo "command: grep Free /proc/meminfo | sort | tail -n 1"
echo "---------------------------------------------------"
echo "$OUTPUT"
echo "---------------------------------------------------"

echo
# Count how many characters are in a file
OUTPUT=`cat /proc/meminfo | wc -c`
echo "command: cat /proc/meminfo | wc -c"
echo "---------------------------------------------------"
echo "The /proc/meminfo file contains $OUTPUT characters."
echo "---------------------------------------------------"

echo
# Display just the month/day/year
# "man date" for more information
OUTPUT=`date +%m/%d/%Y`
echo "command: date +%m/%d/%Y"
echo "---------------------------------------------------"
echo "Today's Date is: $OUTPUT"
echo "---------------------------------------------------"

exit 0