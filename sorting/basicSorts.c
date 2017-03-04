#include "basicSorts.h"

void insertionSort(int* array, int len)
{
    int i, j;
    for (i=1; i<len; i++) {
        for (j=i; array[j-1] > array[j]; j--) {
            int temp = array[j-1];
            array[j-1] = array[j];
            array[j] = temp;
        }
    }
}
