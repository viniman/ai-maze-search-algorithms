//
// Created by viniman on 22/06/19.
//

#ifndef AI_MAZE_SEARCH_ALGORITHMS_STATISTICS_H
#define AI_MAZE_SEARCH_ALGORITHMS_STATISTICS_H

#include <ctime>

class Statistics
{
private:
    clock_t time;
    unsigned int nosExpandidos = 0;
    unsigned int nosVisitados = 0;
    unsigned int profundidade = 0;
    unsigned int profundidadeSolucao = 0;
    unsigned int custoSolucao = 0;



public:
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

};


#endif //AI_MAZE_SEARCH_ALGORITHMS_STATISTICS_H
