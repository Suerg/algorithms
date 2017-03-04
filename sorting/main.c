#include <stdio.h>

#include "basicSorts.h"

void printArray(int* array, int len);

int main()
{
    int array[5] = {5, 3, 2, 1, 4};
    printArray(array, 5);
    insertionSort(array, 5);
    printArray(array, 5);

    return 0;
}

void printArray(int* array, int len)
{
    int i;
    for (i=0; i<5; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
