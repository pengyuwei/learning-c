#include "lib.h"
/*
-shared: 要编译动态链接库
-fPIC: 编译生成的代码与位置无关
gcc -Wall -g -fPIC -c so.c -o so.o
gcc -shared so.o -o so.so
*/
int lib_func(int param)
{
    return param + 1;
}