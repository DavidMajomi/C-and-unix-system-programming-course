#include <stdio.h>

const int MAX = 3;

int main () {
    int  var[MAX];
    int  i, *ptr;

    for (i = 0; i < MAX; i++) {
        printf("Enter an integer: ");
        scanf("%d", &var[i]);
    }
    /* let us have array address in pointer */
    ptr = var;

    printf("Starting at the beginning:\n");
    for (i = 0; i < MAX; i++) {
        printf("Address of var[%d] = %p\n", i, ptr);
        printf("Value of var[%d] = %d\n\n", i, *ptr);
        /* move to the next location */
        ptr++;
    }

//    ptr--;
    printf("Starting at the end:\n");
    for (i = MAX; i > 0; i--) {
        printf("Address of var[%d] = %p\n", i-1, ptr);
        printf("Value of var[%d] = %d\n", i-1, *ptr);
        /* move to the previous location */
        ptr--;
    }
    return 0;
}