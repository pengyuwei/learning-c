# learning-c

本项目是对 C 和 C++ 的复习，不适合用于语言入门。
如果对你有帮助，请帮点Star。

## 目录说明

* [autotools](autotools): 包含autoconf和automake的用法示例
* [C](C): 使用gcc编译的C语言基础学习代码
    * [base](C/base)：C语言基础(堆、栈、结构体)
    * [dynamic_link](C/dynamic_link): 动态链接
    * [static_link](C/static_link): 静态链接
    * [scope](C/scope): 变量作用域
    * [socket](C/socket): Socket通讯、进程间通讯、共享内存通讯
    * [tunjinkaotang](C/tunjinkaotang): “屯斤拷烫”这个梗的来源演示。
* [CPP](CPP): 使用g++编译的C++语言基础学习代码
    * [class](CPP/class)：类(类、继承、重载、多态)
    * [dynamic_link](CPP/dynamic_link): C++调用C的动态链接库
    * [static_link](CPP/static_link): C++静态链接C的导出库
    * [thread](CPP/thread): C++多线程、多进程
    * [stl](CPP/stl): C++ STL库
    * [new](CPP/new): C++语言新特性（v11-20）
* [lib](lib)：一些库
    * [sdl](lib/sdl): C++ SDL图形库
* [gui](gui/)：图形界面技术
* [Linux](Linux)：Linux系统特性（POSIX）
    * epoll
    * lock-free
    * curses
* [FreeBSD](FreeBSD)：FreeBSD系统特性
    * kqueue

## 编译环境

Ubuntu
```
apt-get install build-essential
```

MacOS
```
brew install gcc
brew install g++
brew install gdb
```

FreeBSD
```
pkg install gcc
pkg install gdb
```

编译器版本
```
% gcc --version
Apple clang version 11.0.3 (clang-1103.0.32.62)
% c++ --version
Apple clang version 11.0.3 (clang-1103.0.32.62)
```

其他扩展环境：
```
sudo apt install clang-tidy
```

## 常用命令

Ubuntu
```
ldd libso.so
strace
clang-tidy -list-checks
```

MacOS
```
查看依赖库：otool -L libso.so
查看so的导出函数：nm libso.so
查看运行时的系统调用：sudo dtruss df -h
```


## Github actions

使用github进行自动构建。配置文件为：
```
.github/workflows/c-cpp.yml
```
