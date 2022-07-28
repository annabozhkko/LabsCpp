cmake_minimum_required(VERSION 3.20)
project(task-1)

set(CMAKE_CXX_STANDARD 14)

include_directories()

add_executable(task-1
        fileReader.cpp
        fileReader.h
        fileWriter.cpp
        fileWriter.h
        main.cpp
        sorting.cpp
        sorting.h
        splitString.h
        splitString.cpp
        statistics.cpp
        statistics.h
        )

target_link_libraries(task-1)