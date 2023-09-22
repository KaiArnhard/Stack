#include "../include/stack.h"

int main() {
    Stack stk = {};
    
    STACK_CTOR(&stk);
    StackDtor(&stk);
}

void PoisStack(Stack* stk) {
    for (size_t counter = 0; counter < stk->capacity; counter++) {
        stk->data[counter] = POISON;
    }
}
