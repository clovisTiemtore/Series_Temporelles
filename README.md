# 📈 Séries Temporelles - Classification & Génération

Ce projet en C++ propose une boîte d'outils complète pour la manipulation, la génération et la classification de séries temporelles. Il implémente notamment l'algorithme des **k-plus proches voisins (k-NN)** avec plusieurs métriques de distance avancées pour comparer des séquences temporelles.

## Fonctionnalités

### 1. Générateurs de Séries (Synthesize Data)
Le projet permet de générer des données synthétiques pour tester les algorithmes :
* **GaussianGenerator** : Génération de bruit blanc gaussien.
* **SinWaveGenerator** : Séries basées sur des ondes sinusoïdales.
* **StepGenerator** : Séries temporelles en "marches d'escalier" (changements brusques).

### 2. Mesures de Similarité (Distances)
Le cœur du projet repose sur la comparaison de séries via :
* **Distance Euclidienne** : Pour les séries de même longueur et parfaitement alignées.
* **Dynamic Time Warping (DTW)** : Pour comparer des séries avec des décalages temporels ou des vitesses variées.
* **EDR (Edit Distance on Real sequences)** : Robuste aux bruits et aux outliers.

### 3. Classification
* Implémentation de l'algorithme **k-NN (k-Nearest Neighbors)** pour prédire la classe d'une série temporelle inconnue en se basant sur un dataset d'entraînement.

---

## Installation et Compilation

### Prérequis
* Un compilateur C++ (GCC, Clang ou MSVC) supportant le C++11 ou supérieur.

### Compilation
Utilisez la commande suivante dans votre terminal pour compiler l'ensemble du projet :

```bash
g++ main.cpp \
GaussianGenerator.cpp \
SinWaveGenerator.cpp \
StepGenerator.cpp \
TimeSeriesDataset.cpp \
Distance.cpp \
Knn.cpp \
TimeSeriesGenerator.cpp \
-o series_app
