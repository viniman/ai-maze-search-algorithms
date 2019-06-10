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
    unsigned int rooms;
    unsigned int source;
    unsigned int destination;
    vector<int> heuristicFunc;

    vector<Node*> chambers;
    char nextOperation();

    explicit Maze(string path);
};


#endif //AI_MAZE_SEARCH_ALGORITHMS_MAZE_H
