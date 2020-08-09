# learning-c

转型产品经理之后，有6年没写过 C 代码了，本项目是对 C 和 C++ 的复习。

## 目录说明

* autotools: 包含autoconf和automake的用法示例
* C: 使用gcc编译的C语言基础学习代码
* CPP: 使用g++编译的C++语言基础学习代码

## Github actions

配置文件
```
.github/workflows/c-cpp.yml
```

## 坑

* git默认对大小写不敏感，c目录改为C目录时，导致了自动构建失败。此时应该使用`git mv`修改目录名而不是直接从系统里改