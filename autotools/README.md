# Autotools

## 快速运行

```
sh make.sh
./configure
make
make check
make distcheck
make clean
sh clean.sh
```

## key

* Makefile.am中，必须使用TAB缩进而不能使用空格缩进
* 源代码默认位于src目录中

## 基础环境

```
ubuntu:
apt-get install autoconf

MacOS:
brew install autoconf
brew install automake
```

## 编译和打包

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
https://www.lrde.epita.fr/~adl/autotools.html

## 快速完成

```
创建configure.ac、Makefile.am
touch NEWS README AUTHORS ChangeLog
aclocal; autoconf; automake --add-missing;
./configure; make;
```

## 文件样例

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
    rm -f AUTHORS
	rm -f COPYING
	rm -f ChangeLog
	rm -f INSTALL
	rm -f NEWS
	rm -f README
	rm -f aclocal.m4
	rm -f compile
	rm -f config.h.in
	rm -f config.log
	rm -f config.status
	rm -f configure
	rm -f configure.scan
	rm -f depcomp
	rm -f install-sh
	rm -f missing
	rm -f autoscan.log
	rm -rf autom4te.cache
```