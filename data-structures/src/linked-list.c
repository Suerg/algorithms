/**
 * linked-list.c
 *
 * Author: David Piper
 *
 *      The purpose of this file is to implement
 *  the operations defined in linked-list.h.
 *  In other words, this file creates the various
 *  actions that can be done on the list.
 */
#include "linked-list.h"

LL_Node* LL_initNode(int value)
{
    LL_Node* node = malloc(sizeof(*node));
    /* make sure the malloc succeeded */
    if (node != NULL) {
        node->mValue = value;
        node->mNext = NULL;
        node->mPrevious = NULL;
    }
    return node;
}

/**
 *  LL_append
 *
 *      The purpose of this function is to
 *  add a new node with the given value to the
 *  end of the list pointed to by head.
 *
 *      Note however that head need not be the actual
 *  head of the list, in fact in order to do linear
 *  time appending one can keep track of the current
 *  node and simply pass that in and nodes will be
 *  appended to the end of the list in O(1) time.
 *
 *      This use of LL_append is the reason for
 *  the function returning a LL_Node. That is,
 *  the function returns the LL_Node that was created
 *  and appended to the list. Thus, the user can
 *  use this feature to update a pointer
 *  to a current node to do the aforementioned O(1) append
 *  trick.
 */
LL_Node* LL_append(LL_Node* head, int value)
{
    LL_Node* current = head;
    /* traverse the list */
    while (current->mNext != NULL) {
        current = current->mNext;
    }
    current->mNext = LL_initNode(value);
    current->mNext->mPrevious = current; /* set the new node's prev */
    return current->mNext; /* return the newly created node */
}

/**
 *  LL_prepend
 *
 *      The purpose of this function is to add a node
 *  to the front of a list. This can be useful for implementing
 *  things like queues. The returned node will be the new head.
 */
LL_Node* LL_prepend(LL_Node* head, int value)
{
    LL_Node* oldFront = head;
    LL_Node* newFront;
    /**
     *      traverse the list
     *  needed in case the user wanted to prepend to a node
     *  that isn't the head without traversing themselves.
     *
     *  TODO: add method that allows the user to insert in middle
     */
    while (oldFront->mPrevious) {
        oldFront=oldFront->mPrevious;
    }
    /* set the previous of head to new */
    newFront = LL_initNode(value);
    oldFront->mPrevious = newFront;
    /* make the new node point to the old head */
    newFront->mNext = oldFront;
    return newFront;
}

/**
 *  LL_getElement
 *
 *      The purpose of this node is to act like
 *  the array access operator. That is, given a node
 *  and an offset, it returns the node at that offset.
 */
LL_Node* LL_getElement(LL_Node* head, int index)
{
    int i; LL_Node* current = head;
    /* traverse the list */
    for (i=0; i<index; i++) {
        current = LL_getNext(current);
    }
    return current;
}

/**
 *  LL_getNext
 *
 *      The purpose of this function is to provide
 *  functionality similar to an iterators.next function.
 *  So it can be called repeatedly to traverse the list.
 */
LL_Node* LL_getNext(LL_Node* node)
{
    return node->mNext;
}

/**
 *  LL_getValue
 *
 *      Gets the value of the node at the given index.
 *  The purpose of this function is to act as a more user
 *  friendly wrapper for LL_getElement for times when the user
 *  doesn't need the actual Node* and just needs the value of
 *  the node.
 */
int LL_getValue(LL_Node* head, int index)
{
    return LL_getElement(head, index)->mValue;
}

/**
 *  LL_getNodeValue
 *
 *      Gets the value associated with the given node.
 *  The purpose of this function is to provide an interface
 *  for accessing the value of a node that has already been
 *  retrieved. This could already have been accomplished with
 *  a call to LL_getValue(node, 0) however this is a very
 *  ugly interface so I have provided this wrapper instead.
 */
int LL_getNodeValue(LL_Node* node)
{
    return node->mValue;
}

/**
 *  LL_delete
 *
 *      The purpose of this function is to remove
 *  the node at the given index from the linked-list.
 *  In addition, since we could be deleting the head
 *  we must also return the new head of the list.
 */
LL_Node* LL_delete(LL_Node* head, int index)
{
    LL_Node* node = LL_getElement(head, index);
    LL_Node* newHead;
    if (node->mPrevious) { /* isn't the first node */
        /* make the next node pointing here point to this next */
        node->mPrevious->mNext = node->mNext;
    }
    if (node->mNext) /* isn't the last node */ {
        /* make prev ptr pointing here point to this prev */
        node->mNext->mPrevious = node->mPrevious;
    }
    /* if we are deleting the head then return the new head */
    if (head == node) {
        newHead = node->mNext;
    } else {
        newHead = head;
    }
    free(node);
    return newHead;
}

/**
 *  LL_deleteList
 *
 *      The purpose of this function is to remove
 *  an entire linked-list.
 */
/* TODO: implement LL_dedleteList */
