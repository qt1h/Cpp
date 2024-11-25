#ifndef KNN_H
#define KNN_H

#include <vector>
#include <string>
#include "tsdata.h"

class KNN
{
private:
    int k;                          // Nombre de voisins
    std::string similarity_measure; // Méthode de similarité ("euclidean_distance" ou "dtw")

    // Calculer la distance Euclidienne entre deux vecteurs
    double euclideanDistance(const std::vector<double> &a, const std::vector<double> &b) const;

    // Calculer la distance DTW entre deux vecteurs
    double dtwDistance(const std::vector<double> &a, const std::vector<double> &b) const;

public:
    // Constructeur
    KNN(int k, const std::string &similarity_measure);

    // Évaluer en utilisant des vecteurs de données
    double evaluate(const std::vector<std::vector<double>> &X_train,
                    const std::vector<int> &y_train,
                    const std::vector<std::vector<double>> &X_test,
                    const std::vector<int> &y_test) const;

    // Nouvelle surcharge pour évaluer en utilisant TimeSeriesDataset
    double evaluate(const TimeSeriesDataset &trainData,
                    const TimeSeriesDataset &testData,
                    const std::vector<int> &ground_truth) const;
};

#endif
