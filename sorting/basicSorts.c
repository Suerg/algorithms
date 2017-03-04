#include "basicSorts.h"

void swap(int *array, int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void insertionSort(int* array, int len)
{
    int i, j;
    for (i=1; i<len; i++) {
        for (j=i; array[j-1] > array[j]; j--) {
            swap(array, j, j-1);
        }
    }
}

void bubbleSort(int* array, int len)
{
    int i, j;
    for (i=0; i<len; i++) {
        for (j=len-1; j>=i+1; j--) {
            if (array[j] < array[j-1]) {
                swap(array, j, j-1);
            }
        }
    }
}
