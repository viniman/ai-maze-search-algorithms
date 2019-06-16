//
// Created by viniman on 10/06/19.
//

#include <iostream>
#include "Backtracking.h"

vector<char> operations;


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
        default:
            return 'N';
    }
}

char nextOperation(Node* searchPointer)
{
    if(searchPointer->getDirectionVisited() == 'N') // nao visitou ninguem, entao testa todos
    {
        if(searchPointer->getRight() && oppositeWay(searchPointer->getVisitedBy()) != 'R')
            return 'R';
        if(searchPointer->getBotton()&& oppositeWay(searchPointer->getVisitedBy()) != 'B')
            return 'B';
        if(searchPointer->getLeft()&& oppositeWay(searchPointer->getVisitedBy()) != 'L')
            return 'L';
        if(searchPointer->getTop() && oppositeWay(searchPointer->getVisitedBy()) != 'T')
            return 'T';

    }
    if(searchPointer->getDirectionVisited()== 'R') //ja visitou R, entao visita o que sobrou
    {
        if(searchPointer->getBotton() && oppositeWay(searchPointer->getVisitedBy()) != 'B')
            return 'B';
        if(searchPointer->getLeft() && oppositeWay(searchPointer->getVisitedBy()) != 'L')
            return 'L';
        if(searchPointer->getTop()&& oppositeWay(searchPointer->getVisitedBy()) != 'T')
            return 'T';
    }
    if(searchPointer->getDirectionVisited()== 'B')
    {
        if(searchPointer->getLeft()&& oppositeWay(searchPointer->getVisitedBy()) != 'L')
            return 'L';
        if(searchPointer->getTop()&& oppositeWay(searchPointer->getVisitedBy()) != 'T')
            return 'T';
    }
    if(searchPointer->getDirectionVisited()== 'L')
    {
        if(searchPointer->getTop()&& oppositeWay(searchPointer->getVisitedBy()) != 'T')
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

    Node* searchPointer = maze.getOrigin();

    while (!(failure || success))
    {
        char nextOp = nextOperation(searchPointer); // proxima operacao a tomar
        if(nextOp != 'N' && !searchPointer->roomDirectionReturn(nextOp))
        {

            searchPointer->setDirectionVisited(nextOp);
            searchPointer = searchPointer->roomDirectionReturn(nextOp);
            searchPointer->setVisitedBy(nextOp);
            searchPointer->setVisited();
            if(searchPointer->getId() == maze.getDestination()->getId())
                success = true;
        }
        else
        {
            if(searchPointer->getId() == maze.getOrigin()->getId())
                failure = true;
            else
            {
                nextOp = oppositeWay(searchPointer->getVisitedBy());//funcao para pegar o pai
                searchPointer = searchPointer->roomDirectionReturn(nextOp);
            }
        }
    }
    if(failure)
        cout << "FALHA" << endl;
    if(success)
        cout << "SUCESSO" << endl;
}
