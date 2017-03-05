/**
 *  advancedSorts.c
 *
 *  Author: David Piper
 *
 *      The purpose of this file is to implement the various functions
 *  dealing with advanced sorting algorithms defined in the respective
 *  header file.
 */
#include "advancedSorts.h"

/**
 *  ASorts_merge
 *
 *      This procedure takes in an array along with the indices
 *  of two sorted adjacent subarrays and merges them together.
 *  Specifically, it takes the inclusive start of the left subarray
 *  and the inclusive end of the right subarray and merges.
 *
 *   ---------------
 *  | 1 | 3 | 2 | 8 |
 *   ---------------
 *    ^           ^
 *   leftStart rightEnd
 */
void ASorts_merge(int* array, int* temp, int leftStart, int rightEnd)
{
    int i, j, k;
    int leftEnd = (rightEnd-leftStart)/2;
    int rightStart = leftEnd+1;
    for (i=leftStart, j=rightStart, k=0; i<=leftEnd || j<=rightEnd; k++) {
        if (i>leftEnd) { /* left subarray done */
            temp[k] = array[j];
            j++;
        } else if (j>rightEnd) { /* right subarray done */
            temp[k] = array[i];
            i++;
        } else { /* neither done yet */
            if (array[i] < array[j]) {
                temp[k] = array[i];
                i++;
            } else {
                temp[k] = array[j];
                j++;
            }
        }
    }
}
