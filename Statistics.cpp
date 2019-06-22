//
// Created by viniman on 22/06/19.
//

#include "Statistics.h"

void Statistics::startTiming()
{
    time = clock();
}

void Statistics::executionTimeMeasure()
{
    time = (clock() - time)/CLOCKS_PER_SEC;
}
