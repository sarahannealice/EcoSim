//
// Created by sarah on 18/04/2023.
//

#include <windows.h>
#include "../inc/City.h"

City::City() {

    //generates an empty city
    for (int i = 0; i < GRIDSIZE; i++) {
        for (int j = 0; j < GRIDSIZE; j++) {
            grid[i][j] = nullptr;
        }
    }
}

//destructor
City::~City() = default;

//gets pointer to organism
Organism *City::getOrganism(int x, int y) {
    return grid[x][y];
}

void City::setOrganism(Organism *organism, int x, int y) {
    grid[x][y] = organism;
}

int City::countType(char orgType) {
    return 0;
}

bool City::hasDiversity() {
    return true;
}


//----------------methods----------------//
//initializes city with humans & zombies
void City::spawnOrganisms() {
    //humans
}

/*
//checks every organism on the grid and makes them perform their routine
void City::move() {
    for (auto & row : grid) {
        for (auto & organism : row) {
            if (organism != nullptr) {
                organism->moveRoutine();
            }
        }
    }
}

//resets every organism's 'move' boolean for next generation
void City::reset() {
    for (auto & row : grid) {
        for (auto & organism : row) {
            if (organism != nullptr) {
                organism->resetMove();
            }
        }
    }
}
 */

ostream& operator<<(ostream &output, City &city) {

    //prints grid
    for (auto & row : city.grid) {
        for (auto & organism : row) {
            if (organism == nullptr) {
                output << " " << BLANKCOLOR << "0" << " ";
            } else {
                output << organism;
            }
        }
        output << endl;
    }
    return output;
}

