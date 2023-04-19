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
    //gathers potential coordinates
    vector<Coordinate> gridSpaces = viableSpaces();
    int i = 0;
    //gets x-y coordinates from last coordinate in vector
    //used as a last resort in while loop
    //https://stackoverflow.com/a/14275413
    int endx = gridSpaces.back().x;
    int endy = gridSpaces.back().y;

    //checks if the chosen grid space contains a human
    while (!moved) {
        if (map->isHuman(gridSpaces.at(i))) {
            eat(gridSpaces.at(i));
            moved = true;
        }

        //if endx and endy are the current coordinate values, we're at the last
        //element in the viable spaces vector
        //if that's the case, move zombie (has been unable to eat)
        if (gridSpaces.at(i).x == endx && gridSpaces.at(i).y == endy) {
            if (map->getOrg(gridSpaces.at(i)) == nullptr) {
                placeOrg(this, gridSpaces.at(i));
            }
        }
        i++
    }




}

//zombie eats human
//removes current zombie location and replaces human-to-eat with zombie
//resets 'starve' counter
void Zombie::eat() {

}

vector<Coordinate> Zombie::viableSpaces() {
    vector<Coordinate> gridSpaces{};

    //check if grid spaces are within bounds
    //north
    if (y > 0) {
        gridSpaces.push_back(*new Coordinate(this->x, this->y-1));
    }
    //northeast
    if (y > 0 && x < GRIDSIZE-1) {
        gridSpaces.push_back(*new Coordinate(this->x+1, this->y-1));
    }
    //east
    if (x < GRIDSIZE-1) {
        gridSpaces.push_back(*new Coordinate(this->x+1, this->y));
    }
    //southeast
    if (x < GRIDSIZE-1 && y < GRIDSIZE-1) {
        gridSpaces.push_back(*new Coordinate(this->x+1, this->y+1));
    }
    //south
    if (y < GRIDSIZE-1) {
        gridSpaces.push_back(*new Coordinate(this->x, this->y+1));
    }
    //southwest
    if (y < GRIDSIZE-1 && x > 0) {
        gridSpaces.push_back(*new Coordinate(this->x-1, this->y+1));
    }
    //west
    if (x > 0) {
        gridSpaces.push_back(*new Coordinate(this->x-1, this->y));
    }
    //northwest
    if (x > 0 && y > 0) {
        gridSpaces.push_back(*new Coordinate(this->x-1, this->y-1));
    }

    //return a randomized vector
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(gridSpaces.begin(), gridSpaces.end(), default_random_engine(seed));

    return gridSpaces;
}



/*
void Zombie::starve() {
    city->grid[x][y] = new Human;
}
*/


