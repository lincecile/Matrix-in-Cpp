#include <iostream>
#include <vector>
#include <string> 
#include "Matrice.hpp"

using namespace std;
using namespace std::chrono;

// Constructeur
Matrice::Matrice(int l, int c) : lignes(l), colonnes(c) {
    if (l <= 0 || c <= 0) {
        throw std::invalid_argument("Les dimensions doivent être positives");
    }
    data.resize(lignes, std::vector<double>(colonnes, 0.0));
}

/***************************************************************************************/
/************************* MANIPULATION DES DONNEES DE LA MATRICE **********************/
/***************************************************************************************/

// Accesseurs
double Matrice::get(int i, int j) const {
    if (i >= 0 && i < lignes && j >= 0 && j < colonnes) {
        return data[i][j];
    }
    throw std::out_of_range("Indices hors limites");
}


std::vector<double> Matrice::getLignes(int i) const {
    if (i >= 0 && i < lignes) {
        return data[i];
    }
    throw std::out_of_range("Indices hors limites");
}

std::vector<double> Matrice::getColonne(int j) const {
    if (j >= 0 && j < colonnes) {
        std::vector<double> column;
        for (const auto& row : data) {
            column.push_back(row[j]);
        }
        return column;
    }
    throw std::out_of_range("Indice de colonne hors limites");
}

void Matrice::set(int i, int j, double valeur) {
    if (i >= 0 && i < lignes && j >= 0 && j < colonnes) {
        data[i][j] = valeur;
    } else {
        throw std::out_of_range("Indices hors limites");
    }
}

/***************************************************************************************/
/************************************** OPERATEUR **************************************/
/***************************************************************************************/

// Addition de matrices
Matrice Matrice::operator+(const Matrice& autre) const {
    if (lignes != autre.lignes || colonnes != autre.colonnes) {
        throw std::invalid_argument("Dimensions incompatibles pour l'addition");
    }

    // chrono
    auto start = high_resolution_clock::now();

    // addition
    Matrice resultat(lignes, colonnes);
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            resultat.data[i][j] = data[i][j] + autre.data[i][j];
        }
    }

    // affichage du chrono
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    std::cout << "Additions des matrices en " 
              << duration.count() << " microsecondes, soit "
              << duration.count() / 1000000.0 << " secondes" << std::endl;
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
    // chrono
    auto start = high_resolution_clock::now();

    // Transposition
    Matrice resultat(colonnes, lignes);
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            resultat.data[j][i] = data[i][j];
        }
    }

    // affichage du chrono
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    std::cout << "Transposition de la matrice en " 
              << duration.count() << " microsecondes, soit "
              << duration.count() / 1000000.0 << " secondes" << std::endl;

    return resultat;
}

// Trace
double Matrice::trace() const {
    // vérification de matrice carrée
    if (lignes != colonnes) {
        throw std::invalid_argument("La Trace n'existe que pour les matrices carrés");
    }

    double tr = 0.0;
    for (int i = 0; i < lignes; i++) {
        tr += data[i][i];
    }
    return tr;
}

/***************************************************************************************/
/**************************************** TEST *****************************************/
/***************************************************************************************/

bool Matrice::isCarre() const {
    // Verifie si on a le même nombre de ligne et de colonne
    return lignes == colonnes;
}

bool Matrice::isTriangulaireSup() const {
    // Verifie que la matrice est carrée
    if (!isCarre()) {
        return false;
    }

    // Verifie que tous les éléments en dessous de la diagonale sont nuls
    for (int i = 1; i < lignes; i++) {
        for (int j = 0; j < i; j++) {
            
            // on prend pour seuil une valeur de type float tres faible qui correspondra à la valeur considérée comme nulle
            if (std::abs(data[i][j]) > 1e-10) {  
                return false;
            }
        }
    }
    return true;
}

bool Matrice::isTriangulaireInf() const {
    // Verifie que la matrice est carrée
    if (!isCarre()) {
        return false;
    }

    // Verifie que tous les éléments au dessus de la diagonale sont nuls
    for (int i = 0; i < lignes; i++) {
        for (int j = i + 1; j < colonnes; j++) {
            
            // on prend pour seuil une valeur de type float tres faible qui correspondra à la valeur considérée comme nulle
            if (std::abs(data[i][j]) > 1e-10) {  
                return false;
            }
        }
    }
    return true;
}

bool Matrice::isDiagonal() const {
    // Verifie que la matrice est carrée
    if (!isCarre()) {
        return false;
    }

    // Verifie que tous les éléments hors diagonale sont nuls
    return isTriangulaireSup() && isTriangulaireInf();
}


/***************************************************************************************/
/************************************** AFFICHAGE **************************************/
/***************************************************************************************/

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
