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
};


#endif //AI_MAZE_SEARCH_ALGORITHMS_UTILS_H
