#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define uint unsigned int

int global;
int public = 1;

int main(int argc, char *argv[])
{
    int var = 1;
    static int var3 = 3;
    char *var4 = "const string";
    char *str = malloc(8);

    int addr1, addr2, addr3;
    printf("address:\n");

    addr1 = (uint)&var;
    addr2 = (uint)&argc;
    addr3 = (uint)&str;
    printf("stack > heap: %X|%X>%X\n", addr1, addr2, addr3);
    assert(addr1>addr3);
    assert(addr2>addr3);

    addr1 = (uint)str;
    addr2 = (uint)&global;
    printf("heap > BSS: %X>%X\n", addr1, addr2);
    assert(addr1>addr2);

    addr1 = (uint)&global;
    addr2 = (uint)&public;
    printf("BSS(uninit global var) > data(inited global var): %X>%X\n", addr1, addr2);
    assert(addr1>addr2);

    addr1 = (uint)&var3;
    addr2 = (uint)var4;
    printf("data(static) > text(const string): %X>%X\n", addr1, addr2);
    assert(addr1>addr2);

    free(str);
    str = NULL;

    return 0;
}