#include <stdio.h>
#include <stdlib.h>

int main() {
  int j; 
  int *k;

  j = 7;    // line 1   (compiler uses address of j to store value 7)
  k = &j;   // line 2   (compiler points k to address of j)
  // Just to be clear here: There is only one memory location that contains
  // the value 7, but you both j and *k will display the same value.
  printf("%d\n", *k);
  return 0;
}
