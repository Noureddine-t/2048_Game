//
// Created by noure on 07/11/2023.
//
#include "iostream"
#include <iomanip>
#include "Plateau.h"
#include <cstring>


Plateau::Plateau(int size) : size(size) {
    tableau = new int[size * size];
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            tableau[size * i + j] = 0;
}

Plateau::~Plateau() {
    delete[] tableau;
}

void Plateau::moveDirectionLeft() {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (tableau[size * i + j] == 0)
                for (int k = j + 1; k < size; k++)
                    if (tableau[size * i + k] != 0) {
                        tableau[size * i + j] = tableau[size * i + k];
                        tableau[size * i + k] = 0;
                        break; //ou j++ ou k=4
                    }
}

void Plateau::moveDirectionRight() {
    for (int i = 0; i < size; i++)
        for (int j = size - 1; j >= 0; j--)
            if (tableau[size * i + j] == 0)
                for (int k = j - 1; k >= 0; k--)
                    if (tableau[size * i + k] != 0) {
                        tableau[size * i + j] = tableau[size * i + k];
                        tableau[size * i + k] = 0;
                        break;
                    }
}

void Plateau::moveDirectionUp() {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (tableau[size * j + i] == 0)
                for (int k = j + 1; k < size; k++)
                    if (tableau[size * k + i] != 0) {
                        tableau[size * j + i] = tableau[size * k + i];
                        tableau[size * k + i] = 0;
                        break;
                    }
}

void Plateau::moveDirectionDown() {
    for (int i = 0; i < size; i++)
        for (int j = size - 1; j >= 0; j--)
            if (tableau[size * j + i] == 0)
                for (int k = j - 1; k >= 0; k--)
                    if (tableau[size * k + i] != 0) {
                        tableau[size * j + i] = tableau[size * k + i];
                        tableau[size * k + i] = 0;
                        break;
                    }
}


void Plateau::moveDirection(Direction dir) {

    if (dir == Direction::right)
        moveDirectionRight();
    else if (dir == Direction::left)
        moveDirectionLeft();
    else if (dir == Direction::up)
        moveDirectionUp();
    else if (dir == Direction::down)
        moveDirectionDown();
}

bool Plateau::estFusionnable(Direction dir) const {
    bool canFusion = false;
    int dirValue = static_cast<int>(dir); //conversion en int pour comparer selon les cas , sinon utiliser if (dir == Direction::right) {
    switch (dirValue) {
        case static_cast<int>(Direction::right): {
            for (int i = 0; i < size; i++)
                for (int j = size - 1; j > 0; j--)
                    if (tableau[size * i + j] == tableau[size * i + j - 1])
                        canFusion = true;
            break;
        }
        case static_cast<int>(Direction::left): {
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size - 1; j++)
                    if (tableau[size * i + j] == tableau[size * i + j + 1])
                        canFusion = true;
            break;
        }
        case static_cast<int>(Direction::up): {
            for (int j = 0; j < size; j++)
                for (int i = 0; i < size - 1; i++)
                    if (tableau[size * i + j] == tableau[size * (i + 1) + j])
                        canFusion = true;
            break;
        }
        case static_cast<int>(Direction::down): {
            for (int j = 0; j < size; j++)
                for (int i = size - 1; i > 0; i--)
                    if (tableau[size * i + j] == tableau[size * (i - 1) + j])
                        canFusion = true;
            break;
        }
        default:
            break;
    }

    return canFusion;
}

void Plateau::fusionDirectionLeft() {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size - 1; j++)
            if (tableau[size * i + j] == tableau[size * i + j + 1]) {
                tableau[size * i + j] *= 2;
                tableau[size * i + j + 1] = 0;
            }
}

void Plateau::fusionDirectionRight() {
    for (int i = 0; i < size; i++)
        for (int j = size - 1; j > 0; j--)
            if (tableau[size * i + j] == tableau[size * i + j - 1]) {
                tableau[size * i + j] *= 2;
                tableau[size * i + j - 1] = 0;
            }
}

void Plateau::fusionDirectionUp() {
    for (int j = 0; j < size; j++)
        for (int i = 0; i < size - 1; i++)
            if (tableau[size * i + j] == tableau[size * (i + 1) + j]) {
                tableau[size * i + j] *= 2;
                tableau[size * (i + 1) + j] = 0;
            }
}

void Plateau::fusionDirectionDown() {
    for (int j = 0; j < size; j++)
        for (int i = size - 1; i > 0; i--)
            if (tableau[size * i + j] == tableau[size * (i - 1) + j]) {
                tableau[size * i + j] *= 2;
                tableau[size * (i - 1) + j] = 0;
            }
}

void Plateau::fusionDirection(Direction dir) {
    if (dir == Direction::right)
        fusionDirectionRight();
    else if (dir == Direction::left)
        fusionDirectionLeft();
    else if (dir == Direction::up)
        fusionDirectionUp();
    else if (dir == Direction::down)
        fusionDirectionDown();
}

Plateau::Plateau(const Plateau &other) : size(other.size) {
    tableau = new int[size * size];
    std::memcpy(tableau, other.tableau, size * size * sizeof(int));
}

bool Plateau::operator!=(const Plateau &other) const {
    return std::memcmp(tableau, other.tableau, size * size * sizeof(int)) != 0;
}

void Plateau::affiche() {
    int maxNumber = 0;

    // Trouver le plus grand nombre dans le tableau
    for (int i = 0; i < size * size; i++) {
        if (tableau[i] > maxNumber) {
            maxNumber = tableau[i];
        }
    }

    // Calculer la largeur de chaque colonne en fonction du plus grand nombre
    int columnWidth = std::to_string(maxNumber).length() + 2;

    // Afficher le tableau
    std::cout << std::string((columnWidth + 1) * size, '-') << std::endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (tableau[size * i + j] != 0) {
                // Ajouter un espacement pour centrer le chiffre dans la cellule
                int paddingBefore = (columnWidth - std::to_string(tableau[size * i + j]).length()) / 2;
                int paddingAfter = columnWidth - paddingBefore - std::to_string(tableau[size * i + j]).length();
                std::cout << "|" << std::setw(paddingBefore) << " " << tableau[size * i + j]
                          << std::setw(paddingAfter) << " ";
            } else {
                std::cout << "|" << std::setw(columnWidth) << " ";
            }
        }
        std::cout << "|" << std::endl;
        std::cout << std::string((columnWidth + 1) * size, '-') << std::endl;
    }
}

void Plateau::nouvelleCase() {
    int emptyCells = 0;
    int emptyCellIndices[size * size][2]; // Tableau pour stocker les indices des cases vides.

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (tableau[size * i + j] == 0) {
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

    tableau[size * rowIndex + colIndex] = targetValue;
}

int Plateau::getSize() const {
    return size;
}

int Plateau::getTableau(int i, int j) {
    return tableau[size * i + j];
}