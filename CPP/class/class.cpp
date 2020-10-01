#include <stdio.h>
#include <assert.h>
#include "class.h"

Demo::Demo()
{
    this->priv = 0;
    this->var = 1;
    this->priv2 = 0;
    this->prot = 0;
}

Demo::~Demo()
{
    
}

Demo::Demo(int para)
:var(0), priv(0)
{
    this->priv = para;
}

int Demo::show(int a)
{
    printf("%d\n", a);
    return 0;
}

#ifdef _CLASSMAIN_
int main(int argc, char *argv[])
{
    Demo obj;
    Demo obj2(1);
    Demo *pobj = new Demo();
    
    obj.var = 1;
    pobj->show(1);

    return 0;
}
#endif