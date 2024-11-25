#ifndef DTW_H
#define DTW_H

#include <vector>
#include <cmath>
#include <limits>
#include <stdexcept>

class DTW
{
public:
    // Calculer la distance DTW entre deux séries temporelles
    static double compute(const std::vector<double> &x, const std::vector<double> &y);
};

#endif
