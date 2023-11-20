//
// Created by noure on 07/11/2023.
//

#ifndef INC_2048_GAME_PLATEAU_H
#define INC_2048_GAME_PLATEAU_H

#include "Direction.h"

class Plateau {
private:
    int size;
    int* tableau;

public:
    Plateau(int size) ;
    ~Plateau() ;

    void moveDirectionLeft();
    void moveDirectionRight();
    void moveDirectionUp();
    void moveDirectionDown();
    void moveDirection(Direction dir);

    bool estFusionnable(Direction dir) const;
    void fusionDirectionLeft();
    void fusionDirectionRight();
    void fusionDirectionUp();
    void fusionDirectionDown();
    void fusionDirection(Direction dir);

    Plateau(const Plateau& other);

    bool operator!=(const Plateau& other) const; // Declaration for operator!=

     int getSize() const ;

    void affiche() ;

    void nouvelleCase();

    int getTableau(int,int);
};
#endif //INC_2048_GAME_PLATEAU_H
