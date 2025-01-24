#include "Matrice.hpp"
int main() {
    // Création de deux matrices carrées
    Matrice matrice_carree1(2, 2);
    matrice_carree1.set(0, 0, 1); matrice_carree1.set(0, 1, 2);
    matrice_carree1.set(1, 0, 3); matrice_carree1.set(1, 1, 4);

    Matrice matrice_carree2(2, 2);
    matrice_carree2.set(0, 0, 5); matrice_carree2.set(0, 1, 6);
    matrice_carree2.set(1, 0, 7); matrice_carree2.set(1, 1, 8);

    // Création d'une matrice non carrée
    Matrice matrice_non_carree(3, 2);
    matrice_non_carree.set(0, 0, 1); matrice_non_carree.set(0, 1, 2); // ligne 1
    matrice_non_carree.set(1, 0, 3); matrice_non_carree.set(1, 1, 4); // ligne 2
    matrice_non_carree.set(2, 0, 5); matrice_non_carree.set(2, 1, 4); // ligne 3
    std::cout << "Matrice non carrée :\n" << matrice_non_carree;

    // Accès à la valeur (n, m)
    int n = 0;
    int m = 0;
    double valeur_choisie = matrice_carree2.get(n,m);
    std::cout << "Valeur de coordonnée (" << std::to_string(n) + "," + std::to_string(m) << ")\n" << valeur_choisie << std::endl;
    
    // Accès à une ligne n
    std::vector<double> ligne = matrice_carree2.getLignes(n);
    std::cout << "Valeurs de la ligne numéro " << n << std::endl;
    for (double val : ligne) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Accès à une colonne m
    std::vector<double> col = matrice_carree2.getColonne(m);
    std::cout << "Valeurs de la colonne numéro " << m << std::endl;
    for (double val : col) {
        std::cout << val << "\n";
    }
    std::cout << std::endl;

    // Affectation de valeur dans la matrice
    matrice_carree2.set(0,0,10);
    std::cout << "Changement de valeur :\n" << matrice_carree2;

    // Addition
    Matrice matrice_carree3 = matrice_carree1 + matrice_carree2;
    std::cout << "Addition :\n" << matrice_carree3;

    // Multiplication
    Matrice matrice_carree4 = matrice_carree1 * matrice_carree2;
    std::cout << "Multiplication :\n" << matrice_carree4;

    // Trace
    double tr = matrice_carree4.trace();
    std::cout << "Trace: " << tr << std::endl;
    // double trace_erreur = matrice_non_carree.trace(); // renvoie bien une erreur

    // Transposition
    std::cout << "Transposition d'une matrice non carrée :\n" << matrice_non_carree.transpose();

    return 0;
}