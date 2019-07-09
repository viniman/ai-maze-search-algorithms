//
// Created by viniman on 09/06/19.
//

#include "Greedy.h"

void Greedy::greedySearchAlgorithm(Maze& maze)
{
    cleanMazeForSearch(maze);

    //Nó de origem e nós auxiliares
    Node *corrente = maze.getOrigin();
    Node *proximo = NULL;
    Node *menor = NULL;
    float distancia = HUGE_VALF;
    bool fracasso = false;

    //Se corrente é diferente de NULL e corrente e diferente do nó objetivo, continue.
    while((corrente != NULL) && (corrente->getId() != maze.getDestination()->getId()))
    {
        //Marca o nó corrente como visitado, e seta o menor como null e distancia com valor infinito
        corrente->setVisited();
        menor = NULL;
        distancia = HUGE_VALF;

        //Verifia (visitado e se ele é menor) o nó a direita.
        proximo = corrente->getRight();

        if(proximo != NULL)
        {
            if((!proximo->isVisited()) && (proximo->getHeuristicValue() < distancia))
            {
                menor = proximo;
                distancia = menor->getHeuristicValue();
            }
        }

        //Verifia (visitado e se ele é menor) o nó para baixo.
        proximo = corrente->getBotton();

        if(proximo != NULL)
        {
            if((!proximo->isVisited()) && (proximo->getHeuristicValue() < distancia))
            {
                menor = proximo;
                distancia = menor->getHeuristicValue();
            }
        }

        //Verifia (visitado e se ele é menor) o nó a esquerda.
        proximo = corrente->getLeft();

        if(proximo != NULL)
        {
            if((!proximo->isVisited()) && (proximo->getHeuristicValue() < distancia))
            {
                menor = proximo;
                distancia = menor->getHeuristicValue();
            }
        }

        //Verifia (visitado e se ele é menor) o nó em cima.
        proximo = corrente->getTop();

        if(proximo != NULL)
        {
            if((!proximo->isVisited()) && (proximo->getHeuristicValue() < distancia))
            {
                menor = proximo;
                distancia = menor->getHeuristicValue();
            }
        }

        //Verifica se o nó menor foi atualizado
        if(menor != NULL)
        {
            menor->setFather(corrente); //Seta corrente como pai do menor
            corrente = menor;
        }
        else
        {
            if(corrente->getFather() != NULL)  //Verifica se corrente é o nó de origem.
            {
                corrente = corrente->getFather();
            }
            else
            {
                fracasso = true;
                break;
            }
        }



    }

    if(fracasso)
        cout<<"FRACASSO GREEDY SEARCH.\n";

    else
        cout<<"SUCESSO GREEDY SEARCH.\n";
}
