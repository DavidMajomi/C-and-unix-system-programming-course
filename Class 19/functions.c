#include <stdio.h>

void function1();
void function2();

int main() {
    int number = 10;
    char ch = 'A';
    int array[5] = {1, 2, 3, 4, 5};
    function1();
    printf("This is main\n")
    function2();
    printf("This is main again\n");
    return 0;
}

void function1() {
    printf("This is function1\n");
}

void function2() {
    printf("This is function2\n");
    printf("This is another function2\n");
}