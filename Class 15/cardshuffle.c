#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARDS 52
#define FACES 13

typedef struct card {
    const char *face;
    const char *suit;
} Card;

void fillDeck(Card * const Deck, const char * Face[], const char * Suit[]);
void shuffle(Card * const Deck);
void deal(Card * const Deck);

int main()
{
   Card deck[CARDS];
   const char *face[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
   const char *suit[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

   srand(time(NULL));

   fillDeck(deck, face, suit);
   shuffle(deck);
   deal(deck);

   return 0;
}

void fillDeck(Card * const Deck, const char * Face[], const char * Suit[])
{
    for (size_t i = 0; i < CARDS; i++) {
        Deck[i].face = Face[i % FACES];
        Deck[i].suit = Suit[i / FACES];
    }
}

void shuffle(Card * const Deck)
{
    for (size_t i = 0; i < CARDS; i++) {
        size_t j = rand() % CARDS;
        Card temp = Deck[i];
        Deck[i] = Deck[j];
        Deck[j] = temp;
    }
}

void deal(Card * const Deck)
{
    for (size_t i = 0; i < CARDS; i++) {
        printf("%5s of %-8s", Deck[i], Deck[i].suit);
        ((i+1)% 5) ? printf(" ") : printf("\n");
    }
    printf("\n");
}
