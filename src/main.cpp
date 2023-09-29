#include "../include/stack.h"

int main() {
    stack_t stk = {};
    elem_t ptr = 0;

    STACK_CTOR(&stk);
    for (size_t i = 0; i < 8; i++) {
        StackPush(&stk, 10);
    }
    StackDtor(&stk);
}
