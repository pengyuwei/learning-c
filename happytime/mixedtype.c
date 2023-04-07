// a lot of people don't know this:
// C actually lets you do arithmetic with mixed types, much like JavaScript:
// 🐶
#include <stdio.h>

// gcc -w mixedtype.c
int main() {
    puts("-0.5" + 1);
    return 0;
}