#!/bin/sh
echo "Enter your name:"
read NAME

echo "Enter your age:"
read AGE

if [ "$AGE" -lt 18 ]; then
  echo "You are not an adult yet."
elif [ "$AGE" -lt 65 ]; then
  echo "You are an adult."
else
  echo "You are a senior citizen."
fi

echo "Hello, $NAME! Your age is $AGE."