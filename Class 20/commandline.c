#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main (int argc, char **argv) {
    /* Use "quotes" when your arguments have spaces */
    int i;
    printf("argc = %d\n\n",argc);
    for (i=0;i<argc;++i) {
        printf("argv[%d]: %s\n", i, argv[i]);
        if (strcmp(argv[i], "-h") == 0)
        { printf("  You're obviously looking for help!\n"); }
        if (strcmp(argv[i], "--list") == 0)
        { printf("  What kind of list would you like?\n"); }
        if (strcmp(argv[i], "hi there") == 0)
        { printf("  And Hi to you too!\n"); }
    }
    exit(0);
}
