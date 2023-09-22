#include "../include/stack.h"
#include "../include/debug.h"
#include <limits.h>

void StackCtor(Stack* stk, size_t capacity, const char* name, const int line, const char* file, const char* function) {

    assert(stk);
    stk->data = (elem_t*) calloc(capacity, sizeof(elem_t));
    stk->capacity = capacity;
    stk->size = 0;

    stk->var.file = file;
    stk->var.function = function;
    stk->var.name = name;
    stk->var.line = line;

    PoisStack(stk);
}

void StackDtor(Stack* stk) {
    STACK_DUMP(stk);

    PoisStack(stk);
    free(stk->data);
}

void StackPush(Stack* stk) {

}

void StackDump(Stack* stk, const char* file, const char* function, size_t line) {
    
    assert(stk);
    printf("Stack [%p], %s  from %s line: %d %s \n\n", stk, stk->var.name, stk->var.file, stk->var.line, stk->var.function);
    printf("Called from %s(%d), %s\n", file, line, function);
    printf("size = %d, capacity = %d \n", stk->size, stk->capacity);
    printf("data [%p] \n", stk->data);

    if (stk->capacity != UINT_MAX && stk->data != nullptr) {
        size_t counter = 0;
        for (; counter < stk->size; counter++) {
            printf("[%d] = %d \n", counter, stk->data[counter]);
        }
        for (; counter < stk->capacity; counter++) {
            printf("[%d] = ", counter);
            for (size_t i = 0; i < 4; i++) {
                putchar(*((char*) (stk->data + counter) + i));
            }
            printf("\n");
        }
    }
    
    abort();
}

Errors_t StackVerify(Stack* stk) {
    if (stk->data == nullptr) {
        MyError = STACK_ERROR_PTR_TO_DATA_ZERO;
        return STACK_ERROR_PTR_TO_DATA_ZERO;
    }
    return STACK_ERROR_STACK_OVERFLOW;
}
