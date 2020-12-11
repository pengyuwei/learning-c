#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 不要添乱，立即解散ISO工作小组 -- 匿名人士 */

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

const int C_TYPE_A = 1;
const char *NAME = "Tom";

enum INFOTYPE {
    TYPE_A,
    TYPE_B
};

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
    
    // end
    return 0;
}