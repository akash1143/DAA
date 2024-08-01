#include <stdio.h>

// Function to reverse the given number
int reverse_number(int num) {
    int reversed = 0;
    while (num != 0) {
        int digit = num % 10;  // Get the last digit
        reversed = reversed * 10 + digit;  // Append digit to the reversed number
        num /= 10;  // Remove the last digit from the number
    }
    return reversed;
}

int main() {
    int num;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    int reversed = reverse_number(num);
    
    printf("Reversed number is %d\n", reversed);
    
    return 0;
}

