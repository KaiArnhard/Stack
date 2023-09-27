#include "../include/stack.h"

void StackCtor (stack_t* stk, size_t capacity, const char* name, const size_t line, const char* file, const char* function) {
    assert(stk);
    #if defined(CANARY_PROT)
        char* ptr = nullptr;
        ptr = (char* ) calloc(capacity * sizeof(elem_t) + 2 * sizeof(canary_t), sizeof(char));
        assert(ptr);
        stk->data = (elem_t*) (ptr + sizeof(canary_t));

    #else
        stk->data = (elem_t*) calloc(capacity, sizeof(elem_t));
        
    #endif // CANARY_PROT
    stk->capacity = capacity;
    stk->size = 0;
    stk->OldCapacity = 0;
    stk->var = {name, line, file, function};
    
    PoisStack(stk);
    STACK_CHECK(stk);
}

void StackDtor(stack_t* stk) {
    STACK_CHECK(stk);

    PoisStack(stk);
    free(stk->data);
    stk->data = nullptr;
    stk->capacity = UINT_MAX;
    stk->size = UINT_MAX;
    stk->var = {"alsdjfas", UINT_MAX, "aslkdfjaslkf", "lasdkjfsaklf"};
    stk = nullptr;
    fclose(PointerToDump);
}

void PoisStack(stack_t* stk) {
    for (size_t counter = stk->size; counter < stk->capacity; counter++) {
        stk->data[counter] = POISON;
    }
}

void StackPush(stack_t* stk, const elem_t variable) {
    STACK_CHECK(stk);
    if (stk->size + 1 == stk->capacity) {
        stk->OldCapacity = StackResize(stk, UP);
    }
    
    stk->data[stk->size] = variable;
    stk->size++;
    STACK_CHECK(stk);
}

void StackPop(stack_t* stk, elem_t* ptr) {
    STACK_CHECK(stk);
    if (stk->OldCapacity != 0 && stk->size <= stk->OldCapacity - 3) {
        stk->OldCapacity = StackResize(stk, DOWN);
    }
    stk->size--;
    *ptr = stk->data[stk->size];
    stk->data[stk->size] = POISON;
    STACK_CHECK(stk);
}

size_t StackResize(stack_t* stk, bool CodeOfResize) {
    STACK_CHECK(stk);
    elem_t* ptr = nullptr;
    size_t OldCapacity = 0;
    switch (CodeOfResize) {
    case DOWN:
        ptr = (elem_t*) realloc(stk->data, sizeof(elem_t) * stk->OldCapacity);
        assert(ptr);
        stk->data = ptr;
        PoisStack(stk);
        stk->capacity = stk->OldCapacity;
        break;
    case UP:
        OldCapacity = stk->capacity;
        stk->capacity *= ResizeConst;
        ptr = (elem_t*) realloc(stk->data, sizeof(elem_t) * stk->capacity);
        assert(ptr);
        stk->data = ptr;
        break;
    default:
        abort();
        break;
    }
    STACK_CHECK(stk);
    return OldCapacity;
}

void StackDump(stack_t* stk, const char* file, const char* function, size_t line) {
    
    fprintf(PointerToDump, "Stack [%p], %s  from %s line: %d %s \n\n", stk, stk->var.name, stk->var.file, stk->var.line, stk->var.function);
    fprintf(PointerToDump, "Called from %s(%d), %s\n", file, line, function);
    fprintf(PointerToDump, "Error number %d\n", MyError);
    fprintf(PointerToDump, "size = %d, capacity = %d \n", stk->size, stk->capacity);
    fprintf(PointerToDump, "data [%p] \n", stk->data);

    if (stk->capacity != UINT_MAX && stk->data != nullptr) {
        size_t counter = 0;
        for (; counter < stk->size && counter < stk->capacity; counter++) {
            fprintf(PointerToDump, "[%d] = %d \n", counter, stk->data[counter]);
        }
        PrintOfPoison(stk, counter, PointerToDump);
    
    } else if (stk->size != __UINT32_MAX__) {
        for (size_t counter = 0; counter < stk->size; counter++) {
            fprintf(PointerToDump, "[%d] = %d \n", counter, stk->data[counter]);
        }
    }
    
    exit(-1);
}

void PrintOfPoison(stack_t* stk, size_t counter, FILE* fp) {
    for (; counter < stk->capacity; counter++) {
            fprintf(fp, "[%d] = ", counter);
            for (size_t i = 0; i < 4; i++) {
                fputc(*((char*) (stk->data + counter) + i), fp);
            }
            fprintf(fp, "\n");
        }
}

size_t StackVerify(stack_t* stk) {
    assert(stk);
    if (stk->data == nullptr) {
        MyError |= STACK_ERROR_PTR_TO_DATA_ZERO;
    } if (stk->capacity < stk->size) {
        MyError |= STACK_ERROR_SIZE_OVER_CAPACITY;
    } if (stk->capacity == __UINT32_MAX__) {
        MyError |= STACK_ERROR_CAPACITY_LOWER_ZERO;
    } if (stk->capacity == 0) {
        MyError |= STACK_ERROR_CAPACITY_EQUAL_ZERO;
    } if (stk->size == __UINT32_MAX__) {
        MyError |= STACK_ERROR_SIZE_LOWER_ZERO;
    } if (stk->capacity < DefaultSize) {
        MyError |= STACK_ERROR_CAPACITY_LOWER_DEFAULT;
    }
    MyError = STACK_ERROR_STACK_OVERFLOW;
    return MyError;
}
