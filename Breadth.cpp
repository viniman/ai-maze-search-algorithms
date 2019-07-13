//
// Created by viniman on 09/06/19.
//

#include <queue>
#include <iostream>
#include "Breadth.h"
#include "Statistics.h"

using namespace std;

void Breadth::breadthSearchAlgorithm(Maze &maze)
{
    cleanMazeForSearch(maze);
    Statistics statistics(maze.getNumRooms());
    statistics.setAlgorithmName("BreadthSearchAlgorithm");
    statistics.startTiming();

    queue<Node*> openedNodeList;
    queue<Node*> closedNodeList;
    Node* searchPointer = maze.getOrigin();
    bool failure, success;
    failure = success = false;

    Node* neighbor;

    openedNodeList.push(searchPointer);
    searchPointer->setProfundidade(0);

    while (!(success || failure))
    {
        if(openedNodeList.empty())
            failure = true;
        else
        {
            searchPointer = openedNodeList.front();
            searchPointer->setVisited();
            statistics.visitarNo();

            statistics.pathSolution.push_back(searchPointer->getId());

            if(searchPointer->getFather())
                (searchPointer->getFather())->setSucessores();

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
                        neighbor->setProfundidade(searchPointer->getProfundidade() + 1);
                        neighbor->setFather(searchPointer);
                        statistics.expandirNo();
                        statistics.setProfundidade(neighbor->getProfundidade());

                        openedNodeList.push(neighbor);
                    }
                    searchPointer->setDirectionVisited(nextOp);
                }
                while (searchPointer->getDirectionVisited() != 'N');
                closedNodeList.push(searchPointer);
            }
        }
    }

    statistics.executionTimeMeasure();
    statistics.setSucced((maze.getDestination())->getProfundidade());
    statistics.setProfundidadeSolucao((maze.getDestination())->getProfundidade());
    int custo = statistics.pathSolution.size();
    statistics.setCustoSolucao(custo);

    const vector<Node*> &rooms = maze.getRooms();

    int sucessores = 0;

    for(auto it = rooms.begin(); it != rooms.end(); ++it)
    {

        if((*it)->isVisited())
            sucessores += (*it)->getSucessores();


    }

    statistics.setMediaRamificacao(float(sucessores)/statistics.getNosVisitados());

    statistics.printStatistics();


}
