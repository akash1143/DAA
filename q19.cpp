#include <stdio.h>

// A structure to represent an item with weight and value
typedef struct {
    int value;
    int weight;
} Item;

// Function to sort items by value/weight ratio
void sort_items_by_ratio(Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            double r1 = (double)items[j].value / items[j].weight;
            double r2 = (double)items[j + 1].value / items[j + 1].weight;
            if (r1 < r2) {
                // Swap items[j] and items[j+1]
                Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

// Function to perform the fractional knapsack problem
double fractional_knapsack(Item items[], int n, int capacity) {
    sort_items_by_ratio(items, n);

    int cur_weight = 0; // Current weight in knapsack
    double final_value = 0.0; // Result (value in knapsack)

    // Loop through all items
    for (int i = 0; i < n; i++) {
        // If adding Item won't overflow, add it completely
        if (cur_weight + items[i].weight <= capacity) {
            cur_weight += items[i].weight;
            final_value += items[i].value;
        } else {
            // If we can't add current Item, add fractional part of it
            int remain = capacity - cur_weight;
            final_value += items[i].value * ((double)remain / items[i].weight);
            break;
        }
    }

    return final_value;
}

int main() {
    int n; // Number of items
    int capacity; // Capacity of knapsack

    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    Item items[n];

    for (int i = 0; i < n; i++) {
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    double max_value = fractional_knapsack(items, n, capacity);

    printf("Maximum value in Knapsack = %.2f\n", max_value);

    return 0;
}

