#include "knn.h"
#include "dtw.h"
#include <stdexcept>
#include <algorithm>
#include <map>

KNN::KNN(int k, const std::string &similarity_measure)
    : k(k), similarity_measure(similarity_measure)
{
    if (k <= 0)
    {
        throw std::invalid_argument("Le nombre de voisins k doit être supérieur à 0.");
    }
}

double KNN::euclideanDistance(const std::vector<double> &a, const std::vector<double> &b) const
{
    if (a.size() != b.size())
    {
        throw std::invalid_argument("Les vecteurs doivent avoir la même taille.");
    }
    double sum = 0.0;
    for (size_t i = 0; i < a.size(); ++i)
    {
        sum += std::pow(a[i] - b[i], 2);
    }
    return std::sqrt(sum);
}

double KNN::dtwDistance(const std::vector<double> &a, const std::vector<double> &b) const
{
    return DTW::compute(a, b);
}

double KNN::evaluate(const std::vector<std::vector<double>> &X_train,
                     const std::vector<int> &y_train,
                     const std::vector<std::vector<double>> &X_test,
                     const std::vector<int> &y_test) const
{
    // Générer les prédictions
    std::vector<int> y_pred;
    for (const auto &test_point : X_test)
    {
        // Calculer les distances pour chaque point de test
        std::vector<std::pair<double, int>> distances;
        for (size_t i = 0; i < X_train.size(); ++i)
        {
            double distance = (similarity_measure == "dtw")
                                  ? dtwDistance(test_point, X_train[i])
                                  : euclideanDistance(test_point, X_train[i]);
            distances.emplace_back(distance, y_train[i]);
        }

        // Trier des distances par ordre croissant
        std::sort(distances.begin(), distances.end());

        // Trouver les k plus proches voisins
        std::map<int, int> class_counts;
        for (int i = 0; i < k; ++i)
        {
            class_counts[distances[i].second]++;
        }

        // Déterminer la classe majoritaire parmi les k voisins
        int predicted_class = -1;
        int max_count = 0;
        for (const auto &pair : class_counts)
        {
            if (pair.second > max_count)
            {
                max_count = pair.second;
                predicted_class = pair.first;
            }
        }
        y_pred.push_back(predicted_class);
    }

    // Accuracy
    if (y_test.size() != y_pred.size())
    {
        throw std::invalid_argument("y_test et y_pred doivent avoir la même taille.");
    }

    int correct = 0;
    for (size_t i = 0; i < y_test.size(); ++i)
    {
        if (y_test[i] == y_pred[i])
        {
            ++correct;
        }
    }
    return static_cast<double>(correct) / y_test.size();
}

double KNN::evaluate(const TimeSeriesDataset &trainData,
                     const TimeSeriesDataset &testData,
                     const std::vector<int> &ground_truth) const
{
    // Récupère les données et labels de TimeSeriesDataset
    const auto &X_train = trainData.getData();
    const auto &y_train = trainData.getLabels();
    const auto &X_test = testData.getData();

    // Appeler la méthode evaluate avec les données brutes
    return evaluate(X_train, y_train, X_test, ground_truth);
}
