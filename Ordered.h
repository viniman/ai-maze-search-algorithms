//
// Created by viniman on 09/06/19.
//

#ifndef AI_MAZE_SEARCH_ALGORITHMS_ORDERED_H
#define AI_MAZE_SEARCH_ALGORITHMS_ORDERED_H


#include "SearchAlgorithm.h"

class Ordered : public SearchAlgorithm
{
public:
    static void orderedSearchAlgorithm(Maze &maze);
};


#endif //AI_MAZE_SEARCH_ALGORITHMS_ORDERED_H
