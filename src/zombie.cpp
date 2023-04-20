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
#include "../inc/Human.h"


//function to check if zombie can-should move or eat
void Zombie::routine() {
    //check if zombie has moved already
    if (!moved) {
        move();

        //checks the breed counter and calls method
        if (breedCount >= BREED) {
            reproduce();
        }

        //checks the starve counter and calls method
        if (starveCount >= STARVE) {
            starve();
        }

        //increases counters and sets 'moved' to true
        breedCount++;
        starveCount++;
        moved = true;
    }
}

//function to check where's viable for zombie to move
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

    //checks if the chosen grid space contains a human to eat
    while (!moved) {
        //if iterator is greater than vector, stop while loop (can cause issues otherwise)
        if (i >= gridSpaces.size()) {
            break;
        } else if (map->isHuman(gridSpaces.at(i))) {
            //if human is present, replace with zombie (zombie eats human)
            map->resetOrg(current);
            map->placeOrg(this, gridSpaces.at(i));
            starveCount = 0;//reset counter

            //update counter
            map->decHumans();
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
}//end Zombie::move

//collects all in-bounds grid coordinates
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

//breed zombie method
void Zombie::reproduce() {
    //gathers potential coordinates
    vector<Coordinate> gridSpaces = viableSpaces();
    int i = 0;

    //checks if the chosen grid space contains a human
    //if so, convert human to zombie
    //if not, keep counter as is and return to routine method
    while (!moved) {
        if (i >= gridSpaces.size()) {
            break;
        } else if (map->isHuman(gridSpaces.at(i))) {
            Organism* newOrg = new Zombie (map, this->xy, ZOMBIE);
            map->placeOrg(newOrg, gridSpaces.at(i));
            breedCount = 0;//reset counter

            //update counter
            map->decHumans();
            break;
        }
        i++;
    }
}

//converts starved zombie back to human
void Zombie::starve() {
    Organism* newOrg = new Human (map, this->xy, HUMAN);
    map->resetOrg(this->xy);
    map->placeOrg(newOrg, this->xy);

    //update counters
    map->decZombies();
}


