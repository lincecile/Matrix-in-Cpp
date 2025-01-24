#include "Matrice.hpp"
int main() {
    // Création de deux matrices
    Matrice m1(2, 2);
    m1.set(0, 0, 1); m1.set(0, 1, 2);
    m1.set(1, 0, 3); m1.set(1, 1, 4);

    Matrice m2(2, 2);
    m2.set(0, 0, 5); m2.set(0, 1, 6);
    m2.set(1, 0, 7); m2.set(1, 1, 8);

    // Accès à la valeur (n, m)
    int n = 0;
    int m = 0;
    double valeur_choisie = m2.get(n,m);
    std::cout << "Valeur de coordonnée (" << std::to_string(n) + "," + std::to_string(m) << ")\n" << valeur_choisie << std::endl;
    
    // Accès à une ligne n
    std::vector<double> ligne = m2.getLignes(n);
    std::cout << "Valeurs de la ligne numéro " << n << std::endl;
    for (double val : ligne) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Accès à une colonne m
    std::vector<double> col = m2.getColonne(m);
    std::cout << "Valeurs de la colonne numéro " << m << std::endl;
    for (double val : col) {
        std::cout << val << "\n";
    }
    std::cout << std::endl;

    // Affectation de valeur dans la matrice
    m2.set(0,0,10);
    std::cout << "Changement de valeur :\n" << m2;

    // Addition
    Matrice m3 = m1 + m2;
    std::cout << "Addition :\n" << m3;

    // Multiplication
    Matrice m4 = m1 * m2;
    std::cout << "Multiplication :\n" << m4;

    // Trace
    double tr = m4.trace();
    std::cout << "Trace: " << tr << std::endl;



    return 0;
}