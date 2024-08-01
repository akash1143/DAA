#include <stdio.h>
int isPerfect(int num) {
    int sum = 0;
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return (sum == num);
}
int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (num <= 0) {
        printf("Please enter a positive integer.\n");
    } else {
        if (isPerfect(num)) {
            printf("%d is a perfect number.\n", num);
        } else {
            printf("%d is not a perfect number.\n", num);
        }
    }
    return 0;
}

