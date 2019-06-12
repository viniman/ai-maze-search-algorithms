//
// Created by viniman on 10/06/19.
//

#ifndef AI_MAZE_SEARCH_ALGORITHMS_MAZE_H
#define AI_MAZE_SEARCH_ALGORITHMS_MAZE_H


#include <vector>
#include <string>
#include "Node.h"

using namespace std;

class Maze
{
public:
    unsigned int mazeLines;
    unsigned int mazeColumns;
    unsigned int numRooms;
    unsigned int source;
    unsigned int destination;
    char operacao(Node *no1, Node *no2);
    vector<int> heuristicFunc;

    vector<Node*> rooms;
    char nextOperation();

    void calculaXY();


    explicit Maze(string path);
};


#endif //AI_MAZE_SEARCH_ALGORITHMS_MAZE_H
