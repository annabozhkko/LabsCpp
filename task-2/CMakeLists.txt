cmake_minimum_required(VERSION 3.20)
project(task-2)

set(CMAKE_CXX_STANDARD 14)

include_directories()

add_executable(task-2
        block.h
        block.cpp
        dump.h
        dump.cpp
        exeption.h
        execute.h
        execute.cpp
        fileReader.h
        fileReader.cpp
        grep.cpp
        grep.h
        main.cpp
        readfile.cpp
        readfile.h
        replace.cpp
        replace.h
        splitString.cpp
        splitString.h
        sort.cpp
        sort.h
        worker.h
        worker.cpp
        workerFabric.h
        workerFabric.cpp
        writefile.cpp
        writefile.h)

target_link_libraries(task-2)