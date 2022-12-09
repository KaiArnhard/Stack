#ifndef STACK_ELEMENTS_H
#define STACK_ELEMENTS_H

typedef double elem_t;

struct Stack
{
    elem_t *data;
    size_t capacity;
    size_t size;
};

const int POISON = 'SOIP';



void StackInit(Stack *stack, size_t capacity);
void StackDtor(Stack *stack);

void StackPush(Stack *stack, elem_t  elem);
void StackPop (Stack *stack, elem_t *elem);

void StackDump(Stack *stack);

int StackVerify(Stack *stack);

#endif