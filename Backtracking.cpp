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

char nextOperation()
{
    if(searchPointer->directionVisited == 'N') // nao visitou ninguem, entao testa todos
    {
        if(searchPointer->right && oppositeWay(searchPointer->visitedBy) != 'R')
            return 'R';
        if(searchPointer->botton && oppositeWay(searchPointer->visitedBy) != 'B')
            return 'B';
        if(searchPointer->left && oppositeWay(searchPointer->visitedBy) != 'L')
            return 'L';
        if(searchPointer->top && oppositeWay(searchPointer->visitedBy) != 'T')
            return 'T';

    }
    if(searchPointer->directionVisited == 'R') //ja visitou R, entao visita o que sobrou
    {
        if(searchPointer->botton && oppositeWay(searchPointer->visitedBy) != 'B')
            return 'B';
        if(searchPointer->left && oppositeWay(searchPointer->visitedBy) != 'L')
            return 'L';
        if(searchPointer->top && oppositeWay(searchPointer->visitedBy) != 'T')
            return 'T';
    }
    if(searchPointer->directionVisited == 'B')
    {
        if(searchPointer->left && oppositeWay(searchPointer->visitedBy) != 'L')
            return 'L';
        if(searchPointer->top && oppositeWay(searchPointer->visitedBy) != 'T')
            return 'T';
    }
    if(searchPointer->directionVisited == 'L')
    {
        if(searchPointer->top && oppositeWay(searchPointer->visitedBy) != 'T')
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
    bool failure, success;
    failure = success = false;

    searchPointer = maze.chambers[maze.source];

    while (!(failure || success))
    {
        char nextOp = nextOperation(); // proxima operacao a tomar
        if(nextOp != 'N' && !searchPointer->roomDirectionReturn(nextOp)->alreadyVisited)
        {

            searchPointer->directionVisited = nextOp;
            searchPointer = searchPointer->roomDirectionReturn(nextOp);
            searchPointer->visitedBy = nextOp;
            searchPointer->alreadyVisited = true;
            if(searchPointer->id == maze.destination)
                success = true;
        }
        else
        {
            if(searchPointer->id == maze.source)
                failure = true;
            else
            {
                nextOp = oppositeWay(searchPointer->visitedBy);//funcao para pegar o pai
                searchPointer = searchPointer->roomDirectionReturn(nextOp);
            }
        }
    }
    if(failure)
        cout << "FALHA" << endl;
    if(success)
        cout << "SUCESSO" << endl;
}
