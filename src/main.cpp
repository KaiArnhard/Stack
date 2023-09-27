#include "../include/stack.h"

int main() {
    stack_t stk = {};
    elem_t ptr = 0;

    STACK_CTOR(&stk);
    for (size_t i = 0; i < 11; i++) {
        StackPush(&stk, 10);
    }
    for (size_t i = 0; i < 9; i++) {
        StackPop(&stk, &ptr);
    }
    StackDtor(&stk);
}
