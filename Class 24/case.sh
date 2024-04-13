#!/bin/bash

echo "Enter a number between 1 and 5:"
read number

case $number in
  1) echo "You entered 1";;
  2) echo "You entered 2";;
  3) echo "You entered 3";;
  4) echo "You entered 4";;
  5) echo "You entered 5";;
  *) echo "Invalid input. Please enter a number between 1 and 5.";;
esac