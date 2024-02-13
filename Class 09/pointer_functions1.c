#include <stdio.h>
#include <stdlib.h>

void swap(int *, int *);

int main() {
  int a, b;
  a = 10;
  b = 20;
  printf("a = %d\n", a);
  printf("b = %d\n", b);

  // Remember: swap(a, b) would not work!
  swap(&a, &b);
  printf("swap(&a, &b)\n");
  printf("a = %d\n", a);
  printf("b = %d\n", b);

  return 0;
}

void swap(int *px, int *py) {

  int temp;
  temp = *px;
  *px = *py;
  *py = temp;
}