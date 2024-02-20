#include <stdio.h>
#include <stdlib.h>
#include "get.h"

void main()
{
   printf("\nTo use this calculator, enter any expression without spaces");
   printf("\nAn expression may include the operators:");
   printf("\n           +, -, *, /, %%, or ^(raise to a power).");
   printf("\nUse = at the beginning of a line to operate on ");
   printf("\nthe result of the previous calculation.");
   printf("\nUse quit by itself to stop the calculator.\n\n");

   get_input();
   exit(0);
}
