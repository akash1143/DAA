#include <stdio.h>

// Function to generate Pascal's Triangle
void generatePascalsTriangle(int n) {
    int pascal[n][n];
    
    // Initialize the Pascal's Triangle
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pascal[i][j] = 0;
        }
    }

    // Generate Pascal's Triangle
    for (int i = 0; i < n; i++) {
        pascal[i][0] = 1; // The first column is always 1
        for (int j = 1; j <= i; j++) {
            if (j == i) {
                pascal[i][j] = 1; // The diagonal is always 1
            } else {
                pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
            }
        }
    }

    // Print Pascal's Triangle
    for (int i = 0; i < n; i++) {
        // Print leading spaces for alignment
        for (int j = 0; j < n - i - 1; j++) {
            printf("   ");
        }

        // Print the numbers
        for (int j = 0; j <= i; j++) {
            printf("%4d", pascal[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter the number of rows for Pascal's Triangle: ");
    scanf("%d", &n);

    generatePascalsTriangle(n);

    return 0;
}

