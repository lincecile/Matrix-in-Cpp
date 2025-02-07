#include <iostream>
#include <vector>
#include "Matrice.hpp"

using namespace std;
using namespace std::chrono;

// Constructeurs

// Matrice
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

    // addition
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

    // Transposition
    Matrice resultat(colonnes, lignes);
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            resultat.data[j][i] = data[i][j];
        }
    }

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

// Inverse
Matrice Matrice::inverse() const {
    // Vérifie si la matrice est inversible
    if (!isInversible()) {
        throw std::runtime_error("La matrice n'est pas inversible");
    }

    // chrono
    auto start = high_resolution_clock::now();

    // Crée la matrice augmentée [A|I]
    Matrice augmented(lignes, colonnes * 2);
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            augmented.set(i, j, data[i][j]);
            augmented.set(i, j + colonnes, (i == j) ? 1.0 : 0.0);
        }
    }

    // Applique la méthode de Gauss-Jordan
    for (int i = 0; i < lignes; i++) {
        // Trouve le pivot maximum dans cette colonne
        double pivotMax = std::abs(augmented.get(i, i));
        int lignePivotMax = i;
        for (int k = i + 1; k < lignes; k++) {
            if (std::abs(augmented.get(k, i)) > pivotMax) {
                pivotMax = std::abs(augmented.get(k, i));
                lignePivotMax = k;
            }
        }

        // Échange les lignes si nécessaire
        if (lignePivotMax != i) {
            for (int j = 0; j < 2 * colonnes; j++) {
                double temp = augmented.get(i, j);
                augmented.set(i, j, augmented.get(lignePivotMax, j));
                augmented.set(lignePivotMax, j, temp);
            }
        }

        // Normalise la ligne du pivot
        double pivot = augmented.get(i, i);
        for (int j = 0; j < 2 * colonnes; j++) {
            augmented.set(i, j, augmented.get(i, j) / pivot);
        }

        // Rend nulle les valeurs de la colonne hors pivot
        for (int k = 0; k < lignes; k++) {
            if (k != i) {
                double c = augmented.get(k, i);
                for (int j = 0; j < 2 * colonnes; j++) {
                    augmented.set(k, j, augmented.get(k, j) - c * augmented.get(i, j));
                }
            }
        }
    }

    // Extrait la partie droite qui contient l'inverse [I|A^(-1)]
    Matrice inverse(lignes, colonnes);
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            inverse.set(i, j, augmented.get(i, j + colonnes));
        }
    }

    // affichage du chrono
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    std::cout << "Inversion de la matrice en " 
              << duration.count() << " microsecondes, soit "
              << duration.count() / 1000000.0 << " secondes" << std::endl;

    return inverse;
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

bool Matrice::isIdentite() const {
    // Verifie d'abord si c'est une matrice diagonale
    if (!isDiagonal()) {
        return false;
    }

    // Verifie que tous les éléments diagonaux sont 1
    for (int i = 0; i < lignes; i++) {
        if (std::abs(data[i][i] - 1.0) > 1e-10) {
            return false;
        }
    }
    return true;
}

bool Matrice::isNulle() const {
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            if (std::abs(data[i][j]) > 1e-10) {
                return false;
            }
        }
    }
    return true;
}

bool Matrice::isInversible() const {
    // Une matrice est inversible si elle est carrée et son déterminant n'est pas nul

    // Vérification de la matrice carrée
    if (!isCarre()) {
        return false;
    }
    
    // Pour une matrice 1x1
    if (lignes == 1) {
        return std::abs(data[0][0]) > 1e-10;
    }
    
    // Pour une matrice 2x2, vérifie si le déterminant n'est pas nul
    if (lignes == 2) {
        double det = data[0][0] * data[1][1] - data[0][1] * data[1][0];
        return std::abs(det) > 1e-10;
    }
    
    // Pour les matrices plus grandes, on vérifie le rang
    // Si la matrice a son rang égale au nombre de ligne 
    int rang = 0;
    std::vector<std::vector<double>> mat = data;
    
    for (int i = 0; i < lignes; i++) {
        // Trouve le pivot maximum dans la colonne
        double pivotMax = 0;
        int lignePivotMax = -1;
        for (int k = i; k < lignes; k++) {
            if (std::abs(mat[k][i]) > pivotMax) {
                pivotMax = std::abs(mat[k][i]);
                lignePivotMax = k;
            }
        }
        
        // Si le pivot maximum de la colonne est nulle, la matrice n'est pas inversible
        if (pivotMax < 1e-10) {
            return false;
        }
        
        // Échange les lignes pour avoir le pivot en diagonal
        std::swap(mat[i], mat[lignePivotMax]);
        
        // Élimination des éléments en dessous du pivot
        for (int k = i + 1; k < lignes; k++) {
            double facteur = mat[k][i] / mat[i][i];
            for (int j = i; j < lignes; j++) {
                mat[k][j] -= facteur * mat[i][j];
            }
        }
        
        rang++;
    }
    
    // La matrice est inversible si le rang est égal au nombre de lignes
    return rang == lignes;
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

// Méthode pour arrondir les valeurs très proches de zéro
void Matrice::arrondiZero() {
    const double EPSILON = 1e-10;  // Seuil pour considérer une valeur comme zéro
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            if (std::abs(data[i][j]) < EPSILON) {
                data[i][j] = 0.0;
            }
        }
    }
}
