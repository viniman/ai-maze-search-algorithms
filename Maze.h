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
    Node* origin;
    Node* destination;
    char operacao(Node *no1, Node *no2);
    vector<int> heuristicFunc; //usar unordered_map ou map?

    vector<Node*> rooms;

    void calculaXY();
    int manhattanDistance(Node *no1);

    explicit Maze(string path);
};


#endif //AI_MAZE_SEARCH_ALGORITHMS_MAZE_H
