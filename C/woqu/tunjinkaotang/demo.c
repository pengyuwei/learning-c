#include <stdio.h>
#include <stdlib.h>

int tang()
{
	char a[5];
	a[0] = 'a';//只赋了第一个值
		printf("%s\n",a);
	return 0;
}


int tun()
{
	char *p;
 
	p = (char *)malloc(16);
	if (p)
		printf("%s", p);//p没赋值、没初始化，直接输出
	free(p);
	return 0;
}

int kunjinkao()
{
	char *a = "\xef\xbf\xbd\xef\xbf\xbd";
	printf("%s\n", a);
	return 0;
}

int nuo()
{
	char *a = "\xef\xbb";
	printf("%s\n", a);
	return 0;
}

int main()
{
    tang();
    kunjinkao();
    tun();
    nuo();
    return 0;
}