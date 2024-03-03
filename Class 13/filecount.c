#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *file;
    char filename[100];
    char ch, prev;
    int words = 0, sentences = 0, characters = 0;
    int letters = 0, numbers = 0, punctuation = 0;
    int spaces = 0;

    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        characters++;
        if (isalpha(ch)) {
            letters++;
        }
        if (isdigit(ch)) {
            numbers++;
        }
        if (isspace(ch)) {
            spaces++;
            if (prev != ' ') {  
                words++;
            }
        }
        if (ch == '.' || ch == '!' || ch == '?') {
            sentences++;
        }
        if (ispunct(ch)) {
            punctuation++;
        }
        prev = ch;
    }

    fclose(file);

    printf("Number of words: %d\n", words);
    printf("Number of sentences: %d\n", sentences);
    printf("Number of characters: %d\n", characters);
    printf("Number of spaces: %d\n", spaces);
    printf("Number of letters: %d\n", letters);
    printf("Number of numbers: %d\n", numbers);
    printf("Number of punctuation marks: %d\n", punctuation);

    return 0;
}