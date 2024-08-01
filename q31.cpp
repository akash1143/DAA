#include <stdio.h>

// Function to find the sum of digits of a given number
int sumOfDigits(int num) {
    int sum = 0;

    // Handle negative numbers
    num = (num < 0) ? -num : num;

    while (num > 0) {
        sum += num % 10; // Add the last digit to sum
        num /= 10;       // Remove the last digit
    }

    return sum;
}

int main() {
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    int result = sumOfDigits(number);

    printf("The sum of the digits is: %d\n", result);

    return 0;
}

