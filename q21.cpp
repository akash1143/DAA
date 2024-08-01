#include <stdio.h>
#include <limits.h>

// Function to calculate the sum of frequencies from i to j
int sum(int freq[], int i, int j) {
    int s = 0;
    for (int k = i; k <= j; k++)
        s += freq[k];
    return s;
}

// Function to find the cost of the optimal binary search tree
int optimal_bst(int keys[], int freq[], int n) {
    // Create a 2D table to store results of subproblems
    int cost[n][n];

    // Cost when there's only one key
    for (int i = 0; i < n; i++)
        cost[i][i] = freq[i];

    // Fill the table in a bottom-up manner
    for (int L = 2; L <= n; L++) { // L is the chain length
        for (int i = 0; i <= n - L; i++) {
            int j = i + L - 1;
            cost[i][j] = INT_MAX;

            // Try making all keys in interval keys[i..j] root
            for (int r = i; r <= j; r++) {
                int c = ((r > i) ? cost[i][r - 1] : 0) +
                        ((r < j) ? cost[r + 1][j] : 0) +
                        sum(freq, i, j);
                if (c < cost[i][j])
                    cost[i][j] = c;
            }
        }
    }

    return cost[0][n - 1];
}

int main() {
    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n = sizeof(keys) / sizeof(keys[0]);

    printf("Cost of Optimal BST is %d\n", optimal_bst(keys, freq, n));

    return 0;
}

