//
// Created by sarah on 18/04/2023.
//

#include <random>
#include <chrono>
#include <algorithm>
#include "../inc/Human.h"

//goes through human's routine
void Human::routine() {
    //check if human has moved already
    if (!moved) {
        move();

        //checks recruit counter and calls method
        if (recruitCount >= RECRUIT) {
            recruit();
            //resets even if recruiting was unsuccessful
            recruitCount = 0;
        }

        //increases counter and sets 'moved' to true
        recruitCount++;
        moved = true;
    }
}

//checks for viable map coordinate
void Human::move() {
    Coordinate current = xy;
    //gathers potential coordinates
    vector<Coordinate> gridSpaces = viableSpaces();
    int i = 0;

    while (!moved) {
        //if iterator is greater than vector, stop while loop (can cause issues otherwise)
        if (i >= gridSpaces.size()) {
            break;
        } else if (map->getOrg(gridSpaces.at(i)) == nullptr) {
            //move current human to new grid coordinate
            map->resetOrg(current);
            map->placeOrg(this, gridSpaces.at(i));
            break;
        }
        i++;
    }
}

//method to collect potential moving grid spaces
vector<Coordinate> Human::viableSpaces() {
    vector<Coordinate> spaces{};
    //check if grid spaces are within bounds then adds to vector if so
    //north
    if (this->xy.y > 0) {
        spaces.push_back(*new Coordinate(this->xy.x, this->xy.y-1));
    }
    //east
    if (this->xy.x < GRIDSIZE-1) {
        spaces.push_back(*new Coordinate(this->xy.x+1, this->xy.y));
    }
    //south
    if (this->xy.y < GRIDSIZE-1) {
        spaces.push_back(*new Coordinate(this->xy.x, this->xy.y+1));
    }
    //west
    if (this->xy.x > 0) {
        spaces.push_back(*new Coordinate(this->xy.x-1, this->xy.y));
    }

    //returns a randomized vector
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(spaces.begin(), spaces.end(), default_random_engine(seed));

    return spaces;
}

//adds another human to the grid if spot is available
void Human::recruit() {
    //gathers all viable grid locations
    vector<Coordinate> gridSpaces = viableSpaces();
    int i = 0;

    while (!moved) {
        //prevents iteration from exceeding vector size
        if (i >= gridSpaces.size()) {
            this->recruitCount = 0;
            break;
        } else if (map->getOrg(gridSpaces.at(i)) == nullptr) {
            //generates new human organism in adjacent grid coordinate
            Organism* newOrg = new Human(map, gridSpaces.at(i), HUMAN);
            map->placeOrg(newOrg, gridSpaces.at(i));
            recruitCount = 0;
            break;
        }
        i++;
    }
}