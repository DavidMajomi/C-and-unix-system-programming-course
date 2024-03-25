#include <stdio.h>

struct card {
   char *face;
   char *suit;
};

int main()
{
   struct card aCard;
   struct card *cardPtr = &aCard;

   aCard.face = "Ace";
   aCard.suit = "Spade";

   printf("%s of %s . Operator\n%s of %s -> Operator\n%s of %s Pointer", aCard.face, aCard.suit, aCard->face, aCard->suit, (*cardPtr).face, (*cardPtr).suit);
   printf("\n");
   return 0;
}
