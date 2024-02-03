#include <stdio.h>
#include <stdlib.h>

int main()
{
   char character;
   int number;
   printf("Enter a Character: ");
   /* "&" means address, pass-by-reference */
   scanf("%c", &character);
   printf("Enter a Number: ");
   scanf("%d", &number);
   printf("\n");
   printf("Your Character: %c\n", character);
   printf("Your Number: %d\n", number);
   printf("\n");
   // This catches the return key from the number input
   character = getchar();
   printf("Enter another character: ");
   character = getchar();
   printf("You just entered '%c'.\n", character);
   printf("\n");

   return 0;
}
