#include <stdio.h>
#include <stdlib.h>

int main()
{
  int number1, number2=25, number3=100;
  char lettera;
  char letterb='t', letterc='y';

  printf("Enter a number : ");
  scanf("%d",&number1);

  if (number1 == number2)
  { printf("Your number %d is equal to number2 %d\n", number1,number2);  }

  if (number1 != number2)
  { printf("Your number %d is not equal to number2 %d\n", number1, number2);  }

  if (number1 > number2)
  { printf("Your number %d is greater than number2 %d\n", number1, number2);  }

  if (number1 < number2)
  { printf("Your number %d is less than number2 %d\n", number1, number2);  }

  if (number1 == number3)
  { printf("Your number %d is equal to number3 %d\n", number1,number3);  }

  if (number1 != number3)
  { printf("Your number %d is not equal to number3 %d\n", number1, number3);  }

  if (number1 > number3)
  { printf("Your number %d is greater than number3 %d\n", number1, number3);  }

  if (number1 < number3)
  { printf("Your number %d is less than number3 %d\n", number1, number3);  }

  if (number1 == number2)
  {
    printf("Your number %d is equal to number2 %d and ", number1, number2);
    if (number1 < number3)
    { printf("less than number3 %d\n", number3);  }
    else
    { printf("greater than number3 %d\n", number3);  }
  }
  else if (number1 == number3)
  {
    printf("Your number %d is equal to number3 %d and ", number1, number3);
    if (number1 < number2)
    { printf("less than number2 %d\n", number2);  }
    else
    { printf("greater than number2 %d\n", number2);  }
  }
  else if (number1 < number2 && number1 < number3)
  { printf("Your number %d is less than number2 %d and number3 %d\n", number1, number2, number3);  }
  else if (number1 > number2 && number1 < number3)
  { printf("Your number %d is greater than number2 %d and less than number3 %d\n", number1, number2, number3);  }
  else if (number1 > number2 && number1 > number3)
  { printf("Your number %d is greater than number2 %d and number3 %d\n", number1, number2, number3);  }
  else if (number1 > number3 && number1 < number2)
  { printf("Your number %d is greater than number3 %d and number2 %d\n", number1, number2, number3);  }
  else
  { printf("It may not work.\n");  }

  printf("Enter a character : ");
  scanf(" %c",&lettera);

  switch(lettera)
  {
    case 'a' :
    case 'e' :
    case 'i' :
    case 'o' :
    case 'u' :
      printf("lettera %c is a vowel\n", lettera);
      break;
    case 'g' :
    case 'j' :
    case 'p' :
    case 'q' :
    case 'y' :
      printf("lettera %c has a tail\n", lettera);
      break;
    case 'b' :
    case 'c' :
    case 'd' :
    case 'f' :
    case 'h' :
    case 'm' :
    case 'n' :
    case 'r' :
    case 's' :
      printf("lettera %c is written with a curve\n", lettera);
      break;
    case 'k' : case 'l' :  case 't' : case 'v' : case 'w' : case 'x' : case 'z' :
      printf("lettera %c is written with straight lines\n", lettera);
      break;
    default: 
      printf("lettera %c is not lowercase\n", lettera);
      break;
  }

  return 0;
}
