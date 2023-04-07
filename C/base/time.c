#include <stdio.h>
#include <time.h>

int main() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    long lastMoveTime = ts.tv_sec*1000000000 + ts.tv_nsec;
    printf("%ld\n", lastMoveTime);
}
