#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/* 国际C语言混乱代码大赛（The International Obfuscated C Code Competition）*/

int main()
{
    // malloc memory from heap
    char *buf1 = (char *)malloc(16);
    char *buf2 = (char *)malloc(16);

    printf("%d < %d\n", (int)buf1, (int)buf2);
    assert((int)buf1 < (int)buf2);

    free(buf1);
    free(buf2);
    buf1 = NULL;
    buf2 = NULL;

    return 0;
}