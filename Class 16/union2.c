#include <stdio.h>
#include <string.h>

union number {
    int x;
    double y;
};

int main() {
    union number value;
    
    value.x = 104;
    printf("Print value of x %d and y %f\n", value.x, value.y);
    value.y = 104.0;
    printf("Print value of x %d and y %f\n", value.x, value.y);
    printf("Address of x : %p\nAddress of y : %p\n", &value.x, &value.y);

    return 0;
}
