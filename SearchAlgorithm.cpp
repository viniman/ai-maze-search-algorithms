//
// Created by viniman on 22/06/19.
//

#include "SearchAlgorithm.h"


char SearchAlgorithm::oppositeWay(char c)
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


char SearchAlgorithm::nextOperation(Node* searchPointer)
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

void SearchAlgorithm::cleanMazeForSearch(Maze& maze)
{

    for(auto& iterator : maze.getRooms())
    {
        iterator->setVisitedBy('N');
        iterator->setDirectionVisited('N');
        iterator->setNonVisited();
        iterator->setdistanceOrigin(0);
        iterator->setsumHeurDist(0);
        iterator->setFather(NULL);
        iterator->removerNodeLista();
        iterator->setProfundidade(0);
    }
}
