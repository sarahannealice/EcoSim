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
//    if (!moved) {
        move();
//        moved = true;
//        breedCount++;
//        starveCount++;

        /*
        if (breedCount >= BREED) {
            if (reproduce()) {
                breedCount = 0;
            }
        }

        if (starveCount >= STARVE) {
            starve();
        }
         */
//    }
}

void Zombie::move() {
    Coordinate current = xy;
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
        if (i >= gridSpaces.size()) {
            break;
        } else if (map->isHuman(gridSpaces.at(i)) && i < gridSpaces.size()) {
            map->resetOrg(current);
            map->placeOrg(this, gridSpaces.at(i));
            starveCount = 0;//reset counter
            break;
        }

        //if endx and endy are the current coordinate values, we're at the last
        //element in the viable spaces vector
        //if that's the case, move zombie (has been unable to eat)
        if (gridSpaces.at(i).x == endx && gridSpaces.at(i).y == endy) {
            if (map->getOrg(gridSpaces.at(i)) == nullptr) {
                map->resetOrg(current);
                map->placeOrg(this, gridSpaces.at(i));
            }
        }
        i++;
    }

    //another loop if they weren't able to eat the first time through
//    while (!moved) {
//        if (map->getOrg(gridSpaces.at(0)) == nullptr) {
//            map->resetOrg(current);
//            map->placeOrg(this, gridSpaces.at(0));
//            break;
//        } else {
//            break;
//        }
//    }
}//end Zombie::move


vector<Coordinate> Zombie::viableSpaces() {
    vector<Coordinate> spaces{};

    //check if grid spaces are within bounds then adds to vector if so
    //north
    if (this->xy.y > 0) {
        spaces.push_back(*new Coordinate(this->xy.x, this->xy.y-1));
    }
    //northeast
    if (this->xy.y > 0 && this->xy.x < GRIDSIZE-1) {
        spaces.push_back(*new Coordinate(this->xy.x+1, this->xy.y-1));
    }
    //east
    if (this->xy.x < GRIDSIZE-1) {
        spaces.push_back(*new Coordinate(this->xy.x+1, this->xy.y));
    }
    //southeast
    if (this->xy.x < GRIDSIZE-1 && this->xy.y < GRIDSIZE-1) {
        spaces.push_back(*new Coordinate(this->xy.x+1, this->xy.y+1));
    }
    //south
    if (this->xy.y < GRIDSIZE-1) {
        spaces.push_back(*new Coordinate(this->xy.x, this->xy.y+1));
    }
    //southwest
    if (this->xy.y < GRIDSIZE-1 && this->xy.x > 0) {
        spaces.push_back(*new Coordinate(this->xy.x-1, this->xy.y+1));
    }
    //west
    if (this->xy.x > 0) {
        spaces.push_back(*new Coordinate(this->xy.x-1, this->xy.y));
    }
    //northwest
    if (this->xy.x > 0 && this->xy.y > 0) {
        spaces.push_back(*new Coordinate(this->xy.x-1, this->xy.y-1));
    }

    //returns randomized vector
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(spaces.begin(), spaces.end(), default_random_engine(seed));
    return spaces;
}//end Zombie::viablespaces



/*
void Zombie::starve() {
    city->grid[x][y] = new Human;
}
*/


