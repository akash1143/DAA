#include <stdio.h>

// Function to calculate binomial coefficient C(n, k) using dynamic programming
int binomial_coefficient(int n, int k) {
    int C[n + 1][k + 1];
    int i, j;

    // Calculate value of Binomial Coefficient in bottom-up manner
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= (i < k ? i : k); j++) {
            // Base cases
            if (j == 0 || j == i)
                C[i][j] = 1;
            // Calculate value using previously stored values
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }

    return C[n][k];
}

int main() {
    int n, k;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter k: ");
    scanf("%d", &k);

    printf("Binomial Coefficient C(%d, %d) is %d\n", n, k, binomial_coefficient(n, k));

    return 0;
}

