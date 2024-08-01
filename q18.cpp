#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Function to print all prime numbers up to a given limit
void sieve_of_eratosthenes(int limit) {
    // Create an array to store the prime status of each number
    bool *is_prime = (bool *)malloc((limit + 1) * sizeof(bool));

    // Initialize all entries to true
    for (int i = 0; i <= limit; i++) {
        is_prime[i] = true;
    }

    is_prime[0] = is_prime[1] = false; // 0 and 1 are not prime numbers

    for (int p = 2; p * p <= limit; p++) {
        // If is_prime[p] is not changed, then it is a prime
        if (is_prime[p]) {
            // Update all multiples of p as false
            for (int i = p * p; i <= limit; i += p) {
                is_prime[i] = false;
            }
        }
    }

    // Print all prime numbers
    printf("Prime numbers up to %d are:\n", limit);
    for (int p = 2; p <= limit; p++) {
        if (is_prime[p]) {
            printf("%d ", p);
        }
    }
    printf("\n");

    // Free allocated memory
    free(is_prime);
}

int main() {
    int limit;
    printf("Enter the limit: ");
    scanf("%d", &limit);

    sieve_of_eratosthenes(limit);

    return 0;
}

