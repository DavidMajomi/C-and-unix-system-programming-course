#include <stdio.h>
#define SIZE 5

int main() {

    // Declare and initialize an array of 5 integers
    int numbers[SIZE];
    int i;

    printf("Enter the elements of the array:");
    for (i = 0; i < SIZE; i++) {
        scanf("%d", &numbers[i]);
    }

    // Update all the elements of the array
    printf("\nModified array:\n");
    for (i = 0; i < SIZE; i++) {
        numbers[i] = numbers[i] * 10;
    }

    // Print the modified array
    for (i = 0; i < SIZE; i++) {
        printf("numbers[%d] = %d\n", i, numbers[i]);
    }

    // Modify the elements of the array
    numbers[2] = 10;
    numbers[4] = 20;

    // Print the modified array
    printf("Modified array:\n");
    for (i = 0; i < SIZE; i++) {
        printf("numbers[%d] = %d\n", i, numbers[i]);
    }

    return 0;
}
