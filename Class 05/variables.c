#include <stdio.h>
#include <stdlib.h>

int main()
{
   int j, k; 

   k = 2; 
   j = 7;
   printf("Address %p has k = %d\n", &k, k);
   printf("Address %p has j = %d\n", &j, j);
   k = j;

   // There are two different memory locations that have the value of 7.
   printf("Address %p has k = %d\n", &k, k);
   printf("Address %p has j = %d\n", &j, j);
   printf("\n");
   
   return 0;
}
