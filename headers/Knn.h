#ifndef KNN_H
#define KNN_H

#include <vector>
#include <string>
#include "TimeSeriesDataset.h"

class KNN {
private:
    int k;
    std::string similarity_measure;
    std::vector<std::vector<double>> trainData;
    std::vector<int> trainLabels;

public:
    KNN(int k_value, const std::string& measure);

    void fit(const std::vector<std::vector<double>>& data, const std::vector<int>& labels);
    int predict(const std::vector<double>& serie);

    // version adaptée à ton main.cpp
    double evaluate(const TimeSeriesDataset& train,
                    const TimeSeriesDataset& test,
                    const std::vector<int>& ground_truth);
};

#endif
