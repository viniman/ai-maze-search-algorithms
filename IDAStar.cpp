//
// Created by viniman on 09/06/19.
//

#include "IDAStar.h"

void IDAStar::IDAStarSearchAlgorithm(Maze &maze, Statistics &statistics)
{

    float oldPatamar = HUGE_VALF;
    float patamar = (maze.getOrigin())->getHeuristicValue();

    Node *corrente = maze.getOrigin();
    corrente->setdistanceOrigin(0);

    Node *destination = maze.getDestination();

    //Verifica se existe elemento na lista e se o destino já foi visitado.
    while(!(destination->isVisited()))
    {

        corrente->setVisited();
        statistics.visitarNo();

        //Verifica cada direção de corrente

        if(verificaPatamar(corrente, corrente->getTop(), patamar, &oldPatamar, statistics))
        {

            (corrente->getTop())->setFather(corrente);

            corrente = corrente->getTop();

        }
        else if(verificaPatamar(corrente, corrente->getLeft(), patamar, &oldPatamar, statistics))
        {
            (corrente->getLeft())->setFather(corrente);
            corrente = corrente->getLeft();

        }
        else if(verificaPatamar(corrente, corrente->getBotton(), patamar, &oldPatamar, statistics))
        {
            (corrente->getBotton())->setFather(corrente);
            corrente = corrente->getBotton();

        }
        else if(verificaPatamar(corrente, corrente->getRight(), patamar, &oldPatamar, statistics))
        {
            (corrente->getRight())->setFather(corrente);
            corrente = corrente->getRight();

        }
        else
        {
            //Verifica se corrente é igual a origem
            if(corrente == maze.getOrigin())
            {

                if(oldPatamar == HUGE_VALF)
                {
                    break;
                }
                else
                {

                    patamar = oldPatamar;
                    oldPatamar = HUGE_VALF;

                    corrigeNos(maze);
                }

            }
            else
                corrente = corrente->getFather();

        }


    }

    if((maze.getDestination())->isVisited())
    {
        cout << "SUCESSO IDASTAR\n";
        statistics.setProfundidadeSolucao((maze.getDestination())->getdistanceOrigin());
    }
    else
        std::cout<<"FRACASSO IDASTAR\n";
}

bool IDAStar::verificaPatamar(Node *corrente, Node *direcao, const float patamar, float *oldpatamar, Statistics &statistics)
{
    if(!direcao)
        return false;

    if(direcao->isVisited())
        return false;

    float distHeur = (corrente->getdistanceOrigin() + 1 + direcao->getHeuristicValue());

    //Verifica se a distancia é menor do que o patamar
    if(distHeur <= patamar)
    {
        direcao->setdistanceOrigin(corrente->getdistanceOrigin() + 1);

        statistics.setProfundidade(corrente->getdistanceOrigin() + 1);
        statistics.expandirNo();

        return true;
    }
    else
    {
        //Verifica se a distancia é menor que oldpatamar
        if(distHeur < *oldpatamar)
        {
            *oldpatamar = distHeur;
        }

        return false;
    }

}

void IDAStar::corrigeNos(Maze& maze)
{
    auto vetRooms = maze.getRooms();

    for(auto it = vetRooms.begin(); it != vetRooms.end(); ++it)
    {
        //Corrige parametros

        (*it)->setFather(NULL);
        (*it)->setdistanceOrigin(0);
        (*it)->setNonVisited();
    }
}

