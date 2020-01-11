#ifndef Quicksort_h
#define Quicksort_h

#include "Arduino.h"

extern void quicksort(int array[], int low, int high);

extern int partition(int array[], int low, int high);

extern void swap(int *a, int *b);

#endif

