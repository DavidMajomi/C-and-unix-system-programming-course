#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void demonstrate_pass_by_value(float, float);
void demonstrate_pass_by_reference(float *, float *);

int main() {
   float a=5,b=18;

   printf("\nDemonstrate 'Pass by Value':\n");
   printf("main function: a = %2.2f, b = %2.2f\n", a, b);
   printf("from main function calling: demonstrate_pass_by_value(a, b)\n");
   demonstrate_pass_by_value(a, b);
   printf("main function: a = %2.2f, b = %2.2f\n", a, b);
   printf("\n");
   printf("\nDemonstrate 'Pass by Reference':\n");
   printf("main function: a = %2.2f, b = %2.2f\n", a, b);
   printf("from main function call: demonstrate_pass_by_reference(&a, &b)\n");
   // Address sent, instead of value
   demonstrate_pass_by_reference(&a, &b);
   printf("main function: a = %2.2f, b = %2.2f\n", a, b);

   return 0;
}

void demonstrate_pass_by_value(float a, float b) {
   float temp;
   temp = a;
   a = b;
   b = temp;
   printf("demo value function: Swapping values, a = %2.2f, b = %2.2f\n", a, b);
}

void demonstrate_pass_by_reference(float *a, float *b) {
   float temp;
   temp = *a;
   *a = *b;
   *b = temp;
   printf("demo reference: Swapping values, a = %2.2f, b = %2.2f\n", *a, *b);
}
