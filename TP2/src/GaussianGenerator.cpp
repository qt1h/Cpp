#include "gau.h"
#include <cmath>    // Pour std::log, std::sqrt, std::cos, M_PI
#include <cstdlib>  // Pour std::rand, std::srand

GaussianGenerator::GaussianGenerator()
    : TimeSeriesGenerator(1), mean(mean), stdDev(stdDev) {
     // Initialise la graine pour les nombres aléatoires
}

GaussianGenerator::GaussianGenerator(int seed, double mean, double stdDev)
    : TimeSeriesGenerator(seed), mean(mean), stdDev(stdDev) {
    std::srand(seed); // Initialise la graine pour les nombres aléatoires
}

std::vector<double> GaussianGenerator::generateTimeSeries(int size) {
    std::vector<double> serie(size);
    for (int i = 0; i < size; ++i) {
        serie[i] = generateGaussian();
    }
    return serie;
}

double GaussianGenerator::generateGaussian() {
    // Méthode de Box-Muller
    double u1 = static_cast<double>(std::rand()) / RAND_MAX; // Uniforme entre 0 et 1
    double u2 = static_cast<double>(std::rand()) / RAND_MAX;

    // Transformation de Box-Muller
    double z0 = std::sqrt(-2.0 * std::log(u1)) * std::cos(2.0 * M_PI * u2);

    // Conversion en gaussienne avec moyenne (mean) et écart type (stdDev)
    return mean + z0 * stdDev;
}
