//
// Created by viniman on 09/06/19.
//

#include "AStar.h"
#include "Statistics.h"

using namespace std;

void AStar::ASearchAlgorithm(Maze& maze)
{
    cleanMazeForSearch(maze);
    Statistics statistics(maze.getNumRooms());
    statistics.setAlgorithmName("A*");

    cleanMazeForSearch(maze);

    statistics.startTiming();

    list<Node*> listNode;

    Node *corrente = maze.getOrigin();
    corrente->setProfundidade(0);

    Node const * const destination = maze.getDestination();

    //Atualiza origem
    corrente->setdistanceOrigin(0);
    corrente->setsumHeurDist(corrente->getHeuristicValue());

    Node *aux2 = new Node(0,0);
    Node **aux =&aux2;

    //Inicializa a lista com a origem
    listNode.push_back(maze.getOrigin());

    //Verifica se existe elemento na lista e se o destino já foi visitado.
    while(removeBest(&listNode, aux) && !(destination->isVisited()))
    {
        corrente = *aux;

        corrente->setVisited();
        statistics.visitarNo();
        statistics.pathSolution.push_back(corrente->getId());

        insereNode(&listNode, corrente, corrente->getTop(), statistics);
        insereNode(&listNode, corrente, corrente->getLeft(), statistics);
        insereNode(&listNode, corrente, corrente->getBotton(), statistics);
        insereNode(&listNode, corrente, corrente->getRight(), statistics);

    }

    statistics.executionTimeMeasure();

    statistics.setSucced((maze.getDestination())->isVisited());

    statistics.setProfundidadeSolucao((maze.getDestination())->getProfundidade());

    int custo = statistics.pathSolution.size();
    statistics.setCustoSolucao(custo);

    statistics.printStatistics();

    delete aux2;

}

bool AStar::removeBest(list<Node*> *listNode, Node **corrente)
{
    Node *aux;

    if(corrente == NULL)
    {
        cout<<"Corrente NULL\n";
        exit(-5);
    }

    if(listNode->empty())  //Verifica se a lista está vazia.
        return false;

    auto it = listNode->begin();
    aux = *it;


    for(;it != listNode->end(); ++it)   //Percorre a lista verificando se existe um Node melhor do que o corrente.
    {

        if((*it)->getsumHeurDist() < aux->getsumHeurDist())
            aux = *it;

    }

    listNode->remove(aux);

    *corrente = aux;

    return true;


}

void AStar::insereNode(list<Node *> *listNode, Node *corrente, Node *direcao, Statistics &statistics)
{
    if(direcao == NULL)
        return;

    //Se direcao já foi visitado, retorna
    if(direcao->isVisited())
        return;

    unsigned int distanceOrigin = corrente->getdistanceOrigin() + 1;

    //Verifica se já foi inserido na lista
    if(direcao->getdistanceOrigin() == 0)
    {
        //Atualiza dados.
        direcao->setdistanceOrigin(distanceOrigin);
        direcao->setsumHeurDist(distanceOrigin + direcao->getHeuristicValue());

        listNode->push_back(direcao); //Insere direcao na lista

        statistics.expandirNo();
        statistics.setProfundidade(corrente->getProfundidade() + 1);

    }
    else
    {
        //Valor distancia até direcao mais o valor heurístico
        unsigned int sumDistHeur = distanceOrigin + direcao->getHeuristicValue();

        //Verifica se direcao chegando por corrente é melhor do que o atual.
        if(sumDistHeur < direcao->getsumHeurDist())
        {
            //Atualiza dados
            direcao->setdistanceOrigin(distanceOrigin);
            direcao->setsumHeurDist(distanceOrigin + direcao->getHeuristicValue());
            statistics.setProfundidade(corrente->getProfundidade() + 1);

        }


    }
}