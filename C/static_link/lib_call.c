#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

/*
-L: 在当前路径寻找so文件
-l:要链接的so文件
gcc -o sosample call_so.c -L -lso
*/
int main(void)
{
    int ret = 0;
    char str[256] = {0};

    ret = lib_func(str);
    printf("%s, return %d\n", str, ret);

    return 0;
}