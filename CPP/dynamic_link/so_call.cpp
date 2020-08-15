#include <stdio.h>
#include <stdlib.h>
#include <cassert>
#include "so_call.h"

/*
-L: 在当前路径寻找so文件
-l:要链接的so文件
gcc -o sosample call_so.c -L -lso
*/
int main(void)
{
    int ret = 0;

    ret = so_c_func(0);
    printf("%d\n", ret);
    assert(ret == 1);

    ret = so_cpp_func(0);
    printf("%d\n", ret);
    assert(ret == 10);

    return 0;
}