#ifndef MATRICE_H
#define MATRICE_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Matrice {
private:
    std::vector<std::vector<double>> data;
    int lignes;
    int colonnes;

public:
    // Constructeurs
    Matrice(int l, int c);
    
    // Accesseurs
    double get(int i, int j) const;
    void set(int i, int j, double valeur);
    std::vector<double> getLignes(int i) const;// std::vector<double>;
    std::vector<double> getColonne(int j) const;

    // Opérations de base
    Matrice operator+(const Matrice& autre) const;
    Matrice operator-(const Matrice& autre) const;
    Matrice operator*(const Matrice& autre) const;
    Matrice operator*(double scalaire) const;
    Matrice transpose() const;
    double trace() const;

    // test
    bool isDiagonal() const;
    bool isTriangulaireSup() const;
    bool isTriangulaireInf() const;
    bool isCarre() const;

    // Affichage
    friend std::ostream& operator<<(std::ostream& os, const Matrice& m);

};

#endif