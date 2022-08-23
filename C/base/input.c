#include <stdio.h>
#include <assert.h>

void test_fgets() {
    char content[60] = {0};
    FILE * fp = fopen("readme.md", "r");
    char * r = fgets(content, sizeof(content), fp);
    if (NULL != r) {
        // "hello\n", '\000' <repeats 53 times>
        puts(content);
        assert(content[5] == '\n');
    }
    fclose(fp);
}

void test_scanf() {
    char content[4] = {0}; 
    printf("Enter a string:");
    scanf("%5s",content);
    printf("%s\n", content);

    return 0;
}

void test_getc() {
    char c = '\0'; 
    // getc只接收一个字符，如果输入多个，会自动缓冲给下面的getc
    printf("input a char:");
    c = getc(stdin);
    putc(c, stdout);
    c = getc(stdin);
    putc(c, stdout);
}

int main() {
    test_fgets();
    test_getc();
    test_scanf(); // 如果getc输多了，会buffer给scanf，而且可能给不全

    return 0;
}