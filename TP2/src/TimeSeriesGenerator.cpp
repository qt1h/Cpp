#include "tsgenerator.h" 
#include <iostream>
TimeSeriesGenerator::TimeSeriesGenerator(int s): seed(s)
{
}

std::vector<double> TimeSeriesGenerator::generateTimeSeries(int size)
{
    return std::vector<double>();
}

void TimeSeriesGenerator::printTimeSeries(const std::vector<double>& serie){
    for (const auto& e : serie) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}
