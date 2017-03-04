#ifndef LINKED_LIST_H
#define LINKED_LIST_H
/**
 *  linked-list.h
 *
 *  Author: David Piper
 *
 *      The purpose of this file is to define
 *  the linked list data structure. Which is implemented
 *  as a series of nodes in memory, unlike the stack and
 *  queue which are simply operations on top of arrays.
 */
#include <stdlib.h>
#include <assert.h>

struct _Node
{
    int mValue; /* the actual item stored */
    int mKey; /* like an array index */
    struct _Node* mNext; /* the "child" of this node */
};

typedef struct _Node Node;

/**
 * LL_initNode
 *
 *      Setup the a node.
 */
Node* LL_initNode(int key, int value);

/**
 * LL_insert
 *
 *      Inserts an element at the
 *  end of the list
 */
void LL_insert(Node* head, int value);

/**
 * LL_getElement
 *
 *      Gets the value at the given key.
 */
int LL_getElement(Node* head, int key);

#endif /* LINKED_LIST_H */
