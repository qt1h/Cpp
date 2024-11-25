#ifndef TSDATA_H
#define TSDATA_H

#include <vector>
#include <cmath>
#include <stdexcept>

class TimeSeriesDataset
{
public:
    // Constructeur
    TimeSeriesDataset(bool znorm = false, bool isTrainMode = true);
    // Accesseurs
    const std::vector<std::vector<double>> &getData() const;
    const std::vector<int> &getLabels() const;

    // Ajouter une série temporelle
    void addTimeSeries(const std::vector<double> &series, int label);
    void addTimeSeries(const std::vector<double> &series); // Surcharge sans label

private:
    bool znormalize;                       // Indique si la normalisation Z est activée
    bool isTrain;                          // Indique si le dataset est en mode entraînement
    std::vector<std::vector<double>> data; // Données des séries temporelles
    std::vector<int> labels;               // Labels associés aux séries
    int maxLength;                         // Longueur maximale des séries
    int numberOfSamples;                   // Nombre de séries dans le dataset

    // Z-normalisation et calculs internes
    std::vector<double> zNormalize(const std::vector<double> &series);
    double calculateMean(const std::vector<double> &series);
    double calculateStdDev(const std::vector<double> &series, double mean);
};

#endif
