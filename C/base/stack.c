#include <stdio.h>
#include <assert.h>

char gbuf[16] = {0};

int func(int para)
{
    return para;
}

int main()
{
    int var = func(0);
    char buf1[16] = {0};
    char buf2[16] = {0};
    char strbuf[] = "stack";
    static char sbuf[16];
    static int svar = 0;
    char *p = "stack";
    // char buf_overflow[2048*1024*10];// segmentation fault

    printf("%d > %d\n", (int)buf1, (int)buf2);
    assert((int)buf1 > (int)buf2);

    printf("%d != %d\n", (int)strbuf, (int)p);
    assert((int)strbuf != (int)p);
    printf("%d,%s,%s,%d\n", var, strbuf, sbuf, svar);

    return 0;
}