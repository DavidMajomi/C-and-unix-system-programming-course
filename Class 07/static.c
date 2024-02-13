#include <stdio.h>

void stat(); /* prototype function */ 
     
int main() {
   int i;
   for (i=0; i<5; ++i)
   { stat(); }

   return 0;
}

void stat() {
   int auto_var = 0;
   static int static_var = 0;
   printf("auto = %d, static = %d\n", auto_var, static_var);
   ++auto_var;
   ++static_var;
}
