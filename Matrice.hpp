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
    Matrice(int l, int c);  // matrice de taille lxc
    
    // Accesseurs
    double get(int i, int j) const;
    void set(int i, int j, double valeur);
    std::vector<double> getLignes(int i) const;
    std::vector<double> getColonne(int j) const;
    int getLignes() const { return lignes; }
    int getColonnes() const { return colonnes; }

    // Opérations de base
    Matrice operator+(const Matrice& autre) const;
    Matrice operator-(const Matrice& autre) const;
    Matrice operator*(const Matrice& autre) const;
    Matrice operator*(double scalaire) const;
    Matrice transpose() const;
    double trace() const;
    Matrice inverse() const;

    // test
    bool isTriangulaireSup() const;
    bool isTriangulaireInf() const;
    bool isCarre() const;
    bool isDiagonal() const;
    bool isIdentite() const;
    bool isNulle() const;
    bool isInversible() const;

    // Affichage
    friend std::ostream& operator<<(std::ostream& os, const Matrice& m);
    void arrondiZero();
};

#endif