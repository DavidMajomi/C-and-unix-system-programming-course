#include <stdio.h>

float triangleArea(float,float);

int main() {
   float base, height, area;
   printf("Enter the base of the triangle: ");
   scanf("%f", &base);
   printf("Enter the height of the triangle: ");
   scanf("%f", &height);
   area = triangleArea(base,height);
   printf("The area of the triangle is: %f\n", area);
   return 0;
}

float triangleArea(float base, float height) {
   return (0.5 * base * height);

}
