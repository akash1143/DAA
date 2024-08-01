#include <stdio.h>
#include <stdbool.h>

#define MAX 20

int board[MAX][MAX];

// Function to print the board configuration
void printBoard(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if it's safe to place a queen at board[row][col]
bool isSafe(int row, int col, int n) {
    int i, j;

    // Check this column on all rows
    for (i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Check upper left diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check upper right diagonal
    for (i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

// Recursive function to solve the N Queens problem
bool solveNQueens(int row, int n) {
    if (row >= n) {
        return true; // All queens are placed
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, n)) {
            board[row][col] = 1; // Place queen

            if (solveNQueens(row + 1, n)) {
                return true; // Recur to place next queen
            }

            board[row][col] = 0; // Backtrack if placing queen doesn't lead to a solution
        }
    }

    return false; // No place is valid
}

int main() {
    int n;

    printf("Enter the number of queens (and size of the board): ");
    scanf("%d", &n);

    // Initialize the board with 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = 0;
        }
    }

    if (solveNQueens(0, n)) {
        printf("One of the solutions is:\n");
        printBoard(n);
    } else {
        printf("No solution exists for %d queens.\n", n);
    }

    return 0;
}

