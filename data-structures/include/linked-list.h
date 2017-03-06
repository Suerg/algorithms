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

struct _LL_Node
{
    int mValue; /* the actual item stored */
    struct _LL_Node* mNext; /* the "child" of this node */
    struct _LL_Node* mPrevious; /* the "parent" of this node */
};

typedef struct _LL_Node LL_Node;

/**
 * LL_initNode
 *
 *      Setup the a node.
 */
LL_Node* LL_initNode(int value);

/**
 * LL_append
 *
 *      Inserts an element at the
 *  end of the list
 */
LL_Node* LL_append(LL_Node* head, int value);

/**
 *  LL_getElement
 *
 *      Gets the node at the given index.
 */
LL_Node* LL_getElement(LL_Node* head, int index);

/**
 *  LL_getNext
 *
 *      Gets the next node given a node.
 */
LL_Node* LL_getNext(LL_Node* node);

/**
 *  LL_getValue
 *
 *      Gets the value of the node at the given index.
 */
int LL_getValue(LL_Node* head, int index);

/**
 *  LL_getNodeValue
 *
 *      Gets the value of the passed in node.
 */
int LL_getNodeValue(LL_Node* node);

/**
 *  LL_delete
 *
 *      Deletes the node at the given index.
 *  Returns the head of the linked list after
 *  deletion, which could potentially change if
 *  the head is deleted.
 */
LL_Node* LL_delete(LL_Node* head, int index);

/**
 *  LL_deleteList
 *
 *      Deletes the entire linked-list pointed
 *  to by head.
 */
void LL_deleteList(LL_Node* head);

#endif /* LINKED_LIST_H */
