//
// Created by noure on 07/11/2023.
//
#include "iostream"
#include "Partie.h"


Partie::Partie(int size) : plateau(size) {}

void Partie::jouer(Direction dir) {
    // Sauvegarde de l'état initial du plateau
    Plateau plateauAvant = plateau;

    // Effectuer le déplacement
    plateau.moveDirection(dir);

    // Effectuer la fusion après le déplacement
    while (plateau.estFusionnable(dir)) {
        Plateau plateauAvantFusion = plateau;  // Sauvegarde de l'état avant la fusion
        plateau.fusionDirection(dir);

        // Vérifier si la fusion a effectivement modifié le plateau
        if (!(plateauAvantFusion != plateau))
            break;
    }

    // Vérifier s'il y a eu un changement après le déplacement et la fusion
    if (plateauAvant != plateau) {
        plateau.nouvelleCase();
        cptMouvement++;
    }
}


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