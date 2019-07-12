//
// Created by viniman on 09/06/19.
//

#ifndef AI_MAZE_SEARCH_ALGORITHMS_GREEDY_H
#define AI_MAZE_SEARCH_ALGORITHMS_GREEDY_H


#include "SearchAlgorithm.h"
#include "Maze.h"
#include "math.h"
#include <iostream>
#include <list>
#include "Statistics.h"

using namespace std;

class Greedy : public SearchAlgorithm
{

public:
    static void greedySearchAlgorithm(Maze& maze);

private:
    static bool removeBest(list<Node*> *listNode, Node **corrente);
    static void insereNode(list<Node *> *listNode, Node *corrente, Node *direcao, Statistics &statistics);
};


#endif //AI_MAZE_SEARCH_ALGORITHMS_GREEDY_H
