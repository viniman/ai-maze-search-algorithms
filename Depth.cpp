//
// Created by viniman on 09/06/19.
//

#include "Depth.h"
#include "Statistics.h"


void Depth::DepthSearchAlgorithm(Maze& maze)
{
    cleanMazeForSearch(maze);

    Statistics statistics(maze.getNumRooms());
    statistics.setAlgorithmName("DepthSearchAlgorithm");
    statistics.startTiming();

    stack<Node*> stackNode;             //Pilha de nós
    stackNode.push(maze.getOrigin());   //Coloca a origem no topo da pilha.
    statistics.expandirNo();

    Node * dest = maze.getDestination();

    Node *corrente = NULL;
    Node *neighborhood = NULL;

    (maze.getOrigin())->setProfundidade(0);

    // Continua enqunto a origem não for atingida e a pilha for não fazia.
    while((!dest->isVisited()) && (!stackNode.empty()))
    {

        corrente = stackNode.top(); //Atualiza o nó corrente
        stackNode.pop();            //Remove o topo da pilha.

        statistics.pathSolution.push_back(corrente->getId());

        statistics.visitarNo();

        //Tenta o quarto a esquerda.

        neighborhood = corrente->getLeft();

        if((neighborhood != NULL) &&  (!neighborhood->isVisited()))
        {
            neighborhood->setFather(corrente);
            stackNode.push(neighborhood);
            neighborhood->setProfundidade(corrente->getProfundidade() + 1);
            statistics.setProfundidade(neighborhood->getProfundidade());
            statistics.expandirNo();
        }

        //Tenta o quarto em baixo.

        neighborhood = corrente->getBotton();

        if((neighborhood != NULL) &&  (!neighborhood->isVisited()))
        {
            neighborhood->setFather(corrente);
            stackNode.push(neighborhood);
            statistics.expandirNo();
            neighborhood->setProfundidade(corrente->getProfundidade() + 1);
            statistics.setProfundidade(neighborhood->getProfundidade());
        }

        //Tenta o quarto a direita.

        neighborhood = corrente->getRight();

        if((neighborhood != NULL) &&  (!neighborhood->isVisited()))
        {
            neighborhood->setFather(corrente);
            stackNode.push(neighborhood);
            statistics.expandirNo();
            neighborhood->setProfundidade(corrente->getProfundidade() + 1);
            statistics.setProfundidade(neighborhood->getProfundidade());
        }

        //Tenta o quarto de cima.

        neighborhood = corrente->getTop();

        if((neighborhood != NULL) &&  (!neighborhood->isVisited()))
        {
            neighborhood->setFather(corrente);
            stackNode.push(neighborhood);
            statistics.expandirNo();
            neighborhood->setProfundidade(corrente->getProfundidade() + 1);
            statistics.setProfundidade(neighborhood->getProfundidade());
        }

        //Visitamos o Nó.
        corrente->setVisited();


    }

    statistics.executionTimeMeasure();
    statistics.setSucced(dest->isVisited());
    statistics.setProfundidadeSolucao(dest->getProfundidade());
    int custo = statistics.pathSolution.size();
    statistics.setCustoSolucao(custo);

    statistics.printStatistics();


}
