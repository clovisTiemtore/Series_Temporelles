#include "headers/GaussianGenerator.h"

#include <cmath>
#include <vector>
#include <cstdlib>

using namespace std;

GaussianGenerator::GaussianGenerator() 
    : TimeSeriesGenerator(20), moyenne(0.0), ecartType(1.0) {}

GaussianGenerator::GaussianGenerator(int s, double m, double eT)
    : TimeSeriesGenerator(s), moyenne(m), ecartType(eT) {}

double GaussianGenerator::boxMuller()
{    
    double u1 = static_cast<double>(rand()) / (RAND_MAX + 1.0);
    double u2 = static_cast<double>(rand()) / (RAND_MAX + 1.0);

    double Z = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
    return Z;
}

vector<double> GaussianGenerator::generateTimeSeries(int sizeSerie)
{
    vector<double> vect;
    vect.reserve(sizeSerie);

    srand(seed);

    for (int i = 0; i < sizeSerie; ++i) {
        vect.push_back(moyenne + ecartType * boxMuller());
    }
    return vect;
}

int GaussianGenerator::getSeed() {
    return seed;
}
