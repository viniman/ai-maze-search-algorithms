//
// Created by viniman on 10/06/19.
//

#include "Node.h"


Node::Node(int id, unsigned int heuristicValue)
{
    this->id = id;
    this->heuristicValue = heuristicValue;
}

Node* Node::roomDirectionReturn(char &op)
{
    switch (op)
    {
        case 'L':
            return left;
        case 'B':
            return botton;
        case 'R':
            return right;
        case 'T':
            return top;
    }
}
