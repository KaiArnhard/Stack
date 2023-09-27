#ifndef DEBUG_H
#define DEBUG_H
    
typedef unsigned long long canary_t;

static const char* NameOfDump = "../StackDump.txt";

enum Errors_t {
    STACK_NO_ERRORS                    = 0,
    STACK_ERROR_STACK_OVERFLOW         = 1,
    STACK_ERROR_PTR_TO_STK_ZERO        = 2,
    STACK_ERROR_PTR_TO_DATA_ZERO       = 4,
    STACK_ERROR_SIZE_OVER_CAPACITY     = 8,
    STACK_ERROR_SIZE_LOWER_ZERO        = 16,
    STACK_ERROR_CAPACITY_LOWER_ZERO    = 32,
    STACK_ERROR_CAPACITY_EQUAL_ZERO    = 64,
    STACK_ERROR_CAPACITY_LOWER_DEFAULT = 128,
    #if defined(CANARY_PROT)
    
        STACK_ERROR_LEFT_CANARY_DIED       = 256,
        STACK_ERROR_RIGHT_CANARY_DIED      = 512,
    #endif // CANARY_PROT
    
};

static size_t MyError = STACK_NO_ERRORS;

#define STACK_DUMP(stk)                                                    \
    if (StackVerify(stk)) {                                                \
        StackDump(stk, __FILE__, __PRETTY_FUNCTION__, __LINE__);           \
    }    

#define assert(condition)                                                                                                       \
if(!condition) {                                                                                                                \
    printf("Error number %d, occurs in FILE %s, on line %d, function %s\n", condition, __FILE__, __LINE__, __PRETTY_FUNCTION__);\
    MyError | STACK_ERROR_PTR_TO_STK_ZERO;                                                                                      \
    abort();                                                                                                                    \
    }


#endif