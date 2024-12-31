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

// Function to display the board
void displayBoard() {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1)
                printf("|");
        }
        printf("\n");
        if (i < SIZE - 1)
            printf("---|---|---\n");
    }
    printf("\n");
}

// Function to check for a winner
int checkWinner() {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) // Row check
            return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) // Column check
            return 1;
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) // Main diagonal
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) // Opposite diagonal
        return 1;

    return 0; // No winner yet
}

// Function to check if the board is full
int isDraw() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') // Empty cell exists
                return 0;
        }
    }
    return 1; // Board is full
}

// Function to make a move
void makeMove(int position) {
    int row = (position - 1) / SIZE;
    int col = (position - 1) % SIZE;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = player; // Mark the cell
        player = (player == 'X') ? 'O' : 'X'; // Switch player
    } else {
        printf("Invalid move! Try again.\n");
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
