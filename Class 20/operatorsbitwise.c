#include <stdio.h>

void displayBits(unsigned int value);

int main() {
    unsigned int number1;
    unsigned int number2 = 5;

    printf("Enter a nonnegative integer: ");
    scanf("%u", &number1);

    printf("The result of:\n");
    displayBits(number1);
    displayBits(number2);
    printf("using bitwise AND operator & is \n");
    displayBits(number1 & number2);
    printf("\nThe result of:\n");
    displayBits(number1);
    displayBits(number2);
    printf("using bitwise inclusive OR operator | is \n");
    displayBits(number1 | number2);
    printf("\nThe result of:\n");
    displayBits(number1);
    displayBits(number2);
    printf("using bitwise exclusive OR operator ^ is \n");
    displayBits(number1 ^ number2);
    printf("\nThe result of:\n");
    displayBits(number1);
    printf("using bitwise one's complement operator ~ is \n");
    displayBits(~number1);

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