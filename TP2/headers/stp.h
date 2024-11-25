#ifndef STP_H
#define STP_H

#include "tsgenerator.h"
#include <vector>

class StepGenerator : public TimeSeriesGenerator
{
public:
    // Constructeurs
    StepGenerator();
    StepGenerator(int seed);

    // Implémentation de la méthode virtuelle pure
    std::vector<double> generateTimeSeries(int size) override;

private:
    // Génération d'une valeur entière entre 0 et 100
    int generateRandomValue();
};

#endif
