#ifndef GAU_H
#define GAU_H

#include "tsgenerator.h"
#include <vector>

class GaussianGenerator : public TimeSeriesGenerator
{
public:
    // Constructeurs
    GaussianGenerator();
    GaussianGenerator(int seed, double mean, double stdDev);

    // Implémentation de la méthode virtuelle pure
    std::vector<double> generateTimeSeries(int size) override;

private:
    double mean;   // Moyenne (μ)
    double stdDev; // Écart type (σ)

    // Méthode pour générer une valeur gaussienne avec Box-Muller
    double generateGaussian();
};

#endif
