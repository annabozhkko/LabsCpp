cmake_minimum_required(VERSION 3.20)
project(task-1)

set(CMAKE_CXX_STANDARD 14)

include_directories()

add_executable(task-1
        main.cpp
        proxyTrit.cpp
        proxyTrit.h
        trit.cpp
        trit.h
        tritSet.cpp
        tritSet.h)

target_link_libraries(task-1)