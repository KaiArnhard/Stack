#include <stdio.h>
#include <stdlib.h>

typedef double elem_t;

struct Stack
{
    elem_t *data;
    size_t capacity;
    size_t size;
};

void StackInit(Stack *stack, size_t capacity);
void StackPush(Stack *stack, elem_t elem);
void StackPop(Stack *stack, elem_t *elem);

int main()
{
    Stack st1;

    StackInit(&st1, 5);
    StackPush(&st1, 45);
    elem_t elem = 0;
    StackPop(&st1, &elem);
    printf("%lg", elem);
    return 0;
}

void StackInit(Stack *stack, size_t capacity)
{
    stack->capacity = capacity;
    stack->data = (elem_t*) calloc(stack->capacity, sizeof(elem_t));
    stack->size = 0;
}

void StackPush(Stack *stack, elem_t elem)
{
    *(stack->data) = elem;
    stack->data++;
    stack->size++;
}

void StackPop(Stack *stack, elem_t *elem)
{
    stack->data--; 
    *elem = *(stack->data);
    *(stack->data) = 0;
    stack->size--;
}