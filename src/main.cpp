#include "../include/stack.h"

int main() {
    stack_t stk = {};
    
    STACK_CTOR(&stk);
    StackPush(&stk, 10);
    elem_t ptr = 0;
    StackPop(&stk, &ptr);
    printf("%d\n", ptr);
    StackDtor(&stk);
}
