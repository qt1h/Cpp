#ifndef GAU_H
#define GAU_H
#include "tsgenerator.h"
class GaussianGenerator : public TimeSeriesGenerator
{
private:
    double mean;    // Moyenne (μ)
    double stdDev;  // Écart type (σ)


    // Méthode pour générer une valeur gaussienne avec Box-Muller
    double generateGaussian();
public:
    GaussianGenerator();
    GaussianGenerator(int seed, double mean, double stdDev);
    //~gaussiangenerator();
    std::vector<double> generateTimeSeries(int size) override;

};



#endif