#include "headers/KNN.h"
#include "headers/Distance.h"
#include <cmath>
#include <algorithm>

KNN::KNN(int k_value, const std::string& measure)
    : k(k_value), similarity_measure(measure) {}

void KNN::fit(const std::vector<std::vector<double>>& data, const std::vector<int>& labels) {
    trainData = data;
    trainLabels = labels;
}

int KNN::predict(const std::vector<double>& serie) {
    std::vector<std::pair<double, int>> distances;

    for (size_t i = 0; i < trainData.size(); ++i) {
        double d = 0.0;
        if (similarity_measure == "euclidean")
            d = euclidean_distance(serie, trainData[i]);
        else if (similarity_measure == "dtw")
            d = dtw(serie, trainData[i]);
        else
            d = std::numeric_limits<double>::infinity();

        distances.push_back({ d, trainLabels[i] });
    }

    std::sort(distances.begin(), distances.end());

    std::vector<int> votes;
    for (int i = 0; i < k; ++i)
        votes.push_back(distances[i].second);

    std::sort(votes.begin(), votes.end());
    int majority = votes[0];
    int count = 1, maxCount = 1;

    for (size_t i = 1; i < votes.size(); ++i) {
        if (votes[i] == votes[i - 1])
            count++;
        else
            count = 1;

        if (count > maxCount) {
            maxCount = count;
            majority = votes[i];
        }
    }

    return majority;
}

double KNN::evaluate(const TimeSeriesDataset& train, const TimeSeriesDataset& test, const std::vector<int>& ground_truth) {
    int correct = 0;
    for (size_t i = 0; i < test.getData().size(); ++i) {
        fit(train.getData(), train.getLabels());
        int pred = predict(test.getData()[i]);
        if (pred == ground_truth[i]) correct++;
    }
    return static_cast<double>(correct) / ground_truth.size();
}

