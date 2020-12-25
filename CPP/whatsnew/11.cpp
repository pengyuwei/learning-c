#include <stdio.h>

// C++ 11(ISO C++ 2011) features
// g++ -std=c++11 features.cpp

int main() {
    int a[5] = { 1, 2, 2, 5, 1 };
    for( int i:a ) {
        printf( "%d\n", a[i] );
    }
    return 0;
}