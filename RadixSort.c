#include <stdio.h>

// Function to get the maximum value in an array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform Radix Sort
void radixSort(int arr[], int n) {
    // Find the maximum value to determine the number of passes
    int max = getMax(arr, n);

    // Perform passes until the array is sorted
    for (int exp = 1; max / exp > 0; exp *= 10) {
        // Create counting buckets (0-9)
        int count[10] = {0};

        // Count occurrences of each digit in the current place value
        for (int i = 0; i < n; i++) {
            int digit = (arr[i] / exp) % 10;
            count[digit]++;
        }

        // Accumulate count array to get stable sorting based on previous digits
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        // Output elements back to the array in sorted order
        int output[n];
        for (int i = n - 1; i >= 0; i--) {
            int digit = (arr[i] / exp) % 10;
            count[digit]--;
            output[count[digit]] = arr[i];
        }

        // Copy the output array back to the original array
        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
        }
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {170, 43, 75, 90, 802, 24, 567};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: ");
    printArray(arr, n);

    radixSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
