/*
用c语言写一个程序：提取所有输入的正则表达式中的固定字符串，并打印出来。
举例：
    输入：abcd.*efgh[0-9]
    输入：abcd
               efgh
chatGPT的回答：
#include <stdio.h>
#include <string.h>
#include <regex.h>

int main(int argc, char ** argv) {
    char *pattern = argv[1];
    regex_t regex;
    regcomp(&regex, pattern, REG_EXTENDED);

    int status;
    int cflags = REG_NOTBOL | REG_NOTEOL;
    regmatch_t pmatch[1];

    char line[1024];
    while (fgets(line, 1024, stdin) != NULL) {
        status = regexec(&regex, line, 1, pmatch, cflags);
        if (status == 0) {
            printf("Matched: %.*s\n", pmatch[0].rm_eo - pmatch[0].rm_so, &line[pmatch[0].rm_so]);
        }
    }

    regfree(&regex);
    return 0;
}
*/
#include <stdio.h>
#include <string.h>
#include <regex.h>

int main(int argc, char ** argv) {
    char *pattern = argv[1];
    regex_t regex;
    regcomp(&regex, pattern, REG_EXTENDED);

    int status;
    int cflags = REG_NOTBOL | REG_NOTEOL;

    char line[1024] = {0};
    while (fgets(line, 1024, stdin) != NULL) {
        regmatch_t pmatch;
        status = regexec(&regex, line, 1, pmatch, cflags);
        if (status == 0) {
            printf("Matched: %lld\n", pmatch[0].rm_eo - pmatch[0].rm_so);
        }
    }

    regfree(&regex);
    return 0;
}