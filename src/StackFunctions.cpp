#include "../include/stack.h"
#include <limits.h>

static void StackCtor(stack_t* stk, size_t capacity, const char* name, const size_t line, const char* file, const char* function) {

    assert(stk);
    stk->data = (elem_t*) calloc(capacity, sizeof(elem_t));
    stk->capacity = capacity;
    stk->size = 0;
    stk->var = {name, line, file, function};
    
    PoisStack(stk);
    STACK_DUMP(stk);
}

static void StackDtor(stack_t* stk) {
    STACK_DUMP(stk);

    free(stk->data);
    PoisStack(stk);
    stk->data = nullptr;
    stk->capacity = UINT_MAX;
    stk->size = UINT_MAX;
    stk->var = {"alsdjfas", UINT_MAX, "aslkdfjaslkf", "lasdkjfsaklf"};
    stk = nullptr;
}

static void PoisStack(stack_t* stk) {
    for (size_t counter = 0; counter < stk->capacity; counter++) {
        stk->data[counter] = POISON;
    }
}

static void StackPush(stack_t* stk, const elem_t variable) {
    STACK_DUMP(stk);
    if (stk->size == stk->capacity) {
        StackResize(stk);
    }
    
    stk->data[stk->size] = variable;
    stk->size++;
    STACK_DUMP(stk);
}

static void StackPop(stack_t* stk, elem_t* ptr) {
    STACK_DUMP(stk);
    if (stk->size <= stk->capacity - (stk->capacity / 5)) {
        StackResize(stk);
    }
    stk->size--;
    *ptr = stk->data[stk->size];
    STACK_DUMP(stk);
}

static void StackDump(stack_t* stk, const char* file, const char* function, size_t line) {
    
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

static Errors_t StackVerify(stack_t* stk) {
    assert(stk);
    if (stk->data == nullptr) {
        MyError | STACK_ERROR_PTR_TO_DATA_ZERO;
    } if (stk->capacity < stk->size) {
        MyError | STACK_ERROR_SIZE_OVER_CAPACITY;
    } if (stk->capacity == 0 || stk->capacity == UINT_MAX) {
        MyError | STACK_ERROR_CAPACITY_LEQUAL_ZERO;
    } if (stk->size == UINT_MAX) {
        MyError | STACK_ERROR_SIZE_LOWER_ZERO;
    } if (stk->size == UINT_MAX) {
        MyError | STACK_ERROR_SIZE_LOWER_ZERO;
    } if (stk->capacity < DefaultSize) {
        MyError | STACK_ERROR_CAPACITY_LOWER_DEFAULT;
    }
       
    return MyError;
}

static void StackResize(stack_t* stk) {
    
}