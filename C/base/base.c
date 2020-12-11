#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 不要添乱，立即解散ISO工作小组 -- 匿名人士 */

// K&R C定义的特征
#define KR_C
// ANSI_C定义的特征
#define ANSI_C
#define WILL_ERROR //
#define READ_ONLY const

/*
typedef struct
{
    int type;
    char name[16];
} INFO;
INFO info;

struct t_info
{
    int type;
    char name[16];
};
struct t_info info;
*/
typedef struct t_info
{
    int type;
    char name[16];
} INFO;

ANSI_C const int C_TYPE_A = 1;
ANSI_C const char *NAME = "Tom";
ANSI_C signed var1 = 0;
ANSI_C void *var2 = NULL;
ANSI_C volatile float var3;

ANSI_C enum INFOTYPE {
    TYPE_A,
    TYPE_B
};

KR_C int func1();
KR_C int func1(para)
    int para;
{
    return para + 1;
}

ANSI_C int func2(int para);
ANSI_C int func2(int para)
{
    return para + 1;
}

void func_const(const int readonly) {
    const int num = 11;
    const int *p = &num;
    #ifdef ERROR_IS_RIGHT
        WILL_ERROR *p = 1;
    #endif
    // 不能通过 p 修改 num ，但是p自己可以被改变：
    int i = 99;
    p = &i;

    printf("func_const::*p=%d, readonly=%d\n", *p, readonly);
}

int main(int argc, char *argv[])
{
    // 1.
    INFO info;
    memset(&info, 0, sizeof(INFO));

    info.type = C_TYPE_A;
    info.type = TYPE_A;
    strcpy(info.name, NAME);

    printf("%s\n", info.name);

    // 2.
    INFO *pinfo = (INFO *)malloc(sizeof(struct t_info));
    memcpy(pinfo, &info, sizeof(INFO));
    memcpy(pinfo, &info, sizeof info);

    printf("p is %s\n", pinfo->name);
    free(pinfo);
    pinfo = NULL;

    // 3. const
    int var = 1;
    func_const(var);
    
    // end
    return 0;
}