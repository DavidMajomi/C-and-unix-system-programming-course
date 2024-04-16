#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printUsageOptions();
 

void printArray(int* arr, int size, bool notComplete);
   

int calculateSum(int* arr, int size);


int findMax(int* arr, int size);


int isPrime(int num);


void printPrimes(int* arr, int size);

int main(int argc, char * argv[]) {
    bool notComplete;

    if (argc < 4) 
    {
        printUsageOptions();
        return 1;
    }

    char option = argv[1][1];
    int size = atoi(argv[2]);

    // Allocate memory of num values in array type int
    int* arr = (int*)malloc(size * sizeof(int));

    if (arr == NULL) 
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < size; i++) 
    {
        if ((i + 3 < argc))
        {
            arr[i] = atoi(argv[i + 3]);
        }
        else
        {
            notComplete = true;

            arr[i] = 0;
        }
        
    }

    switch (option) {
        case 'p':
            printArray(arr, size, notComplete);
            break;
        case 's':
            printf("Sum of array elements: %d\n", calculateSum(arr, size));
            break;
        case 'm':
            printf("Maximum value in the array: %d\n", findMax(arr, size));
            break;
        case 'c':
            printPrimes(arr, size);
            break;
        default:
            printf("Invalid option\n");
            printUsageOptions();
            break;
    }

    free(arr);

    return 0;
}



void printUsageOptions() 
{
    printf("Usage: ./assignment <option> <array_size> [array_elements...]\n");
    printf("Options:\n");
    printf("  -p: Print array elements\n");
    printf("  -s: Calculate the sum of array elements\n");
    printf("  -m: Find the maximum value in the array\n");
    printf("  -c: Print the prime numbers in the array\n");
}

void printArray(int* arr, int size, bool notComplete) 
{
    printf("Array elements:");

    if(notComplete == false)
    {
        for (int i = size - 1; i >= 0; i--) 
        {
            printf(" %d", arr[i]);
        }

        printf("\n");
    }
    else
    {
        for (int i = 0; i < size; i++) 
        {
            printf(" %d", arr[i]);
        }
        printf("\n");
    }
    
}

int calculateSum(int* arr, int size) 
{
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}


int findMax(int* arr, int size) 
{
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}


int isPrime(int num) 
{
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

void printPrimes(int* arr, int size) 
{
    printf("Prime numbers in the array:");
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (isPrime(arr[i])) {
            printf(" %d", arr[i]);
            found = 1;
        }
    }
    if (!found) {
        printf(" None");
    }
    printf("\n");
}