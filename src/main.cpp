#include "../include/stack.h"

int main() {
    Stack stk = {};
    
    STACK_CTOR(&stk);
    StackPush(&stk, 10);
    elem_t ptr = 0;
    StackPop(&stk, &ptr);
    printf("%d\n", ptr);
    StackDtor(&stk);
}
