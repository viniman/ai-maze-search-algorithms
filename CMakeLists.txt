cmake_minimum_required(VERSION 3.12)
project(ai_maze_search_algorithms)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ai_maze_search_algorithms
        main.cpp
        Maze.cpp
        Maze.h
        Node.cpp
        Node.h
        Utils.cpp
        Utils.h
        Breadth.cpp
        Breadth.h
        Depth.cpp
        Depth.h
        Ordered.cpp
        Ordered.h
        Greedy.cpp
        Greedy.h
        IDAStar.cpp
        IDAStar.h
        AStar.cpp
        AStar.h
        Backtracking.cpp
        Backtracking.h
        SearchAlgorithm.cpp
        SearchAlgorithm.h
        Statistics.cpp
        Statistics.h)
