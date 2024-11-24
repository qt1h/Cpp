#include "sin.h"
#include <cmath> // Pour std::sin

SinWaveGenerator::SinWaveGenerator(int seed, double amplitude, double frequency, double phase)
    : TimeSeriesGenerator(seed), amplitude(amplitude), frequency(frequency), phase(phase) {
    // Rien de particulier à initialiser pour la sinusoïde
}

SinWaveGenerator::SinWaveGenerator() : TimeSeriesGenerator(0), amplitude(1), frequency(20), phase(30)
{
}

std::vector<double> SinWaveGenerator::generateTimeSeries(int size) {
    std::vector<double> serie(size);
    for (int i = 0; i < size; ++i) {
        double x = static_cast<double>(i); // On utilise l'indice comme variable x
        serie[i] = amplitude * std::sin(frequency * x + phase);
    }
    return serie;
}
