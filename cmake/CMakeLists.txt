# 设置项目名称和版本
set(CMP0048 NEW)
project(Demo)
cmake_minimum_required(VERSION 3.10)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)

# 添加可执行文件
add_executable(demo demo.cpp)

# 添加子目录
#add_subdirectory(log)

# 寻找math子目录并添加到链接库
#target_link_libraries(demo math)

# 添加include目录
#include_directories(include)

# 设置变量存储一些路径
set(INCLUDE_DIRS include/)
set(LIB_DIRS lib/)

# 打印一些信息 
message(STATUS "Project name: ${PROJECT_NAME}")
message(STATUS "Project version: ${PROJECT_VERSION}")

# 安装规则
install(TARGETS demo DESTINATION bin)
install(FILES demo.h DESTINATION include/)

# 添加测试
enable_testing()
add_test(NAME DemoTest COMMAND demo)
