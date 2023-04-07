#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Num
{
    int a;
    int b;
    int c;
    int max;
    int min;
    public: 
    void Next() {
        
        this->max = 0;
    }
};


int rnd(int from, int to) {
    return rand() % (to - from + 1) + from;
}

int getNext(int a, int b, int c) {

}

int main(int argc, char *argv[]) {
    time_t t;
    srand((unsigned)time(&t));
    int a, b, c;
    a = rnd(0, 10);
    b = rnd(0, 10);
    c = rnd(0, 10);
    int num = a*100 + b*10 + c;
    int big = 0;
    int small = 0;
    while (1)
    {
        printf("%d - %d = %d\n", big, small, big - small);
        if (big - small == 495) {
            break;
        }
    }
    
}