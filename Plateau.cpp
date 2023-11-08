//
// Created by noure on 07/11/2023.
//
#include "iostream"
#include "Plateau.h"


Plateau::Plateau(int size) : N(size) {
    tableau = new int *[N];
    for (int i = 0; i < N; i++) {
        tableau[i] = new int[N];
        for (int j = 0; j < N; j++) {
            tableau[i][j] = 0;
        }
    }
}

Plateau::~Plateau() {
    for (int i = 0; i < N; i++) {
        delete[] tableau[i];
    }
    delete[] tableau;
}


bool Plateau::estDeplacable(Direction dir) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
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
                if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < N) {
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
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
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

                if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < N) {
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
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (tableau[i][j] == 0) {
                for (int k = j + 1; k < N; k++) {
                    if (tableau[i][k] != 0) {
                        tableau[i][j] = tableau[i][k];
                        tableau[i][k] = 0;
                        break;
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
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

                if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < N) {
                    if (tableau[newRow][newCol] == tableau[i][j]) {
                        tableau[newRow][newCol] *= 2;
                        tableau[i][j] = 0;
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (tableau[i][j] == 0) {
                for (int k = j + 1; k < N; k++) {
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
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            std::cout <<"| "<< tableau[i][j] << "\t";

        std::cout <<"| "<<std::endl;
        std::cout <<"-----------------"<< std::endl;
    }
}

void Plateau::nouvelleCase() {
    int emptyCells = 0;
    int emptyCellIndices[N * N][2]; // Tableau pour stocker les indices des cases vides.

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
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