#include "headers/StepGenerator.h"
#include <cstdlib>

using namespace std;

StepGenerator::StepGenerator()
    : TimeSeriesGenerator(42) {}

StepGenerator::StepGenerator(int s)
    : TimeSeriesGenerator(s) {}

vector<double> StepGenerator::generateTimeSeries(int sizeSerie)
{
    vector<double> serie;
    serie.reserve(sizeSerie);

    srand(seed);

    double currentValue = 0.0;
    serie.push_back(currentValue);

    for (int i = 1; i < sizeSerie; ++i) {
        double u = static_cast<double>(rand()) / (RAND_MAX + 1.0);
        if (u < 0.5) {
        } else {
            currentValue = rand() % 101;
        }
        serie.push_back(currentValue);
    }
    return serie;
}
