#ifndef TIME_SERIES_DATASET_H
#define TIME_SERIES_DATASET_H

#include <vector>

class TimeSeriesDataset {
private:
    bool znormalize;
    bool isTrain;
    std::vector<std::vector<double>> data;
    std::vector<int> labels;
    int maxLength;
    int numberOfSamples;

    std::vector<double> normalize(const std::vector<double>& serie);

public:
    TimeSeriesDataset(bool znorm, bool train);
    void addTimeSeries(const std::vector<double>& serie, int label);

    const std::vector<std::vector<double>>& getData() const;
    const std::vector<int>& getLabels() const;
    int getMaxLength() const;
    int getNumberOfSamples() const;
};

#endif
