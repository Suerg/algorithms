/**
 *  The purpose of this file is to practice
 * implementing various data structures.
 * In particular I would like to implement
 * the following:
 *  * Stack (FILO)
 *  * Queue (FIFO)
 *  * Deque
 *  * Priority Queue
 *  * Binary Tree
 *  * Linked list
 *  * Doubly linked list
 *  * Circularly linked list
 *  * Hash Table
 *  * Binary Search Tree
 *  * Heap
 *
 * Advanced:
 *  * AVL Tree
 *  * Segment/Interval Tree
 *  * B-tree
 *  * Trie
 */

#include <stdio.h>
#include "stack.h"
#include "queue.h"
#include "linked-list.h"

void stackTest();
void queueTest();
void linkedListTest();
void linkedListTest2();
void linkedListTest3();

int main()
{
    linkedListTest();
    linkedListTest2();
    linkedListTest3();
    return 0;
}

void stackTest()
{
    Stack *sp = Stack_initStack(1000);
    Stack_push(sp, 1);
    Stack_push(sp, 2);
    Stack_push(sp, 5);
    printf("%d\n", Stack_pop(sp));
    printf("%d\n", Stack_pop(sp));
    printf("%d\n", Stack_pop(sp));
}

void queueTest()
{
    Queue* qp = Queue_initQueue(1000);
    Queue_enqueue(qp, 1);
    Queue_enqueue(qp, 3);
    printf("%d\n", Queue_dequeue(qp));
    printf("%d\n", Queue_dequeue(qp));
}

void linkedListTest()
{
    printf("Test Case #1\n");
    LL_Node* head = LL_initNode(1);
    LL_append(head, 3);
    printf("%d\n", LL_getValue(head, 0));
    head = LL_delete(head, 0);
    printf("%d\n", LL_getValue(head, 0));
    LL_delete(head, 0); /* delete the last node */
}

void linkedListTest2()
{
    int i;
    LL_Node* head = LL_initNode(1);
    LL_Node* current = head;
    LL_Node* next;

    printf("Test Case #2\n");

    for (i=2; i<=50; i++) {
        current = LL_append(current, i);
    }
    current = head; /* reset the current to head for printing */
    for (i=0; i<50; i++) {
        next = LL_getNext(current);
        printf("%d\n", LL_getNodeValue(current));
        current = next;
    }
    LL_deleteList(head); /* clean up after test*/
}

void linkedListTest3()
{
    int i;
    LL_Node* end = LL_initNode(1);
    LL_Node* head = end;
    LL_Node* currentFront = end;

    printf("Test Case #3\n");

    for (i=2; i<=50; i++) {
        currentFront = LL_prepend(currentFront, i);
    }
    head = currentFront; /* save a ref to the front */
    for (i=1; i<=50; i++) {
        printf("%d\n", LL_getNodeValue(currentFront));
        currentFront = LL_getNext(currentFront);
    }
    LL_deleteList(head); /* clean up after test */
}
