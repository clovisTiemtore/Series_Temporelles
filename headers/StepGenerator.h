#ifndef STEP_GENERATOR_H
#define STEP_GENERATOR_H

#include "TimeSeriesGenerator.h"
#include <vector>

class StepGenerator : public TimeSeriesGenerator {
public:
    StepGenerator();
    StepGenerator(int s);
    ~StepGenerator() override = default;

    std::vector<double> generateTimeSeries(int sizeSerie) override;
};

#endif
