#include <stdio.h>

int main()
{
   int a,b;

   a = 1;
   printf("set a = %d\n", a);
   printf("++a + 5 = %d\n", ++a + 5);
   printf("now a = %d\n\n", a);

   a = 1;
   printf("set a = %d\n", a);
   printf("5 + a++ = %d\n", 5 + a++);
   printf("now a = %d\n\n", a);

   a = 1;
   printf("set a = %d\n", a);
   a = a + 1;
   printf("a = a + 1 = %d\n", a);
   a += 1;
   printf("a += 1 : %d\n", a);
   a -= 1;
   printf("a -= 1 : %d\n", a);

   printf("\n");
   a=0;
   printf("set a = %d\n", a);
   printf("while (a != 5) { print a++ }:\n");
   while (a != 5)
   {
      // printf("  a = %d ", a);
      printf("  a = %d\n", a++);
   }
   printf("\n");
   a=0;
   printf("set a = %d\n", a);
   printf("while (a != 5) { print ++a }:\n");
   while (a != 5)
   {
      // printf("  a = %d ", a);
      printf("  a = %d\n", ++a);
   }
   printf("\n");
 
   a=2;
   b=3;
   printf("set a = %d\n", a);
   printf("set b = %d\n", b);
   a *= (b + 2);
   printf("a *= b + 2 : %d\n", a);
   printf("NOTE: Above would be 'a = a * (b + 2)' NOT 'a = a * b + 2'\n");
   printf("\n");

   return 0;
}
