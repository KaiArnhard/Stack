#ifndef STACK_H
#define STACK_H

#include <cstdio>
#include <cstdlib>
#include <limits.h>
#include "debug.h"

typedef int elem_t;

static const int ResizeConst = 2;

enum Resize {
    UP   = 1,
    DOWN = 0
};

const size_t DefaultSize = 10;
const elem_t POISON = *((elem_t*) "POIS");

struct DebugVariables
{
    const char*  name;
    size_t       line;
    const char*  file;
    const char*  function;
};
struct stack_t {
    #if defined(CANARY_PROT)
        canary_t CanaryLeft = 0xDED320BED;
    #endif //LEFT_CANARY_PROT 
    
    elem_t*        data;
    size_t         size;
    size_t         capacity;
    DebugVariables var;  
    size_t         OldCapacity;

    #if defined(CANARY_PROT)
        canary_t CanaryLeft = 0xBADC0FFEE;
    #endif //RIGHT_CANARY_PROT
};

#define STACK_CTOR(stk) {                                                          \
    StackCtor(stk, DefaultSize, #stk, __LINE__, __FILE__, __PRETTY_FUNCTION__);    \
}

void StackCtor (stack_t* stk, size_t capacity, const char* name, const size_t line, const char* file, const char* function);
void StackDtor (stack_t* stk);
void PoisStack(stack_t* stk);

void StackPush(stack_t* stk, const elem_t variable);
void StackPop(stack_t* stk, elem_t* ptr);
size_t StackResize(stack_t* stk, bool CodeOfResize);

void StackDump(stack_t* stk, const char* file, const char* function, size_t line);
size_t StackVerify(stack_t* stk);
void PrintOfPoison(stack_t* stk, size_t counter, FILE* fp);

#endif
