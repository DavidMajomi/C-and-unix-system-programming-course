#!/bin/bash

# Function to print user information
print_user_info() {
  echo "Name: $NAME"
  echo "Email: $EMAIL"
  echo "Age: $AGE"
}

# Prompt the user to enter their information
echo "Enter your name:"
read NAME

echo "Enter your email:"
read EMAIL

echo "Enter your age:"
read AGE

# Call the function to print the user information
echo
print_user_info