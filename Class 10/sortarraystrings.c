#include <stdio.h>
#include <string.h>

#define SIZE 5

void sortStrings(char *strings[], int n);

int main() {
    char *strings[SIZE] = {"Python", "C", "Java", "JavaScript", "Ruby"};

    sortStrings(strings, SIZE);
    printf("Strings in sorted order are : \n");
    for (int i = 0; i < SIZE; i++) {
        printf("%s \n", strings[i]);
    }

    return 0;
}

void sortStrings(char *strings[], int n) {
    char *temp;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(strings[i], strings[j]) > 0) {
                temp = strings[i];
                strings[i] = strings[j];
                strings[j] = temp;
            }
        }
    }
}
