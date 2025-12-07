#include "headers/TimeSeriesDataset.h"
#include <cmath>

TimeSeriesDataset::TimeSeriesDataset(bool znorm, bool train)
    : znormalize(znorm), isTrain(train), maxLength(0), numberOfSamples(0) {}

std::vector<double> TimeSeriesDataset::normalize(const std::vector<double>& serie) {
    double sum = 0.0;
    for (double x : serie) sum += x;
    double mean = sum / serie.size();

    double sqSum = 0.0;
    for (double x : serie) sqSum += (x - mean) * (x - mean);
    double stddev = std::sqrt(sqSum / serie.size());

    std::vector<double> result;
    result.reserve(serie.size());
    for (double x : serie) result.push_back((x - mean) / stddev);
    return result;
}

void TimeSeriesDataset::addTimeSeries(const std::vector<double>& serie, int label) {
    std::vector<double> processed = znormalize ? normalize(serie) : serie;
    data.push_back(processed);
    labels.push_back(label);
    numberOfSamples++;
    if (processed.size() > maxLength) maxLength = processed.size();
}

const std::vector<std::vector<double>>& TimeSeriesDataset::getData() const {
    return data;
}

const std::vector<int>& TimeSeriesDataset::getLabels() const {
    return labels;
}

int TimeSeriesDataset::getMaxLength() const {
    return maxLength;
}

int TimeSeriesDataset::getNumberOfSamples() const {
    return numberOfSamples;
}
