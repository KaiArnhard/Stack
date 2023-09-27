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

#if defined(CANARY_PROT)
    struct stack_t {
        canary_t LEFT_CANARY = 0xDED320BED;
        elem_t*        data;
        size_t         size;
        size_t         capacity;
        DebugVariables var;  
        size_t         OldCapacity;
        canary_t RIGHT_CANARY = 0xD;
    };
#else
    struct stack_t {
        elem_t*        data;
        size_t         size;
        size_t         capacity;
        DebugVariables var;  
        size_t         OldCapacity;
        
    };
    
#endif // CANARY_PROT

#define STACK_CTOR(stk) {                                                          \
    StackCtor(stk, DefaultSize, #stk, __LINE__, __FILE__, __PRETTY_FUNCTION__);    \
}

void StackCtor (stack_t* stk, size_t capacity, const char* name, const size_t line, const char* file, const char* function);
void StackDtor (stack_t* stk);
void PoisStack(stack_t* stk);

void StackPush(stack_t* stk, const elem_t variable);
void StackPop(stack_t* stk, elem_t* ptr);
size_t StackResize(stack_t* stk, bool CodeOfResize);


#endif
