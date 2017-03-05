/* TODO: add destructor */
/**
 * Author: David Piper
 *
 *      The purpose of this file is to implement the
 *  stack data structure. This will be implemented
 *  with an array for now.
 *  Specifically I want to implement the following
 *  operations:
 *      * push -- add an element to the top
 *      * pop -- remove an element from the top
 *      * peek -- like pop, but does not remove
 *      * isFull -- checks if the stack/array is full
 *      * isEmpty -- checks if the stack/array is empty
 */
#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

struct _Stack {
    int *mData; /* the pointer to the data */
    int mTop; /* the index of the top of the stack (-1 is empty) */
    int mSize; /* the number of elements in the underlying array */
};

typedef struct _Stack Stack;

/**
 * initStack:
 *      Initializes the stack, creates the
 *  structure and returns it. Takes in the
 *  max size of the stack.
 */
Stack* Stack_initStack(int maxSize);

/**
 * push:
 *      Takes in a pointer to a stack struct as well
 *  as the data to push onto the stack. It then does
 *  the push operation which adds this value to the
 *  top of the stack.
 */
void Stack_push(Stack *sp, int data);

/**
 * pop:
 *      Takes in a pointer to a stack struct.
 *  The function removes the top element from
 *  the stack given and returns it.
 */
int Stack_pop(Stack *sp);

/**
 * peek:
 *      Functions almost identically to pop, with
 *  the exception that it does not remove the top
 *  element, but simply returns it.
 */
int Stack_peek(Stack *sp);

/**
 * isFull:
 *      This function returns whether or not
 *  the stack has used all of the space in
 *  its array. So that no more elements can
 *  be added to it.
 */
int Stack_isFull(Stack *sp);

/**
 * isEmpty:
 *      Tells whether or not the stack has
 *  any elements.
 */
int Stack_isEmpty(Stack *sp);

#endif /* STACK_H */
