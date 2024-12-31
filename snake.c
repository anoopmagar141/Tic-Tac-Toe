#include <stdio.h>

#define SIZE 3

char board[SIZE][SIZE]; // Game board
char player = 'X';      // Current player

// Function to initialize the game board
void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '1' + i * SIZE + j; // Fill board with numbers 1-9
        }
    }
}


int main() {
    int position;
    initializeBoard();

    printf("Welcome to Tic-Tac-Toe!\n");
    displayBoard();

    while (1) {
        printf("Player %c, enter your position (1-9): ", player);
        scanf("%d", &position);

        if (position < 1 || position > 9) {
            printf("Invalid position! Enter a number between 1 and 9.\n");
            continue;
        }

        makeMove(position);
        displayBoard();

        if (checkWinner()) {
            printf("Player %c wins!\n", (player == 'X') ? 'O' : 'X'); // Previous player wins
            break;
        }

        if (isDraw()) {
            printf("It's a draw!\n");
            break;
        }
    }

    return 0;
}
