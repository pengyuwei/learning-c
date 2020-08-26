#include "lib.h"
/*
gcc -Wall -g -fPIC -c lib.c -o libfunc.o
ar crv libfunc.a libfunc.o
*/
int lib_func(int param)
{
    return param + 1;
}