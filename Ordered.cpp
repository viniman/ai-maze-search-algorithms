//
// Created by viniman on 09/06/19.
//

#include <queue>
#include <list>
#include <iostream>
#include <algorithm>
#include "Ordered.h"
#include "OrderedEdgeStruct.h"
#include "Statistics.h"

void Ordered::orderedSearchAlgorithm(Maze &maze)
{
    cleanMazeForSearch(maze);

    Statistics statistics(maze.getNumRooms());
    statistics.setAlgorithmName("Busca Ordenada");
    statistics.startTiming();

    //queue<Node*> openedNodeList;
    queue<Node*> closedNodeList;
    Node* searchPointer = maze.getOrigin();
    bool failure, success;
    failure = success = false;

    Node* neighbor;

    list<OrderedEdgeStruct> orderedOpenEdgeList;

    orderedOpenEdgeList.emplace_back(searchPointer, searchPointer, 0);

    while (!(success || failure))
    {
        if(orderedOpenEdgeList.empty())
            failure = true;
        else
        {
            searchPointer = orderedOpenEdgeList.front().room2;
            double curretNodeWeight= orderedOpenEdgeList.front().weight;
            orderedOpenEdgeList.pop_front();
            if(searchPointer->getId() == maze.getDestination()->getId())
            {
                success = true;
                /// Pegar a solução aqui
            }
            else
            {
                // fazer metodo que retorna proximo room nao nulo
                // com metodo acima, proxNaoNulo, while(op!='N' && proxNaoNulo = getProxNaoNulo())

                do
                {
                    char nextOp = nextOperation(searchPointer);
                    neighbor = searchPointer->roomDirectionReturn(nextOp);
                    if(neighbor && !neighbor->isVisited())
                    {
                        neighbor->setVisitedBy(nextOp);
                        neighbor->setVisited();
                        int weight = maze.weightMatrix[searchPointer->getX()][neighbor->getY()];
                        orderedOpenEdgeList.emplace_back(searchPointer, neighbor, weight+curretNodeWeight);
                    }
                    searchPointer->setDirectionVisited(nextOp);
                }
                while (searchPointer->getDirectionVisited() != 'N');
                closedNodeList.push(searchPointer);
            }
            orderedOpenEdgeList.sort();
        }
    }

    statistics.executionTimeMeasure();
    statistics.setSucced(success && !failure);
    statistics.printStatistics();
}
