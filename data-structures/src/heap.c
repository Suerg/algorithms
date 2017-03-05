/**
 *  TODO: refactor/rethink/redesign the heap
 *  module. It was written using CLRS as a template
 *  and this is increasingly becoming unwieldly. This
 *  is due to several factors:
 *      * the hardcoded max/min heap nature of the CLRS
 *        heaps
 *      * CLRS's use of -inf/inf sentinel values
 *      * the confusion caused by CLRS not having
 *        a separate heap struct/object and instead
 *        just using special arrays.
 *
 *  I will take a break from working on heaps, due to getting
 *  slightly burned out from messing around with them and will
 *  come back to finish them and do this refactor.
 *
 */
/**
 *  heap.c
 *
 *  Author: David Piper
 *
 *      The purpose of this file is to implement the heap operations
 *  defined in the heap.h header file.
 */
#include "heap.h"

Heap* Heap_initHeap(int maxSize, int min, int len)
{
    Heap* heap = malloc(sizeof(*heap));
    if (heap != NULL) {
        heap->mMaxSize = maxSize;
        heap->mLen     = len;
        heap->mMin     = min;
        heap->mValues  = malloc(sizeof(int)*maxSize);
    }
    return heap;
}

int Heap_parentIndex(Heap* heap, int index)
{
    return (index-2)/2;
}

int Heap_leftChildIndex(Heap* heap, int index)
{
    return index*2+1;
}

int Heap_rightChildIndex(Heap* heap, int index)
{
    return index*2+2;
}

/**
 *  Design Notes:
 *      My heap is intended to be a bit
 *  more flexible than the classic CLRS-style
 *  heap, that is it can be either min or max
 *  depending on the constructor. Thus, it will
 *  require special handling of all the cases
 *  relying on the < or > operators. So
 *  it would be a good idea to investigate which
 *  design pattern fits here to help.
 *
 *      Right off-hand, I cannot think of exactly which
 *  one is needed, however I think it is probably either
 *  Strategy or Factor/Abstract Factory. So I will need to
 *  study each of these in detail before proceeding.
 *
 *      My current thoughts are to have two sets of functions.
 *  Ones for max heaps and ones for min heaps. This will funcion
 *  similar to a factory/v-table dispatch.
 */
/**
 *      The purpose of this function is to fix a broken heap property.
 *  We know that the current node may be broken. So we look for the largest
 *  or smallest node either: the node itself, or its left or right children.
 *  In a min heap, we find the smallest and swap up. In a max heap we find
 *  the largest and swap up. Since in a max heap the largest element is the one
 *  at the top and in a min heap the smallest is the one at the top, if we assume
 *  that the children of the node i are already heaps, then if we swap the node i
 *  down (if it is not the largest/smallest) then it will eventually reach a place
 *  where it will satisfy the heap property.
 */
void Heap_heapify(Heap* heap, int index)
{
    /**
     * this function is only going to work on max heaps for now
     * until I get that working.
     */
    /**
     *  CLRS pseudocode:
     *      l = LEFT(i)
     *      r = RIGHT(i)
     *      if l <= A.heap-size and A[l] > A[i]
     *          largest = l
     *      else largest = i
     *      if r <= A.heap-size and A[r] > A[largest]
     *          largest = r
     *      if largest != i
     *          exchange A[i] with A[largest]
     *          MAX-HEAPIFY(A, largest)
     */
    int left  = Heap_leftChildIndex(heap, index);
    int right = Heap_rightChildIndex(heap, index);
    int largest;
    /* make sure that is in heap */
    if (left < heap->mLen &&
            heap->mValues[left] > heap->mValues[index]) {
        largest = left;
    } else {
        largest = index;
    }
    if (right < heap->mLen &&
            heap->mValues[right] > heap->mValues[largest]) {
        largest = right;
    }
    if (largest != index) {
        int temp = heap->mValues[index]
        heap->mValues[index]   = heap->mValues[largest];
        heap->mValues[largest] = temp;
        Heap_heapify(heap, largest);
    }

}

Heap* Heap_buildHeap(int *array, int len, int min)
{
    /**
     *  CLRS:
     *      A.heap-size = len
     *      for i = [A.length/2] downto 1
     *          MAX-HEAPIFY(A, i)
     */
    int i;
    Heap* heap = Heap_initHeap(len, min);
    /**
     *      Since CLRS simply uses an array as its heap
     *  this function is implemented a bit differently,
     *  instead adding each of the elements from the
     *  array to the heap using the insert operation.
     */
    for (i=0; i<len; i++) {
        Heap_insert(heap, array[i]);
    }
}

void Heap_insert(Heap* heap, int value)
{
    int newLen = heap->len;
    newLen++;
    if (newLen < heap->mMaxSize) {
        
    }
}
