#ifndef GAUSSIAN_GENERATOR_H
#define GAUSSIAN_GENERATOR_H

#include "TimeSeriesGenerator.h"
#include <vector>

class GaussianGenerator : public TimeSeriesGenerator {
    protected:
        double moyenne, ecartType;

    private:
        double boxMuller();

    public:
        GaussianGenerator();
        GaussianGenerator(int s, double m, double eT);
        ~GaussianGenerator() override = default;

        std::vector<double> generateTimeSeries(int sizeSerie) override;

        int getSeed();
};

#endif
