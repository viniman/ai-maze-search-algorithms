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

    virtual ~Maze();

    explicit Maze(unsigned int m, unsigned int n, bool addDoors, unsigned int origin=0, unsigned int dest=0);
    Node *getOrigin() const;
    Node *getDestination() const;
    void setDestination(unsigned int id);
    void setOrigin(unsigned int id);
    unsigned int getMazeLines() const;
    unsigned int getMazeColumns() const;
    unsigned int getNumRooms() const;
    Node * getRoom(int id) const;
    char operacao(Node *no1, Node *no2);
    void calculaXY();
    int manhattanDistance(Node *no1);
    void setVisitedAllFalse();
    void addDoor(unsigned int room1, unsigned int room2);

    const vector<Node *> &getRooms() const;
    int** weightMatrix;
    void initiateWeightMatrix(bool randomizedWeight, unsigned int maxRandValue);


};


#endif //AI_MAZE_SEARCH_ALGORITHMS_MAZE_H
