// Bubble Sort Algorithm
#include <stdio.h>
// Function to sort an array using Bubble Sort
void sort(int arr[], int n) {
    // Outer loop controls the number of passes.
    // After each pass, the largest unsorted element
    // moves (or "bubbles") to its correct position.
    for (int i = 0; i < n - 1; i++) {
        // Inner loop compares adjacent elements.
        // We stop at (n - i - 1) because the last i
        // elements are already sorted.
        for (int j = 0; j < n - i - 1; j++) {
            // Compare two neighboring elements.
            // If the left element is larger,
            // swap them.
            if (arr[j] > arr[j + 1]) {
                // Store the first value temporarily.
                int temp = arr[j];
                // Move the smaller value to the left.
                arr[j] = arr[j + 1];
                // Put the larger value on the right.
                arr[j + 1] = temp;
            }
        }
    }
}
int main() {
    // Array to be sorted
    int numbers[] = {76, 56, 89, 94, 78, 89, 90};
    // Calculate the number of elements in the array.
    // sizeof(numbers) gives the total bytes occupied by the array.
    // sizeof(numbers[0]) gives the bytes occupied by one integer.
    // Dividing them gives the number of elements.
    int n = sizeof(numbers) / sizeof(numbers[0]);
    // Display the original array.
    printf("Original Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n\n");
    // Sort the array.
    sort(numbers, n);
    // Display the sorted array.
    printf("Sorted Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    return 0;
}