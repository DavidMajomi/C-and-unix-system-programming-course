#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
   int i;

   // Special Char Arrays
   char label_exact[] = "Hello Here";
   printf("Label = '%s'\n", label_exact);
   char label[14] = "Hello There";
   printf("Label = '%s'\n", label);

   char string1[] = "Hello World!";
   char string2[20];
   char string3[] = "Changes";
   char string4[] = "Made!!";
   char string5[20] = "Hello ";
   char string6[] = "Bye ";
   char string7[150];
   char one;

   // Character Array (a string)
   // Single quotes, not double quotes
   char letters[50];
   letters[0] = 'H';
   letters[1] = 'e';
   letters[2] = 'l';
   letters[3] = 'l';
   letters[4] = 'o';
   // Strings must terminate with a null zero
   letters[5] = '\0';

   printf("letters = %s\n", letters);
   printf("3rd letter = %c\n", letters[2]);

   strcpy(string2, string1);
   printf("String 1 %s\n", string1);
   printf("String 2 %s\n", string2);
   printf("String 1 length is %d\n", strlen(string1));
   printf("String 2 length is %d\n\n", strlen(string2));

   printf("String 3 %s\n", string3);
   printf("String 4 %s\n", string4);

   if (strcmp(string3, string4) == 0)
   { printf("strings are equal\n"); }
   else
   { printf("strings are different\n"); }

   printf("String 3 length is %d\n", strlen(string3));
   printf("String 4 length is %d\n\n", strlen(string4));
   printf("String 5 %s\n", string5);
   printf("String 5 length is %d\n", strlen(string5));
   strcat(string5,string6);
   printf("String 5 %s\n", string5);
   printf("String 5 length is %d\n", strlen(string5));
   strcat(string6,letters);
   printf("String 6 %s\n", string6);
   printf("String 6 length is %d\n\n", strlen(string6));

   printf("Enter a string ");
   fgets(string7, sizeof(string7), stdin);

   printf("String 7 %s\n", string7);

   for (i=0; i<strlen(string7); i++)
   {
      if (string7[i] >= 'a' && string7[i] <= 'z')
      { string7[i]-=32; } 
   }

   printf("String 7 Upper %s\n", string7);
   printf("String 7 length is %d\n\n", strlen(string7));

   one = 't';
   printf("Character %c Uppercase %c\n", one, toupper(one));
}
