#include "tsgenerator.h"
#include <iostream>

// Constructeur paramétré
TimeSeriesGenerator::TimeSeriesGenerator(int s) : seed(s) {}

// Méthode statique pour imprimer une série temporelle
void TimeSeriesGenerator::printTimeSeries(const std::vector<double> &serie)
{
    for (const auto &e : serie)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}