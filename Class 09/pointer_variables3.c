#include <stdlib.h>
#include <stdio.h>


void main() {
    int a;
    a = 5;

    int *b;
    b = (int *)malloc(sizeof(int));
    *b = 25;
    printf("a memory location '%p' contains %d\n", &a, a);
    printf("b Memory location '%p' contains %d\n", b, *b);

    int *c;
    c = &a;
    *c = *c + 2;
    printf("a memory location '%p' contains %d\n", &a, a);
    printf("c memory location '%p' contains %d\n", c, *c);
}
