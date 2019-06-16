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
private:
    unsigned int mazeLines;
    unsigned int mazeColumns;
    unsigned int numRooms;
    Node* origin;
    Node* destination;
    vector<Node*> rooms;

public:
    explicit Maze(string path);
    Node *getOrigin() const;
    Node *getDestination() const;
    unsigned int getMazeLines() const;
    unsigned int getMazeColumns() const;
    unsigned int getNumRooms() const;
    const Node* getRoom(int id) const;
    char operacao(Node *no1, Node *no2);
    void calculaXY();
    int manhattanDistance(Node *no1);

};


#endif //AI_MAZE_SEARCH_ALGORITHMS_MAZE_H
