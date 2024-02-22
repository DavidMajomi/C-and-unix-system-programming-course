#include <stdio.h>

int main() {
    // Open the file in read-write mode
    FILE *file = fopen("reference.dat", "a+");

    // Check if the file was opened successfully
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return   1; // Return an error code
    }

    // Write a string to the file
    const char *str = "Hello, world!";
    if (fputs(str, file) == EOF) {
        printf("Error writing to the file.\n");
        fclose(file);
        return 1;
    }

    // Move the file pointer to the beginning of the file
    rewind(file);

    // Read the string from the file
    char buffer[50];
    if (fgets(buffer, sizeof(buffer), file) == NULL) {
        printf("Error reading from the file.\n");
        fclose(file);
        return 1;
    }

    // Print the string
    printf("Read from the file: %s\n", buffer);

    // Close the file
    fclose(file);

    return 0; // Indicate successful completion
}