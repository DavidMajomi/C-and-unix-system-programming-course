#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int size, newSize;

    // Initial size of the array
    size = 5;
    arr = (int *)malloc(size * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Initialize the array
    for (int i = 0; i < size; i++) {
        arr[i] = i + 6;
        printf("%d ", arr[i]);
    }

    // Request a new size for the array
    newSize = 10;

    // Resize the array using realloc()
    arr = (int *)realloc(arr, newSize * sizeof(int));

    if (arr == NULL) {
        printf("Memory reallocation failed.\n");
        return 1;
    }

    // Initialize the new elements in the resized array
    for (int i = size; i < newSize; i++) {
        arr[i] = i + 7;
    }
    printf("\n");

    // Print the resized array
    for (int i = 0; i < newSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);

    return 0;
}