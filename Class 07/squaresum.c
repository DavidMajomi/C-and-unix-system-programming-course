#include <stdio.h>

int total;

int Square(int);

int SquareOfSum(int,int);

int main()
{
    int a = 4, b = 8;
    total = SquareOfSum(a,b);
    printf("Output = %d\n",total);
}

int Square(int x)
{
    return x*x;
}

int SquareOfSum(int x,int y)
{
    int z = Square(x+y);
    return z;
}
