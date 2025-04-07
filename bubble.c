#include <stdio.h>

// Function to perform the bubble sort
void bubble_sort(float a[], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            // If the current element is greater than the next element, swap them
            if (a[j] > a[j + 1]) {
                // Swap the elements
                float temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

// Function to print the array
void print_array(float a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", a[i]);  // Print with 2 decimal places
    }
    printf("\n");
}

int main() {
    int n;

    // Ask the user for the number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Declare an array with the size entered by the user
    float arr[n];

    // Input the array elements from the user
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);  // Accept float values
    }

    // Print the original array
    printf("Original array: ");
    print_array(arr, n);

    // Sort the array
    bubble_sort(arr, n);

    // Print the sorted array
    printf("Sorted array: ");
    print_array(arr, n);

    return 0;
}
