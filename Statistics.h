//
// Created by viniman on 22/06/19.
//

#ifndef AI_MAZE_SEARCH_ALGORITHMS_STATISTICS_H
#define AI_MAZE_SEARCH_ALGORITHMS_STATISTICS_H

#include <ctime>
#include <iostream>
#include <list>

/**
 * Caminho, profundidade e custo da solução
 * Número total de nós expandidos e visitados
 * Valor médio do fator de ramificação da árvore de busca
 * Tempo de execução
 */
class Statistics
{
private:
    clock_t timeInit;
    double executionTime;
    //int* pathSolution;
    std::list<unsigned int> pathSolution;
    unsigned int averageRamificationTreeSearch;
    unsigned int nosExpandidos = 0;
    unsigned int nosVisitados = 0;
    unsigned int profundidade = 0;
    unsigned int profundidadeSolucao = 0;
    unsigned int numNodes;
    unsigned int custoSolucao = 0;
    std::string algorithmName;
    bool succed;




public:
    Statistics(unsigned int numNodes);

    void startTiming();
    void executionTimeMeasure();
    void expandirNo();
    unsigned int getNosExpandidos();
    void visitarNo();
    unsigned int getNosVisitados();
    void setProfundidade(unsigned int profundidade);
    unsigned int getProfundidade();
    void setProfundidadeSolucao(unsigned int profundidadeSolucao);
    unsigned int getProfundidadeSolucao();
    unsigned int getCustoSolucao();
    void printStatistics();
    void setNodeSolution(unsigned int id);
    void setAlgorithmName(const std::string &algorithmName);
    void setSucced(bool succed);

};


#endif //AI_MAZE_SEARCH_ALGORITHMS_STATISTICS_H
