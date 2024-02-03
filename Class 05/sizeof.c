#include <stdio.h>
#include <stdlib.h>

int main()
{
  char c;
  double d;
  float f;

  struct 
  {
    int a;
    int b;
  } TwoInts;

  char name[10];
  int numbers[10];
 
  printf("Size of char c:             %d bytes\n", sizeof(c));
  printf("Size of double d:           %d bytes\n", sizeof(d));
  printf("Size of float f:            %d bytes\n", sizeof(f));
  printf("Size of int:                %d bytes\n", sizeof(int));
  printf("Size of struct TwoInts:     %d bytes\n", sizeof(TwoInts));
  printf("Size of array name[10]:     %d bytes\n", sizeof(name));
  printf("Size of array numbers[10]:  %d bytes\n", sizeof(numbers));
  printf("\n");

  return 0;
}
