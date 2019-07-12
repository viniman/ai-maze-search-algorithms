//
// Created by viniman on 22/06/19.
//

#include <iostream>
#include "Statistics.h"

using namespace std;

void Statistics::setAlgorithmName(const string &algorithmName)
{
    Statistics::algorithmName = algorithmName;
}

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

void Statistics::printStatistics()
{
    cout << endl << "--------------------------------------------------------------------" << endl;
    cout << "Nome do Algoritmo: " << algorithmName << endl;
    cout << "Tempo de execução: " << fixed << executionTime << endl;
    cout << "Estado da solução: " << (succed ? "Sucesso" : "Fracasso") << endl;
    cout << "Custo da solução: " << endl;
    cout << "Numero de nós do labirinto: " << numNodes << endl;
    cout << "Nós visitados: " << endl;
    cout << "Nós expandidos: " << endl;
    cout << "Profundidade Solucao: " << endl;
    cout << "Fator de ramificação médio: " << endl;
    cout << "Caminho da Solução: ";
    for(const auto& it : pathSolution)
        cout << it << " ";
    cout << endl << "--------------------------------------------------------------------" << endl;

}

void Statistics::setSucced(bool succed)
{
    Statistics::succed = succed;
}

Statistics::Statistics(unsigned int numNodes) : numNodes(numNodes) {}


void Statistics::setNodeSolution(unsigned int id)
{
    pathSolution.push_front(id);
}
