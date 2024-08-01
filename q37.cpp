#include <stdio.h>
#include <math.h>

void findFactors(int n) {
    printf("Factors of %d are: ", n);
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            printf("%d ", i);
            if (i != n / i) {
                printf("%d ", n / i);
            }
        }
    }
    printf("\n");
}

int main() {
    int n = 100;
    findFactors(n);
    return 0;
}

