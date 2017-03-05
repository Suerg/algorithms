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

int main()
{
    linkedListTest();
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
    Node* head = LL_initNode(0, 1);
    LL_insert(head, 3);
    printf("%d\n", LL_getElement(head, 0));
    printf("%d\n", LL_getElement(head, 1));
}
