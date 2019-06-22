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

public:
    void startTiming();
    void executionTimeMeasure();
};


#endif //AI_MAZE_SEARCH_ALGORITHMS_STATISTICS_H
