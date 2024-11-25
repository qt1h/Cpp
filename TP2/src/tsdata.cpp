#include "tsdata.h"

// Constructeur
TimeSeriesDataset::TimeSeriesDataset(bool znorm, bool isTrainMode)
    : znormalize(znorm), isTrain(isTrainMode), maxLength(0), numberOfSamples(0) {}

// Ajouter une série temporelle avec un label
void TimeSeriesDataset::addTimeSeries(const std::vector<double> &series, int label)
{
    if (series.empty())
    {
        throw std::invalid_argument("La série temporelle ne peut pas être vide.");
    }

    std::vector<double> processedSeries = series;

    if (znormalize)
    {
        processedSeries = zNormalize(processedSeries);
    }

    data.push_back(processedSeries);
    labels.push_back(label);

    maxLength = std::max(maxLength, static_cast<int>(processedSeries.size()));
    numberOfSamples = data.size();
}

// Ajouter une série temporelle sans label
void TimeSeriesDataset::addTimeSeries(const std::vector<double> &series)
{
    addTimeSeries(series, -1); // Appel à la version avec label (-1 comme valeur par défaut)
}

// Z-normalisation d'une série temporelle
std::vector<double> TimeSeriesDataset::zNormalize(const std::vector<double> &series)
{
    double mean = calculateMean(series);
    double stddev = calculateStdDev(series, mean);

    if (stddev == 0)
    {
        throw std::runtime_error("Écart type nul lors de la normalisation Z.");
    }

    std::vector<double> normalizedSeries(series.size());
    for (size_t i = 0; i < series.size(); ++i)
    {
        normalizedSeries[i] = (series[i] - mean) / stddev;
    }
    return normalizedSeries;
}

// Calcul de la moyenne d'une série
double TimeSeriesDataset::calculateMean(const std::vector<double> &series)
{
    double sum = 0.0;
    for (double val : series)
    {
        sum += val;
    }
    return sum / series.size();
}

// Calcul de l'écart type d'une série
double TimeSeriesDataset::calculateStdDev(const std::vector<double> &series, double mean)
{
    double sum = 0.0;
    for (double val : series)
    {
        sum += (val - mean) * (val - mean);
    }
    return std::sqrt(sum / series.size());
}

const std::vector<std::vector<double>> &TimeSeriesDataset::getData() const
{
    return data;
}

const std::vector<int> &TimeSeriesDataset::getLabels() const
{
    return labels;
}
