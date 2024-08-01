#include <stdio.h>
#include <limits.h>

// Structure to hold the min and max values
typedef struct {
    int min;
    int max;
} MinMax;

// Function to find the min and max values using Divide and Conquer
MinMax find_min_max(int arr[], int left, int right) {
    MinMax result, left_result, right_result;
    int mid;

    // If there is only one element
    if (left == right) {
        result.min = arr[left];
        result.max = arr[left];
        return result;
    }

    // If there are two elements
    if (right == left + 1) {
        if (arr[left] < arr[right]) {
            result.min = arr[left];
            result.max = arr[right];
        } else {
            result.min = arr[right];
            result.max = arr[left];
        }
        return result;
    }

    // If there are more than two elements
    mid = (left + right) / 2;
    left_result = find_min_max(arr, left, mid);
    right_result = find_min_max(arr, mid + 1, right);

    // Compare results of two halves
    if (left_result.min < right_result.min) {
        result.min = left_result.min;
    } else {
        result.min = right_result.min;
    }

    if (left_result.max > right_result.max) {
        result.max = left_result.max;
    } else {
        result.max = right_result.max;
    }

    return result;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7, 3, 8};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    MinMax result;

    result = find_min_max(arr, 0, arr_size - 1);

    printf("Minimum element is %d\n", result.min);
    printf("Maximum element is %d\n", result.max);

    return 0;
}

