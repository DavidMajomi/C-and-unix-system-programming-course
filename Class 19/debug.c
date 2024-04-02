#include <stdio.h>

int calculate_sum(int a, int b);

int main() {
    int x = 5;
    int y = 10;
    int z = calculate_sum(x, y);
    printf("Sum: %d\n", z);
    return 0;
}

int calculate_sum(int a, int b) {
    int result = a + b;
    return result;
}