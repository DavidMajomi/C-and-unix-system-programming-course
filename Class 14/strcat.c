#include <stdio.h>
#include <string.h>

int main() {
    char src[50] = "forgeeks";
    char dest1[50] = "geeks";
    char dest2[50] = "geeks";

    printf("Before strcat() function execution, destination string: %s\n", dest1);
    strcat(dest1, src); // Appends the entire string of src to dest1
    printf("After strcat() function execution, destination string: %s\n", dest1);

    printf("Before strncat() function execution, destination string: %s\n", dest2);
    strncat(dest2, src,  3); // Appends  3 characters from src to dest2
    printf("After strncat() function execution, destination string: %s\n", dest2);

    return  0;
}