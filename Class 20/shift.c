#include <stdio.h>

void displayBits(unsigned int value);

int main() {
    unsigned int number1 = 960;

    printf("The result of:\n");
    displayBits(number1);
    printf("using bitwise right shift operator >> 4 is \n");
    // Divide by 2^4
    displayBits(number1 >> 4);
    printf("\nThe result of:\n");
    displayBits(number1);
    printf("using bitwise left shift operator << 8 is \n");
    // Mulitply by 2^8
    displayBits(number1 << 8);

    return 0;
}

void displayBits(unsigned int value) {
    unsigned int bitMask = 1 << 31;

    printf("%10u = ", value);

    for (unsigned int c = 1; c <= 32; c++) {
        if (value & bitMask)
        { printf("1"); }
        else
        { printf("0"); }

        value <<= 1;

        if (c % 8 == 0)
        { printf(" "); }
    }
    printf("\n");
}