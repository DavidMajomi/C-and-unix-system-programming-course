#include "get.h"
#include "parse.h"
#include "execute.h"

void get_input()
{
   char input[MAX_INPUT];
   char number_string[30];
   char op = 0;

   unsigned int index = 0;
   unsigned int to = 0;
   size_t input_length = 0;
   unsigned int number_length = 0;
   double result = 0.0;
   double number = 0.0;

   /* The main calculator loop */
   while(strcmp(fgets(input, 255, stdin), "quit\n") != 0)
   {
      input_length = strlen(input)-1;
      *(input+input_length) = '\0';

      index = 0;

      if(input[index]== '=')
      { index++; }
      else
      {
         parse_input(&number_length, input, number_string, &index);

         if(number_length>0)
         { result = atof(number_string); }
      }

      /* Now look for 'op number' combinations */
      while(index < input_length)
      { 
         op = *(input+index++);
         parse_input(&number_length, input, number_string, &index);
         number = atof(number_string);
         result = execute_operation(op, result, number);
      }
      printf("= %f\n", result);
   }
}
