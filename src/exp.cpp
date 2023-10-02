#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <stdint.h>

size_t StackHash(char* ptr, size_t lenght);
int main() {

    int data[20];
    for (size_t i = 0; i < 20; i++) {
        data[i] = i;
    }
    
    printf("%d \n", sizeof(size_t));

}

size_t StackHash(char* ptr, size_t length) {
    size_t hash = 0;

    for (size_t count = 0; count < (length - (length % 4)); count += 4) {
        printf("%d\n", count);
        for (size_t counter = 0; counter < 4; counter++) {
            ((char*) &hash)[counter] |= ptr[count + counter];
        }
    }
    for (int count = (length - 1 - (length % 4)); count >= 0; count -= 4) {
        printf("%d\n", count);
        for (int counter = 3; counter < 8; counter++) {
            ((char*) &hash)[counter] |= ptr[count - counter];
        }
    }
    
    return hash;
}