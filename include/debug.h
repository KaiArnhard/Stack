#ifndef DEBUG_H
#define DEBUG_H


enum Errors_t {
    STACK_NO_ERRORS                  = 0,
    STACK_ERROR_STACK_OVERFLOW       = 1,
    STACK_ERROR_PTR_TO_STK_ZERO      = 2,
    STACK_ERROR_PTR_TO_DATA_ZERO     = 4,
    STACK_ERROR_SIZE_OVER_CAPACITY   = 8,
    STACK_ERROR_SIZE_LOWER_ZERO      = 16,
    STACK_ERROR_CAPACITY_LEQUAL_ZERO = 32
};

static Errors_t MyError = STACK_NO_ERRORS;

#endif