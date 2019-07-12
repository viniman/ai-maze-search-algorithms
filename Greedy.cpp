//
// Created by viniman on 09/06/19.
//

#include "Greedy.h"

void Greedy::greedySearchAlgorithm(Maze& maze)
{


    cleanMazeForSearch(maze);
    list<Node*> listNode;

    Node *corrente = maze.getOrigin();
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

        insereNode(&listNode, corrente, corrente->getTop());
        insereNode(&listNode, corrente, corrente->getLeft());
        insereNode(&listNode, corrente, corrente->getBotton());
        insereNode(&listNode, corrente, corrente->getRight());

    }

    if((maze.getDestination())->isVisited())
        cout<<"SUCESSO GREEDY\n";
    else
        std::cout<<"FRACASSO GREEDY\n";

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

void Greedy::insereNode(list<Node*> *listNode, Node *corrente, Node *direcao)
{
    if(direcao == NULL)
        return;

    //Se direcao já foi visitado, retorna
    if(direcao->isVisited())
        return;

    //Verifica se já foi inserido na lista
    if(!direcao->getAdicionadoNodeLista())
    {


        listNode->push_back(direcao); //Insere direcao na lista
        direcao->adicionarNodeLista();

    }


}
