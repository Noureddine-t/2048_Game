//
// Created by noure on 07/11/2023.
//
#include "iostream"
#include "Partie.h"


Partie::Partie(int size) : plateau(size), score(0), cptMouvement(0) {}

void Partie::jouer(Direction dir) {
                plateau.moveDirection(dir);
                plateau.nouvelleCase();
                cptMouvement++;
    }


/*void Partie::jouer(Direction dir) {

    if (plateau.estDeplacable(dir) || plateau.estFusionnable(dir)) {
        plateau.moveDirection(dir);
        plateau.nouvelleCase();
        cptMouvement++;
    }
}*/

int Partie::calculerScore() {
    score=0;
    for (int i = 0; i < plateau.getSize(); i++) {
        for (int j = 0; j < plateau.getSize(); j++) {
            score += plateau.getTableau(i, j);
        }
    }
    return  score;
}

//pour le main lors du lancement du jeu
Plateau &Partie::getPlateau()  {
    return plateau;
}

void Partie::afficher(const std::string &touche) {
    plateau.affiche();
    std::cout << "Score : " << calculerScore() << std::endl;
    std::cout << "Nombre de mouvements : " << cptMouvement << std::endl;
    std::cout << "Touches à utiliser pour déplacement : " << touche << " \t X pour arreter " << std::endl;
}




