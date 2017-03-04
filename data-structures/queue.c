#include "queue.h"

Queue* Queue_initQueue(int maxSize)
{
    Queue *queue = malloc(sizeof(*queue));
    /* make sure the malloc worked */
    if (queue != NULL) {
        queue->mHead = 0;
        queue->mTail = 0;
        queue->mData = malloc(sizeof(int)*maxSize);
        queue->mSize = maxSize;
    }
    return queue;
}

void Queue_enqueue(Queue* qp, int data)
{
    /* add the data to the line */
    qp->mData[qp->mTail] = data;

    /* extend the line for the next datum */
    if (qp->mTail == qp->mSize-1) {
        qp->mTail = 0; /* wrap around */
    } else {
        qp->mTail++;
    }
}

/* TODO: add error checking for when qp->mHead is -1 */
int Queue_dequeue(Queue* qp)
{
    int datum = qp->mData[qp->mHead];
    /* remove the old spot */
    if (qp->mHead == qp->mSize-1) {
        qp->mHead = 0; /* wrap around */
    } else {
        qp->mHead++;
    }
    return datum;
}

/* TODO: add error checking for when qp->mHead is -1 */
int Queue_peek(Queue* qp)
{
    return qp->mData[qp->mHead];
}
