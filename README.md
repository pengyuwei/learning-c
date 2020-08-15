# learning-c

转型产品经理之后，有6年没写过 C 代码了，本项目是对 C 和 C++ 的复习。

## 目录说明

* autotools: 包含autoconf和automake的用法示例
* C: 使用gcc编译的C语言基础学习代码
* CPP: 使用g++编译的C++语言基础学习代码

## 基础环境

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

## 常用命令

Ubuntu
```
ldd libso.so
strace
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

## 坑

* git默认对大小写不敏感，小写c目录改为大写C目录时，导致了自动构建失败。此时应该使用`git mv`修改目录名而不是直接从系统里改