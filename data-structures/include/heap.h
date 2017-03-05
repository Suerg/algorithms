/**
 *  heap.h
 *
 *  Author: David Piper
 *
 *      The purpose of this header file is to
 *  provide the definitions needed for the heap
 *  data structure. Specifically, this will be
 *  a flexible heap, in which the mMin property
 *  will determine whether or not the heap is
 *  a min heap. If this value is 0/false then
 *  it will be a max heap instead.
 */
#ifndef HEAP_H
#define HEAP_H

#include <stdlib.h>

struct _Heap {
    int* mValues; /* CLRS calls the values "keys" */
    int mMaxSize; /* the size of the underlying array */
    int mLen;
    int mMin; /* either min or max */
};

typedef struct _Heap Heap;

Heap* Heap_initHeap(int maxSize, int min);

/**
 *      This set of functions uses the special
 *  shape of heaps to calculate the relative indices
 *  of a node's: parent, left child, and right child.
 */
int Heap_parentIndex(Heap* heap, int index);
int Heap_leftChildIndex(Heap* heap, int index);
int Heap_rightChildIndex(Heap* heap, int index);

/**
 *  Heap_heapify
 *
 *      Transforms a heap with a broken
 *  heap property at the given index to
 *  a proper heap.
 */
void Heap_heapify(Heap* heap, int index);

/**
 *  Heap_buildHeap
 *
 *      This function converts an arbitrary array
 *  into a heap.
 */
Heap* Heap_buildHeap(int *array, int len, int min);

/**
 *      Returns either the max or min
 *  element of a the heap. Which will
 *  be either the first or last element
 *  of the heap.
 */
int Heap_maximum(Heap* heap);
int Heap_minimum(Heap* heap);

/**
 *      Functions the same as the above
 *  Heap_maximum and Heap_minimum functions
 *  with the exception that instead of just
 *  returning the element it actually deletes
 *  it. This is analogous to the difference
 *  between the peek and pop operations
 *  on stacks.
 */
int Heap_extractMax(Heap* heap);
int Heap_extractMin(Heap* heap);

/**
 *      These functions set the value ("key") of
 *  the element at the given index in the heap.
 */
void Heap_increaseValue(Heap* heap, int index, int value);
void Heap_decreaseValue(Heap* heap, int index, int value);

/**
 *  Heap_insert
 *
 *      This function adds a new element with the given
 *  value into the heap.
 */
void Heap_insert(Heap* heap, int value);

#endif /* HEAP_H */
