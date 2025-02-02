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
    // std::cout << "Matrice non carrée :\n" << matrice_non_carree; POURQUOI AFFICHER ??

    int choix;
    int n = 0;
    int m = 0;
    do {
        // Affichage du menu
        cout << "\n===== MENU =====" << endl;
        cout << "1. Afficher une valeur" << endl;
        cout << "2. Afficher une ligne" << endl;
        cout << "3. Afficher une colonne" << endl;
        cout << "4. Modifier une valeur" << endl;
        cout << "5. Additionner deux matrices" << endl;
        cout << "6. Soustraire deux matrices" << endl;
        cout << "7. Multiplier deux matrices" << endl;
        cout << "8. Multiplier par un scalaire" << endl;
        cout << "9. Calculer la trace" << endl;
        cout << "10. Calculer la transposée" << endl;
        cout << "11. Calculer l'inverse" << endl;
        cout << "12. Quitter" << endl;
        cout << "Votre choix : ";
        cin >> choix;
        cout << endl;


        switch (choix) {
            case 1:
            {
                 // Accès à la valeur (n, m)
                std::cout << "Matrice :\n" << matrice_carree2 << endl;
                double valeur_choisie = matrice_carree2.get(n,m);
                std::cout << "Valeur de coordonnée (" << std::to_string(n) + "," + std::to_string(m) << ")\n" << valeur_choisie << std::endl;
                break;
            }
                
            case 2:
            {
                // Accès à une ligne n
                std::cout << "Matrice :\n" << matrice_carree2 << endl;
                std::vector<double> ligne = matrice_carree2.getLignes(n);
                std::cout << "Valeurs de la ligne numéro " << n << std::endl;
                for (double val : ligne) {
                    std::cout << val << " ";
                }
                std::cout << std::endl;
                break;
            }
            case 3:
            {
                // Accès à une colonne m
                std::cout << "Matrice :\n" << matrice_carree2 << endl;
                std::vector<double> col = matrice_carree2.getColonne(m);
                std::cout << "Valeurs de la colonne numéro " << m << std::endl;
                for (double val : col) {
                    std::cout << val << "\n";
                }
                std::cout << std::endl;
                break;
                }
            case 4:
            {

                // Affectation de valeur dans la matrice
                std::cout << "Matrice avant modification :\n" << matrice_carree2 << endl;
                matrice_carree2.set(0,0,10);
                std::cout << "Matrice après modification :\n" << matrice_carree2;
                break;
            }
            case 5:
            {

                // Addition
                std::cout << "Matrice 1 :\n" << matrice_carree1 << endl;
                std::cout << "Matrice 2 :\n" << matrice_carree2 << endl;
                Matrice matrice_carree3 = matrice_carree1 + matrice_carree2;
                std::cout << "Addition des deux matrices :\n" << matrice_carree3;
                break;
                }
            case 6:
            {

                // Soustraction
                std::cout << "Matrice 1 :\n" << matrice_carree1 << endl;
                std::cout << "Matrice 2 :\n" << matrice_carree2 << endl;
                Matrice matrice_carree4 = matrice_carree1 - matrice_carree2;
                std::cout << "Soustraction des deux matrices :\n" << matrice_carree4;
                break;
                 }
            case 7:
            {
                // Multiplication
                std::cout << "Matrice 1 :\n" << matrice_carree1 << endl;
                std::cout << "Matrice 2 :\n" << matrice_carree2 << endl;
                Matrice matrice_carree5 = matrice_carree1 * matrice_carree2;
                std::cout << "Multiplication des deux matrices :\n" << matrice_carree5;
                break;
                }
            case 8:
            {
                // Multiplication par un scalaire
                std::cout << "Matrice :\n" << matrice_carree1 << endl;
                Matrice matrice_carree6 = matrice_carree1 * 4;
                std::cout << "Multiplication par un scalaire :\n" << matrice_carree6;
                break;
                }
            case 9:
            {
                // Trace
                std::cout << "Matrice :\n" << matrice_carree1 << endl;
                double tr = matrice_carree1.trace();
                std::cout << "Trace de la matrice : " << tr << std::endl;
                // double trace_erreur = matrice_non_carree.trace(); // renvoie bien une erreur
                break;
                }
            case 10:
            {
                // Transposition
                std::cout << "Matrice non carrée :\n" << matrice_non_carree; 
                std::cout << "Transposition de la matrice non carrée :\n" << matrice_non_carree.transpose();
                break;
                 }
            case 11:
            {
                // Inversion
                 std::cout << "En cours...\n" << endl;
                break;
                }
            case 12:
            {
                cout << "Programme terminé !" << endl;
                break;
                }
            default:
                cout << "Choix invalide, veuillez réessayer." << endl;
        }
    } while (choix != 12);
    return 0;
}