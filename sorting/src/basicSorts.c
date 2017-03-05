#include <stdio.h>
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

/**
 * selectionSort:
 *
 *      Selection sort works by maintaining a sorted and unsorted portion
 *  of the array, similarly to insertion sort. The difference is that
 *  insertion sort works by putting each element into the correct place
 *  in the subarray, while selection sort finds the minimum element of the
 *  unsorted array and inserts in into the correct place in the sorted
 *  subarray. This means, that each time the element is put into the sorted
 *  subarray it is in its final position.
 */
void selectionSort(int* array, int len)
{
    int i, j;
    for (i=0; i<len; i++) {
        int min = i;
        /* sorted to end */
        for (j=i; j<len; j++) {
            if (array[j] < array[min]) {
                min = j;
            }
        }
        swap(array, i, min);
    }

}
