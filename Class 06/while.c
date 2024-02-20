#include <stdio.h>

int main()
{
   int value;
   //printf("Please enter a value:");
   while (scanf("%d", &value) == 1 && value != 0)
   {
      if (value < 0)
      {
         printf("Illegal value\n");
         // Abandon the loop
         break;
      }
      if (value > 100)
      {
         printf("Invalid value\n");
         // Skip to start loop again
         continue;
      }
      printf("Value = %d\n",value);
   }
   return 0;
}
