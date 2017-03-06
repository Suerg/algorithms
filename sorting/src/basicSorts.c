#include <stdio.h>
#include "basicSorts.h"

/**
 * Based on:
 * http://stackoverflow.com/questions/13469381/how-to-make-generic-function-using-void-in-c
 */
void Sorts_swap(void* p1, void* p2, size_t size)
{
    size_t i;
    char* byte1 = (char*)p1;
    char* byte2 = (char*)p2;
    char byte;

    for (i=0; i<size; i++) {
        byte     = byte1[i];
        byte1[i] = byte2[i];
        byte2[i] = byte;
    }
}

void Sorts_insertionSort(void* array, int len, size_t size,
        int (*cmp)(const void*, const void *))
{
    int i, j;
    for (i=1; i<len; i++) {
        for (j=i;
                cmp(
                    (char *)array+(j-1)*size,
                    (char *)array+j*size
                ) == 1;
                /*array[j-1] > array[j];*/
                j--) {
            Sorts_swap(
                    (char *)array+j*size,
                    (char *)array+(j-1)*size, size);
        }
    }
}

void Sorts_bubbleSort(void* array, int len, size_t size,
        int (*cmp)(const void*, const void*))
{
    int i, j;
    for (i=0; i<len; i++) {
        for (j=len-1; j>=i+1; j--) {
            if (cmp(
                    (char *)array+j*size,
                    (char *)array+(j-1)*size
                    )
                    == -1) {
                 Sorts_swap(
                        (char *)array+j*size,
                        (char *)array+(j-1)*size,
                        size
                        );
            }
            /*if (array[j] < array[j-1]) {*/
                /*Sorts_swap(&array[j], &array[j-1], size);*/
            /*}*/
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
void Sorts_selectionSort(void* array, int len, size_t size,
        int (*cmp)(const void*, const void*))
{
    int i, j;
    for (i=0; i<len; i++) {
        int min = i;
        /* sorted to end */
        for (j=i; j<len; j++) {
            if (cmp(
                        (char *)array+j*size,
                        (char *)array+min*size
                    ) == -1) {
                min = j;
            }
            /*if (array[j] < array[min]) {*/
                /*min = j;*/
            /*}*/
        }
        Sorts_swap(
                (char *)array+i*size,
                (char *)array+min*size,
                size);
    }

}

/**
 *  Sorts_intcmp
 *
 *      Int comparison function
 *  follows the same standard as qsort.
 */
int Sorts_intcmp(const void* a, const void* b)
{
    if ( *(int *)a < *(int *)b ) return -1;
    if ( *(int *)a == *(int *)b ) return 0;
    if ( *(int *)a > *(int *)b ) return 1;
}

int Sorts_charcmp(const void* a, const void* b)
{
    if ( *(char *)a < *(char *)b ) return -1;
    if ( *(char *)a == *(char *)b ) return 0;
    if ( *(char *)a > *(char *)b ) return 1;
}

int Sorts_longcmp(const void* a, const void* b)
{
    if ( *(long *)a < *(long *)b ) return -1;
    if ( *(long *)a == *(long *)b ) return 0;
    if ( *(long *)a > *(long *)b ) return 1;
}
