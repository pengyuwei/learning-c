#include <stdio.h>
#include <stdlib.h>
#include "readline/readline.h"

int main(int argc, char** argv)
{
    printf("Use `man readline` to get detail.\n");
    char* line = readline("readline> ");
    printf("You entered: \"%s\"\n", line);
    free(line);
    
    return 0;
}