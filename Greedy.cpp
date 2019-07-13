//
// Created by viniman on 09/06/19.
//

#include "Greedy.h"

void Greedy::greedySearchAlgorithm(Maze& maze)
{

    cleanMazeForSearch(maze);
    list<Node*> listNode;

    Statistics statistics(maze.getNumRooms());
    statistics.startTiming();

    statistics.setAlgorithmName("greedySearchAlgorithm");

    Node *corrente = maze.getOrigin();
    corrente->setProfundidade(0);
    Node const * const destination = maze.getDestination();

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

        if(corrente->getFather())
            (corrente->getFather())->setSucessores();

        (statistics.pathSolution).push_back(corrente->getId());

        insereNode(&listNode, corrente, corrente->getTop(), statistics);
        insereNode(&listNode, corrente, corrente->getLeft(), statistics);
        insereNode(&listNode, corrente, corrente->getBotton(), statistics);
        insereNode(&listNode, corrente, corrente->getRight(), statistics);

    }

    statistics.executionTimeMeasure();
    statistics.setProfundidadeSolucao((maze.getDestination())->getProfundidade());


    statistics.setSucced(destination->isVisited());

    int custo = (statistics.pathSolution).size();

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

    delete aux2;




}

bool Greedy::removeBest(list<Node*> *listNode, Node **corrente)
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

        if((*it)->getHeuristicValue() < aux->getHeuristicValue())
            aux = *it;

    }

    listNode->remove(aux);

    *corrente = aux;

    return true;


}

void Greedy::insereNode(list<Node *> *listNode, Node *corrente, Node *direcao, Statistics &statistics)
{
    if(direcao == NULL)
        return;

    //Se direcao já foi visitado, retorna
    if(direcao->isVisited())
        return;

    //Verifica se já foi inserido na lista
    if(!direcao->getAdicionadoNodeLista())
    {

        statistics.expandirNo();
        listNode->push_back(direcao); //Insere direcao na lista
        direcao->adicionarNodeLista();
        direcao->setProfundidade(corrente->getProfundidade() + 1);
        statistics.setProfundidade(corrente->getProfundidade() + 1);
        direcao->setFather(corrente);

    }


}
