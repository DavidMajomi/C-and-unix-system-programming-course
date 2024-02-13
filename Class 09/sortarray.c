#include <stdio.h>
#define SIZE 10

void printArray(int array[]);
void sortArray(int array[], char sort);

void main() {
    int arrayNumbers[SIZE] = {4,5,37,6,87,89,11,2,3,24};
    char order;

    printf("Data in original order.\n");
    printArray(arrayNumbers);
    printf("\n");
    printf("Select the sort array 'a' or 'd': \n");
    scanf("%c", &order);

    sortArray(arrayNumbers, order);
    printArray(arrayNumbers);
    printf("\n");
}

void printArray(int array[]) {
    for(size_t i = 0; i < SIZE; i++) {
        printf("%4d", array[i]);
    }
}

void sortArray(int array[], char sort) {
    int temp;
    for(int p = 0; p < (SIZE - 1); p++) {
        for(int i = 0; i < (SIZE - 1); i++) {
            if (sort == 'a') {
                if (array[i] > array[i + 1]) {
                    temp = array[i];
                    array[i] = array[i + 1];
                    array[i + 1] = temp;
                }
            }
            else {
                if (array[i] < array[i + 1]) {
                    temp = array[i];
                    array[i] = array[i + 1];
                    array[i + 1] = temp;
                }
            }
        }
    }
}