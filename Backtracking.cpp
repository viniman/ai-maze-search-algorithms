//
// Created by viniman on 10/06/19.
//

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
        if(searchPointer->right)
            return 'B';
    }
    else if(searchPointer->directionVisited == 'B')
    {
        if(searchPointer->right)
            return 'L';
    }
    else if(searchPointer->directionVisited == 'L')
    {
        if(searchPointer->right)
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
        char nextOp = nextOperation(maze);
        if(nextOp != 'N')
        {
            searchPointer = searchPointer->roomDirectionReturn(nextOp);
            if(searchPointer->id == maze.destination)
                success = true;
        }
        else
        {
            if(initialState == currentState)
                failure = true;
            else
            {
                currentState = oppositeWay(searchPointer->directionVisited);//funcao para pegar o pai
                searchPointer = maze.chambers[currentState];
            }
        }
    }

}
