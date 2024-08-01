#include <stdio.h>

void printSubset(int subset[], int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }
    printf("]\n");
}

void subsetSum(int set[], int subset[], int n, int subsetSize, int total, int node, int target) {
    if (total == target) {
        printSubset(subset, subsetSize);
        return;
    }

    if (node == n) {
        return;
    }

    subset[subsetSize] = set[node];
    subsetSum(set, subset, n, subsetSize + 1, total + set[node], node + 1, target);
    subsetSum(set, subset, n, subsetSize, total, node + 1, target);
}

void findSubsets(int set[], int n, int target) {
    int subset[n];
    subsetSum(set, subset, n, 0, 0, 0, target);
}

int main() {
    int set[] = {3, 34, 4, 12, 5, 2};
    int target = 9;
    int n = sizeof(set) / sizeof(set[0]);

    printf("Subsets of the given set that sum to %d are:\n", target);
    findSubsets(set, n, target);

    return 0;
}

