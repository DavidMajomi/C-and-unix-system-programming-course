#include <stdio.h>
#define SIZE 5

int main() {
   int s[SIZE];

   for (size_t j = 0; j < SIZE; j++) {
      s[j] = 2 + 2 * j;
   }

   printf("Element%13s\n", "Value");

   for (size_t j = 0; j < SIZE; j++) {
      printf("%7u %13d\n", j, s[j]);
   }

   int array[] = {1,2,3,4};
   printf("array = %p\n&array = %p\n&array[0] = %p\n",array, &array, &array[0]);

   return 0;
}
