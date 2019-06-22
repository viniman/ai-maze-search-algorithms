//
// Created by viniman on 22/06/19.
//

#ifndef AI_MAZE_SEARCH_ALGORITHMS_SEARCHALGORITHM_H
#define AI_MAZE_SEARCH_ALGORITHMS_SEARCHALGORITHM_H

#include <vector>
#include "Node.h"

class SearchAlgorithm
{
public:
    static std::vector<char> operations;
    static char oppositeWay(char c);
    static char nextOperation(Node* searchPointer);
};


#endif //AI_MAZE_SEARCH_ALGORITHMS_SEARCHALGORITHM_H
