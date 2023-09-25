#ifndef STACK_H
#define STACK_H

#include <cstdio>
#include <cstdlib>
#include "../include/debug.h"

typedef int elem_t;

const size_t DefaultSize = 10;
const elem_t POISON = *((elem_t*) "POIS");

struct DebugVariables
{
    const char*  name;
    size_t       line;
    const char*  file;
    const char*  function;
};


struct stack_t
{
    elem_t*        data;
    size_t         size;
    size_t         capacity;
    DebugVariables var;  
};

#define STACK_CTOR(stk) {                                                          \
    StackCtor(stk, DefaultSize, #stk, __LINE__, __FILE__, __PRETTY_FUNCTION__);    \
}

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

static void StackCtor (stack_t* stk, size_t capacity, const char* name, const size_t line, const char* file, const char* function);
static void StackDtor (stack_t* stk);
static void PoisStack(stack_t* stk);

static void StackPush(stack_t* stk, const elem_t variable);
static void StackPop(stack_t* stk, elem_t* ptr);
static void StackResize(stack_t* stk);

static void StackDump(stack_t* stk, const char* file, const char* function, size_t line);
static Errors_t StackVerify(stack_t* stk);


#endif
