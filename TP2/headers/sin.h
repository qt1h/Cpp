#ifndef SIN_H
#define SIN_H

#include "tsgenerator.h"
#include <vector>

class SinWaveGenerator : public TimeSeriesGenerator
{
public:
    // Constructeurs
    SinWaveGenerator();
    SinWaveGenerator(int seed, double amplitude, double frequency, double phase);

    // Implémentation de la méthode virtuelle pure
    std::vector<double> generateTimeSeries(int size) override;

private:
    double amplitude; // Amplitude (A)
    double frequency; // Fréquence (ω)
    double phase;     // Phase initiale (ϕ)
};

#endif
