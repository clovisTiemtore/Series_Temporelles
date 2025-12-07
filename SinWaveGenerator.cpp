#include "headers/SinWaveGenerator.h"
#include <cmath>
#include <vector>

using namespace std;

SinWaveGenerator::SinWaveGenerator()
    : TimeSeriesGenerator(0), amplitude(1.0), frequence(1.0), phase(0.0) {}

SinWaveGenerator::SinWaveGenerator(int s, double A, double w, double phi)
    : TimeSeriesGenerator(s), amplitude(A), frequence(w), phase(phi) {}

vector<double> SinWaveGenerator::generateTimeSeries(int sizeSerie)
{
    vector<double> serie;
    serie.reserve(sizeSerie);

    for (int i = 0; i < sizeSerie; ++i) {
        double value = amplitude * sin(frequence * i + phase);
        serie.push_back(value);
    }

    return serie;
}
