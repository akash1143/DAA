#include <stdio.h>
#include <string.h>
#include <ctype.h>
int isPalindrome(char str[]) {
    int l = 0;
    int h = strlen(str) - 1;
    while (l < h) {
        while (!isalnum(str[l]) && l < h)
            l++;
        while (!isalnum(str[h]) && l < h)
            h--;
        if (tolower(str[l]) != tolower(str[h]))
            return 0;
        l++;
        h--;
    }
    return 1;
}
int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;
    if (isPalindrome(str))
        printf("\"%s\" is a palindrome.\n", str);
    else
        printf("\"%s\" is not a palindrome.\n", str);
    return 0;
}

