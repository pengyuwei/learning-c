#include <stdio.h>
#include <stdlib.h>
#include "readline/readline.h"

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