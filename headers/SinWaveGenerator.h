#ifndef SIN_WAVE_GENERATOR_H
#define SIN_WAVE_GENERATOR_H

#include "TimeSeriesGenerator.h"
#include <vector>

class SinWaveGenerator : public TimeSeriesGenerator {
protected:
    double amplitude;
    double frequence;
    double phase;

public:
    SinWaveGenerator();
    SinWaveGenerator(int s, double A, double w, double phi);
    ~SinWaveGenerator() override = default;

    std::vector<double> generateTimeSeries(int sizeSerie) override;
};

#endif
