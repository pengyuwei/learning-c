#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct t_info
{
    int type;
    char name[16];
} INFO;

const int TYPE_A = 1;
const char *NAME = "Tom";


int main()
{
    // 1.
    INFO info;
    memset(&info, 0, sizeof(INFO));

    info.type = TYPE_A;
    strcpy(info.name, NAME);

    printf("%s\n", info.name);

    // 2.
    INFO *pinfo = (INFO *)malloc(sizeof(struct t_info));
    memcpy(pinfo, &info, sizeof(INFO));

    printf("p is %s\n", pinfo->name);
    free(pinfo);
    pinfo = NULL;
    
    // end
    return 0;
}