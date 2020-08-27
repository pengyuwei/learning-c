#include "lib.h"
#include <string.h>
/*
gcc -Wall -g -fPIC -c lib.c -o libfunc.o
ar crv libfunc.a libfunc.o
*/
int lib_func(char *param)
{
    strcpy(param, "lib_func@lib");
    return 0;
}