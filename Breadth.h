//
// Created by viniman on 09/06/19.
//

#ifndef AI_MAZE_SEARCH_ALGORITHMS_BREADTH_H
#define AI_MAZE_SEARCH_ALGORITHMS_BREADTH_H


#include "Maze.h"
#include "SearchAlgorithm.h"

class Breadth : public SearchAlgorithm
{
public:
    static void breadthSearchAlgorithm(Maze& maze);
};


#endif //AI_MAZE_SEARCH_ALGORITHMS_BREADTH_H
