//
// Created by viniman on 09/06/19.
//

#ifndef AI_MAZE_SEARCH_ALGORITHMS_IDASTAR_H
#define AI_MAZE_SEARCH_ALGORITHMS_IDASTAR_H

//https://algorithmsinsight.wordpress.com/graph-theory-2/ida-star-algorithm-in-general/

#include "SearchAlgorithm.h"
#include <list>
#include <iostream>
#include "Statistics.h"
#include<cmath>

class IDAStar : public SearchAlgorithm
{

public:
    static void IDAStarSearchAlgorithm(Maze &maze, Statistics &statistics);

private:
    static bool
    verificaPatamar(Node *corrente, Node *direcao, const float patamar, float *oldpatamar, Statistics &statistics);
    static void corrigeNos(Maze& maze);

};


#endif //AI_MAZE_SEARCH_ALGORITHMS_IDASTAR_H
