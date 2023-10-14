cmake_minimum_required(VERSION 3.10)
project(lab_3)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")

add_executable(prot
    prototype/test.cpp
    figures/figure.h
    figures/point.h
    figures/point.cpp
    figures/triangle.h
    figures/triangle.cpp
    figures/hexagon.h
    figures/hexagon.cpp
    figures/octagon.h
    figures/octagon.cpp
    vector/vector.h)

enable_testing()
add_executable(test_lab3
    tests.cpp
    figures/figure.h
    figures/point.h
    figures/point.cpp
    figures/triangle.h
    figures/triangle.cpp
    figures/hexagon.h
    figures/hexagon.cpp
    figures/octagon.h
    figures/octagon.cpp)

target_link_libraries(test_lab3 ${GTEST_LIBRARIES})
add_test(NAME counter_test COMMAND test_lab3)