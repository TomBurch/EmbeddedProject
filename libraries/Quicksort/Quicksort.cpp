#include "Arduino.h"
#include "Quicksort.h"

void quicksort(int array[], int low, int high) {
  if (low < high) {
    int p = partition(array, low, high);
    quicksort(array, low, p - 1);
    quicksort(array, p + 1, high);
  }
}

int partition(int array[], int low, int high) {
  int pivot = array[high];
  int i = low;
  for (int j = low; j < high; j++) {
    if (array[j] < pivot) {
      swap(&array[i], &array[j]);
      i++;
    }
  }
  swap(&array[i], &array[high]);
  return i;
}

//Swap 2 array elements using pointers
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
