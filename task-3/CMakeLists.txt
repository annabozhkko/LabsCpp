cmake_minimum_required(VERSION 3.20)
project(task-3)

set(CMAKE_CXX_STANDARD 14)

include_directories()

add_executable(task-3
        consoleCamer.cpp
        consoleGamer.h
        consoleView.cpp
        consoleView.h
        gamer.h
        gameView.h
        main.cpp
        optimalGamer.cpp
        optimalGamer.h
        randomGamer.cpp
        randomGamer.h
        ship.cpp
        ship.h)

target_link_libraries(task-3)