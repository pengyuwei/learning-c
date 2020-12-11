#include <stdio.h>
#include <time.h>
#include <assert.h>
#include <limits.h>

/* C诡异离奇，缺陷重重，却获得了巨大的成功。 -- Dennis Ritchie */
/*
Compile to 32-bit binary on a 64-bit system:
sudo apt-get install -y build-essential module-assistant
sudo apt-get install -y gcc-multilib g++-multilib
gcc -m32 -Wall -g -O0 2038.c -o 2038.out
*/
int main (int argc, char *argv[])
{
    time_t maxtime32 = 0x7FFFFFFF;
    // UTC time: Tue Jan 19 03:14:07 2038
    printf("32位支持的最大时间: %s", asctime(gmtime(&maxtime32)));

    // 32bit: 0x7FFFFFFF == 2147483647
    // 64bit: 0x7FFFFFFFFFFFFFFF == 9223372036854775807
    printf("time_t size:%zd\n", sizeof(time_t));
    printf("long size:%zd\n", sizeof(long));
    printf("long max:%ld\n", LONG_MAX);
    assert(sizeof(time_t) == 4);
    assert(sizeof(time_t) == sizeof(long));
    assert(maxtime32 > maxtime32 + 1);
    assert(maxtime32 + 1 == -0x80000000);

    return 0;
}