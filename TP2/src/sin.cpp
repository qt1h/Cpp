#include "sin.h"
#include <cmath>

// Constructeurs
SinWaveGenerator::SinWaveGenerator(int seed, double amplitude, double frequency, double phase)
    : TimeSeriesGenerator(seed), amplitude(amplitude), frequency(frequency), phase(phase) {}

SinWaveGenerator::SinWaveGenerator()
    : TimeSeriesGenerator(0), amplitude(1.0), frequency(1.0), phase(0.0) {}

// Génération d'une série temporelle basée sur une sinusoïde
std::vector<double> SinWaveGenerator::generateTimeSeries(int size)
{
    std::vector<double> serie(size);
    for (int i = 0; i < size; ++i)
    {
        double x = static_cast<double>(i);
        serie[i] = amplitude * std::sin(frequency * x + phase);
    }
    return serie;
}
