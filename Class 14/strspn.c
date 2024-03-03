#include <stdio.h>
#include <string.h>

int main() {
    const char *string1 = "This is a test apple";
    const char *string2 = "The value is 3.14159";
    const char *string3 = "1234567890";
    const char *string4 = "aehi lsTuv";
    const char *string5 = "beware";
    const char *string6 = "456";
    char letter1 = 'a';
    char letter2 = 'z';
    
    if (strchr(string1,letter1))
    { printf("Found\n"); }
    else
    { printf("Not Found\n"); }

    if (strchr(string1,letter2))
    { printf("Found\n"); }
    else
    { printf("Not Found\n"); }

    printf("Length (#) of string1 having none of strings3 characters = %u\n", strcspn(string2, string3));

    printf("Length (#) of string2 containing only strings4 characters = %u\n", strspn(string2, string4));
    return 0;
}