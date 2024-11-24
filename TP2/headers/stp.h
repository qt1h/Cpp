#ifndef STP_H
#define STP_H
#include "tsgenerator.h"
class StepGenerator : TimeSeriesGenerator
{
private:
    int generateRandomValue();
public:
    StepGenerator(int seed);
    StepGenerator();
    //~StepGenerator();
    std::vector<double> generateTimeSeries(int size) override;
};
#endif