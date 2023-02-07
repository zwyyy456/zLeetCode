cmake_minimum_required(VERSION 3.25)
# 设置项目名
project(LeetCpp)

# 源文件
aux_source_directory(. SOURCES)

# 头文件
include_directories(.)

add_executable(${PROJECT_NAME} ${SOURCES})

# Enable C++11
set(CMAKE_CXX_STANDARD 17)
