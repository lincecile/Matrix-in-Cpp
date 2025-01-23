#include "Matrice.h"
int main() {
    // Création de deux matrices
    Matrice m1(2, 2);
    m1.set(0, 0, 1); m1.set(0, 1, 2);
    m1.set(1, 0, 3); m1.set(1, 1, 4);

    Matrice m2(2, 2);
    m2.set(0, 0, 5); m2.set(0, 1, 6);
    m2.set(1, 0, 7); m2.set(1, 1, 8);

    // Addition
    Matrice m3 = m1 + m2;
    std::cout << "Addition :\n" << m3;

    // Multiplication
    Matrice m4 = m1 * m2;
    std::cout << "Multiplication :\n" << m4;

    return 0;
}