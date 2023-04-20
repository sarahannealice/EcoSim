//
// Created by sarah on 18/04/2023.
//
using namespace std;

#include "../inc/Organism.h"
#include "../inc/City.h"

//resets 'moved' boolean for desired organism
void Organism::resetMoves() {
    moved = false;
}

ostream &operator<<(ostream &output, Organism *organism) {
    //checks organism type and prints in corresponding colour (blank has its own color)
    switch (organism->type) {
        case ZOMBIE:
            output << " " << ZOMBIECOLOR << organism->type << BLANKCOLOR << " ";
            break;
        case HUMAN:
            output << " " << HUMANCOLOR << organism->type << BLANKCOLOR << " ";
    }
    return output;
}

