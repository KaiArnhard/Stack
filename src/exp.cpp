#include <cstdio>
#include <cstdlib>

typedef int elem_t;
typedef unsigned long long canary_t;

int main() {
    fopen("../StackDump.txt", "w");
    int capacity = 10;
    char* ptr = nullptr;
    int offset = 0;
    ptr = (char* ) calloc(capacity * sizeof(elem_t) + 2 * sizeof(canary_t), sizeof(char));

    ((canary_t*) ptr)[0] = 0xBADDED;
    
    if(offset = (((size_t) (ptr + sizeof(canary_t) + sizeof(elem_t) * capacity)) % 8) != 0) {
        ((canary_t*) (ptr + sizeof(canary_t) + capacity * sizeof(elem_t) + offset))[0] = 0xBAD0BED;
    } else {
        ((canary_t*) (ptr + sizeof(canary_t) + capacity * sizeof(elem_t)))[0] = 0xBAD0BED32;
    }
    printf("%d\n", offset);
    printf("%llX\n", ((canary_t*) ptr)[0]);
    printf("%llX\n", ((canary_t*) (ptr + sizeof(canary_t) + capacity * sizeof(elem_t)))[0]);
}