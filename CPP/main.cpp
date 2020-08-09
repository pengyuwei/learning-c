#include <stdio.h>
#include "func.h"
#include <cassert>

using namespace std;

extern int global;
enum INFOTYPE {
    TYPE_A,
    TYPE_B
};

int cast()
{
    int i = 0x7fff;
    long l;

    l = static_cast<long>(i);
    printf("long=%ld\n", l);

    return 0;
}

int main(int argc, char *argv[])
{
    printf("main.main().global = %d\n", global); // 0
    invoke();

    
    printf("main.main().global = %d\n", global); // 2

    cast();

    INFOTYPE itype;
    itype = TYPE_A;

    assert(itype == TYPE_A);

    return 0;
}