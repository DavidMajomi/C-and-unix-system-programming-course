#include <stdio.h>

// Function prototypes
unsigned long int factorial(unsigned int);

int main() {
   unsigned long int number;

   printf("Enter a positive integer\n");
   scanf(" %lu",&number);

   printf("%d! equals %lu\n", number, factorial(number));

   return 0;
}

unsigned long int factorial(unsigned int number) {
   if (number >= 1)
   { return(number * factorial(number -1)); }
   else
   { return 1; }
}
