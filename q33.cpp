#include <stdio.h>

#define MAX_SIZE 100

// Function to print the list
void printList(int list[], int size) {
    printf("List: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

// Function to insert a number at a specific position
void insertNumber(int list[], int *size, int num, int pos) {
    if (pos < 0 || pos > *size) {
        printf("Invalid position!\n");
        return;
    }

    if (*size >= MAX_SIZE) {
        printf("List is full!\n");
        return;
    }

    // Shift elements to the right to make space for the new element
    for (int i = *size; i > pos; i--) {
        list[i] = list[i - 1];
    }

    // Insert the new number
    list[pos] = num;
    (*size)++;
}

int main() {
    int list[MAX_SIZE];
    int size = 0;
    int num, pos;

    // Read the initial list
    printf("Enter the number of elements in the list: ");
    scanf("%d", &size);

    if (size > MAX_SIZE || size < 0) {
        printf("Invalid size. Please enter a number between 0 and %d.\n", MAX_SIZE);
        return 1;
    }

    printf("Enter the elements of the list:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &list[i]);
    }

    // Read the number to be inserted and its position
    printf("Enter the number to be inserted: ");
    scanf("%d", &num);
    printf("Enter the position where the number should be inserted: ");
    scanf("%d", &pos);

    // Insert the number into the list
    insertNumber(list, &size, num, pos);

    // Print the updated list
    printList(list, size);

    return 0;
}
 
