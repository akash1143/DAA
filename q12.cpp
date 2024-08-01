#include <stdio.h>

// Function to perform binary search
int binary_search(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == target) {
            return mid; // Target found at index mid
        } else if (arr[mid] < target) {
            low = mid + 1; // Search in the right half
        } else {
            high = mid - 1; // Search in the left half
        }
    }
    
    return -1; // Target not found
}

// Function to perform quicksort
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        
        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                // Swap arr[i] and arr[j]
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        // Swap arr[i + 1] and arr[high] (pivot)
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        
        int pi = i + 1; // Pivot index
        
        quicksort(arr, low, pi - 1); // Recursively sort the left subarray
        quicksort(arr, pi + 1, high); // Recursively sort the right subarray
    }
}

int main() {
    int arr[] = {34, 7, 23, 32, 5, 62, 32, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;
    
    printf("Enter the number to search: ");
    scanf("%d", &target);
    
    // Sort the array
    quicksort(arr, 0, size - 1);
    
    // Perform binary search
    int result = binary_search(arr, size, target);
    
    if (result != -1) {
        printf("Number %d found at index %d\n", target, result);
    } else {
        printf("Number %d not found in the array\n", target);
    }
    
    return 0;
}

