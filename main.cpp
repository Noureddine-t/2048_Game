#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Partie.h"


int main() {
    srand(time(0));
    int size = 4;
    std::cout << "enter la taille du tableau N*N : ";
    std::cin >> size;
    Partie match(size);
    match.getPlateau().nouvelleCase();
    match.afficher("ZQSD");
    bool quitter = false;
    while (!quitter) {

        std::string touche;
        std::cout << "Touche (Z, Q, S, D, X) : ";

        std::cin >> touche;

        Direction direction;
//ou touche[0] == 'Z' "Zzef" non valid "Z d s" execution de tout les touches est correcte ou char touche=='Z' "Zzef" est considérer "Z"
        if (touche == "Z" || touche =="z")
            direction = Direction::up;
        else if (touche == "Q" || touche == "q")
            direction = Direction::left;
        else if (touche == "S" || touche == "s")
            direction = Direction::down;
        else if (touche == "D" || touche == "d")
            direction = Direction::right;
        else if (touche == "X" || touche == "x") {
            quitter = true;
            std::cout << "Vous avez quitte la partie";
            continue;
        } else {
            std::cout << "Touche non valide. Utilisez Z, Q, S, D, ou X pour quitter." << std::endl;
            continue;
        }

        match.jouer(direction);
        match.afficher("ZQSD");


    }
    return 0;
}
