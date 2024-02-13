#include <stdio.h>
#include <stdlib.h>

void copyarray(char from[], char to[]);

int main() {
   // Number Array
   int numbers[50];
   int num_array[6] = { 1, 2, 3, 4, 5, 6 };
   int i,j;
   for (i=100; i<150; i++) {
      numbers[i-100] = i;
   }
   printf("First number element = %d\n", numbers[0]);
   printf("Last number element = %d\n", numbers[49]);

   printf("num_array = {");
   for (i=0; i < sizeof(num_array); i++) {
      printf("%i, %d", i, num_array[i]);
   }
   printf("}\n");

   // Multidimensional Arrays
   int multi_dim[3][2];
   multi_dim[0][0] = 1;
   multi_dim[0][1] = 2;
   multi_dim[1][0] = 3;
   multi_dim[1][1] = 4;
   multi_dim[2][0] = 5;
   multi_dim[2][1] = 6;
   for (i=0; i<3; i++) {
      for (j=0; j<2; j++) {
         printf("multi_dim[%d][%d]=%d\n",i,j,multi_dim[i][j]);
      }
   }

   // Arrays passing to functions "by reference" not the normal "by value"
   char arrayA[10] = "ABCDEFG";
   char arrayB[10];
   copyarray(arrayA, arrayB);
   printf("Contents of arrayA = %s\n", arrayA);
   printf("Contents of arrayB = %s\n", arrayB);
}

void copyarray(char from[], char to[]) {
   int i;
//   i = 0;
//   while((to[i] = from[i]) != '\0')
//   { i++; }

   for(i = 0; from[i] != '\0'; i++)
   { to[i] = from[i];  }
}