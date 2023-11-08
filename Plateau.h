//
// Created by noure on 07/11/2023.
//

#ifndef INC_2048_GAME_PLATEAU_H
#define INC_2048_GAME_PLATEAU_H

#include "Direction.h"

class Plateau {
private:
    int size;
    int** tableau;

public:
    Plateau(int size) ;

    ~Plateau() ;

    bool estDeplacable(Direction dir) ;

    bool estFusionnable(Direction dir) ;

    void direction(Direction dir);

    int getSize();

    void affiche() ;

    void nouvelleCase();

    int getTableau(int,int);
};
#endif //INC_2048_GAME_PLATEAU_H
