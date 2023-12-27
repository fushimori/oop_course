cmake_minimum_required(VERSION 3.10)
project(lab_7)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -g -O0")

add_executable(lab7
    main.cpp
    ./npc/npc.h
    ./npc/ork.h
    ./npc/bear.h
    ./npc/squirrel.h
    ./patterns/factory.h
    ./patterns/visitor.h
    ./patterns/observer.h
    ./patterns/factory.cpp
    ./patterns/visitor.cpp
    ./patterns/observer.cpp
    ./npc/npc.cpp
    ./npc/ork.cpp
    ./npc/bear.cpp
    ./npc/squirrel.cpp
    )

# enable_testing()
# add_executable(test_lab6
#     tests.cpp
#     ./npc/npc.h
#     ./npc/ork.h
#     ./npc/bear.h
#     ./npc/squirrel.h
#     ./patterns/factory.h
#     ./patterns/visitor.h
#     ./patterns/observer.h
#     ./patterns/factory.cpp
#     ./patterns/visitor.cpp
#     ./patterns/observer.cpp
#     ./npc/npc.cpp
#     ./npc/ork.cpp
#     ./npc/bear.cpp
#     ./npc/squirrel.cpp
#     )

# target_link_libraries(test_lab6 ${GTEST_LIBRARIES})
# add_test(NAME counter_test COMMAND test_lab6)
