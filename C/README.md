# C

- [basic](basic)
1990年的国际混乱C大赛上，Diomides Spinellis用1500字节实现的BASIC语言解释器。
    * 源代码地址：http://grail.cba.csuohio.edu/~somos/ddsbasic.c
    * 测试代码：http://grail.cba.csuohio.edu/~somos/LANDER.BAS

运行：
```
gcc ddsbasic.c
./a.out
OLD LANDER.BAS
RUN
```

## gcc(g++)编译选项

* shared ：指定生成动态链接库。
* static ：指定生成静态链接库。
* fPIC ：表示编译为位置独立的代码，用于编译共享库。目标文件需要创建成位置无关码，念上就是在可执行程序装载它们的时候，它们可以放在可执行程序的内存里的任何地方。
* L. ：表示要连接的库所在的目录。
* l：指定链接时需要的动态库。编译器查找动态连接库时有隐含的命名规则，即在给出的名字前面加上lib，后面加上.a/.so来确定库的名称。
* Wall ：生成所有警告信息。
* ggdb ：此选项将尽可能的生成gdb的可以使用的调试信息。
* g ：编译器在编译的时候产生调试信息。
* c ：只激活预处理、编译和汇编,也就是把程序做成目标文件(.o文件)。
* Wl,options ：把参数(options)传递给链接器ld。如果options中间有逗号,就将options分成多个选项,然后传递给链接程序。
