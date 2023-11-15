//
// Created by noure on 07/11/2023.
//
#include "iostream"
#include <iomanip>
#include "Plateau.h"


Plateau::Plateau(int size) : size(size) {
    tableau = new int [size * size];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            tableau[size*i+j] = 0;
        }
    }
}

Plateau::~Plateau() {
    delete[] tableau;
}

/*
bool Plateau::estDeplacable(Direction dir) {

}
bool Plateau::estFusionnable(Direction dir ) {

}
*/


void Plateau::moveDirectionLeft() {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (tableau[size*i+j] == 0)
                for (int k = j + 1; k < size; k++)
                    if (tableau[size*i+k] != 0) {
                        tableau[size*i+j] = tableau[size*i+k];
                        tableau[size*i+k] = 0;
                        break; //ou j++ ou k=4
                    }
}

void Plateau::moveDirectionRight() {
    for (int i = 0; i < size; i++)
        for (int j = size - 1; j >= 0; j--)
            if (tableau[size*i+j] == 0)
                for (int k = j - 1; k >= 0; k--)
                    if (tableau[size*i+k] != 0) {
                        tableau[size*i+j] = tableau[size*i+k];
                        tableau[size*i+k] = 0;
                        break;
                    }
}

void Plateau::moveDirectionUp() {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (tableau[size*j+i] == 0)
                for (int k = i + 1; k < size; k++)
                    if (tableau[size*j+k] != 0) {
                        tableau[size*j+i] = tableau[size*j+k];
                        tableau[size*j+k] = 0;
                        break;
                    }
}

void Plateau::moveDirectionDown() {
    for (int i = 0; i < size; i++)
        for (int j = size - 1; j >= 0; j--)
            if (tableau[size*j+i] == 0)
                for (int k = i - 1; k >= 0; k--)
                    if (tableau[size*j+k] != 0) {
                        tableau[size*j+i] = tableau[size*j+k];
                        tableau[size*j+k] = 0;
                        break;
                    }
}


void Plateau::moveDirection(Direction dir) {
   if(dir==Direction::right)
       moveDirectionRight();

    if(dir==Direction::left)
        moveDirectionLeft();

    if(dir==Direction::up)
        moveDirectionUp();

    if(dir==Direction::down)
        moveDirectionDown();
}


void Plateau::affiche() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (tableau[size*i+j] != 0)
                std::cout << "|" << std::setw(5) << tableau[size*i+j] << std::setw(5);
            else
                std::cout << "|" << std::setw(5) << " "
                          << std::setw(5);  // Ou utilisez std::setw(4) pour une largeur fixe, par exemple
        }
        std::cout << "|" << std::endl;
        std::cout << "-----------------------------------------" << std::endl;
    }
}

void Plateau::nouvelleCase() {
    int emptyCells = 0;
    int emptyCellIndices[size * size][2]; // Tableau pour stocker les indices des cases vides.

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (tableau[size*i+j] == 0) {
                emptyCellIndices[emptyCells][0] = i;
                emptyCellIndices[emptyCells][1] = j;
                emptyCells++;
            }
        }
    }

    if (emptyCells == 0)
        return; // Pas de cases vides

    int randomCell = rand() % emptyCells;
    int targetValue = (rand() % 2 + 1) * 2; // Génère un 2 ou un 4

    int rowIndex = emptyCellIndices[randomCell][0];
    int colIndex = emptyCellIndices[randomCell][1];

    tableau[size*rowIndex+colIndex] = targetValue;
}

int Plateau::getSize() const {
    return size;
}

int Plateau::getTableau(int i, int j) {
    return tableau[size*i+j];
}