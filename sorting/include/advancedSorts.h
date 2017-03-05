/**
 *  advancedSorts.h
 *
 *  Author: David Piper
 *
 *      The purpose of this header file is to define the functions
 *  needed for the speedier and more advanced sorting algorithms.
 */
#include <stdlib.h>

void ASorts_quicksort(int* array, int len);
void ASorts_quicksort_internal(int* array, int len, int left, int right);

void ASorts_mergesort(void* array, int len);
void ASorts_mergesortInternal(void* array, int* temp,
        int leftStart, int rightEnd);
void ASorts_merge(void* array, void* temp, int leftStart,
        int rightStart);
