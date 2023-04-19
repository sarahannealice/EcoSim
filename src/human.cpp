//
// Created by sarah on 18/04/2023.
//

#include <random>
#include <chrono>
#include <algorithm>
#include "../inc/Human.h"

//goes through human's routine
void Human::routine() {
    if (!moved) {
        move();
        if (recruitCount > RECRUIT) {
            this->recruitCount = 0;
            recruit();
        }
        recruitCount++;
        moved = true;
    } else {
    }
}

//checks for viable map coordinate
void Human::move() {
    Coordinate current = xy;
    //gathers potential coordinates
    vector<Coordinate> gridSpaces = viableSpaces();
    int i = 0;

    while (!moved) {
        if (i >= gridSpaces.size()) {
            break;
        } else if (map->getOrg(gridSpaces.at(i)) == nullptr) {
            map->resetOrg(current);
            map->placeOrg(this, gridSpaces.at(i));
            break;
        }
        i++;
    }
}

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

//    this->gridSpaces = spaces;
    //randomized the vector
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(spaces.begin(), spaces.end(), default_random_engine(seed));
    return spaces;
}

void Human::recruit() {
    vector<Coordinate> gridSpaces = viableSpaces();
    int i = 0;

    while (!moved) {
        if (i >= gridSpaces.size()) {
            this->recruitCount = 0;
            break;
        } else if (map->getOrg(gridSpaces.at(i)) == nullptr) {
            Organism* newOrg = new Human(map, gridSpaces.at(i), HUMAN);
            map->placeOrg(newOrg, gridSpaces.at(i));
            this->recruitCount = 0;
            break;
        }
        i++;
    }
}