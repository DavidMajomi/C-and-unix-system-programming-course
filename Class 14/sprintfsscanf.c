#include <stdio.h>
#define SIZE 80

int main() {
    int x1, x2;
    double y1, y2;
    char s1[SIZE];
    char s2[] = "31324 76.375";

    puts("Enter an integer and a double:");
    scanf("%d%lf", &x1, &y1);
    sprintf(s1, "Integer:%6d\nDouble:%7.2f", x1, y1);
    printf("String: %s\nInteger: %d\nDouble: %f\n",
    s1, x1, y1);

    printf("\nThe formatted output stored in array s1 is:\n%s\n\n", s1);

    sscanf(s2, "%d%lf", &x2, &y2);
    printf("String: %s\nInteger: %d\nDouble: %f",
    s2, x2, y2);

    printf("String 2 = %s\n", s2);

    return 0;
}