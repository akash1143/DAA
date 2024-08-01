#include <stdio.h>
int main() {
    int first[100][100], second[100][100], result[100][100], r1, c1, r2, c2;
    printf("Enter rows and columns for the first matrix: ");
    scanf("%d %d", &r1, &c1);
    printf("\nEnter elements:\n");
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c1; ++j) {
            scanf("%d", &first[i][j]);
        }
    }
    printf("Enter rows and columns for the second matrix: ");
    scanf("%d %d", &r2, &c2);
    for (int i = 0; i < r2; ++i) {
        for (int j = 0; j < c2; ++j) {
                scanf("%d", &second[i][j]);
        }
    }
    if (c1 != r2) {
        printf("Error!");
    }
    else{
	for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < c1; ++k) {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }
    printf("\nOutput Matrix:\n");
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) {
            printf("%d ", result[i][j]);
            if (j == c2 - 1)
                printf("\n");
        }
    }
}
    return 0;
}
