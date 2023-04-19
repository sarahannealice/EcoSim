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

//destructor
City::~City() = default;


//----------------methods----------------//
//checks if both humans and zombies are on the map
bool City::hasDiversity() {
    return true;
}

//function to count zombies and humans
int City::counter(char type) {
    switch (type) {
        HUMAN:
            count = humans;
            break;
        ZOMBIE:
            count = zombies;
            break;
    }

    return count;
}

//checks if grid spot contains human
bool City::isHuman(Coordinate xy) {
    bool human = false;
    //check if grid space is within bounds
    if (xy.x < 0 || xy.y < 0 || xy.x > GRIDSIZE || xy.y > GRIDSIZE) {
        human = false;
    }

    //checks that the organism at the grid spot is human
    if (map[xy.x][xy.y] != nullptr && map[xy.x][xy.y]->getType() == HUMAN) {
        human = true;
    }
    return human;
}

//places desired organism at x,y location on map
void City::placeOrg(Organism* activeOrg, Coordinate xy) {
    map[xy.x][xy.y] = activeOrg;
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


/*
//resets every organism's 'move' boolean for next generation
void City::reset() {
    for (auto & row : map) {
        for (auto & organism : row) {
            if (organism != nullptr) {
                organism->resetMove();
            }
        }
    }
}
 */

//function to spawn starting zombies and humans
array<int, 2> City::spawnPoint() {
    /*
    * finds a random, empty spot on the city grid for a zombie or human to spawn
    *randomly selects value between 1-20 (grid size) for both x and y
    *resources -- https://cplusplus.com/reference/cstdlib/rand/
    **note** there is a limited 'randomness' using 'rand'
    */
    int x;
    int y;
    array<int, 2> spawn{};
    srand (time(NULL));

    //loop in case it generates a grid location pre-occupied
    do {
        x = rand() % GRIDSIZE;
        y = rand() % GRIDSIZE;

        spawn[0] = x;
        spawn[1] = y;
    } while (map[x][y] != nullptr);

    return spawn;
}

//initializes city with humans & zombies
void City::spawnOrganisms() {

    //variables for spawn locations
    array<int, 2> spawn{};
    int x;
    int y;

    //adds zombies to starting grid so long as there aren't more than initial quantity
    for (int i = 0; i < ZOMBIESTART; i++) {
        spawn = spawnPoint();
        Coordinate xy = *new Coordinate;
        xy.x = spawn[0];
        xy.y = spawn[1];

        Organism* zombie = new Zombie(this, xy, ZOMBIE);
        map[xy.x][xy.y] = zombie;
    }

    //adds humans to starting grid so long as there aren't more than initial quantity
    for (int i = 0; i < HUMANSTART; i++) {
        spawn = spawnPoint();
        Coordinate xy = *new Coordinate;
        xy.x = spawn[0];
        xy.y = spawn[1];

//        Organism* human = new Human(this, xy, HUMAN);
//        map[x][y] = human;
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
