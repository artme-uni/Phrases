cmake_minimum_required(VERSION 3.13)
project(cpp_task1)

set(CMAKE_CXX_STANDARD 14)

add_executable(ccp_task1 main.cpp frequency.cpp frequency.h)
add_executable(unittest frequency.cpp frequency.h test.cpp catch.hpp)