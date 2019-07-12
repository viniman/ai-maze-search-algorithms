//
// Created by viniman on 10/06/19.
//

#ifndef AI_MAZE_SEARCH_ALGORITHMS_BACKTRACKING_H
#define AI_MAZE_SEARCH_ALGORITHMS_BACKTRACKING_H


#include "Maze.h"
#include "SearchAlgorithm.h"
#include "Statistics.h"

class Backtracking : public SearchAlgorithm
{
public:
    static void backtrackingSearchAlgorithm(Maze &maze);
    static void backtrackingSearchAlgorithmPAI(Maze& maze);
};


#endif //AI_MAZE_SEARCH_ALGORITHMS_BACKTRACKING_H
