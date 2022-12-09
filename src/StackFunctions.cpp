#include <stdio.h>
#include <stdlib.h>
#include "stack_elements.h"
#include "debug.h"

                                                                    //TODO assert (define), wrong size, wrong pointer, нарушение целостности, расширение стека при нехватке
                                                                    //TODO в дампе проверять хеш, 

void StackInit(Stack *stack, size_t capacity)
{

    stack->capacity = capacity;
    
    stack->data = (elem_t*) calloc(stack->capacity, sizeof(elem_t));
    
    stack->size = 0;
    
    for (size_t counter = 0; counter < stack->capacity; counter++)
    {
        stack->data[counter] = POISON;
    }
}

void StackPush(Stack *stack, elem_t elem)
{
    ASSERT(StackVerify(stack));
    stack->data[stack->size] = elem;
    stack->size++;
    ASSERT(StackVerify(stack));
}

void StackPop(Stack *stack, elem_t *elem)
{ 
    ASSERT(StackVerify(stack));
    *elem = *(stack->data);
    stack->data[stack->size - 1] = 0;
    stack->size--;
    ASSERT(StackVerify(stack));
}

void StackDtor(Stack* stack)
{
    ASSERT(StackVerify(stack));
    stack->size  = POISON;

    for (size_t counter = 0; counter < stack->capacity; counter++)
    {
        stack->data[counter] = POISON;
    }
    stack->capacity = POISON;
    free(stack->data);
    stack->data = (elem_t*) POISON;
}

void StackDump(Stack *stack)
{
    if (stack->data == (elem_t*) POISON)
    {
        printf("Stack was destroyed\n");
    }
    else
    {
        printf("Pointer to the beging of stack %p\n", stack->data);
        printf("Number of elements in stack %d, all elements %d\n", stack->size, stack->capacity);
        for (size_t counter = 0; counter < stack->size; counter++)
        {
            printf("%d\t%lg\n", counter, stack->data[counter]);
        }
        
    }

    system("pause");       
}

int StackVerify(Stack *stack)
{
    if (stack->data == NULL)
    {
        return STACK_ERROR_MEM_NULL;
    }
    else if (stack->capacity <= 0)
    {
        return STACK_ERROR_CAPASITY_LEQ_ZERO;
    }
    else if (stack->size < 0)
    {
        return STACK_ERROR_SIZE_LOWER_ZERO;
    }
    else if (stack->size > stack->capacity)
    {
        return STACK_ERROR_SIZE_BIGGER_CAPASITY;
    }
    else
    {
        return 0;
    }
    
}