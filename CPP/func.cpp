#include <stdio.h>
#include <cassert>
#include "func.h"

int global;

int global_add(void)
{
    global++;
    printf("global_add().global++ = %d\n", global);
    return 0;
}

int invoke()
{
    int (*funcPtr)(void);
    funcPtr = global_add;

    global = 1;
    printf("func.global = %d\n", global);
    assert(global == 1);
    
    funcPtr();
    assert(global == 2);
    printf("func.global = %d\n", global);

    return 0;
}