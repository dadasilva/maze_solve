cmake_minimum_required(VERSION 3.8)
project(maze_solve)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        maze_solve.cpp)

add_executable(maze_solve ${SOURCE_FILES})