#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef double elem_t;

struct StackInfo
{
    elem_t *data;
    size_t capacity;
    size_t size;
};

struct Stack
{
    elem_t *data;
    size_t capacity;
    size_t size;
    StackInfo stDump;
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

    StackInit(&st1, 6);
    StackDump(&st1);
    StackPush(&st1, 54);
    StackDump(&st1);
    StackDtor(&st1);

    return 0;
}

void StackInit(Stack *stack, size_t capacity)
{
    assert(capacity);

    (stack->stDump).capacity = capacity;
    stack->capacity = capacity;
    
    stack->data = (elem_t*) calloc(stack->capacity, sizeof(elem_t));
    assert(stack->data);
    
    (stack->stDump).data = stack->data;
    (stack->stDump).size = stack->size = 0;
    
    for (size_t counter = 0; counter < stack->capacity; counter++)
    {
        (stack->data)[counter] = poison;
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
    if (stack->data != (elem_t*) poison)
    {
        printf("Number of stack elements %d\n", stack->size);
        printf("Stack capacity %d\n", stack->capacity);
        printf("Pointer to the first element of stack %p, pointer to the top of stack %p\n", (stack->stDump).data, stack->data);
        printf("Stack elements:\n");

        for (size_t counter = 0; counter < stack->capacity; counter++)
        {
            printf("%d\t%lg\n", counter, (stack->stDump).data[counter]);
        }  
    }
    else if (stack->data == (elem_t*) poison)
    {
        printf("Stack was destroyed, values after destructions\n");
        printf("Number of stack elements %d\n", stack->size);
        printf("Stack capacity %d\n", stack->capacity);
        printf("Pointer to the first element of stack %p, pointer to the top of stack %p\n", stack->stDump.data, stack->data);
        printf("Stack elements:\n");

        for (size_t counter = 0; counter < (stack->stDump).capacity; counter++)
        {
            printf("%d\t%lg\n", counter, (stack->stDump).data[counter]);
        }
    }
    printf("\nClick enter button to continue\n");
    while (!getchar())
        { }       
}