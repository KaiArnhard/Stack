#ifndef DEBUG_H
#define DEBUG_H

#define ASSERT(condition)                                                                                                          \
{                                                                                                                                  \
if(condition)                                                                                                                      \
    {                                                                                                                              \
        printf("ERROR number %d, on line %d, in function %s, in file %s\n", condition, __LINE__, __PRETTY_FUNCTION__, __FILE__);   \
        abort();                                                                                                                   \
    }                                                                                                                              \
}                                                    

const unsigned int STACK_ERROR_MEM_NULL             = 1;
const unsigned int STACK_ERROR_SIZE_BIGGER_CAPASITY = 2;
const unsigned int STACK_ERROR_SIZE_LOWER_ZERO      = 3;
const unsigned int STACK_ERROR_CAPASITY_LEQ_ZERO    = 4;
const unsigned int STACK_ERROR_WRONG_HASH           = 5;

#endif