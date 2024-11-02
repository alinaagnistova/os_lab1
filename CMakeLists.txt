cmake_minimum_required(VERSION 3.26)
project(os_lab1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

add_executable(os_lab1
        src/shell/shell.cpp
        src/benchmark/bench1.cpp
        src/benchmark/bench2.cpp
        src/benchmark/multi_bench.cpp
        include/bench1.hpp
        include/bench2.hpp
        include/multi_bench.hpp
)
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)
add_executable(tests
        src/tests/test_main.cpp
        src/tests/test_bench1.cpp
        src/tests/test_bench2.cpp
        src/tests/test_multi_bench.cpp
        src/benchmark/bench1.cpp
        src/benchmark/bench2.cpp
        src/benchmark/multi_bench.cpp
)

target_link_libraries(tests gtest gtest_main)

# Включаем поддержку тестов
enable_testing()
add_test(NAME EMASearchTest COMMAND tests)
add_test(NAME SortTest COMMAND tests)
add_test(NAME MultiBenchTest COMMAND tests)

