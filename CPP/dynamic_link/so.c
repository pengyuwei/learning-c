#include "so.h"
/*
-shared: 要编译动态链接库
-fPIC: 编译生成的代码与位置无关
gcc -Wall -g -fPIC -c so.c -o so.o
gcc -shared so.o -o libso.so
*/

// C-like func
int so_c_func(int param)
{
    return param + 1;
}

// C++-like func
int so_cpp_func(int param)
{
    return param + 10;
}