#include <stdio.h>
#include <stdlib.h>
#include "stack_elements.h"

int main()
{
    Stack st1 = { }; 
    elem_t x = 0; 

    StackInit(&st1, 6);
    StackDump(&st1);
    StackPush(&st1, 54);
    StackPush(&st1, 45);
    StackDump(&st1);
    StackPop(&st1, &x);
    StackDump(&st1);
    StackDtor(&st1);
    StackDump(&st1);

    return 0;                                                                       
}
