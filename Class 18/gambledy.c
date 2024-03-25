#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cash = 100;

int Play(int);

int main () {
    int bet;
    while (cash > 0) {
        printf("What is your bet? $");
        scanf("%d",&bet);
        if (bet == 0 || bet > cash)
        { break; }
        Play(bet);
        printf("\nThank you for playing!!\n");
    }
}

int Play(int bet) {
    char *C = (char*)malloc(3*sizeof(char));
    int i;
    int guess;
    C[0] = 'J';
    C[1] = 'Q';
    C[2] = 'K';
    printf("Shuffling ..... \n");
    srand(time(NULL)); // Seeding random number generator
    for (i = 0; i <5; i++) {
        int x = rand() % 3;
        int y = rand() % 3;
        int temp = C[x];
        C[x] = C[y];
        C[y] = temp;
    }
    printf("What is the position of the Queen - 1, 2 or 3? ");
    scanf("%d",&guess);
    if (C[guess-1] == 'Q') {
        cash += 3 * bet;
        printf("You Win!! Cards are %c%c%c Total Cash = $%d\n",C[0],C[1],C[2],cash);
    }
    else {
        cash -= bet;
        printf("You Lose!! Cards are %c%c%c Total Cash = $%d\n",C[0],C[1],C[2],cash);
    }
    free(C);
}