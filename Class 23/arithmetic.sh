#!/bin/bash
# Define two variables
X=10
Y=3

# Perform arithmetic operations using bc
SUM=$(echo "$X + $Y" | bc)
DIFFERENCE=$(echo "$X - $Y" | bc)
PRODUCT=$(echo "$X * $Y" | bc)
let PRODUCT2=$X*$Y
QUOTIENT=$(echo "scale=2; $X / $Y" | bc)
let QUOTIENT2=$X/$Y

# Print the results
echo "Sum: $SUM"
echo "Difference: $DIFFERENCE"
echo "Product: $PRODUCT"
echo "Product: $PRODUCT2"
echo "Quotient: $QUOTIENT"
echo "Quotient2: $QUOTIENT2"

# Define a variable
VAR=500

# Perform a modulo operation using bc
RESULT=$(echo "$VAR % 7" | bc)

# Print the result
echo "The result is: $RESULT"