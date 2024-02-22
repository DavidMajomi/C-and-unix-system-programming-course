#include <stdio.h>

int main() {
    // Open the input file
    FILE *inputFile = fopen("client.dat", "r");
    if (inputFile == NULL) {
        printf("Unable to open the input file.\n");
        return 1;
    }

    // Open the output file
    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Unable to open the output file.\n");
        fclose(inputFile); // Close the input file
        return 1;
    }

    // Read characters from the input file and write them to the output file
    int ch, count = 0;
    while ((ch = fgetc(inputFile)) != EOF) {
        // Write the character to the output file
        count++;
        fputc(ch, outputFile);
    }

    // Close the files
    fclose(inputFile);
    fclose(outputFile);

    printf("File has been copied successfully. (%d characters copied)\n", count);
    return 0;
}