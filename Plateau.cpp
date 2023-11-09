//
// Created by noure on 07/11/2023.
//
#include "iostream"
#include <iomanip>
#include "Plateau.h"


Plateau::Plateau(int size) : size(size) {
    tableau = new int *[size];
    for (int i = 0; i < size; i++) {
        tableau[i] = new int[size];
        for (int j = 0; j < size; j++) {
            tableau[i][j] = 0;
        }
    }
}

Plateau::~Plateau() {
    for (int i = 0; i < size; i++) {
        delete[] tableau[i];
    }
    delete[] tableau;
}


bool Plateau::estDeplacable(Direction dir) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int value = tableau[i][j];
            if (value != 0) {
                int newRow = i;
                int newCol = j;
                if (dir == Direction::up) {
                    newRow--;
                } else if (dir == Direction::down) {
                    newRow++;
                } else if (dir == Direction::left) {
                    newCol--;
                } else if (dir == Direction::right) {
                    newCol++;
                }
                if (newRow >= 0 && newRow < size && newCol >= 0 && newCol < size) {
                    int newValue = tableau[newRow][newCol];
                    if (newValue == 0 || newValue == value) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool Plateau::estFusionnable(Direction dir) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int value = tableau[i][j];
            if (value != 0) {
                int newRow = i;
                int newCol = j;

                if (dir == Direction::up) {
                    newRow--;
                } else if (dir == Direction::down) {
                    newRow++;
                } else if (dir == Direction::left) {
                    newCol--;
                } else if (dir == Direction::right) {
                    newCol++;
                }

                if (newRow >= 0 && newRow < size && newCol >= 0 && newCol < size) {
                    int newValue = tableau[newRow][newCol];
                    if (newValue == value) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

void Plateau::direction(Direction dir) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (tableau[i][j] == 0) {
                for (int k = j + 1; k < size; k++) {
                    if (tableau[i][k] != 0) {
                        tableau[i][j] = tableau[i][k];
                        tableau[i][k] = 0;
                        break;
                    }
                }
            }
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (tableau[i][j] != 0) {
                int newRow = i;
                int newCol = j;

                if (dir == Direction::up) {
                    newRow--;
                } else if (dir == Direction::down) {
                    newRow++;
                } else if (dir == Direction::left) {
                    newCol--;
                } else if (dir == Direction::right) {
                    newCol++;
                }

                if (newRow >= 0 && newRow < size && newCol >= 0 && newCol < size) {
                    if (tableau[newRow][newCol] == tableau[i][j]) {
                        tableau[newRow][newCol] *= 2;
                        tableau[i][j] = 0;
                    }
                }
            }
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (tableau[i][j] == 0) {
                for (int k = j + 1; k < size; k++) {
                    if (tableau[i][k] != 0) {
                        tableau[i][j] = tableau[i][k];
                        tableau[i][k] = 0;
                        break;
                    }
                }
            }
        }
    }
}

void Plateau::affiche() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (tableau[i][j] != 0)
                std::cout << "|" << std::setw(5) << tableau[i][j] << std::setw(5);
            else
                std::cout << "|" << std::setw(5) <<" " << std::setw(5);  // Ou utilisez std::setw(4) pour une largeur fixe, par exemple
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
            if (tableau[i][j] == 0) {
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

    tableau[rowIndex][colIndex] = targetValue;
}

int Plateau::getSize() const{
    return size;
}

int Plateau::getTableau(int i,int j){
    return tableau[i][j];
}