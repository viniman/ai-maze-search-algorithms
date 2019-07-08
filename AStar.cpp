//
// Created by viniman on 09/06/19.
//

#include "AStar.h"
using namespace std;

void AStar::ASearchAlgorithm(Maze& maze)
{

    list<Node*> listNode;

    Node *corrente = maze.getOrigin();
    Node *nodeAux = NULL;
    Node const * const destination = maze.getDestination();

    //Atualiza origem
    corrente->setdistanceOrigin(0);
    corrente->setsumHeurDist(corrente->getHeuristicValue());

    Node **aux;

    //Inicializa a lista com a origem
    listNode.push_back(maze.getOrigin());

    //Verifica se existe elemento na lista e se o destino já foi visitado.
    while(removeBest(&listNode, aux) && !(destination->isVisited()))
    {
        corrente = *aux;

        if(corrente == NULL)
        {
            cout<<"NULLL;\n";
            cout<<"Ponteiro Nulo.\n";
            exit(-5);
        }

        corrente->setVisited();

        insereNode(&listNode, corrente, corrente->getTop());
        insereNode(&listNode, corrente, corrente->getLeft());
        insereNode(&listNode, corrente, corrente->getBotton());
        insereNode(&listNode, corrente, corrente->getRight());


    }

    if((maze.getDestination())->isVisited())
        cout<<"SUCESSO ASTAR\n";
    else
        std::cout<<"FRACASSO ASTAR\n";

}

bool AStar::removeBest(list<Node*> *listNode, Node **corrente)
{
    Node *aux;

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

void AStar::insereNode(list<Node*> *listNode, Node *corrente, Node *direcao)
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

        }


    }
}
