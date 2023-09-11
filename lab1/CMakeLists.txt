cmake_minimum_required(VERSION 3.10)
project(gtest)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab1 main.cpp vowel_counter.cpp)

enable_testing()
add_executable(gtest tests.cpp vowel_counter.cpp)
target_link_libraries(gtest ${GTEST_LIBRARIES})

add_test(NAME counter_test COMMAND gtest)