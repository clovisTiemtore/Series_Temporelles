#include "headers/Distance.h"
#include <cmath>
#include <limits>
#include <algorithm>

double euclidean_distance(const std::vector<double>& x, const std::vector<double>& y) {
    double sum = 0.0;
    int n = std::min(x.size(), y.size());
    for (int i = 0; i < n; i++) {
        double diff = x[i] - y[i];
        sum += diff * diff;
    }
    return std::sqrt(sum);
}

double dtw(const std::vector<double>& x, const std::vector<double>& y) {
    int n = x.size();
    int m = y.size();

    std::vector<std::vector<double>> dp(n+1, std::vector<double>(m+1, std::numeric_limits<double>::infinity()));
    dp[0][0] = 0.0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            double cost = (x[i-1] - y[j-1]) * (x[i-1] - y[j-1]);
            dp[i][j] = cost + std::min({ dp[i-1][j], dp[i][j-1], dp[i-1][j-1] });
        }
    }

    return std::sqrt(dp[n][m]);
}

double edr(const std::vector<double>& x, const std::vector<double>& y, double epsilon) {
    int n = x.size();
    int m = y.size();

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));

    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int j = 0; j <= m; j++) dp[0][j] = j;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            bool match = std::fabs(x[i - 1] - y[j - 1]) <= epsilon;
            if (match)
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + std::min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] });
        }
    }

    return dp[n][m];
}
