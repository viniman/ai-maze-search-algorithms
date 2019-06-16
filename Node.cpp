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

Node *Node::getRight() const
{
    return right;
}

Node *Node::getLeft() const
{
    return left;
}

Node *Node::getBotton() const
{
    return botton;
}

Node *Node::getTop() const
{
    return top;
}

void Node::setRight(Node *right)
{
    Node::right = right;
}

char Node::getDirectionVisited() const
{
    return directionVisited;
}

void Node::setVisited()
{
    Node::alreadyVisited = true;
}

char Node::getVisitedBy() const
{
    return visitedBy;
}

bool Node::isVisited() const
{
    return alreadyVisited;
}

void Node::setDirectionVisited(char directionVisited)
{
    Node::directionVisited = directionVisited;
}

void Node::setVisitedBy(char visitedBy)
{
    Node::visitedBy = visitedBy;
}

void Node::setLeft(Node *left)
{
    Node::left = left;
}

void Node::setBotton(Node *botton)
{
    Node::botton = botton;
}

void Node::setTop(Node *top)
{
    Node::top = top;
}

void Node::setHeuristicValue(unsigned int heuristicValue)
{
    Node::heuristicValue = heuristicValue;
}

unsigned int Node::getHeuristicValue() const
{
    return heuristicValue;
}

int Node::getId() const
{
    return id;
}

int Node::getX() const
{
    return x;
}

int Node::getY() const
{
    return y;
}

void Node::setId(int id)
{
    Node::id = id;
}

void Node::setX(int x)
{
    Node::x = x;
}

void Node::setY(int y)
{
    Node::y = y;
}

Node::Node(int id)
{
    Node::id = id;
}
