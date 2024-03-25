#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int *ptr;
    ptr = (int *) malloc(sizeof(int));

    *ptr = 10;
    printf("%d\n", *ptr);
    free(ptr);

    char text[] = "Hello";
    char *cp;
    cp = (char *) malloc(10*sizeof(char));

    cp[0] = 'H';
    cp[1] = 'e';
    cp[2] = 'l';
    cp[3] = 'l';
    cp[4] = 'o';
    cp[5] = '\0';

    printf("%s\n", cp);
    free(cp);

    char *phrase = "Hi There Everyone!";
    printf("%s\n", phrase);
    phrase[0] = 'A';           // No compiler warnings or errors
    printf("%s\n", phrase);    // Segmentation fault!

    return 0;
}
