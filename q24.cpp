#include <stdio.h>

// Function to check if a number is perfect
int is_perfect_number(int num) {
    int sum = 0;
    
    // Find divisors and their sum
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    
    // Check if sum of divisors is equal to the number
    return (sum == num);
}

int main() {
    int num;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    if (num <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }
    
    if (is_perfect_number(num)) {
        printf("%d is a perfect number.\n", num);
    } else {
        printf("%d is not a perfect number.\n", num);
    }
    
    return 0;
}

