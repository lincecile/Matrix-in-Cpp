#include "Matrice.hpp"
using namespace std;

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

    // Création d'une matrice identité
    Matrice matrice_id(3, 3);
    matrice_id.set(0, 0, 1); matrice_id.set(0, 1, 0); matrice_id.set(0, 2, 0);
    matrice_id.set(1, 0, 0); matrice_id.set(1, 1, 1); matrice_id.set(1, 2, 0);
    matrice_id.set(2, 0, 0); matrice_id.set(2, 1, 0); matrice_id.set(2, 2, 1);

    // Création d'une matrice nulle
    Matrice matrice_nulle(2, 2);

    // Création d'une matrice inverse 
    Matrice matrice_carree1_inverse = matrice_carree1.inverse(); // pour l'exemple, on a vérifie à la main que la matrice était bien inversible

    int choix;
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
        cout << "12. Vérifier si la matrice est diagonale" << endl;
        cout << "13. Vérifier si la matrice est triangulaire supérieure" << endl;
        cout << "14. Vérifier si la matrice est triangulaire inférieure" << endl;
        cout << "15. Vérifier si la matrice est carrée" << endl;
        cout << "16. Vérifier si la matrice est une matrice identité" << endl;
        cout << "17. Vérifier si la matrice est nulle" << endl;
        cout << "18. Vérifier si la matrice est bien inversible" << endl;
        cout << "19. Vérifier si la matrice est bien l'inverse de la matrice testée" << endl;
        cout << "20. Quitter" << endl;
        cout << "Votre choix : ";
        cin >> choix;
        cout << endl;


        switch (choix) {
            case 1:
            {
                // Accès à la valeur (n, m)
                int n, m;
                cout << "Entrez la ligne : ";
                cin >> n;
                cout << "Entrez la colonne : ";
                cin >> m;
                cout << "Matrice :\n" << matrice_carree2 << endl;
                double valeur_choisie = matrice_carree2.get(n,m);
                cout << "Valeur de coordonnée (" << to_string(n) + "," + to_string(m) << ")\n" << valeur_choisie << endl;
                break;
            }
                
            case 2:
            {
                // Accès à une ligne n
                int n;
                cout << "Entrez la ligne souhaitée: ";
                cin >> n;
                cout << "Matrice :\n" << matrice_carree2 << endl;
                vector<double> ligne = matrice_carree2.getLignes(n);
                cout << "Valeurs de la ligne numéro " << n << endl;
                for (double val : ligne) {
                    cout << val << " ";
                }
                cout << endl;
                break;
            }
            case 3:
            {
                // Accès à une colonne m
                int m;
                cout << "Entrez la colonne souhaitée: ";
                cin >> m;
                cout << "Matrice :\n" << matrice_carree2 << endl;
                vector<double> col = matrice_carree2.getColonne(m);
                cout << "Valeurs de la colonne numéro " << m << endl;
                for (double val : col) {
                    cout << val << "\n";
                }
                cout << endl;
                break;
                }
            case 4:
            {
                // Affectation de valeur dans la matrice
                int n, m, valeur_choisi;
                cout << "Matrice avant modification d'une valeur :\n" << matrice_carree2 << endl;
                cout << "Entrez la ligne : ";
                cin >> n;
                cout << "Entrez la colonne : ";
                cin >> m;
                cout << "Entrez la valeur à affecter : ";
                cin >> valeur_choisi;
                matrice_carree2.set(n, m, valeur_choisi);
                cout << "Matrice après modification :\n" << matrice_carree2;
                break;
            }
            case 5:
            {
                // Addition
                cout << "Matrice 1 :\n" << matrice_carree1 << endl;
                cout << "Matrice 2 :\n" << matrice_carree2 << endl;
                Matrice matrice_carree3 = matrice_carree1 + matrice_carree2;
                cout << "Addition des deux matrices :\n" << matrice_carree3;
                break;
                }
            case 6:
            {
                // Soustraction
                cout << "Matrice 1 :\n" << matrice_carree1 << endl;
                cout << "Matrice 2 :\n" << matrice_carree2 << endl;
                Matrice matrice_carree4 = matrice_carree1 - matrice_carree2;
                cout << "Soustraction des deux matrices :\n" << matrice_carree4;
                break;
                 }
            case 7:
            {
                // Multiplication
                cout << "Matrice 1 :\n" << matrice_carree1 << endl;
                cout << "Matrice 2 :\n" << matrice_carree2 << endl;
                Matrice matrice_carree5 = matrice_carree1 * matrice_carree2;
                cout << "Multiplication des deux matrices :\n" << matrice_carree5;
                break;
                }
            case 8:
            {
                // Multiplication par un scalaire
                cout << "Matrice :\n" << matrice_carree1 << endl;
                Matrice matrice_carree6 = matrice_carree1 * 4;
                cout << "Multiplication par un scalaire :\n" << matrice_carree6;
                break;
                }
            case 9:
            {
                // Trace
                cout << "Matrice :\n" << matrice_carree1 << endl;
                double tr = matrice_carree1.trace();
                cout << "Trace de la matrice : " << tr << endl;
                // double trace_erreur = matrice_non_carree.trace(); // renvoie bien une erreur
                break;
                }
            case 10:
            {
                // Transposition
                cout << "Matrice non carrée :\n" << matrice_non_carree; 
                cout << "Transposition de la matrice non carrée :\n" << matrice_non_carree.transpose();
                break;
                 }
            case 11:
            {
                // Inversion
                cout << "Matrice à inverser :\n" << matrice_carree1 << endl;
                if (matrice_carree1.isInversible()) {
                    Matrice inverse = matrice_carree1.inverse();
                    cout << "Matrice inversée :\n" << inverse;
                    
                } else {
                    cout << "La matrice n'est pas inversible" << endl;
                }
                break;
                }
            case 12:
            {
                // Diagonal
                cout << "Matrice :\n" << matrice_carree1 << endl;
                bool estDiagonale = matrice_carree1.isDiagonal();
                cout << "La matrice " << (estDiagonale ? "est diagonale" : "n'est pas diagonale") << endl;
                break;
            }
            case 13:
            {
                // Triangulaire Supérieur
                cout << "Matrice :\n" << matrice_carree1 << endl;
                bool estTriangulaireSuperieure = matrice_carree1.isTriangulaireSup();
                cout << "La matrice " << (estTriangulaireSuperieure ? "est triangulaire supérieure" : "n'est pas triangulaire supérieure") << endl;
                break;
            }
            case 14:
            {
                // Triangulaire inférieur
                cout << "Matrice :\n" << matrice_carree1 << endl;
                bool estTriangulaireInferieure = matrice_carree1.isTriangulaireInf();
                cout << "La matrice " << (estTriangulaireInferieure ? "est triangulaire inférieure" : "n'est pas triangulaire inférieure") << endl;
                break;
            }
            case 15:
            {
                // Matrice carrée
                cout << "Matrice carrée :\n" << matrice_carree1 << endl;
                cout << "Matrice non carrée :\n" << matrice_non_carree << endl;
                bool estCarree1 = matrice_carree1.isCarre();
                bool estCarree2 = matrice_non_carree.isCarre();
                cout << "Matrice carrée 1 est " << (estCarree1 ? "est carrée" : "n'est pas carrée") << endl;
                cout << "Matrice non carrée est " << (estCarree2 ? "carrée" : "non carrée") << endl;
                break;
            }
            case 16:
            {   
                // Matrice identité
                cout << "Matrice identité :\n" << matrice_id << endl;
                cout << "Matrice 1 :\n" << matrice_carree1 << endl;
                bool estIdentite1 = matrice_id.isIdentite();
                bool estIdentite2 = matrice_carree1.isIdentite();
                cout << "Matrice identité " << (estIdentite1 ? "est une matrice identité" : "n'est pas une matrice identité") << endl;
                cout << "Matrice 1 " << (estIdentite2 ? "est une matrice identité" : "n'est pas une matrice identité") << endl;
                break;
            }
            case 17:
            {   
                // Test matrice nulle
                cout << "Matrice nulle :\n" << matrice_nulle << endl;
                cout << "Matrice 1 :\n" << matrice_carree1 << endl;
                bool estNulle1 = matrice_nulle.isNulle();
                bool estNulle2 = matrice_carree1.isNulle();
                cout << "Matrice nulle " << (estNulle1 ? "est une matrice nulle" : "n'est pas une matrice nulle") << endl;
                cout << "Matrice 1 " << (estNulle2 ? "est une matrice nulle" : "n'est pas une matrice nulle") << endl;
                break;
            }
            case 18:
            {   
                // Test inversible
                cout << "Matrice inversible ou non :\n" << matrice_carree1 << endl;
                bool estInversible = matrice_carree1.isInversible();
                cout << (estInversible ? "La matrice est bien inversible, tapez 11 pour obtenir la matrice inverse." : "La matrice n'est pas inversible.") << endl;
                break;
            }
            case 19:
            {   
                // Test matrice inverse: vérification : A * A^(-1) devrait donner la matrice identité
                Matrice verification = matrice_carree1 * matrice_carree1_inverse;
                verification.arrondiZero();
                cout << "Vérification (devrait être proche de la matrice identité) :\n" << verification;
                bool estInverse1 = verification.isIdentite();
                cout << "Matrice 1 inverse " << (estInverse1 ? "est bien la matrice inverse" : "n'est pas l'inverse de la matrice testée") << endl;
                break;
            }
            case 20:
            {
                cout << "Programme terminé !" << endl;
                break;
            }
            default:
                cout << "Choix invalide, veuillez réessayer." << endl;
        }
    } while (choix != 20);
    return 0;
}