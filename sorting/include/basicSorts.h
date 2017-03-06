/**
 *  basicSorts.h
 *
 *  Author: David Piper
 *
 *      This file defines some of the slower sorts
 *  these sorts will generally not be used for much
 *  due to their slowness, however they are good for
 *  testing because they are simpler to understand.
 *
 *      Each of the sorts are generic, meaning that
 *  they function in a way similar to qsort from the
 *  c standard library. Which also means that they
 *  can be used with any type of comparable item.
 */
void Sorts_insertionSort(void* array, int len, size_t size,
        int (*cmp)(const void*, const void*));
void Sorts_bubbleSort(void* array, int len, size_t size,
        int (*cmp)(const void*, const void*));
void Sorts_selectionSort(void* array, int len, size_t size,
        int (*cmp)(const void*, const void*));

void Sorts_swap(void* p1, void* p2, size_t size);

/**
 *      Some standard comparable functions
 *  provided for convenience.
 */
int Sorts_intcmp(const void* a, const void* b);
int Sorts_charcmp(const void* a, const void* b);
int Sorts_longcmp(const void* a, const void* b);
