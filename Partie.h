//
// Created by noure on 07/11/2023.
//

#ifndef INC_2048_GAME_PARTIE_H
#define INC_2048_GAME_PARTIE_H

#include "Plateau.h"

class Partie {
private:
    Plateau plateau;
    int score=0;
    int cptMouvement=0;

public:
    Partie(int size) ;
    void jouer(Direction dir) ;
    int calculerScore();
    Plateau& getPlateau();
    void afficher(const std::string& touche) ;

};
#endif //INC_2048_GAME_PARTIE_H
