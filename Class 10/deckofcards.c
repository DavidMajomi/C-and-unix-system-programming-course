#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52

void shuffle(unsigned int Deck[][FACES]);
void deal(unsigned int Deck[][FACES], const char *Face[], const char *Suit[]);

int main() {
    unsigned int deck[SUITS][FACES]= {0};

    srand(time(NULL));
    shuffle(deck);

    const char *face[FACES] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    const char *suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    
    deal(deck, face, suit);
    printf("\n");
}

void shuffle(unsigned int Deck [][FACES]) {
    for (size_t card = 0; card < CARDS; card++) {
        size_t row;
        size_t column;
        do {
            row = rand() % SUITS;
            column = rand() % FACES;            
        } while (Deck[row][column] != 0);
        Deck[row][column] = card;
    }
}

void deal(unsigned int Deck[][FACES], const char *Face[], const char *Suit[]) {
    for (size_t card = 0; card < CARDS; card++) {
        for (size_t row = 0; row < SUITS; row++) {
            for (size_t column = 0; column < FACES; column++) {
                if (Deck[row][column] == card) {
                    printf("%7s of %-8s%c", Face[column], Suit[row],((card+1) % 2) ==0 ? '\n' : '\t');
                }
            }
        }
    }
}