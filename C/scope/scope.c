#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "scope.h"

int file_var = 1;
extern int extern_var;
extern int extern_0_var;
extern char extern_array[];

// 要么在文件顶部声明函数，要么把函数放在调用者的上面的位置
// check_extern_0_var()：在顶部声明，调用者可以位于函数下方
// check_extern_var()：不做声明，但函数在调用者的上方
void check_extern_0_var();

void print_vars()
{
    printf("extern_var=%d\n", extern_var);
    printf("extern_0_var=%d\n", extern_0_var);
    printf("extern_array=%s\n", extern_array);
}

void check_extern_var()
{
    assert(extern_var == 1);
    assert(strcmp(extern_array, "extern_array") == 0);
}

int scope_func(char *param)
{
    // function and local
    int a = 1;
    {
        int a = 2;
        assert(a == 2);
    }
    assert(a == 1);

    // file and local
    assert(file_var == 1);
    {
        int file_var = 2;
        assert(file_var == 2);
    }
    assert(file_var == 1);

    // extern and local
    assert(extern_0_var == 0xFF);
    int extern_0_var = 1;
    assert(extern_0_var == 1);
    check_extern_0_var();

    // must init extern vars before use
    extern_var = 1;
    strcpy(extern_array, "extern_array");
    check_extern_var();

    return 0;
}

void check_extern_0_var()
{
    assert(extern_0_var == 0xFF);
}

int main()
{
    scope_func(NULL);

    extern_var = 2;
    print_vars();
    
    return 0;
}