#include "stack.h"

Stack* Stack_initStack(int maxSize)
{
    Stack *stack = malloc(sizeof(*stack));
    /* make sure the malloc was successful */
    if (stack != NULL) {
        stack->mTop = -1;
        stack->mData = malloc(sizeof(int)*maxSize);
        stack->mSize = maxSize;
    }
    return stack;
}

/* TODO: check if full first */
void Stack_push(Stack *sp, int data)
{
    (sp->mTop)++;
    sp->mData[sp->mTop] = data;
}

/* TODO: check if empty first */
int Stack_pop(Stack *sp)
{
    int data = sp->mData[sp->mTop];
    (sp->mTop)--;
    return data;
}

/* TODO: check if empty as the array access would be -1 */
int Stack_peek(Stack *sp)
{
    return sp->mData[sp->mTop];
}

int Stack_isFull(Stack *sp)
{
    return sp->mTop == sp->mSize-1;
}

int Stack_isEmpty(Stack *sp)
{
    return sp->mTop < 0;
}
