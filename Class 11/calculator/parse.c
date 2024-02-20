#include "parse.h"

void parse_input(unsigned int *number_length, char input[], char number_string[], unsigned int *index)
{
   unsigned int num_length;
   unsigned int i;
   i = *index;

   num_length = 0;
   if(input[i]=='+' || input[i]=='-')
   { *(number_string+num_length++) = *(input+i++); }
   for( ; isdigit(*(input+i)) ; i++)
   {
      *(number_string+num_length++) = *(input+i);
   }
   if(*(input+i)=='.')
   {
      *(number_string+num_length++) = *(input+i++);
      for( ; isdigit(*(input+i)) ; i++)
      { *(number_string+num_length++) = *(input+i); }
   }
   *(number_string+num_length) = '\0';
   *number_length = num_length;
   *index = i;
}
