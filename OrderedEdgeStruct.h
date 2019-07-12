//
// Created by viniman on 10/07/19.
//

#include "Node.h"

#ifndef AI_MAZE_SEARCH_ALGORITHMS_ORDEREDEDGESTRUCT_H
#define AI_MAZE_SEARCH_ALGORITHMS_ORDEREDEDGESTRUCT_H

#endif //AI_MAZE_SEARCH_ALGORITHMS_ORDEREDEDGESTRUCT_H


class OrderedEdgeStruct{
public:
    Node* room1;
    Node* room2;
    double weight;
    struct Edge { int room1; int room2; double weight; };
    list<Edge> EdgeList;

    bool operator<(const OrderedEdgeStruct &rhs) const
    {
        return weight < rhs.weight;
    }

    bool operator>(const OrderedEdgeStruct &rhs) const
    {
        return rhs < *this;
    }

    bool operator<=(const OrderedEdgeStruct &rhs) const
    {
        return !(rhs < *this);
    }

    bool operator>=(const OrderedEdgeStruct &rhs) const
    {
        return !(*this < rhs);
    }


    OrderedEdgeStruct(Node * room1, Node * room2, double weight) : room1(room1), room2(room2), weight(weight) {};
};
