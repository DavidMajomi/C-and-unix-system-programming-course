#include <stdio.h>

void print_board(char board[3][3]);
int is_full(char board[3][3]);
int has_won(char board[3][3], char player);

int main() {
    // Declare and initialize the Tic Tac Toe board
    char board[3][3] = {
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'}
    };

    int player = 1;
//    int moves = 0;

    while (!is_full(board)) {
        print_board(board);

        // Get the player's move
        int x, y;
        printf("Player %d, enter your move (row and column): ", player);
        scanf("%d %d", &x, &y);

        // Check if the move is valid
        if (board[x-1][y-1] == '-') {
            // Make the move
            board[x-1][y-1] = (player == 1) ? 'X' : 'O';

            // Check if the player has won
            if (has_won(board, (player == 1) ? 'X' : 'O')) {
                print_board(board);
                printf("Player %d has won!\n", player);
                break;
            }

            // Switch to the other player
            player = (player % 2) + 1;
//            moves++;
        }
        else {
            printf("Invalid move. Try again.\n");
        }
    }

    // Check for a tie
    if (!has_won(board, 'X') && !has_won(board, 'O') && is_full(board)) {
        print_board(board);
        printf("The game is a tie!\n");
    }
    return 0;
}

// Function to print the Tic Tac Toe board
void print_board(char board[3][3]) {
    printf("--[TIC TAC TOE]--\n");
    for (int i = 0; i < 3; i++) {
        printf("  ");
        for (int j = 0; j < 3; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
    }
    printf("-----------------\n");
}

// Function to check if the board is full
int is_full(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '-') {
                return 0;
            }
        }
    }
    return 1;
}

// Function to check if a player has won
int has_won(char board[3][3], char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }
    return 0;
}

