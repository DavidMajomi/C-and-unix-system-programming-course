#include <stdio.h>

int main() {
    int j = 0;
    int evens[5];
    char letters[10];

    // print the numbers 1 through 10 one per line
    for (int i = 2; i <= 10; i += 2) {
        evens[j] = i;
        j++;
    }
    // print the letters a through j one per line
    j = 0;
    for (char c = 'a'; c <= 'j'; c++) {
        letters[j] = c;
        j++;
    }

    printf("Even number count :");
    for (j = 0; j < 5; j++) {
        printf(" %d", evens[j]);
    }
    printf("\n");

    printf("Letters to a to j :");
    for (j = 0; j < 10; j++) {
        printf(" %c", letters[j]);
    }
    printf("\n");

    return 0;
}
