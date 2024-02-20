#include <stdio.h>
#include <stdlib.h>

int main() {
  int numbers[] = {11,12,13,14,15,16,17,18,19,20};
  int *pn;
  pn = &numbers[0];     // OR   pn = numbers;
 
  printf("Value of *pn = %d\n", *pn);
  // Manipulating Pointer's memory address
  pn = pn + 1;
  printf("Next value of *pn = %d\n", *pn);
  pn++;
  printf("Next value of *pn = %d\n", *pn);
  pn = pn + 5;
  printf("Skipped head 5, value of *pn = %d\n", *pn);

  printf("Changing value of our current *pn to 99...\n");
  *pn = 99;
  printf("Our new value of numbers[7] = %d\n", numbers[7]);

  return 0;
}
