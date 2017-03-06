#include <stdio.h>
#include <stdlib.h>

#include "basicSorts.h"
#include "advancedSorts.h"

void printArray(int* array, int len);

int intcmp(const void* a, const void* b)
{
    if ( *(int *)a < *(int *)b ) return -1;
    if ( *(int *)a == *(int *)b ) return 0;
    if ( *(int *)a > *(int *)b ) return 1;
}

int main()
{
    int array[7] = {7, 6, 5, 4, 3, 2, 1};
    printArray(array, 7);
    Sorts_bubbleSort(array, 7, sizeof(int), intcmp);
    printArray(array, 7);

    return 0;
}

void printArray(int* array, int len)
{
    int i;
    for (i=0; i<len; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
