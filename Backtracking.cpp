//
// Created by viniman on 10/06/19.
//

#include <iostream>
#include "Backtracking.h"

vector<char> operations;
Node* searchPointer;

char oppositeWay(char c)
{
    switch (c)
    {
        case 'L':
            return 'R';
        case 'R':
            return 'L';
        case 'B':
            return 'T';
        case 'T':
            return 'B';
    }
}

char nextOperation(Maze& maze)
{
    int operationId=0;
    if(searchPointer->directionVisited == 'N')
    {
        if(searchPointer->right)
            return 'R';
    }
    else if(searchPointer->directionVisited == 'R')
    {
        if(searchPointer->botton)
            return 'B';
    }
    else if(searchPointer->directionVisited == 'B')
    {
        if(searchPointer->left)
            return 'L';
    }
    else if(searchPointer->directionVisited == 'L')
    {
        if(searchPointer->top)
            return 'T';
    }
    return 'N';



}


void Backtracking::backtrackingSearchAlgorithm(Maze& maze)
{

    operations.push_back('R');
    operations.push_back('L');
    operations.push_back('T');
    operations.push_back('B');
    int contOperator = 0;
    char op = 'R';
    int initialState = maze.source;
    int currentState = initialState;
    bool failure, success;
    failure = success = false;

    searchPointer = maze.chambers[initialState];

    while (!(failure || success))
    {
        char nextOp = nextOperation(maze); // proxima operacao a tomar
        if(nextOp != 'N')
        {
            //if(searchPointer->alreadyVisited)
                //nextOp = searchPointer->directionVisited;
            searchPointer->directionVisited = nextOp;
            searchPointer = searchPointer->roomDirectionReturn(nextOp);
            searchPointer->visitedBy = nextOp;
            //searchPointer->directionVisited = nextOp;
            searchPointer->alreadyVisited = true;
            currentState = searchPointer->id;
            if(searchPointer->id == maze.destination)
                success = true;
        }
        else
        {
            if(initialState == currentState)
                failure = true;
            else
            {
                nextOp = oppositeWay(searchPointer->visitedBy);//funcao para pegar o pai
                searchPointer = searchPointer->roomDirectionReturn(nextOp);
                currentState = searchPointer->id;
            }
        }
    }
    if(failure)
        cout << "FALHA" << endl;
    if(success)
        cout << "SUCESSO" << endl;
}
