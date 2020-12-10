#include <stdio.h>
#include <time.h>
#include <assert.h>
#include <limits.h>

/*
Compile to 32-bit binary on a 64-bit system:
sudo apt-get install -y build-essential module-assistant
sudo apt-get install -y gcc-multilib g++-multilib
gcc -m32 2038.c -o 2038.out
*/
int main (int argc, char *argv[])
{
    time_t maxtime32 = 2147483648 - 1;
    struct tm maxtime32tm;
    localtime_r(&maxtime32, &maxtime32tm);
    printf("32位支持的最大时间: %s", asctime(&maxtime32tm));

    // 32bit: 2147483647
    // 64bit: 9223372036854775807
    printf("time_t size:%zd\n", sizeof(time_t));
    printf("long size:%zd\n", sizeof(long));
    printf("long max:%ld\n", LONG_MAX);
    assert(sizeof(time_t) == sizeof(long));
    assert(maxtime32 > maxtime32 + 1);
    assert(maxtime32 +1 == -2147483648);

    return 0;
}