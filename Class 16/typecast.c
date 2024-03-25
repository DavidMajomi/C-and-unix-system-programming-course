#include <stdio.h>


int main() {
    float f = 3.14;
    int i;

    // cast the float to an integer
    i = (int)f;

    printf("f = %.2f\n", f);
    printf("i = %d\n\n", i);

    printf("       f %.2f / i %d = %.4f\n", f, i, (f / i));
    printf("CAST : f %.2f / i %d = %.4f\n\n", f, i, (f / (float)i));

    printf("FLOAT : i %d / f %.2f = %.4f\n", f, i, (i / f));
    printf("  INT : i %d / f %.2f = %d\n", f, i, (i / f));
    printf(" CAST : i %d / f %.2f = %d\n", f, i, (i / (int)f));

    return 0;
}