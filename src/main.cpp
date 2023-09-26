#include "../include/stack.h"
#include "../include/debug.h"

int main() {
    stack_t stk = {};
    elem_t ptr = 0;

    STACK_CTOR(&stk);
    for (size_t i = 0; i < 11; i++) {
        StackPush(&stk, 10);
    }
    printf("capacity %d \n", stk.capacity);
    for (size_t i = 0; i < 12; i++) {
        StackPop(&stk, &ptr);
    }
    printf("capacity %d \n", stk.capacity);
    StackDtor(&stk);
}
