cmake_minimum_required(VERSION 3.13)
project(ai_maze_search_algorithms)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ai_maze_search_algorithms
        AStar.cpp
        AStar.h
        Backtracking.cpp
        Backtracking.h
        Breadth.cpp
        Breadth.h
        Depth.cpp
        Depth.h
        Greedy.cpp
        Greedy.h
        IDAStar.cpp
        IDAStar.h
        main.cpp
        Maze.cpp
        Maze.h
        Node.cpp
        Node.h
        Ordered.cpp
        Ordered.h
        Utils.cpp
        Utils.h
        SearchAlgorithm.h
        SearchAlgorithm.cpp
        Statistics.h
        Statistics.cpp
        OrderedEdgeStruct.h)
