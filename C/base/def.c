#include <stdio.h>

void define() {
    int i;
    int *p;
    int f();        // 函数声明
    int **pp;       // 指向指针的指针
    int (*pa)[];    // 指向数组的指针
    int (*pf)();    // 指向函数的指针
    int *fp();      // 返回类型为 int* 的函数声明

    int ***ppp;     // 指向指针的指针的指针
    int (**ppa)[];  // 指向一个未指定大小的数组的指针, explain1()
    int (**ppf)();  // 指向一个返回类型为 int 的函数的函数指针
    int *(*pap)[];  // 指向一个指向 int 类型指针的数组的指针
    int *(*pfp)();  // 指向一个返回类型为 int* 的函数指针的函数指针

    int **fpp();    // 返回类型为 int** 的函数声明
    int (*fpa())[]; // 返回类型为 int(*)[] 的函数声明
    int (*fpf())(); // 返回类型为 int(*)() 的函数声明
}

void explain1() {
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int (*p)[3] = arr;
    int (**ppa)[3] = &p;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", (*ppa)[i][j]);
        }
        printf("\n");
    }
    // 1 2 3
    // 4 5 6
}

void wrong_define() {
    int a[10]; // wrong: int a[];

    // int *afp[]();
    // wrong: int *afp[]();不允许使用不完整的类型 & 不允许使用函数数组
    // 函数指针数组
    // int (*afp[])();
    // // 函数数组
    // int afp[]();

    // int *ap[];
    // int aa[][];
    // int af[]();
    // int fa()[];
    // int ff()();

    // int **app[];
    // int (*apa[])[];
    // int (*apf[])();
    // int *aap[][];
    // int aaa[][][];
    // int aaf[][]();

    // int *fap()[];
    // int faa()[][];
    // int faf()[]();
    // int *ffp()();

    // int (*pfa)()[];
    // int (*pff)()();
    // int *afp[]();
    // int afa[]()[];
    // int aff[]()();

    // int (*paf)[]();
    // int (*paa)[][];
}

int main(int argc, char *argv[]) {
    define();
    wrong_define();
    explain1();
    return 0;
}