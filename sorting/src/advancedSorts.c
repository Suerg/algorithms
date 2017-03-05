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
 *  ASorts_mergesort
 *
 *      Implements the mergesort algorithm.
 *  This algorithm works by using the divide-and-conquer
 *  paradigm. That is, it divides the problem of sorting
 *  up into smaller and smaller pieces until it has only
 *  two elements to compare and then it begins to merge
 *  the sorted subarrays.
 */
void ASorts_mergesort_int(int* array, int len)
{
    int* temp = malloc(sizeof(int)*len);
    ASorts_mergesortInternal(array, temp, 0, len-1);
}

/**
 *  ASorts_mergesortInternal
 *
 *      This is the actual mergesort procedure, the other one is
 *  simply a more user friendly version which handles the
 *  creation of the temp array and the index seletion.
 *
 *      The specific details of this version of the algorithm
 *  were taken from the HackerRank video on Merge Sort.
 *  Since the algorithm is so general, that it works for my
 *  use case as well as theirs. Note however, that the
 *  merge procedure is completely original.
 */
void ASorts_mergesortInternal_int(int* array, int* temp,
        int leftStart, int rightEnd)
{
    if (leftStart >= rightEnd) {
        return;
    }
    int middle = (leftStart+rightEnd)/2;
    ASorts_mergesortInternal(array, temp, leftStart, middle);
    ASorts_mergesortInternal(array, temp, middle+1, rightEnd);
    ASorts_merge(array, temp, leftStart, rightEnd);
}

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
void ASorts_merge_int(int* array, int* temp, int leftStart,
        int rightEnd)
{
    int i, j, k;
    int leftEnd = (rightEnd+leftStart)/2;
    int rightStart = leftEnd+1;
    for (i=leftStart, j=rightStart, k=leftStart; i<=leftEnd || j<=rightEnd; k++) {
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
    for (i=leftStart; i<=rightEnd; i++) {
        array[i] = temp[i];
    }
}
