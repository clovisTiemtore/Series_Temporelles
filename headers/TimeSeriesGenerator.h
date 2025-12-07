#ifndef TIMESERIESGENERATOR_h
#define TIMESERIESGENERATOR_h

#include <vector>

class TimeSeriesGenerator{
    protected:
        int seed;

    public:
        TimeSeriesGenerator();
        TimeSeriesGenerator(int s);
        virtual ~TimeSeriesGenerator() = default;

        virtual std::vector <double >generateTimeSeries(int serieSize) = 0;
        static void printTimeSeries(const std::vector<double>& series);

        int getSeed() const;
};

#endif
