# learning-c

## 编译和打包

基础环境
```
ubuntu:
apt-get install autoconf

MacOS:
brew install autoconf
brew install automake
```

步骤
```
生成configure.scan：
autoscan
mv configure.scan configure.ac
vi configure.ac
(参考内容见底部示例)

如果需要头文件，可以autoheader

根据configure.ac生成aclocal.m4
aclocal

生成configure
autoconf

手工生成Makefile.am
(内容见示例)

生成Makefile.in
touch NEWS README AUTHORS ChangeLog
automake
automake --add-missing

生成make
./configure

编译
make

打包，生成tar.gz
make dist

验证包
./configure
make
sudo make install
hello
sudo make uninstall
```

参考文档：https://www.gnu.org/software/automake/manual/automake.html#true

configure.ac的参考内容
```
AC_INIT(helloworld.c)
AM_INIT_AUTOMAKE(helloworld, 1.0)
AC_PROG_CC
AC_OUTPUT(Makefile)
```

Makefile.am参考nearing
```
AUTOMAKE_OPTIONS=foreign
bin_PROGRAMS=helloworld
helloworld_SOURCES=helloworld.c
```

简化版本的Makefile

```
.DEFAULT_GOAL := all

thread :  thread.c
	c++ thread.c -o thread -lpthread

clang : clang.c
	c++ clang.c -o main

.PHONY : all
all : thread clang

clean:
	rm -f *.o
	rm -f main
	rm -f thread
	rm -f a.out

```