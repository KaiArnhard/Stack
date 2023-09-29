#include "../include/stack.h"

int main() {
    stack_t stk = {};
    elem_t ptr = 0;

    STACK_CTOR(&stk);
    for (size_t i = 0; i < 12; i++) {
        StackPush(&stk, 10);
    }
    STACK_DUMP(&stk);
    for (size_t i = 0; i < 11; i++) {
        printf("%d\n", stk.size);
        StackPop(&stk, &ptr);
    }
    
    STACK_DUMP(&stk);
    StackDtor(&stk);
}
