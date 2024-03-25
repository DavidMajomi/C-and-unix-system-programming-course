#include <stdio.h>
#include <string.h>

union data {
    int i; 
    float f;
    char str[20];
};

int main() {
    union data myData;
    printf("Address of myData: %p\n", &myData);

    myData.i = 10;  
    printf("Integer Value: %d\n", myData.i);
    printf("Address of myData.i : %p\n", &myData.i);

    myData.f = 220.5;
    printf("Float Value: %.2f\n", myData.f);
    printf("Address of myData.f : %p\n", &myData.f);

    strcpy(myData.str, "Hello World");
    printf("String: %s\n", myData.str);
    printf("Address of myData.str : %p\n", myData.str);

    // printf("Interger Value: %d\n", myData.i);
    // printf("Float Value: %.2f\n", myData.f);

    return 0;
}
