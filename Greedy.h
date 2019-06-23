//
// Created by viniman on 09/06/19.
//

#ifndef AI_MAZE_SEARCH_ALGORITHMS_GREEDY_H
#define AI_MAZE_SEARCH_ALGORITHMS_GREEDY_H


#include "SearchAlgorithm.h"
#include "Maze.h"
#include "math.h"
#include <iostream>
using namespace std;

class Greedy : public SearchAlgorithm
{

public:
    static void greedySearchAlgorithm(Maze& maze);
};


#endif //AI_MAZE_SEARCH_ALGORITHMS_GREEDY_H
