//
// Created by viniman on 10/06/19.
//

#include <iostream>
#include "Backtracking.h"
#include "Statistics.h"

//operations.push_back('R');
//operations.push_back('L');
//operations.push_back('T');
//operations.push_back('B');


vector<char> SearchAlgorithm::operations;

void Backtracking::backtrackingSearchAlgorithm(Maze &maze)
{
    cleanMazeForSearch(maze);

    Statistics statistics(maze.getNumRooms());
    statistics.setAlgorithmName("Backtracking");
    statistics.startTiming();

    bool failure, success;
    failure = success = false;

    Node* searchPointer = maze.getOrigin();

    while (!(failure || success))
    {
        char nextOp = nextOperation(searchPointer); // proxima operacao a tomar
        if(nextOp != 'N' && searchPointer->roomDirectionReturn(nextOp))
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

    statistics.executionTimeMeasure();
    statistics.setSucced(success && !failure);
    statistics.printStatistics();

}

void Backtracking::backtrackingSearchAlgorithmPAI(Maze& maze)
{
    cleanMazeForSearch(maze);

    Statistics statistics(maze.getNumRooms());
    statistics.setAlgorithmName("Backtracking com Pai");
    statistics.startTiming();

    bool failure, success;
    failure = success = false;

    Node* searchPointer = maze.getOrigin();

    while (!(failure || success))
    {
        char nextOp = nextOperation(searchPointer); // proxima operacao a tomar
        Node* neighborhood = searchPointer->roomDirectionReturn(nextOp);
        if(nextOp != 'N' && neighborhood)
        {
            neighborhood->setFather(searchPointer);//pai = searchPointer;
            searchPointer->setDirectionVisited(nextOp);
            searchPointer = neighborhood;
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
                //nextOp = oppositeWay(searchPointer->getVisitedBy());//funcao para pegar o pai
                //searchPointer = searchPointer->roomDirectionReturn(nextOp);
                searchPointer = searchPointer->getFather();
            }
        }
    }

    statistics.executionTimeMeasure();
    statistics.setSucced(success && !failure);
    if(success)
        while (searchPointer)
        {
            statistics.setNodeSolution(searchPointer->getId());
            searchPointer = searchPointer->getFather();
        }
    statistics.printStatistics();
}
