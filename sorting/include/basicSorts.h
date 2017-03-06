/**
 *  basicSorts.h
 *
 *  Author: David Piper
 *
 *      This file defines some of the slower sorts
 *  these sorts will generally not be used for much
 *  due to their slowness, however they are good for
 *  testing because they are simpler to understand.
 */
void Sorts_insertionSort(void* array, int len, size_t size,
        int (*cmp)(const void*, const void*));
void Sorts_bubbleSort(void* array, int len, size_t size,
        int (*cmp)(const void*, const void*));
void Sorts_selectionSort(void* array, int len, size_t size,
        int (*cmp)(const void*, const void*));

void Sorts_swap(void* p1, void* p2, size_t size);
