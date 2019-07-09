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

    Node* neighborhood;

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
                    neighborhood = searchPointer->roomDirectionReturn(nextOp);
                    if(neighborhood && !neighborhood->isVisited())
                    {
                        neighborhood->setVisitedBy(nextOp);
                        neighborhood->setVisited();
                        openedNodeList.push(neighborhood);
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
