cmake_minimum_required(VERSION 3.10)
project(lab_02)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -g)

add_executable(lab2 main.cpp twelve.cpp include.h)