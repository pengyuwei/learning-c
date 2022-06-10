#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// [from, to]
int rnd(int from, int to) {
    return rand() % (to - from + 1) + from;
}

void show_rand() {
    for (int i = 0; i < 10; i++) {
        printf("%d  ", rnd(1, 10));
    }
    printf("\n");
}

void show_rand_raw() {
    for (int i = 0; i < 5; i++) {
        printf("%d  ", rand());
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    printf("Range: 0, %d\n", RAND_MAX );

    // Fixed sequences are obtained for each run prior to random seeding
    show_rand();

    time_t t;
    srand((unsigned)time(&t));

    show_rand();

    show_rand_raw();

    return 0;
}