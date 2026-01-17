Series Temporelles is a C++ project for time series generation and classification using various similarity measures (Euclidean, DTW, EDR) and k-Nearest Neighbors (k-NN).

Features

Generate synthetic time series: Gaussian, Sinusoidal, Step

Compute similarity with Euclidean, DTW, and EDR

Classify time series with k-NN

Configurable parameters for series type, distance metric, and k

Technologies

C++

Command-line execution

Project Structure

main.cpp – program entry point

GaussianGenerator.cpp – Gaussian series generator

SinWaveGenerator.cpp – Sinusoidal series generator

StepGenerator.cpp – Step function generator

TimeSeriesDataSet.cpp – dataset management

TimeSeriesGenerator.cpp – helper functions

Distance.cpp – similarity measures

KNN.cpp – k-NN classifier

Capture.png – sample output

Compilation & Execution
g++ main.cpp GaussianGenerator.cpp SinWaveGenerator.cpp StepGenerator.cpp TimeSeriesDataSet.cpp Distance.cpp KNN.cpp TimeSeriesGenerator.cpp -o test
./test      # Linux
.\test.exe  # Windows
