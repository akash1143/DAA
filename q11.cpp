#include <stdio.h>

// Function to copy a string from source to destination
void copy_string(char *source, char *destination) {
    while (*source != '\0') {
        *destination = *source;
        source++;
        destination++;
    }
    *destination = '\0';  // Null-terminate the destination string
}

int main() {
    char source[100];
    char destination[100];
    
    printf("Enter a string: ");
    fgets(source, sizeof(source), stdin);
    
    // Remove newline character if present
    size_t len = strlen(source);
    if (len > 0 && source[len - 1] == '\n') {
        source[len - 1] = '\0';
    }

    copy_string(source, destination);
    
    printf("Copied string is: %s\n", destination);
    
    return 0;
}

