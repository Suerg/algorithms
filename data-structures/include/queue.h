/* TODO: add destructor */
/**
 * queue.h
 *
 * Author: David Piper
 *
 *      The purpose of this file is to create
 *  the queue data structure. This data structure
 *  is one which follows a first-in first-out policy
 *  or FIFO. This means that, we need head and tail
 *  indices to track the first and last places in
 *  line.
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

struct _Queue
{
    int* mData;
    int mHead;
    int mTail;
    int mSize; /* array elements */
};

typedef struct _Queue Queue;

/**
 * initQueue:
 *      Setup the queue structure.
 */
Queue* Queue_initQueue(int size);

/**
 * enqueue:
 *      Adds an element to the end of the line.
 */
void Queue_enqueue(Queue *qp, int data);

/**
 * dequeue:
 *      Removes the element at the front of the line.
 */
int Queue_dequeue(Queue *qp);

/**
 * peek:
 *      Looks at the element at the front of the line,
 *  without removing it.
 */
int Queue_peek(Queue *qp);

/**
 * isFull:
 *      Looks to see if the tail of the line has reached
 *  the max capacity.
 */
int Queue_isFull(Queue* qp);

/**
 * isEmpty:
 *      Looks to see if the line is empty.
 */
int Queue_isEmpty(Queue* qp);

#endif /* QUEUE_H */
