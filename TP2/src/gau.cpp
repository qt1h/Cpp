#include "gau.h"
#include <cmath>
#include <cstdlib>

// Constructeur par défaut
GaussianGenerator::GaussianGenerator()
    : TimeSeriesGenerator(1), mean(0), stdDev(1)
{
    std::srand(1); // Graine par défaut
}

// Constructeur paramétré
GaussianGenerator::GaussianGenerator(int seed, double mean, double stdDev)
    : TimeSeriesGenerator(seed), mean(mean), stdDev(stdDev)
{
    std::srand(seed);
}

// Génération d'une série temporelle
std::vector<double> GaussianGenerator::generateTimeSeries(int size)
{
    std::vector<double> serie(size);
    for (int i = 0; i < size; ++i)
    {
        serie[i] = generateGaussian();
    }
    return serie;
}

// Méthode de Box-Muller pour générer des valeurs gaussiennes
double GaussianGenerator::generateGaussian()
{
    double u1 = static_cast<double>(std::rand()) / RAND_MAX;
    double u2 = static_cast<double>(std::rand()) / RAND_MAX;
    double z0 = std::sqrt(-2.0 * std::log(u1)) * std::cos(2.0 * M_PI * u2);
    return mean + z0 * stdDev;
}
