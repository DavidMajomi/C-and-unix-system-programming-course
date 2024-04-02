#include <stdio.h>

int bitCount(unsigned char);

int main() {
    unsigned char x;
    int ones;
    printf ("Enter a character: ");
    scanf ("%c",&x);
    ones = bitCount(x);
    printf ("There are %d bits set to 1 in %c\n",ones,x);
}

int bitCount(unsigned char c) {
    int count;
    for (count = 0; c != 0; c>>=1) {
        if (c & 01)
	        { count++; }
    }
    return count;
}