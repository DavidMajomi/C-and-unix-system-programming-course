#!/bin/bash

# Check if the correct number of arguments are provided
if [ "$#" -ne 3 ]; then
    echo "Usage: $0 <input_file> <output_file> <search_term>"
    exit 1
fi

# Assign the command line arguments to variables
INPUT_FILE="$1"
OUTPUT_FILE="$2"
SEARCH_TERM="$3"

# Check if the input file exists
if [ ! -f ${2} ]; then
    echo "Error: Input file $INPUT_FILE does not exist."
    echo "Error: Input file $INPUT_FILE does not exist." >> error.log
    exit 1
fi

# Search for the search term in the input file and redirect the output to the output file
grep -w "$SEARCH_TERM" "$INPUT_FILE" > "$OUTPUT_FILE" 2> error.log

# Check if the grep command was successful
if [ $? -ne 0 ]; then
    echo "Error: Failed to search for $SEARCH_TERM in $INPUT_FILE."
    echo "Error: Failed to search for $SEARCH_TERM in $INPUT_FILE." >> error.log
    exit 1
fi

echo "Successfully searched for $SEARCH_TERM in $INPUT_FILE and redirected the output to $OUTPUT_FILE."
