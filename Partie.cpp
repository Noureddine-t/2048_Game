//
// Created by noure on 07/11/2023.
//
#include "iostream"
#include "Partie.h"


Partie::Partie(int size) : plateau(size), score(0), cptMouvement(0) {}



void Partie::jouer(Direction dir) {
    if (plateau.estDeplacable(dir) && plateau.estFusionnable(dir)) {
        plateau.direction(dir);
        plateau.nouvelleCase();
        cptMouvement++;
    }
}

Plateau& Partie::getPlateau() {
    return plateau;
}

void Partie::afficher(const std::string& touche) {
    plateau.affiche();
    std::cout << "Score : " << score << std::endl;
    std::cout << "Nombre de mouvements : " << cptMouvement << std::endl;
    std::cout << "Touches à utiliser pour déplacement : " << touche <<" \t X pour arreter " << std::endl;
}




