//
// Created by noure on 07/11/2023.
//

#ifndef INC_2048_GAME_PLATEAU_H
#define INC_2048_GAME_PLATEAU_H

#include "Direction.h"

class Plateau {
private:
    int N;
    int** tableau;

public:
    Plateau(int size) ;

    ~Plateau() ;

    bool estDeplacable(Direction dir) ;

    bool estFusionnable(Direction dir) ;

    void direction(Direction dir);

    void affiche() ;

    void nouvelleCase();
};
#endif //INC_2048_GAME_PLATEAU_H
