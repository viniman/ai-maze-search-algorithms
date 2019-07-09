//
// Created by viniman on 09/06/19.
//

#include "Depth.h"

void Depth::DepthSearchAlgorithm(Maze& maze)
{
    cleanMazeForSearch(maze);

    stack<Node*> stackNode;             //Pilha de nós
    stackNode.push(maze.getOrigin());   //Coloca a origem no topo da pilha.
    const Node *const dest = maze.getDestination();

    Node *corrente = NULL;
    Node *neighborhood = NULL;

    // Continua enqunto a origem não for atingida e a pilha for não fazia.
    while((!dest->isVisited()) && (!stackNode.empty()))
    {

        corrente = stackNode.top(); //Atualiza o nó corrente
        stackNode.pop();            //Remove o topo da pilha.

        //Tenta o quarto a esquerda.

        neighborhood = corrente->getLeft();

        if((neighborhood != NULL) &&  (!neighborhood->isVisited()))
        {
            neighborhood->setFather(corrente);
            stackNode.push(neighborhood);
        }

        //Tenta o quarto em baixo.

        neighborhood = corrente->getBotton();

        if((neighborhood != NULL) &&  (!neighborhood->isVisited()))
        {
            neighborhood->setFather(corrente);
            stackNode.push(neighborhood);
        }

        //Tenta o quarto a direita.

        neighborhood = corrente->getRight();

        if((neighborhood != NULL) &&  (!neighborhood->isVisited()))
        {
            neighborhood->setFather(corrente);
            stackNode.push(neighborhood);
        }

        //Tenta o quarto de cima.

        neighborhood = corrente->getTop();

        if((neighborhood != NULL) &&  (!neighborhood->isVisited()))
        {
            neighborhood->setFather(corrente);
            stackNode.push(neighborhood);
        }

        //Visitamos o Nó.
        corrente->setVisited();


    }

    if(dest->isVisited())
        cout<<"SUCESSO DepthSearch\n";

    else
        cout<<"FRACASSO DepthSearch\n";




}
