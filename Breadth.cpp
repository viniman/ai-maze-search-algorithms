//
// Created by viniman on 09/06/19.
//

#include <queue>
#include <iostream>
#include "Breadth.h"

using namespace std;

void Breadth::breadthSearchAlgorithm(Maze &maze)
{
    cleanMazeForSearch(maze);

    queue<Node*> openedNodeList;
    queue<Node*> closedNodeList;
    Node* searchPointer = maze.getOrigin();
    bool failure, success;
    failure = success = false;

    Node* neighbor;

    openedNodeList.push(searchPointer);

    while (!(success || failure))
    {
        if(openedNodeList.empty())
            failure = true;
        else
        {
            searchPointer = openedNodeList.front();
            openedNodeList.pop();
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
                        openedNodeList.push(neighbor);
                    }
                    searchPointer->setDirectionVisited(nextOp);
                }
                while (searchPointer->getDirectionVisited() != 'N');
                closedNodeList.push(searchPointer);
            }
        }
    }

    if(success && !failure)
        std::cout << "SUCESSO LARGURA" << std::endl;
    else
        std::cout << "FRACASSO LARGURA" << std::endl;
}
