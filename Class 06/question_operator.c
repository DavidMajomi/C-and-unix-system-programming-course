#include <stdio.h>

int main()
{
   int a,b,z;

   a = 1;
   b = 3;
   z = (a>b) ? a : b;

   printf("? Operator print z = %d\n", z);

   // Same as:
   a = 1;
   b = 3;
   if (a>b)
   { z=a; }
   else
   { z=b; }
   printf("IF print z = %d\n", z);
   return 0;
}
