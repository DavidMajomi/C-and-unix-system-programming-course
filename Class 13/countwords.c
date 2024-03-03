#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char inputParagraph[] = "This is a paragraph with several words. It includes numbers like  123 and punctuation marks, such as commas and periods. Here's a sentence with a question mark? And here's another one with an exclamation mark!";
    int length = strlen(inputParagraph);
    int wordCount =  0;
    int inWord =  0;

    printf("Word count in the paragraph:\n%s\n", inputParagraph);

    for (int i =  0; i < length; i++) {
        char currentChar = inputParagraph[i];

        if (isalpha(currentChar)) {
            inWord =  1; // Found the start of a word
        }
        else if (inWord && !isalpha(currentChar) && currentChar != ' ') {
            inWord =  0; // Found the end of a word
            wordCount++;
        }

        // If we're at the end of the string and we're in a word, count it
        if (i == length - 1 && inWord) {
            wordCount++;
        }
    }

    printf("Number of words: %d\n", wordCount);
    return  0;
}