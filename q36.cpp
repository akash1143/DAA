#include <stdio.h>

int containerLoading(int weights[], int n, int capacity) {
    int total_weight = 0;
    int containers = 0;

    for (int i = 0; i < n; i++) {
        if (total_weight + weights[i] <= capacity) {
            total_weight += weights[i];
        } else {
            containers++;
            total_weight = weights[i];
        }
    }

    if (total_weight > 0) {
        containers++;
    }

    return containers;
}

int main() {
    int weights[] = {10, 20, 30, 40, 50};
    int capacity = 50;
    int n = sizeof(weights) / sizeof(weights[0]);

    printf("Number of containers needed: %d\n", containerLoading(weights, n, capacity));
    return 0;
}

