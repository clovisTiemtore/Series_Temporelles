#ifndef DISTANCE_H
#define DISTANCE_H

#include <vector>

double euclidean_distance(const std::vector<double>& x, const std::vector<double>& y);
double dtw(const std::vector<double>& x, const std::vector<double>& y);
double edr(const std::vector<double>& x, const std::vector<double>& y, double epsilon);

#endif
