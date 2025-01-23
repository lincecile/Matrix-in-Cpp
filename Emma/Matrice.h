#ifndef MATRICE_H
#define MATRICE_H

#include <iostream>
#include <vector>
#include <stdexcept>

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
    int getLignes() const { return lignes; }
    int getColonnes() const { return colonnes; }

    // Opérations de base
    Matrice operator+(const Matrice& autre) const;
    Matrice operator-(const Matrice& autre) const;
    Matrice operator*(const Matrice& autre) const;
    Matrice operator*(double scalaire) const;
    Matrice transpose() const;

    // Affichage
    friend std::ostream& operator<<(std::ostream& os, const Matrice& m);
};

#endif