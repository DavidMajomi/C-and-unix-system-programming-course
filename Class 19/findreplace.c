#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void replaceString(char *str, const char *search, const char *replace);

int main() {
    FILE *file;
    char filename[100];
    char searchStr[100], replaceStr[100];
    char content[1000];

    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fread(content, sizeof(char), sizeof(content), file);
    fclose(file);

    printf("Enter the string to search: ");
    scanf("%s", searchStr);

    printf("Enter the string to replace it with: ");
    scanf("%s", replaceStr);

    replaceString(content, searchStr, replaceStr);

    file = fopen(filename, "w");

    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    fprintf(file, "%s", content);
    fclose(file);

    printf("String replaced successfully.\n");

    return 0;
}

void replaceString(char *str, const char *search, const char *replace) {
    char *pos, temp[1000];
    int index = 0, searchLen = strlen(search), replaceLen = strlen(replace);

    while ((pos = strstr(str, search)) != NULL) {
        strncpy(temp, str, pos - str);
        temp[pos - str] = '\0';

        strcat(temp, replace);
        strcat(temp, pos + searchLen);

        strcpy(str, temp);
        index += pos - str + replaceLen;
    }
}