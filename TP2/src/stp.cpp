#include "stp.h"
#include <cstdlib> // Pour std::rand et std::srand
#include <ctime>   // Pour std::time

StepGenerator::StepGenerator(int seed) : TimeSeriesGenerator(seed) {
    std::srand(seed); // Initialise la graine pour les nombres aléatoires
}

StepGenerator::StepGenerator() : TimeSeriesGenerator(0)
{
}

std::vector<double> StepGenerator::generateTimeSeries(int size) {
    std::vector<double> serie(size);
    if (size <= 0) {
        return serie; // Retourne une série vide si la taille est <= 0
    }

    // Initialisation : la première valeur est 0
    serie[0] = 0;

    for (int i = 1; i < size; ++i) {
        // Générer une probabilité uniforme entre 0 et 1
        double probability = static_cast<double>(std::rand()) / RAND_MAX;

        if (probability < 0.5) {
            // Nouvelle valeur entre 0 et 100
            serie[i] = generateRandomValue();
        } else {
            // Conserve la valeur précédente
            serie[i] = serie[i - 1];
        }
    }

    return serie;
}

int StepGenerator::generateRandomValue() {
    // Génère une valeur entière entre 0 et 100
    return std::rand() % 101;
}
