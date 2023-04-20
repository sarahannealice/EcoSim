//
// Created by sarah on 18/04/2023.
//

#include <chrono>
#include <random>
#include "../inc/City.h"
#include "../inc/Organism.h"
#include "../inc/Zombie.h"
#include "../inc/Human.h"

int count = 0;

City::City() {
    //generates an empty city
    for (int i = 0; i < GRIDSIZE; i++) {
        for (int j = 0; j < GRIDSIZE; j++) {
            map[i][j] = nullptr;
        }
    }

    spawnOrganisms();
}

//----------------methods----------------//
//checks if both humans and zombies are on the map
bool City::hasDiversity() const {
    return (humanCount() > 0 && zombieCount() > 0);
}

//checks if grid spot contains human
bool City::isHuman(Coordinate xy) {
    bool human = false;
    //check if grid space is within bounds
    if (xy.x < 0 || xy.y < 0 || xy.x > GRIDSIZE || xy.y > GRIDSIZE) {
        human = false;
    }

    //checks that the organism at the grid spot is human
    if (this->map[xy.x][xy.y] != nullptr && this->map[xy.x][xy.y]->getType() == HUMAN) {
        human = true;
    }
    return human;
}

//places desired organism at x,y location on map
void City::placeOrg(Organism* activeOrg, Coordinate xy) {
    this->map[xy.x][xy.y] = activeOrg;
    activeOrg->setSpot(xy);
}

//removes desired organism at x,y location on map
void City::resetOrg(Coordinate xy) {
    map[xy.x][xy.y] = nullptr;
}

Organism *City::getOrg(Coordinate xy) {
    return map[xy.x][xy.y];
}

//checks every organism on the grid and makes them perform their routine
void City::move() {
    for (auto & row : map) {
        for (auto & organism : row) {
            if (organism != nullptr) {
                organism->routine();
            }
        }
    }
}

//resets every organism's 'move' boolean for next generation
void City::reset() {
    for (auto & row : map) {
        for (auto & organism : row) {
            if (organism != nullptr) {
                organism->resetMoves();
            }
        }
    }
}

//function to spawn starting zombies and humans
Coordinate City::spawnPoint() {
    /*
    * finds a random, empty spot on the city grid for a zombie or human to spawn
    *randomly selects value between 1-20 (grid size) for both x and y coordinates
    *resources -- https://cplusplus.com/reference/cstdlib/rand/
    **note** there is a limited 'randomness' using 'rand'
    */
    int x;
    int y;
    Coordinate spawn;
    srand (time(NULL));

    //loop in case it generates a grid location pre-occupied
    do {
        x = rand() % GRIDSIZE;
        y = rand() % GRIDSIZE;

        spawn.x = x;
        spawn.y = y;
    } while (map[x][y] != nullptr);

    return spawn;
}

//initializes city with humans & zombies
void City::spawnOrganisms() {

    //variable for spawn point
    Coordinate spawn;

    //adds zombies to starting grid so long as there aren't more than initial quantity
    for (int i = 0; i < ZOMBIESTART; i++) {
        spawn = spawnPoint();

        Organism* zombie = new Zombie(this, spawn, ZOMBIE);
        map[spawn.x][spawn.y] = zombie;
    }

    //adds humans to starting grid so long as there aren't more than initial quantity
    for (int i = 0; i < HUMANSTART; i++) {
        spawn = spawnPoint();

        Organism* human = new Human(this, spawn, HUMAN);
        map[spawn.x][spawn.y] = human;
    }

}

ostream& operator<<(ostream &output, City &city) {
    //prints grid
    for (auto & row : city.map) {
        for (auto & organism : row) {
            if (organism == nullptr) {
                output << " " << BLANK << " ";
            } else {
                output << organism;
            }
        }
        output << endl;
    }
    return output;
}
