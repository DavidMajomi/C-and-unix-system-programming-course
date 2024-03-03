#include <stdio.h>
#include <string.h>

int main() {
    char src[] = "Hello, World!";
    char dest1[20];
    char dest2[20];

    // Using strcpy
    strcpy(dest1, src);
    printf("Using strcpy: %s\n", dest1);

    // Using strncpy
    strncpy(dest2, src, sizeof(dest2) -  1); // -1 to leave space for null terminator
    dest2[sizeof(dest2) -  1] = '\0'; // Ensure null termination
    printf("Using strncpy: %s\n", dest2);

    return  0;
}