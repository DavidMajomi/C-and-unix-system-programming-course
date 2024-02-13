#include <stdio.h>
#include <stdlib.h>

int main() {
  char *ptr1;   // This is a char "pointer variable".
  double *ptr2; // This is a double "pointer variable".
  float *ptr3;  // This is a float "pointer variable".
  int *ptr4;    // This is a in "pointer variable".

  printf("Size of char ptr1:   %d\n", sizeof(ptr1));
  printf("Size of double ptr2: %d\n", sizeof(ptr2));
  printf("Size of float ptr3:  %d\n", sizeof(ptr3));
  printf("Size of int ptr4:    %d\n", sizeof(ptr4));

  printf("\nNow let's dereference our variables:\n");
  printf("Size of char *ptr1:   %d\n", sizeof(*ptr1));
  printf("Size of double *ptr2: %d\n", sizeof(*ptr2));
  printf("Size of float *ptr3:  %d\n", sizeof(*ptr3));
  printf("Size of int *ptr4:    %d\n", sizeof(*ptr4));

  char c = 'A';
  double d = 10.0;
  float f = 20.0;
  int i = 5;
  ptr1 = &c;
  ptr2 = &d;
  ptr3 = &f;
  ptr4 = &i;

  printf("\nNow we've setup some variables...\n");
  // Now let's look at the memory addresses that our stored in our ptr
  printf("Memory Address pointed to by ptr1: %p\n", ptr1);
  printf("Memory Address pointed to by ptr2: %p\n", ptr2);
  printf("Memory Address pointed to by ptr3: %p\n", ptr3);
  printf("Memory Address pointed to by ptr4: %p\n", ptr4);
  printf("\n");
  printf("Value of *ptr1: %c\n", *ptr1);
  printf("Value of *ptr2: %f\n", *ptr2);
  printf("Value of *ptr3: %f\n", *ptr3);
  printf("Value of *ptr4: %d\n", *ptr4);

  *ptr1 = 'B';
  *ptr2 += 1.1;
  *ptr3 += 1.1;
  *ptr4 *= 2;

  printf("\nNow we've modified our original variables via our pointers...\n");
  printf("Value of c: %c\n", c);
  printf("Value of d: %f\n", d);
  printf("Value of f: %f\n", f);
  printf("Value of i: %d\n", i);

  // How about a pointer to a pointer...
  char **ptr11;
  // Memory address of the "pointer" variable
  ptr11 = &ptr1;
  // Dereference twice to get value
  printf("Value of **ptr11: %c\n", **ptr11);

  return 0;
}
