#include <stdio.h>
#include <stdlib.h>

// Read in characters from stdin
// If we see any 'c' characters replace them with 'X'
// Only read the first 6 lines, then exit

int main() {
    char c;
    int num_of_lines=0;

    c = getchar();
    while (c != EOF) {
        if (c == '\n')
        { num_of_lines++; }
        
        if (c == 'c')
        { c = 'X'; }
        
        printf("%c", c);
        if (num_of_lines >= 6)
        { exit(0); }

        c = getchar();
    }
    exit(0);
}
