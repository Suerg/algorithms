#include <stdio.h>
#include <stdlib.h>

#include "basicSorts.h"
#include "advancedSorts.h"

void printArray(int* array, int len);

int main()
{
    int array[7] = {7, 6, 5, 4, 3, 2, 1};
    printArray(array, 7);
    ASorts_mergesort(array, 7, sizeof(int), Sorts_intcmp);
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
