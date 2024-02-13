/* ONE BIG CALCULATOR PROGRAM */
/* gcc -lm calculator.c -o calculator */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#define MAX_INPUT 256

void main() {
   char input[MAX_INPUT];
   char number_string[30];
   char op = 0;

   unsigned int index = 0;
   unsigned int to = 0;
   size_t input_length = 0;
   unsigned int number_length = 0;
   double result = 0.0;
   double number = 0.0;

   printf("\nTo use this calculator, enter any expression without spaces");
   printf("\nAn expression may include the operators:");
   printf("\n           +, -, *, /, %%, or ^(raise to a power).");
   printf("\nUse = at the beginning of a line to operate on ");
   printf("\nthe result of the previous calculation.");
   printf("\nUse quit by itself to stop the calculator.\n\n");

   /* The main calculator loop */
   while(strcmp(fgets(input, MAX_INPUT-1, stdin), "quit\n") != 0) {
      input_length = strlen(input)-1;
      *(input+input_length) = '\0';

      index = 0;

      if(input[index]== '=')
      { index++; }
      else {
         /* Initialize length */
         number_length = 0;

         if(input[index]=='+' || input[index]=='-')
         { *(number_string+number_length++) = *(input+index++); }

         /* Copy all following digits */
         for( ; isdigit(*(input+index)) ; index++)
         { *(number_string+number_length++) = *(input+index); }

         /* Copy any fractional part */
         if(*(input+index)=='.') {
            *(number_string+number_length++) = *(input+index++);
            for( ; isdigit(*(input+index)) ; index++)
            { *(number_string+number_length++) = *(input+index); }
         }
         *(number_string+number_length) = '\0';

         if(number_length>0)
         { result = atof(number_string); }
      }

      /* Now look for 'op number' combinations */
      while(index < input_length) { 
         /* Get the operator */
         op = *(input+index++);

         /* Initialize the length  */
         number_length = 0;

         if(input[index]=='+' || input[index]=='-')
         { *(number_string+number_length++) = *(input+index++); }

         /* Copy all following digits */
         for( ; isdigit(*(input+index)) ; index++)
         { *(number_string+number_length++) = *(input+index); }

         /* Copy any fractional part */
         if(*(input+index)=='.') {
            *(number_string+number_length++) = *(input+index++);  
            for( ; isdigit(*(input+index)) ; index++)
            { *(number_string+number_length++) = *(input+index); }
         }
         *(number_string+number_length) = '\0';

         number = atof(number_string);

         /* Execute operation, as 'result op= number' */
         switch(op) {  
            case '+':
              result += number;
              break;
            case '-':
              result -= number;
              break;
            case '*':
              result *= number;
              break;
            case '/':
              /* Check second operand for zero */
              if(number == 0)   
              { printf("\n\n\aDivision by zero error!\n"); }
              else
              { result /= number; }
              break;
            case '%':
              /* Check second operand for zero */
              if((long)number == 0)               
              { printf("\n\n\aDivision by zero error!\n"); }
              else
              { result = (double)((long)result % (long)number); }
              break;
            case '^':
              result = pow(result, number);
              break;
            default:
              printf("\n\n\a'%c'Illegal operation!\n", op);
         } 
      }

      /* Output the result */
      printf("= %f\n", result);
   }
}
