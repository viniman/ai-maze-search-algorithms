//
// Created by viniman on 22/06/19.
//

#include "Statistics.h"

void Statistics::startTiming()
{
    timeInit = clock();
}

void Statistics::executionTimeMeasure()
{
    executionTime = (clock() - timeInit)/(double)CLOCKS_PER_SEC;
}

void Statistics::expandirNo()
{
    nosExpandidos += 1;
}

unsigned int Statistics::getNosExpandidos()
{
    return nosExpandidos;
}

void Statistics::visitarNo()
{
    nosVisitados += 1;
}

unsigned int Statistics::getNosVisitados()
{
    return nosVisitados;
}

void Statistics::setProfundidade(unsigned int profundidade)
{
    if(profundidade > this->profundidade)
        this->profundidade = profundidade;
}

unsigned int Statistics::getProfundidade()
{

    return profundidade;

}

void Statistics::setProfundidadeSolucao(unsigned int profundidadeSolucao)
{
    this->profundidadeSolucao = profundidadeSolucao;
    custoSolucao = profundidadeSolucao;
}

unsigned int Statistics::getProfundidadeSolucao()
{
    return profundidadeSolucao;
}

unsigned int Statistics::getCustoSolucao()
{
    return custoSolucao;
}
