# learning-c

本项目是对 C 和 C++ 的复习和持续学习。

```
千里之行始於足下
The journey of a thousand miles begins with a single step.

— 老子 (Lao Tsu) in Chapter 64 of 道德经 (Tao Te Ching)
```

## 目录

* [History](History.md)：C语言发展简史，和相关的人物
* [C](C): 使用gcc编译的C语言基础学习代码
    * [base](C/base)：C语言基础(堆、栈、结构体)
    * [dynamic_link](C/dynamic_link): 动态链接
    * [static_link](C/static_link): 静态链接
    * [scope](C/scope): 变量作用域
    * [data_struct](C/data_struct): 数组、链表、堆栈、队列、哈希表、排序、字节顺序、位运算
    * [io](C/io): 阻塞IO、异步IO和并发IO
    * [ipc](C/ipc): 进程间通讯(管道、共享内存、信号、消息队列、命名管道)
    * [socket](C/socket): Socket通讯
* [CPP](CPP): 使用g++编译的C++语言基础学习代码
    * [class](CPP/class)：类(类、继承、重载、多态)
    * [dynamic_link](CPP/dynamic_link): C++调用C的动态链接库
    * [static_link](CPP/static_link): C++静态链接C的导出库
    * [thread](CPP/thread): C++多线程、多进程
    * [stl](CPP/stl): C++ STL标准库
    * [whatsnew](CPP/whatsnew): C++语言新特性（v11-20）
    * [book](CPP/book/): 读书笔记
      * [《C++并发编程》](CPP/book/concurrency/): 《C++并发编程》读书笔记
* [autotools](autotools): 包含autoconf和automake的用法示例
* [lib](lib)：一些库
    * [sdl](lib/sdl): C++ SDL图形库
* [gui](gui/)：图形界面技术
* [Linux](Linux)：Linux系统特性（POSIX）
    * thread：进程、线程、协程、锁、互斥、信号量
    * curses：终端文本图形库
    * epoll
    * lock-free
    * [2038](Linux/2038.c)：32位Linux的2038年问题
* [FreeBSD](FreeBSD)：FreeBSD系统特性
    * kqueue
* [algorithm](algorithm): 算法
    * [leetcode](algorithm/leetcode/): leetcode刷题
* [happytime](happytime)
    * [tunjinkaotang](happytime/tunjinkaotang): “屯斤拷烫”这个梗的来源演示。
    * [basic](happytime/basic)：1990年的国际混乱C大赛上，Diomides Spinellis用1500字节实现的BASIC语言解释器。
    * [numhome](happytime/numhole/)：数字黑洞

## 编译环境

Ubuntu Linux
```
apt-get install build-essential
```

macOS
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
gcc (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0
% c++ --version
Apple clang version 11.0.3 (clang-1103.0.32.62)
c++ (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0
```

其他工具：
```
sudo apt install clang-tidy
# 内存泄漏检查
sudo apt install valgrind
valgrind --tool=memcheck -s ./a.out
```

如果需要在MacOS上使用gdb调试，[参考这里](https://opensource.apple.com/source/lldb/lldb-69/docs/code-signing.txt)
先打开启动台>>其他>>钥匙串访问>>证书助理>>创建证书
名称：gdb_codesign，类型：代码签名，覆盖默认值，证书位置为系统。创建后简介里选择始终信任。
```
sudo killall taskgated
codesign -fs gdb_codesign $(which gdb)
set startup-with-shell off
sudo chgrp procmod $(which gdb)
sudo chmod g+s $(which gdb)  # else u must use sudo gdb a.out
# reboot
sudo gdb a.out
```

## llvm

```
brew install llvm
clang test.c -o test
clang -O1 -emit-llvm test.c -c -o test.bc
lli test.bc
```

## 名词概念

- Clang: 一个由Apple主导编写，基于LLVM的C/C++/Objective-C编译器
- llvm: Low Level Virtual Machine.先编译成中间代码，再编译为目标平台代码。

## 常用工具

- doxygen: 文档生成工具，将程序中的特定注释转换成为文档
- ldd: 查看依赖的共享库列表
- clang-tidy: 基于clang的静态代码分析框架
- strace: 调试工具，监控用户空间进程和内核的交互，比如系统调用、信号传递、进程状态变更等
- ghidra: 逆向工具
- ida pro: 逆向工具

## 常用命令

Ubuntu Linux
```
ldd libso.so
clang-tidy -list-checks
```

macOS
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

# Reference

Book

- [《C程序设计语言》](https://book.douban.com/subject/1139336/)，[K](https://zh.wikipedia.org/wiki/%E5%B8%83%E8%90%8A%E6%81%A9%C2%B7%E6%9F%AF%E6%9E%97%E6%BC%A2)&[R](https://zh.wikipedia.org/wiki/%E4%B8%B9%E5%B0%BC%E6%96%AF%C2%B7%E9%87%8C%E5%A5%87)，机械工业出版社，[维基百科](https://zh.wikipedia.org/wiki/C%E7%A8%8B%E5%BA%8F%E8%AE%BE%E8%AE%A1%E8%AF%AD%E8%A8%80_(%E4%B9%A6))
- [《C和指针》](https://book.douban.com/subject/3012360/)
- [《C专家编程》](https://book.douban.com/subject/2377310/)
- [《C陷阱与缺陷》](https://book.douban.com/subject/2778632/)
- [《UNIX环境高级编程》](https://book.douban.com/subject/1788421/)，人民邮电出版社，APUE
- [《C++编程思想》](https://book.douban.com/subject/1101524/)，机械工业出版社
- [《C语言编程常见问题解答》](https://book.douban.com/subject/1247059/)，清华大学出版社
- [《TCP/IP详解》](https://book.douban.com/subject/1088054/)，机械工业出版社
- [《The Elements of Programming Style》](https://book.douban.com/subject/1470267/)

Document

- [GDB to LLDB command map](https://lldb.llvm.org/use/map.html)
- [std::deque](https://en.cppreference.com/w/cpp/container/deque)
- [automake](https://www.gnu.org/software/automake/manual/automake.html#true)
- [C++ Standards Committee Papers](http://open-std.org/JTC1/SC22/WG21/docs/papers/)
- [Beej's Guide to Network Programming](https://beej.us/guide/bgnet/html/)
- [Autotools Tutorial](https://www.lrde.epita.fr/~adl/autotools.html)
- [kqueue](https://www.freebsd.org/cgi/man.cgi?kqueue)
- [Workflow syntax for GitHub Actions](https://docs.github.com/en/actions/reference/workflow-syntax-for-github-actions#jobsjob_idstepsuses)

Article

- [开源软件指南](https://opensource.guide/zh-hans/)
- [C/C++ 静态链接库(.a) 与 动态链接库(.so)](https://www.cnblogs.com/52php/p/5681711.html)
- [Linux C/C++ 动态链接库的生成和调用](https://blog.csdn.net/alex_bean/article/details/83792988)
- [C/C++ 的编译和链接的问题](https://zhuanlan.zhihu.com/p/26643194)
- [C调用C++编的DLL，C++调用C编写的DLL，extern “C”的用法](https://blog.csdn.net/life_is_too_hard/article/details/52137271)
- ["undefined reference to" 问题汇总及解决方法](https://segmentfault.com/a/1190000006049907)
- [sockaddr和sockaddr_in详解](https://blog.csdn.net/will130/article/details/53326740)
- [Linux IO模式及 select、poll、epoll详解](https://segmentfault.com/a/1190000003063859)

Conference

- [Cppcon](https://cppcon.org/) :C++社区组织的年度聚会
- [2020 Pure C++大会](https://daxuepc.com/detail/l_5fe2f06de4b0231ba88e7586/4):purecpp开源社区和腾讯主办的大会

