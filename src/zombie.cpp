//
// Created by sarah on 18/04/2023.
//

using namespace std;

#include <random>
#include <chrono>
#include <algorithm>
#include "../inc/Organism.h"
#include "../inc/Zombie.h"
#include "../inc/City.h"


//function to check if zombie can-should move or eat
void Zombie::routine() {
    //check if zombie has moved already
    if (!moved) {
        move();
        moved = true;
        breedCount++;
        starveCount++;

        if (breedCount >= BREED) {
            if (reproduce()) {
                breedCount = 0;
            }
        }

        if (starveCount >= STARVE) {
            starve();
        }
    }
}

void Zombie::move() {
    //gathers potential humans locations and checks if any are present
    vector<spaces> gridSpaces = findFood();

    for (int i = 0; i < BREED; i++) {
        if (map->isHuman(this, gridSpaces.at(i))) {
        }
        i++;
    }



}

vector<Organism::spaces> findFood() {
    vector<Zombie::spaces> foodSpaces;

    //potential spaces
    //north
    if (Organism::x > 0)
    foodSpaces.push_back(Zombie::NORTH);
    foodSpaces.push_back(Zombie::EAST);
    foodSpaces.push_back(Zombie::SOUTH);
    foodSpaces.push_back(Zombie::WEST);
    //diagonals
    foodSpaces.push_back(Zombie::NE);
    foodSpaces.push_back(Zombie::SE);
    foodSpaces.push_back(Zombie::SW);
    foodSpaces.push_back(Zombie::NW);

    //return a randomized vector
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(foodSpaces.begin(), foodSpaces.end(), default_random_engine(seed));

    return foodSpaces;
}

vector<Organism::spaces> openSpace() {

}



/*
void Zombie::starve() {
    city->grid[x][y] = new Human;
}
*/


