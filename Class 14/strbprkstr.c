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

    printf("First appearing character of string5 in string1 = %c\n", strpbrk(string1, string5));

    printf("Remainder of string1 starting with the last occurence of character is \"%s\"\n",strrchr(string1, letter1));

    printf("Remainder of string3 with the first occurence of string6 \"%s\"\n", strstr(string3, string6));

    return 0;
}