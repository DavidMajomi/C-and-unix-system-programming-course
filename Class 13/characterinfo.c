#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char inputString[] = "This is a paragraph with several words. It includes numbers like  123 and punctuation marks, such as commas and periods. Here's a sentence with a question mark? And here's another one with an exclamation mark! Here is where we find out if the program is working."; // Example string
    int length = strlen(inputString);

    printf("Character analysis of \"%s\":\n", inputString);

    for (int i =  0; i < length; i++) {
        char currentChar = inputString[i];
        printf("Character '%c': ", currentChar);
        if (isblank(currentChar)) {
            printf("Whitespace ");
        }
        if (isdigit(currentChar)) {
            printf("Numeric ");
        }
        if (isalpha(currentChar)) {
            printf("Alphabetic ");
        }
        if (isalnum(currentChar)) {
            printf("Alphanumeric ");
        }
        if (isxdigit(currentChar)) {
            printf("Hexadecimal digit ");
        }
        if (islower(currentChar)) {
            printf("Lowercase ");
            printf("To Upper '%c' ", toupper(currentChar));
        }
        if (isupper(currentChar)) {
            printf("Uppercase ");
            printf("To Lower '%c' ", tolower(currentChar));
        }
        if (isspace(currentChar)) {
            printf("Formatting Whitespace ");
        }
        if (iscntrl(currentChar)) {
            printf("Control character ");
        }
        if (ispunct(currentChar)) {
            printf("Punctuation ");
        }
        if (isprint(currentChar)) {
            printf("Printable ");
        }
        if (isgraph(currentChar)) {
            printf("Graphical ");
        }
        printf("\n");
    }

    printf(".\n");
    return  0;
}