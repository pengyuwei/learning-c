#include <stdio.h>
#include "class.h"

void func()
{

}

int func(int a)
{
    return a + 1;
}

int main(int argc, char *argv[])
{
    func();
    printf("%d\n", func(1));
    return 0;
}