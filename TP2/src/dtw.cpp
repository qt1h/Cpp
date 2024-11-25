#include "dtw.h"

double DTW::compute(const std::vector<double> &x, const std::vector<double> &y)
{
    if (x.empty() || y.empty())
    {
        throw std::invalid_argument("Les séries temporelles ne peuvent pas être vides.");
    }

    size_t lenX = x.size();
    size_t lenY = y.size();

    // Matrice réduite pour économiser de la mémoire (plus opti)
    std::vector<double> prev(lenY + 1, std::numeric_limits<double>::infinity());
    std::vector<double> curr(lenY + 1, std::numeric_limits<double>::infinity());

    prev[0] = 0; // point de départ

    for (size_t i = 1; i <= lenX; ++i)
    {
        curr[0] = std::numeric_limits<double>::infinity();
        for (size_t j = 1; j <= lenY; ++j)
        {
            double cost = std::pow(x[i - 1] - y[j - 1], 2);
            curr[j] = cost + std::min(std::min(prev[j], curr[j - 1]), prev[j - 1]);
        }
        prev.swap(curr); // ligne suivante
    }

    return std::sqrt(prev[lenY]);
}
