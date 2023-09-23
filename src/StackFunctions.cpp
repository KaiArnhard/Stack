#include "../include/stack.h"
#include <limits.h>

void StackCtor(Stack* stk, size_t capacity, const char* name, const size_t line, const char* file, const char* function) {

    assert(stk);
    stk->data = (elem_t*) calloc(capacity, sizeof(elem_t));
    stk->capacity = capacity;
    stk->size = 0;
    stk->var = {name, line, file, function};
    
    PoisStack(stk);
    STACK_DUMP(stk);
}

void StackDtor(Stack* stk) {
    STACK_DUMP(stk);

    free(stk->data);
    PoisStack(stk);
    stk->data = nullptr;
    stk->capacity = UINT_MAX;
    stk->size = UINT_MAX;
    stk->var = {"alsdjfas", UINT_MAX, "aslkdfjaslkf", "lasdkjfsaklf"};
    stk = nullptr;
}

void PoisStack(Stack* stk) {
    for (size_t counter = 0; counter < stk->capacity; counter++) {
        stk->data[counter] = POISON;
    }
}

void StackPush(Stack* stk, const elem_t variable) {
    STACK_DUMP(stk);
    stk->data[stk->size] = variable;
    stk->size++;
    STACK_DUMP(stk);
}

void StackPop(Stack* stk, elem_t* ptr) {
    STACK_DUMP(stk);
    stk->size--;
    *ptr = stk->data[stk->size];
    STACK_DUMP(stk);
}

void StackDump(Stack* stk, const char* file, const char* function, size_t line) {
    
    printf("Stack [%p], %s  from %s line: %d %s \n\n", stk, stk->var.name, stk->var.file, stk->var.line, stk->var.function);
    printf("Called from %s(%d), %s\n", file, line, function);
    printf("Number of Error %d\n", MyError);
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
    assert(stk);
    if (stk->data == nullptr) {
        MyError = STACK_ERROR_PTR_TO_DATA_ZERO;
        return STACK_ERROR_PTR_TO_DATA_ZERO;
    } else if (stk->capacity < stk->size) {
        MyError = STACK_ERROR_SIZE_OVER_CAPACITY;
        return STACK_ERROR_SIZE_OVER_CAPACITY;
    } else if (stk->capacity == 0 || stk->capacity == UINT_MAX) {
        MyError = STACK_ERROR_CAPACITY_LEQUAL_ZERO;
        return STACK_ERROR_CAPACITY_LEQUAL_ZERO;
    } else if (stk->size == UINT_MAX) {
        MyError = STACK_ERROR_SIZE_LOWER_ZERO;
        return STACK_ERROR_SIZE_LOWER_ZERO;
    }
    
    return STACK_NO_ERRORS;
}
