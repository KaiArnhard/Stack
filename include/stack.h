#ifndef STACK_H
#define STACK_H

#include <cstdio>
#include <cstdlib>

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


struct Stack
{
    elem_t*        data;
    size_t         size;
    size_t         capacity;
    DebugVariables var;  
};

#define STACK_CTOR(stk) {                                                          \
    StackCtor(stk, DefaultSize, #stk, __LINE__, __FILE__, __PRETTY_FUNCTION__);    \
}

void StackCtor (Stack* stk, size_t capacity, const char* name, const int line, const char* file, const char* function);
void StackDtor (Stack* stk);
void PoisStack(Stack* stk);

void StackPush(Stack* stk);
void StackPop(Stack *stk);

#endif
