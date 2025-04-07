#include <stdio.h>

// function to swap elements
void swap(float *a, float *b) {
  float t = *a;
  *a = *b;
  *b = t;
}

// function to find the partition position
int partition(float array[], int low, int high) {
  // select the rightmost element as pivot
  float pivot = array[high];
  
  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;
      // swap element at i with element at j
      swap(&array[i], &array[j]);
    }
  }

  // swap the pivot element with the greater element at i
  swap(&array[i + 1], &array[high]);

  // return the partition point
  return (i + 1);
}

// function to perform quicksort
void quickSort(float array[], int low, int high) {
  if (low < high) {
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pi = partition(array, low, high);
    
    // recursive call on the left of pivot
    quickSort(array, low, pi - 1);
    
    // recursive call on the right of pivot
    quickSort(array, pi + 1, high);
  }
}

// function to print array elements
void printArray(float array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%.2f  ", array[i]);  // Print with 2 decimal places
  }
  printf("\n");
}

// main function
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

  printf("Unsorted Array:\n");
  printArray(data, size);

  // Perform quicksort on the data
  quickSort(data, 0, size - 1);

  printf("Sorted array in ascending order:\n");
  printArray(data, size);

  return 0;
}

