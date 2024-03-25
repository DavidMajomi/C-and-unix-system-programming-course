#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    int i;
    printf("Enter size of array ");
    scanf("%d",&n);
    int Array[n]; // Compile Error

    int *A = (int*) malloc(n*sizeof(int));
    for (i=0; i<n; i++)
    { A[i] = i + 1; }
    for (i=0; i<n; i++)
    { printf("%d ",A[i]); }
    printf ("\n");

    int *B = (int*)realloc(A, 2*n*sizeof(int));
    for (i=n-1; i<2*n; i++)
    { B[i] = i + 1; }
    for (i=0; i<(2*n); i++)
    { printf("%d ",B[i]); }
    printf ("\n");
    free(B);

    exit(0);
}