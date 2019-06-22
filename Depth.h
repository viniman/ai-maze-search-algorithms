//
// Created by viniman on 09/06/19.
//

#ifndef AI_MAZE_SEARCH_ALGORITHMS_DEPTH_H
#define AI_MAZE_SEARCH_ALGORITHMS_DEPTH_H

#include <iostream>
#include "Maze.h"
#include "SearchAlgorithm.h"
#include <stack>

using namespace std;

class Depth : public SearchAlgorithm
{
public:
    static void DepthSearchAlgorithm(Maze& maze);
};


#endif //AI_MAZE_SEARCH_ALGORITHMS_DEPTH_H
