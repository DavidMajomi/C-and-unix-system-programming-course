#include <stdio.h>

int main()
{
   int i;

   for (i = 0; i < 5; i++)
   { printf("for loop: i = %d\n", i); }

   printf("\n");

   i = 0;
   while (i < 5)
   {
//      if (i == 3)
//      { i++; continue; }
      printf("while loop: i = %d\n", i);
      i++;
   }

   printf("\n");

   i = 0;
   do
   {
      printf("do while loop: i = %d\n", i);
      i++;
//      if (i > 3)
//      { break; }

    } while (i < 5);
   return 0;
}