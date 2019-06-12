//
// Created by viniman on 10/06/19.
//

#ifndef AI_MAZE_SEARCH_ALGORITHMS_NODE_H
#define AI_MAZE_SEARCH_ALGORITHMS_NODE_H


class Node
{
public:
    unsigned int heuristicValue;
    int id;

    Node* right = nullptr;
    Node* left = nullptr;
    Node* botton = nullptr;
    Node* top = nullptr;

    char directionVisited = 'N';
    char visitedBy = 'N';
    bool alreadyVisited = false;
    Node* roomDirectionReturn(char &op);

    Node();
    Node(int id, unsigned int peso);

};


#endif //AI_MAZE_SEARCH_ALGORITHMS_NODE_H
