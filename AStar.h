//
// Created by viniman on 09/06/19.
//

#ifndef AI_MAZE_SEARCH_ALGORITHMS_ASTAR_H
#define AI_MAZE_SEARCH_ALGORITHMS_ASTAR_H

#include <iostream>
#include "SearchAlgorithm.h"
#include "Maze.h"
#include<list>

using namespace std;

class AStar : public SearchAlgorithm
{

public:
    static void ASearchAlgorithm(Maze& maze);
    static bool removeBest(list<Node*> *listNode, Node **corrente);
    static void insereNode(list<Node*> *listNode, Node *corrente, Node *direcao);


};


#endif //AI_MAZE_SEARCH_ALGORITHMS_ASTAR_H
