#include <stdio.h>

// function to swap the position of two elements
void swap(float *a, float *b) {
  float temp = *a;
  *a = *b;
  *b = temp;
}

// function to perform the selection sort
void selectionSort(float array[], int size) {
  for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < size; i++) {
      // Select the minimum element in each loop.
      if (array[i] < array[min_idx])
        min_idx = i;
    }
    // put min at the correct position
    swap(&array[min_idx], &array[step]);
  }
}

// function to print the array
void printArray(float array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%.2f  ", array[i]);  // Print with 2 decimal places
  }
  printf("\n");
}

// driver code
int main() {
  int size;

  // Ask the user for the size of the array
  printf("Enter the number of elements: ");
  scanf("%d", &size);

  float data[size];  // Declare the array with the user-defined size

  // Ask the user to input the elements of the array
  printf("Enter %d floating-point numbers:\n", size);
  for (int i = 0; i < size; ++i) {
    scanf("%f", &data[i]);  // Accept float values
  }

  // Perform selection sort
  selectionSort(data, size);

  // Print the sorted array
  printf("Sorted array in Ascending Order:\n");
  printArray(data, size);

  return 0;
}

