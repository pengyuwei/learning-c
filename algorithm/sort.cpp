#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <sys/time.h>
#include <ctime>

// by zzj 2021-2-24

#define N 1000
static int A[N];
static int B[N];
static int C[2*N];

inline int int_compare(void const* a, void const* b) {
	int aa = *(int*)a;
	int bb = *(int*)b;
	if (aa < bb) return -1;
	if (aa > bb) return 1;
	return 0;
}

static void init() {
	for (size_t i = 0; i < N; ++i) {
		A[i] = rand();
		B[i] = rand();
	}
	qsort(A, N, sizeof(int), int_compare);
	qsort(B, N, sizeof(int), int_compare);
}

static void dump(int *p, size_t n) {
#ifndef NDEBUG
	for (size_t i = 0; i < n; ++i) {
		printf("%d ", p[i]);
	}
	printf("\n");
#endif
}

static void merge_sort(int *A, int *B, int *C) {
	int *a = A;
	int *b = B;
	int *a_end = A + N;
	int *b_end = B + N;
	int *out = C;
	while(1) {
		if (a == a_end) break;
		if (b == b_end) break;
		if (*a <= *b)
			*(out++) = *(a++);
		else
			*(out++) = *(b++);
	}
	while (a < a_end) *(out++) = *(a++);
	while (b < b_end) *(out++) = *(b++);
}

long nowus() {
    long ns = 0;
    struct timespec time_now = {0};
    clock_gettime(CLOCK_REALTIME, &time_now);
    ns = time_now.tv_nsec;
    return ns;
}

int main() {
    // c merge_sort 1000 times spend 11053000 ns
	init();
	dump(A, N);
	dump(B, N);

    long begin = nowus();
	for (int i = 0; i < 1000; ++i) {
		merge_sort(A, B, C);
	}
    long end = nowus();
    printf("c_merge 1000 times spend %ld ns\n", end - begin);

	dump(C, 2*N);
}
