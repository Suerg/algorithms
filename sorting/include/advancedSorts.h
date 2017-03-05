/**
 *  advancedSorts.h
 *
 *  Author: David Piper
 *
 *      The purpose of this header file is to define the functions
 *  needed for the speedier and more advanced sorting algorithms.
 */

void ASorts_quicksort(int* array, int len);
void ASorts_quicksort_internal(int* array, int len, int left, int right);
void ASorts_mergesort(int* array, int len);
void ASorts_mergesort_internal(int* array, int len);
void ASorts_merge(int* array, int* temp, int leftStart, int rightStart);
