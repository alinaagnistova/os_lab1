cmake_minimum_required(VERSION 3.26)
project(os_lab1)

set(CMAKE_CXX_STANDARD 17)

add_executable(os_lab1
        shell.cpp
        bench1.cpp
        bench2.cpp
        multi_bench.cpp)
