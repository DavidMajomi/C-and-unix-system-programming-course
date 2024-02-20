#include "execute.h"

double execute_operation(char op, double result, double number)
{
   /* Execute operation, as 'result op= number' */
   switch(op)
   {
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
   return(result);
}
