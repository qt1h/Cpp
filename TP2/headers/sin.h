#ifndef SIN_H
#define SIN_H
#include "tsgenerator.h"
class SinWaveGenerator : TimeSeriesGenerator
{
public:
    // Constructeur
    SinWaveGenerator(int seed, double amplitude, double frequency, double phase);
    SinWaveGenerator();
    // Implémentation de la méthode generateTimeSeries
    std::vector<double> generateTimeSeries(int size) override;

private:
    double amplitude; // Amplitude (A)
    double frequency; // Fréquence (ω)
    double phase;     // Phase initiale (ϕ)
};
#endif