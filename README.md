# Séries Temporelles : Génération et Classification

Ce projet en C++ est dédié au traitement de séries temporelles, incluant la génération de signaux synthétiques et la classification par l'algorithme k-NN.

---

## Fonctionnalités principales

* **Générateurs de données** : Création de signaux Gaussiens, Sinusoïdaux et Step.
* **Mesures de similarité** : 
    * Distance Euclidienne.
    * Dynamic Time Warping (DTW).
    * Edit Distance on Real sequences (EDR).
* **Classification** : Algorithme k-Nearest Neighbors (k-NN) adapté aux séquences temporelles.

---

## Installation et Compilation

**Compilation :**
Utilisez la commande suivante pour compiler tous les fichiers source :
```bash
g++ *.cpp -o series_app
```

Exécution :

Windows :
```
Bash
.\series_app.exe
```

Linux / macOS :
```
Bash
./series_app
```
