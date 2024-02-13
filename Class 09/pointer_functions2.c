#include <stdio.h>
#define SIZE 10

/* prototypes */
void bubble(int work[], const int size, int (*compare)(int a, int b));
int ascending(int a, int b);
int descending(int a, int b);

void main() {
    int order;
    int counter;

    int a[SIZE] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};
    printf("Enter 1 to sort in ascending order,\n"
           "Enter 2 to sort in descending order: ");
    scanf("%d", &order);

    printf("\nData items in original order\n");

    for (counter = 0; counter < SIZE; counter++) {
        printf("%5d", a[counter]);
    }

    /* sort array in ascending order; pass function ascending as an
    argument to specify ascending sorting order */
    if (order == 1) {
        bubble(a, SIZE, ascending);
        printf("\nData items in ascending order\n");
    }
    else {
        bubble(a, SIZE, descending);
        printf("\nData items in descending order\n");
    }

    for (counter = 0; counter < SIZE; counter++) {
        printf("%5d", a[counter]);
    }
    printf("\n");
}

void bubble(int work[], const int size, int (*compare)(int a, int b)) {
    void swap(int *element1Ptr, int *element2ptr); /* prototype */
    
    int pass;
    int count;
    
    for (pass = 1; pass < size; pass++) {
        for (count = 0; count < size - 1; count++) {
            /* if adjacent elements are out of order, swap them */
            if ((*compare)(work[count], work[count + 1])) {
                swap(&work[count], &work[count + 1]);
            }
        }
    }
}

void swap(int *element1Ptr, int *element2Ptr) {
    int hold; /* temporary holding variable */
    hold = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = hold;
}

int ascending(int a, int b) {
    // Return the comparision needed for ascending
    return b < a;
}

int descending(int a, int b) {
    // Return the comparision needed for descending
    return b > a;
}