#include "../include/stack.h"

int main() {
    stack_t stk = {};
    int i = 10;
    fprintf(PointerToDump, "%d\n", i);
    StackDump(&stk, "file", "function", 12);
}

void StackDump(stack_t* stk, const char* file, const char* function, size_t line) {
    
    printf("debug\n");
    fprintf(PointerToDump, "Stack [%p], %s  from %s line: %d %s \n\n", stk, stk->var.name, stk->var.file, stk->var.line, stk->var.function);
    fprintf(PointerToDump, "Called from %s(%d), %s\n", file, line, function);
    fprintf(PointerToDump, "Number of Error %d\n", MyError);
    fprintf(PointerToDump, "size = %d, capacity = %d \n", stk->size, stk->capacity);
    fprintf(PointerToDump, "data [%p] \n", stk->data);

    if (stk->capacity != UINT_MAX && stk->data != nullptr) {
        size_t counter = 0;
        for (; counter < stk->size && counter < stk->capacity; counter++) {
            fprintf(PointerToDump, "[%d] = %d \n", counter, stk->data[counter]);
        }
        //PrintOfPoison(stk, counter, PointerToDump);
    
    } else if (stk->size != __UINT32_MAX__) {
        for (size_t counter = 0; counter < stk->size; counter++) {
            fprintf(PointerToDump, "[%d] = %d \n", counter, stk->data[counter]);
        }
    }
    
    //abort();
}