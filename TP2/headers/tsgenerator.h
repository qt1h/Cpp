#ifndef TSGENERATOR_H
#define TSGENERATOR_H

#include <vector>

class TimeSeriesGenerator
{
public:
    TimeSeriesGenerator() = default;
    explicit TimeSeriesGenerator(int);
    virtual ~TimeSeriesGenerator() = default;

    // Méthode virtuelle pure
    virtual std::vector<double> generateTimeSeries(int) = 0;

    // Méthode statique pour imprimer une série temporelle
    static void printTimeSeries(const std::vector<double> &);

private:
    int seed = 0; // Graine pour la génération de séries
};

#endif
