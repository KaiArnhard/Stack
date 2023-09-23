#ifndef DEBUG_H
#define DEBUG_H

#include "stack.h"

enum Errors_t {
    STACK_NO_ERRORS                  = 0,
    STACK_ERROR_STACK_OVERFLOW       = 1,
    STACK_ERROR_PTR_TO_STK_ZERO      = 2,
    STACK_ERROR_PTR_TO_DATA_ZERO     = 4,
    STACK_ERROR_SIZE_OVER_CAPACITY   = 8,
    STACK_ERROR_SIZE_LOWER_ZERO      = 16,
    STACK_ERROR_CAPACITY_LEQUAL_ZERO = 32
};

Errors_t MyError = STACK_NO_ERRORS;


#define STACK_DUMP(stk)                                                    \
    if (StackVerify(stk)) {                                                \
        StackDump(stk, __FILE__, __PRETTY_FUNCTION__, __LINE__);           \
    }    

#define assert(condition)                                                                                                       \
if(!condition) {                                                                                                                \
    printf("Error number %d, occurs in FILE %s, on line %d, function %s\n", condition, __FILE__, __LINE__, __PRETTY_FUNCTION__);\
    MyError = STACK_ERROR_PTR_TO_STK_ZERO;                                                                                      \
    abort();                                                                                                                    \
    }

void StackDump(Stack* stk, const char* file, const char* function, size_t line);
Errors_t StackVerify(Stack* stk);

#endif