#include <stdio.h>
#include <limits.h>  // For INT_MAX to represent the sentinel value

// Function to merge two halves of the array
void merge(int a[], int p, int q, int r) {
    // Find the sizes of the two sub-arrays to be merged
    int n1 = q - p + 1;
    int n2 = r - q;

    // Create temporary arrays L[] and R[]
    int L[n1 + 1], R[n2 + 1];

    // Copy data into temporary arrays L[] and R[]
    for (int i = 1; i <= n1; i++) {
        L[i] = a[p + i - 1];  // Note: L[i] corresponds to a[p + i - 1]
    }
    for (int j = 1; j <= n2; j++) {
        R[j] = a[q + j];  // Note: R[j] corresponds to a[q + j]
    }

    // Sentinel values at the end of the temporary arrays
    L[n1 + 1] = INT_MAX;  // Use INT_MAX as a sentinel value
    R[n2 + 1] = INT_MAX;  // Use INT_MAX as a sentinel value

    // Merge the temporary arrays back into the original array a[]
    int i = 1, j = 1;
    for (int k = p; k <= r; k++) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
    }
}

// Merge Sort function
void merge_sort(int a[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;  // Find the middle index
        merge_sort(a, p, q);   // Sort the first half
        merge_sort(a, q + 1, r); // Sort the second half
        merge(a, p, q, r);     // Merge the two sorted halves
    }
}

// Function to print the array
void print_array(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int n;

    // Ask the user for the number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Declare an array with the size entered by the user
    int arr[n];

    // Input the array elements from the user
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Print the original array
    printf("Original array: ");
    print_array(arr, n);

    // Perform merge sort on the array
    merge_sort(arr, 0, n - 1);

    // Print the sorted array
    printf("Sorted array: ");
    print_array(arr, n);

    return 0;
}

