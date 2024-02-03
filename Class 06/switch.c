#include <stdio.h>

int main()
{
   int num=2;
   switch(num+2)
   {
      case 4:
         printf("Case1: Value is: %d", num);
      case 6:
         printf("Case2: Value is: %d", num);
      case 8:
         printf("Case3: Value is: %d", num);
      default:
         printf("Default: Value is: %d", num);
   }
   return 0;
}
