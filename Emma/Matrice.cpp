#include "Matrice.h"

// Constructeur
Matrice::Matrice(int l, int c) : lignes(l), colonnes(c) {
    if (l <= 0 || c <= 0) {
        throw std::invalid_argument("Les dimensions doivent être positives");
    }
    data.resize(lignes, std::vector<double>(colonnes, 0.0));
}

// Accesseurs
double Matrice::get(int i, int j) const {
    if (i >= 0 && i < lignes && j >= 0 && j < colonnes) {
        return data[i][j];
    }
    throw std::out_of_range("Indices hors limites");
}

void Matrice::set(int i, int j, double valeur) {
    if (i >= 0 && i < lignes && j >= 0 && j < colonnes) {
        data[i][j] = valeur;
    } else {
        throw std::out_of_range("Indices hors limites");
    }
}

// Addition de matrices
Matrice Matrice::operator+(const Matrice& autre) const {
    if (lignes != autre.lignes || colonnes != autre.colonnes) {
        throw std::invalid_argument("Dimensions incompatibles pour l'addition");
    }

    Matrice resultat(lignes, colonnes);
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            resultat.data[i][j] = data[i][j] + autre.data[i][j];
        }
    }
    return resultat;
}

// Soustraction de matrices
Matrice Matrice::operator-(const Matrice& autre) const {
    if (lignes != autre.lignes || colonnes != autre.colonnes) {
        throw std::invalid_argument("Dimensions incompatibles pour la soustraction");
    }

    Matrice resultat(lignes, colonnes);
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            resultat.data[i][j] = data[i][j] - autre.data[i][j];
        }
    }
    return resultat;
}

// Multiplication de matrices
Matrice Matrice::operator*(const Matrice& autre) const {
    if (colonnes != autre.lignes) {
        throw std::invalid_argument("Dimensions incompatibles pour la multiplication");
    }

    Matrice resultat(lignes, autre.colonnes);
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < autre.colonnes; j++) {
            double somme = 0;
            for (int k = 0; k < colonnes; k++) {
                somme += data[i][k] * autre.data[k][j];
            }
            resultat.data[i][j] = somme;
        }
    }
    return resultat;
}

// Multiplication par un scalaire
Matrice Matrice::operator*(double scalaire) const {
    Matrice resultat(lignes, colonnes);
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            resultat.data[i][j] = data[i][j] * scalaire;
        }
    }
    return resultat;
}

// Transposition
Matrice Matrice::transpose() const {
    Matrice resultat(colonnes, lignes);
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            resultat.data[j][i] = data[i][j];
        }
    }
    return resultat;
}

// Surcharge de l'opérateur d'affichage
std::ostream& operator<<(std::ostream& os, const Matrice& m) {
    for (int i = 0; i < m.lignes; i++) {
        for (int j = 0; j < m.colonnes; j++) {
            os << m.data[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}