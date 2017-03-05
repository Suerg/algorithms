#include <stdio.h>
#include <stdlib.h>

#include "basicSorts.h"

void printArray(int* array, int len);

int main()
{               /*  i        j */
    int array[6] = {1, 3, 6, 2, 4, 8};
    int *temp = malloc(sizeof(int)*6);
    printArray(array, 6);
    ASorts_merge(array, temp, 0, 5);
    printArray(array, 6);

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
