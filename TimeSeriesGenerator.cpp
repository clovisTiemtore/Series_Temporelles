#include "headers/TimeSeriesGenerator.h"
#include <iostream>

using namespace std;

TimeSeriesGenerator::TimeSeriesGenerator() : seed(0) {};

TimeSeriesGenerator::TimeSeriesGenerator(int s) : seed(s) {};

void TimeSeriesGenerator::printTimeSeries(const vector<double>& series) {
    for (int i = 0; i < series.size(); i++) {
        cout << series[i] << " ";
    }
    cout << endl;
}


int TimeSeriesGenerator::getSeed() const{
    return seed;
}
