#include <stdio.h>
#include <assert.h>

enum DATA_TYPE {
    TYPE_LONG = 1
};

void set_data(enum DATA_TYPE type, void *var) {
    long *p = NULL;
/*
0x7fffffffe37c:	0xaa	0xaa	0xaa	0xaa	0xbb	0xbb	0xbb	0xbb
0x7fffffffe384:	0xbb	0xbb	0xbb	0xbb
*/
    if (type == TYPE_LONG) {
        p = (long *)var;
        *p = 0x1122334455667788;
    } else {
        *((int *)var) = 0;
    }
/*
(gdb) x /12xb p
0x7fffffffe37c:	0x88	0x77	0x66	0x55	0x44	0x33	0x22	0x11
0x7fffffffe384:	0xbb	0xbb	0xbb	0xbb
*/
}

// gcc -Wall -g -O0 longsize.c -o longsize.out
int main(int argc, char *argv[]) {
    long b = 0xBBBBBBBBBBBBBBBB; // high address
    int a = 0xAAAAAAAA; // low address
    /*
    in stack memory:
    |1|2|3|4|5|6|7|8|9|10|11|12|
    |-- a --|------- b --------|
    */

    printf("sizeof int=%lu, long=%lu\n", sizeof(a), sizeof(b)); // 64bit:4,8; 32bit: 4,4

    printf("a=0x%X(@%p), b=0x%lX(@%p), &b-&a=%d\n", a, &a, b, &b, (int)&b - (int)&a);

    printf("set a = 0x1122334455667788\n");
    set_data(TYPE_LONG, &a); // bug here: a overwrite b

    printf("a=0x%X(@%p), b=0x%lX(@%p)\n", a, &a, b, &b);
    assert(b == 0xBBBBBBBB11223344);

    return 0;
}