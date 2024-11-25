#include "stp.h"
#include <cstdlib>

// Constructeurs
StepGenerator::StepGenerator(int seed) : TimeSeriesGenerator(seed)
{
    std::srand(seed);
}

StepGenerator::StepGenerator() : TimeSeriesGenerator(0)
{
    std::srand(0); // Graine par défaut
}

// Génération d'une série temporelle
std::vector<double> StepGenerator::generateTimeSeries(int size)
{
    std::vector<double> serie(size);
    if (size <= 0)
        return serie;

    serie[0] = 0; // Première valeur fixée à 0
    for (int i = 1; i < size; ++i)
    {
        double probability = static_cast<double>(std::rand()) / RAND_MAX;
        if (probability < 0.5)
        {
            serie[i] = generateRandomValue();
        }
        else
        {
            serie[i] = serie[i - 1];
        }
    }
    return serie;
}

// Génération d'une valeur entre 0 et 100
int StepGenerator::generateRandomValue()
{
    return std::rand() % 101;
}
