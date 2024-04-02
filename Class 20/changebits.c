#include <stdio.h>
#include <stdlib.h>

int main() {
    char buff[] = "ah";
    int y;
    int counter;

    for (counter = 7; counter >= 0; counter--) {
        y = buff[0] & (0x01 << counter);
        if (y == 0)
        { printf("0 "); }
        else
        { printf("1 "); }
        //printf ("%d ", y);
    }
    printf(" = a (ascii: 97)\n");
    for (counter = 7; counter >= 0; counter--) {
        y = buff[1] & (0x01 << counter);
        if (y == 0)
        { printf("0 "); }
        else
        { printf("1 "); }
        //printf ("%d ", y);
    }
    printf(" = h (ascii: 104)\n");

    buff[0] ^= 1;     // Unset bit 1
    buff[0] |= 2;     // Set bit 2
    buff[0] |= 4;     // Set bit 3
    buff[0] |= 8;     // Set bit 4
    buff[0] |= 16;    // Set bit 5
    buff[0] ^= 32;    // Unset bit 6
    buff[0] ^= 64;    // Unset bit 7
    buff[0] |= 128;   // Set bit 8
    printf("After changing bits:\n");
    for (counter = 7; counter >= 0; counter--) {
        y = buff[0] & (0x01 << counter);
        if (y == 0)
        { printf("0 "); }
        else
        { printf("1 "); }
        //printf ("%d ", y);
    }
    printf(" = Latin small letter z with caron (ascii: 158)\n");
    // Checking for any bits == 1
    if ((unsigned int) (buff[0] & 0xff) == 0xff)
    { printf("Byte Full!\n"); }
    else if ((unsigned int) (buff[0] & 0xff) > 0x00)
    { printf("Byte has something!\n"); }
    else if ((unsigned int) (buff[0] & 0xff) == 0x00)
    { printf("Byte is empty!\n"); }
    for (counter = 7; counter >= 0; counter--) {
        y = buff[0] & (0x01 << counter);
        if (y == 0)
        { printf("0 "); }
        else
        { printf("1 "); }
        //printf ("%d ", y);
    }
    printf("\n");
    return(0);
}