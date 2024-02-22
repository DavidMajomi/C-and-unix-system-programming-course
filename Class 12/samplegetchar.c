#include <stdio.h>

#define RETURN '\n'			/* \n == return in UNIX \r == return in DOS		*/

int main() {
    int count=0;
    printf("Please enter some text.\n");
    while ( getchar() != RETURN)
    { count++; }

    printf("You entered %d characters\n", count);

    return 0;
}
