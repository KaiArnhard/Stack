#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef double elem_t;

struct Stack
{
    elem_t *data;
    size_t capacity;
    size_t size;
};

const int poison = 'SOIP';

void StackInit(Stack *stack, size_t capacity);
void StackDtor(Stack *stack);

void StackPush(Stack *stack, elem_t  elem);
void StackPop (Stack *stack, elem_t *elem);

void StackDump(Stack *stack);

int main()
{
    Stack st1 = { }; 
    printf("%c", poison); 

    StackInit(&st1, 6);
    StackDtor(&st1);
    
    return 0;
}

void StackInit(Stack *stack, size_t capacity)
{
    assert(capacity);

    stack->capacity = capacity;
    stack->data = (elem_t*) calloc(stack->capacity, sizeof(elem_t));
    stack->size = 0;
    for (size_t counter = 0; counter < stack->capacity; counter++)
    {
        stack->data[counter] = poison;
    }
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
void StackDtor(Stack* stack)
{
    stack->size  = NULL;

    for (size_t counter = 0; counter < stack->capacity; counter++)
    {
        stack->data[counter] = poison;
    }
    stack->capacity = NULL;
    stack->data = (elem_t*) poison;
}

void StackDump(Stack *stack)
{
    Stack st2 = { };
    st2.capacity = stack->capacity;
    st2.size = stack->size;

    for (size_t counter = 0; counter < st2.size; counter++)
    {
        
    }
    
}