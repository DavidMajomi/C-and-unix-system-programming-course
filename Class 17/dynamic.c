#include <stdio.h>
#include <stdlib.h>

int main () {
    int a; // goes on the stack

    int *p; // goes on the stack
    p = (int*)malloc(sizeof(int));
    *p = 10;
    free(p);

    p = (int*)malloc(sizeof(int));
    *p = 20;
    free(p);

    p = (int*)malloc(20*sizeof(int));
    // p[0] p[1]    p[2]   ...
    // *p   *(p+1)  *(p+2) ...

    return 0;
}
