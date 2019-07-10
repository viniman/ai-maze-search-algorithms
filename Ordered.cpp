//
// Created by viniman on 09/06/19.
//

#include <queue>
#include <list>
#include <iostream>
#include <algorithm>
#include "Ordered.h"
#include "OrderedEdgeStruct.h"

void Ordered::orderedSearchAlgorithm(Maze &maze)
{
    cleanMazeForSearch(maze);

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
            searchPointer = orderedOpenEdgeList.back().room2;
            orderedOpenEdgeList.pop_back();
            if(searchPointer->getId() == maze.getDestination()->getId())
                success = true;
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
                        orderedOpenEdgeList.emplace_back(searchPointer, neighbor, weight);
                    }
                    searchPointer->setDirectionVisited(nextOp);
                }
                while (searchPointer->getDirectionVisited() != 'N');
                closedNodeList.push(searchPointer);
            }
            orderedOpenEdgeList.sort();
        }
    }

    if(success && !failure)
        std::cout << "SUCESSO Ordered" << std::endl;
    else
        std::cout << "FRACASSO Ordered" << std::endl;
}
