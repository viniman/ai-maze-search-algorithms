//
// Created by viniman on 07/06/19.
//

#ifndef AI_MAZE_SEARCH_ALGORITHMS_UTILS_H
#define AI_MAZE_SEARCH_ALGORITHMS_UTILS_H

#include <string>
#include "Maze.h"
#include <stack>

class Utils
{
public:
    static Maze instanceReader(const std::string &instancePathName);
    static Maze *mazeGenerator(unsigned int m, unsigned int n);
    static void newGenerator(unsigned int m, unsigned int n, unsigned int roomsWithDoor);
    static bool emptyRoom(unsigned long long int& iterator, unsigned long long int& room, unsigned int& m, unsigned int& n, unsigned int& r);
};


#endif //AI_MAZE_SEARCH_ALGORITHMS_UTILS_H
