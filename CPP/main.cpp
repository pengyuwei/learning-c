#include <stdio.h>
#include "func.h"
#include <cassert>
#include <iostream>
#include <cstdint>

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

void overflow() {
    uint16_t x1 = 1;
    uint16_t x2 = 2;
    std::cout << "overflow:" << endl;
    std::cout << x1 - x2 << "\n";
    std::cout << static_cast<uint16_t>(x1 - x2) << "\n";
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

    overflow();

    return 0;
}