#include <stdio.h>
#include <stdlib.h>
#include "so.h"

/*
-L: 在当前路径寻找so文件
-l:要链接的so文件
gcc -o sosample call_so.c -L -lso
*/
int main(void)
{
    int ret = so_func(0);
    printf("%d\n", ret);

    return 0;
}