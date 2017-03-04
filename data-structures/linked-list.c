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

Node* LL_initNode(int key, int value)
{
    Node* node = malloc(sizeof(*node));
    /* make sure the malloc succeeded */
    if (node != NULL) {
        node->mValue = value;
        node->mKey = key;
        node->mNext = NULL;
    }
    return node;
}

void LL_insert(Node* head, int value)
{
    Node* current = head;
    /* traverse the list */
    while (current->mNext != NULL) {
        current = current->mNext;
    }
    current->mNext = LL_initNode(current->mKey+1, value);
}

int LL_getElement(Node* head, int key)
{
    int i; Node* current = head;
    /* traverse the list */
    for (i=0; i<key; i++) {
        if (current->mNext != NULL) {
            current = current->mNext;
        } else {
            assert(0); /* crash and burn; key out of range */
        }
    }
    return current->mValue;
}
