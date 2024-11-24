#ifndef TSGENERATOR_H
#define TSGENERATOR_H
#include <vector>

class TimeSeriesGenerator{
    public : 
        TimeSeriesGenerator()=default;
        TimeSeriesGenerator(int);
        virtual ~TimeSeriesGenerator()=default;

        virtual std::vector<double> generateTimeSeries(int)=0;

        static void printTimeSeries(const std::vector<double>&);
    private : 
        int seed=0;
};

#endif