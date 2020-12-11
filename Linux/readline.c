#include <stdio.h>
#include <stdlib.h>
#include "readline/readline.h"

/* 你可以优化一个文件系统，但不能优化一条鱼。 -- tunefs在线手册 */
/*
sudo apt-get install -y libreadline-dev
gcc readline.c -lreadline -o readline.out
*/
int main(int argc, char** argv)
{
    printf("Use `man readline` to get detail.\n");
    char* line = readline("readline> ");
    printf("You entered: \"%s\"\n", line);
    free(line);
    
    return 0;
}